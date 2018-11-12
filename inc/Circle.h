#pragma once

#include "IShape.h"
#include "GraphicView.h"

namespace graphics {

/**
 * @brief Класс окружности.
 */
class Circle : public IShape {
public:
  /**
   * @brief Конструктор отрезка.
   * @param c - координаты центра.
   * @param r - радиус.
   * @param color - цвет.
   */
  explicit Circle(const Coords& c, int r, Color color = BLACK) : color_(color) {
    make_circle_points(c, r);
  }

  ~Circle() override = default;

  /**
   * @brief Дать тип фигуры.
   * @return тип фигуры.
   */
  ShapeType get_type() const override {
    return CIRCLE;
  }

  /**
   * @brief Дать цвет фигуры.
   * @return цвет фигуры.
   */
  Color get_color() const override {
    return color_;
  }

  /**
   * @brief Дать цвет фигуры.
   * @return цвет фигуры.
   */
  void set_color(Color color) override {
    color_ = color;
  }

  /**
   * @brief Переместить фигуру.
   * @param offset - смещение, на которое необходимо сдвинуть фигуру.
   */
  void move(const Coords& offset) override {
    for(auto& it: points_)
      it += offset;
  }

  /**
   * @brief Перерисовать фигуру в представлении.
   */
  void redraw(GraphicView& view) override {
    view.draw(CIRCLE, color_, points_, is_selected_);
  }

  /**
   * @brief Пометить фигуру как выделенную.
   * @param is_selected - фигура выделена или нет.
   */
  void mark_as_selected(bool is_selected) override {
    is_selected_ = is_selected;
  }

  /**
   * @brief Дать координаты точек фигуры.
   * @return координаты точки фигуры.
   */
  CoordsChain get_coords_chain() const override {
    return points_;
  }

private:

  static constexpr double sqrt0p5 = 0.7071;

  /// Сформировать цепочку точек окружности.
  void make_circle_points(const Coords& c, int r) {
    int d = static_cast<int>(static_cast<double>(r) * sqrt0p5);
    points_.push_back({c.get_x_coord() + r, c.get_y_coord()});
    points_.push_back({c.get_x_coord() + d, c.get_y_coord() + d});
    points_.push_back({c.get_x_coord(), c.get_y_coord() + r});
    points_.push_back({c.get_x_coord() - d, c.get_y_coord() + d});
    points_.push_back({c.get_x_coord() - r, c.get_y_coord()});
    points_.push_back({c.get_x_coord() - d, c.get_y_coord() - d});
    points_.push_back({c.get_x_coord(), c.get_y_coord() - r});
    points_.push_back({c.get_x_coord() + d, c.get_y_coord() - d});
  }

  CoordsChain points_{};
  Color color_{};
  bool is_selected_{};
};

} // namespace graphics.
