#pragma once

#include "IShape.h"
#include "GraphicView.h"

namespace graphics {

/**
 * @brief Класс прямоугольника.
 */
class Rectangle : public IShape {
  public:
    /**
     * @brief Конструктор отрезка.
     * @param p1 - координаты нижнего левого угла.
     * @param p2 - координаты верхнего правого угла.
     * @param color - цвет.
     */
    explicit Rectangle(const Point& p1, const Point& p2, Color color = BLACK) : color_(color) {
      points_.emplace_back(p1);
      points_.emplace_back(p2);
    }

    ~Rectangle() override = default;

    /**
     * @brief Дать тип фигуры.
     * @return тип фигуры.
     */
    ShapeType get_type() const override {
      return RECTANGLE;
    }

    /**
     * @brief Дать характерные точки фигуры.
     * @return характерные точки фигуры.
     */
    PointChain get_point_chain() const override {
      return points_;
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
      view.draw(RECTANGLE, color_, points_);
    }

  private:
    PointChain points_;
    Color      color_;
};

} // namespace graphics.
