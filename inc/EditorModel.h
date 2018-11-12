#pragma once

#include "IShape.h"
#include "CompoundShape.h"
#include "GraphicView.h"
#include "ShapeFactory.h"
#include "IImporter.h"
#include "IExporter.h"

#include <string>
#include <list>
#include <memory>

namespace graphics {

/**
 * @brief Класс модели графического редактора.
 */
class EditorModel {
public:
  explicit EditorModel() = default;
  ~EditorModel() = default;


  /**
   * @brief Создать новое изображение.
   */
  void create_new_image() {
    image_.clear();
    selected_.clear();
    view_.clear();
  }

  /**
   * @brief Очистить изображение.
   */
  void clear_image() {
    image_.clear();
    selected_.clear();
    view_.clear();
  }

  /**
   * @brief Создание новой фигуры.
   * @param type - тип фигуры.
   * @param points - координаты точек, необходимых для построения фигуры.
   */
  void create_shape(ShapeType type, const CoordsChain& points) {
    selected_.mark_as_selected(false);
    image_.push_from(selected_);
    auto shape = shape_factory_.create_shape(type, color_, points);
    image_.push(std::move(shape));
    redraw();
  }

  /**
   * @brief Загрузить изображение из файла.
   * @param importer - импортер изображения.
   * @param filename - имя файла.
   */
  void load_image(std::shared_ptr<IImporter> importer, const std::string& filename) {
    clear_image();
    importer->load(filename, image_);
    redraw();
  }

  /**
   * @brief Сохранить изображение в файл.
   * @param exporter - экспортер изображения.
   * @param filename - имя файла.
   */
  void save_image(std::shared_ptr<IExporter> exporter, const std::string& filename) {
    exporter->save(filename, image_);
  }

  /**
   * @brief Выбор цвета рисования фигур.
   * @param color - цвет.
   */
  void choose_color(Color color) {
    color_ = color;
  }

  /**
   * @brief Выделить фигуру.
   * @param p - координата точки принадлежащей выделяемой фигуре.
   * @return true - фигура была выделена, false - нет выделенных фигур.
   */
  bool select_shape(const Coords& p) {
    image_.push_from(selected_);
    selected_.push_from_if(image_, [&p](const CoordsChain& points) {
      for(const auto& it: points)
        if(it == p)
          return true;
      return false;
    });

    if(!selected_.is_empty()) {
      selected_.mark_as_selected(true);
      redraw();
      return true;
    }
    return false;
  }

  /**
   * @brief Выделить фигуру(ы) в пределах указанного прямоугольника.
   * @param p1 - координаты нижней левой точки прямоугольника.
   * @param p2 - координаты верхней правой точки прямоугольника.
   * @return true - фигура была выделена, false - нет выделенных фигур.
   */
  bool select_shape(const Coords& p1, const Coords& p2) {
    image_.push_from(selected_);
    selected_.push_from_if(image_, [&p1, &p2](const CoordsChain& points) {
      for(const auto& it: points)
        if(it.belongs_to_rect(p1, p2))
          return true;
      return false;
    });

    if(!selected_.is_empty()) {
      selected_.mark_as_selected(true);
      redraw();
      return true;
    }
    return false;
  }

  /**
   * @brief Отменить выделение фигуры.
   */
  void deselect_shape() {
    selected_.mark_as_selected(false);
    image_.push_from(selected_);
    redraw();
  }

  /**
   * @brief Изменить цвет выделенной фигуры.
   * @param color - цвет.
   */
  void change_shape_color(Color color) {
    selected_.set_color(color);
    redraw();
  }

  /**
   * @brief Передвинуть выделенную фигуру(ы).
   * @param offset - смещение.
   */
  void move_shape(const Coords& offset) {
    selected_.move(offset);
    redraw();
  }

  /**
   * @brief Удалить выбраную фигуру(ы).
   */
  void remove_shape() {
    selected_.clear();
    redraw();
  }

private:

  /// Перерисовка представления.
  void redraw() {
    view_.clear();
    image_.redraw(view_);
    selected_.redraw(view_);
    view_.refresh();
  }


  /// Составной объект содержащий все фигуры изображения.
  CompoundShape image_{};

  /// Составной объект содержащий выделенные фигуры.
  CompoundShape selected_{};

  /// Графическое представление.
  GraphicView view_{};

  /// Цвет отрисовки фигур.
  Color color_{BLACK};

  /// Фабрика фигур.
  ShapeFactory shape_factory_{};
};

} // namespace graphics.
