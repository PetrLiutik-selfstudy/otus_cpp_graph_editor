#pragma once

#include "IShape.h"

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

    }

    /**
     * @brief Очистить рисунок.
     */
    void clear_image() {

    }

    /**
     * @brief Экспорт рисунка в файл.
     * @param file_name - имя файла.
     */
    void export_image(const std::string& file_name) {

    }

    /**
     * @brief Импорт рисунка из файла.
     * @param file_name - имя файла.
     */
    void import_image(const std::string& file_name) {

    }

    /**
     * @brief Выбор цвета рисования фигур.
     * @param color - цвет.
     */
    void choose_color(Color color) {
      color_ = color;
    }

    /**
     * @brief Нарисовать отрезок.
     * @param p1 - координата начала отрезка.
     * @param p2 - координата конца отрезка.
     */
    void add_line(const Point& p1, const Point& p2) {

    }

    /**
     * @brief Нарисовать ломаную линию.
     * @param points - точки ломанной линии.
     */
    void add_polyline(const PointChain& points) {

    }

    /**
     * @brief Нарисовать прямоугольник.
     * @param p1 - координата нижней левой точки прямоугольника.
     * @param p2 - координата верхней правой точки прямоугольника.
     */
    void add_rectangle(const Point& p1, const Point& p2) {

    }

    /**
     * @brief Нарисовать окружность.
     * @param c - координаты центра окружности.
     * @param r - радиус окружности.
     */
    void add_circle(const Point& c, int r) {

    }

    /**
     * @brief Выделить фигуру.
     * @param p - координата точки принадлежащей выделяемой фигуре.
     */
    void select_shape(const Point& p) {

    }

    /**
     * @brief Выделить фигуру(ы) в пределах указанного прямоугольника.
     * @param p1 - координата нижней левой точки прямоугольника.
     * @param p2 - координата верхней правой точки прямоугольника.
     */
    void select_shape(const Point& p1, const Point& p2) {

    }

    /**
     * @brief Изменить цвет выделенной фигуры.
     * @param offset - смещение.
     */
    void change_shape_color(Color color) {

    }

    /**
     * @brief Передвинуть выделенную фигуру(ы).
     * @param offset - смещение.
     */
    void move_shape(const Point& offset) {

    }

    /**
     * @brief Удалить выбраную фигуру(ы).
     */
    void remove_shape() {

    }

  private:

    Color color_{BLACK};

};

} // namespace graphics.
