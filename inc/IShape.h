#pragma once

#include "Coords.h"

#include <vector>

namespace graphics {

class GraphicView;

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
   * @brief Дать цвет фигуры.
   * @return цвет фигуры.
   */
  virtual Color get_color() const = 0;

  /**
   * @brief Установить цвет фигуры.
   * @param color - цвет фигуры.
   */
  virtual void set_color(Color color) = 0;

  /**
   * @brief Переместить фигуру.
   * @param offset - смещение, на которое необходимо сдвинуть фигуру.
   */
  virtual void move(const Coords& offset) = 0;

  /**
   * @brief Перерисовать фигуру в представлении.
   */
  virtual void redraw(GraphicView& view) = 0;

  /**
   * @brief Пометить фигуру как выделенную.
   * @param is_selected - фигура выделена или нет.
   */
  virtual void mark_as_selected(bool is_selected) = 0;

  /**
   * @brief Дать координаты точек фигуры.
   * @return координаты точки фигуры.
   */
  virtual CoordsChain get_coords_chain() const = 0;
};

} // namespace graphics.
