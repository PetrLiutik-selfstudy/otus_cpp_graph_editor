#pragma once

#include "IView.h"
#include "IShape.h"
#include "CompoundShape.h"
#include "ShapeFactory.h"

#include <string>
#include <list>
#include <memory>
#include <vector>

namespace graphics {

/**
 * @brief Класс модели графического редактора.
 */
class EditorModel {
public:
  explicit EditorModel() = default;
  ~EditorModel() = default;

  /**
   * @brief Добавить предстваление.
   * @param view - представление.
   */
  void add_view(view_t&& view) {
    views_.push_back(std::move(view));
    views_.back()->render();
  }


  /**
   * @brief Создание новой фигуры.
   * @param type - тип фигуры.
   * @param points - координаты точек, необходимых для построения фигуры.
   */
  void create_shape(ShapeType type, Color color, const CoordsChain& points) {
    auto shape = shape_factory_.create_shape(type, color, points);
    shapes_.push(std::move(shape));
    update_views();
  }


  /**
   * @brief Выделить фигуру.
   * @param p - координата точки принадлежащей выделяемой фигуре.
   * @return true - фигура была выделена, false - нет выделенных фигур.
   */
  bool select_shape(const Coords& p) {
    shapes_.push_from(selected_);
    selected_.push_from_if(shapes_, [&p](const CoordsChain& points) {
      for(const auto& it: points)
        if(it == p)
          return true;
      return false;
    });

    if(!selected_.is_empty()) {
      selected_.mark_as_selected(true);
      update_views();
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
    shapes_.push_from(selected_);
    selected_.push_from_if(shapes_, [&p1, &p2](const CoordsChain& points) {
      for(const auto& it: points)
        if(it.belongs_to_rect(p1, p2))
          return true;
      return false;
    });

    if(!selected_.is_empty()) {
      selected_.mark_as_selected(true);
      update_views();
      return true;
    }
    return false;
  }

  /**
   * @brief Отменить выделение фигуры.
   */
  void deselect_shape() {
    selected_.mark_as_selected(false);
    shapes_.push_from(selected_);
    update_views();
  }

  /**
   * @brief Изменить цвет выделенной фигуры.
   * @param color - цвет.
   */
  void change_shape_color(Color color) {
    selected_.set_color(color);
    update_views();
  }

  /**
   * @brief Передвинуть выделенную фигуру(ы).
   * @param offset - смещение.
   */
  void move_shape(const Coords& offset) {
    selected_.move(offset);
    update_views();
  }

  /**
   * @brief Удалить выбраную фигуру(ы).
   */
  void remove_shape() {
    selected_.clear();
    update_views();
  }


  /**
   * @brief Дать фигуры (для помещения в документ).
   * @return фигуры.
   */
  CompoundShape& get_shapes() {
    return shapes_;
  }

  /**
   * @brief Загрузить фигуры (из документа).
   */
  void add_shapes(CompoundShape& shapes) {
    shapes_.push_from(shapes);
    update_views();
  }

private:
  /**
   * @brief Обновление графических представлений.
   */
  void update_views() {
    for(auto& view: views_)
      view->render();
  }

  /// Представления.
  std::vector<view_t> views_;
  /// Cоставной объект, содержащий все фигуры.
  CompoundShape shapes_{};
  /// Составной объект, содержащий выделенные фигуры.
  CompoundShape selected_{};
  /// Фабрика фигур.
  ShapeFactory shape_factory_{};
};

} // namespace graphics.
