#pragma once

#include "IShape.h"
#include "EditorModel.h"
#include "SvgExporter.h"
#include "SvgImporter.h"

#include <memory>
#include <string>

namespace graphics {

/**
 * @brief Класс контроллера редактора.
 */
class EditorController {
  public:
    explicit EditorController() {
    }
    ~EditorController() = default;

    /**
     * @brief Создать новый рисунок.
     */
    void create_new_image() {
      model_.create_new_image();
    }

    /**
     * @brief Очистить рисунок.
     */
    void clear_image() {
      model_.clear_image();
    }

    /**
     * @brief Сохранение рисунка в файл в формате SVG.
     * @param file_name - имя файла.
     */
    void save_image_as_svg(const std::string& filename) {
      model_.save_image(std::make_shared<SvgExporter>(), filename);
    }

    /**
     * @brief Сохранение рисунка в файл в формате txt.
     * @param file_name - имя файла.
     */
    void save_image_as_txt(const std::string& filename) {
//      model_.save_image(std::make_shared<TxtExporter>(), filename);
    }

    /**
     * @brief Загрузка рисунка из файла.
     * @param file_name - имя файла.
     */
    void load_image_as_svg(const std::string& filename) {
      model_.load_image(std::make_shared<SvgImporter>(), filename);
    }

    /**
     * @brief Загрузка рисунка из файла.
     * @param file_name - имя файла.
     */
    void load_image_as_txt(const std::string& filename) {
//      model_.load_image(std::make_shared<TxtImporter>() filename);
    }

    /**
     * @brief Выбор цвета рисования фигур.
     * @param color - цвет.
     */
    void choose_color(Color color) {
      model_.choose_color(color);
    }

    /**
     * @brief Нарисовать отрезок.
     * @param p1 - координата начала отрезка.
     * @param p2 - координата конца отрезка.
     */
    void add_line(const Coords& p1, const Coords& p2) {
      model_.create_shape(LINE, {p1, p2});
    }

    /**
     * @brief Нарисовать ломаную линию.
     * @param points - точки ломанной линии.
     */
    void add_polyline(const CoordsChain& points) {
      model_.create_shape(POLYLINE, points);
    }

    /**
     * @brief Нарисовать прямоугольник.
     * @param p1 - координата нижней левой точки прямоугольника.
     * @param p2 - координата верхней правой точки прямоугольника.
     */
    void add_rectangle(const Coords& p1, const Coords& p2) {

    }

    /**
     * @brief Нарисовать окружность.
     * @param c - координаты центра окружности.
     * @param r - точка лежащая на окружности (для задания радиуса).
     */
    void add_circle(const Coords& c, const Coords& r) {
      model_.create_shape(CIRCLE, {c, r});
    }

    /**
     * @brief Выделить фигуру.
     * @param p - координата точки принадлежащей выделяемой фигуре.
     */
    void select_shape(const Coords& p) {
      model_.select_shape(p);
    }

    /**
     * @brief Выделить фигуру(ы) в пределах указанного прямоугольника.
     * @param p1 - координата нижней левой точки прямоугольника.
     * @param p2 - координата верхней правой точки прямоугольника.
     */
    bool select_shape(const Coords& p1, const Coords& p2) {
      model_.select_shape(p1, p2);
    }

    /**
     * @brief Отменить выделение фигуры.
     */
    void deselect_shape() {
      model_.deselect_shape();
    }

    /**
     * @brief Изменить цвет выделенной фигуры.
     * @param offset - смещение.
     */
    void change_shape_color(Color color) {
      model_.change_shape_color(color);
    }

    /**
     * @brief Передвинуть выделенную фигуру(ы).
     * @param offset - смещение.
     */
    void move_shape(const Coords& offset) {
      model_.move_shape(offset);
    }

    /**
     * @brief Удалить выбраную фигуру(ы).
     */
    void remove_shape() {
      model_.remove_shape();
    }

  private:

    EditorModel model_;

};

} // namespace graphics.
