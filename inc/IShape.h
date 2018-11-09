#pragma once

#include "Point.h"

#include <vector>

namespace graphics {

class GraphicView;

/// Тип описывающий характерные точки фигуры.
using PointChain = std::vector<Point>;

/// Цвет фигуры.
enum Color {
  WHITE = 0,
  RED,
  GREEN,
  BLUE,
  BLACK
};

/// Тип фигуры.
enum ShapeType {
  LINE = 0,
  POLYLINE,
  RECTANGLE,
  CIRCLE,
  COMPOUND = 255
};

/**
 * @brief Интерфейс графической фигуры.
 */
class IShape {
  public:
    virtual ~IShape() = default;

    /**
     * @brief Дать тип фигуры.
     * @return тип фигуры.
     */
    virtual ShapeType get_type() const = 0;

    /**
     * @brief Дать характерные точки фигуры.
     * @return характерные точки фигуры.
     */
    virtual PointChain get_point_chain() const = 0;

    /**
     * @brief Дать цвет фигуры.
     * @return цвет фигуры.
     */
    virtual Color get_color() const = 0;

    /**
     * @brief Переместить фигуру.
     * @param offset - смещение, на которое необходимо сдвинуть фигуру.
     */
    virtual void move(const Point& offset) = 0;

    /**
     * @brief Перерисовать фигуру в представлении.
     */
    virtual void redraw(GraphicView& view) = 0;
};

} // namespace graphics.
