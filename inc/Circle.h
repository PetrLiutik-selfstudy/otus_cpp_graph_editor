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
    explicit Circle(const Point& c, int r, Color color = BLACK) : center_{c}, radius_{r}, color_(color) {

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
     * @brief Дать характерные точки фигуры.
     * @return характерные точки фигуры.
     */
    PointChain get_point_chain() const override {

    }

    /**
     * @brief Дать цвет фигуры.
     * @return цвет фигуры.
     */
    Color get_color() const override {
      return color_;
    }

    /**
     * @brief Переместить фигуру.
     * @param offset - смещение, на которое необходимо сдвинуть фигуру.
     */
    void move(const Point& offset) override {
      for(auto& it: points_)
        it += offset;
    }

    /**
     * @brief Перерисовать фигуру в представлении.
     */
    void redraw(GraphicView& view) override {
      view.draw(CIRCLE, color_, points_);
    }

  private:
    PointChain points_{};
    Point center_;
    int   radius_;
    Color color_;
};

} // namespace graphics.
