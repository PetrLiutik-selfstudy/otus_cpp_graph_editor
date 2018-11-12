#pragma once

#include "IShape.h"
#include "GraphicView.h"

namespace graphics {

/**
 * @brief Класс ломаной линии.
 */
class Polyline : public IShape {
  public:
    /**
     * @brief Конструктор ломаной линии.
     * @param points - координаты точек.
     * @param color - цвет.
     */
    explicit Polyline(const CoordsChain& points, Color color = BLACK) : points_{points}, color_(color) {
    }

    ~Polyline() override = default;

  /**
   * @brief Дать тип фигуры.
   * @return тип фигуры.
   */
  ShapeType get_type() const override {
    return POLYLINE;
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
    view.draw(POLYLINE, color_, points_, is_selected_);
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
  CoordsChain points_;
  Color      color_;
  bool       is_selected_{};
};

} // namespace graphics.
