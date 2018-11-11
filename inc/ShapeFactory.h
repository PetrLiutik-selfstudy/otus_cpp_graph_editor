#pragma once

#include "IShape.h"
#include "Line.h"
#include "Polyline.h"
#include "CompoundShape.h"
#include "Rectangle.h"
#include "Circle.h"

#include <memory>

namespace graphics {

/**
 * @brief Класс фабрики фигур.
 */
class ShapeFactory {
public:
  explicit ShapeFactory() = default;
  ~ShapeFactory() = default;

  /**
   * @brief Создать фигуру.
   * @param type - тип фигуры.
   * @param color - цвет фигуры.
   * @param points - координаты точек, необходимых для построения фигуры.
   * @return
   */
  std::unique_ptr<IShape> create_shape(ShapeType type, Color color, const CoordsChain& points) {
    switch(type) {
    case LINE:
      return std::make_unique<Line>(points[0], points[1], color);

    case POLYLINE:
      return std::make_unique<Polyline>(points, color);

    case RECTANGLE:
      return std::make_unique<Rectangle>(points[0], points[1], color);

    case CIRCLE:
      return std::make_unique<Circle>(points[0], get_distance(points[0], points[1]), color);

    default:
      break;
    }
    return std::unique_ptr<IShape>{};
  }
};

} // namespace graphics.
