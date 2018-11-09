#pragma once

#include "IShape.h"

#include <string>
#include <iostream>

namespace graphics {

/**
 * @brief Класс представления графического редактора.
 */
class GraphicView {
  public:
    /**
    * @brief Конструктор.
    * @param bulk_size - макисмальный размер блока команд.
    */
    explicit GraphicView();

    ~GraphicView() = default;


    void draw(ShapeType type, Color color, const PointChain& points_) {
      std::cout << "Draw shape";
    }

  private:
};

} // namespace graphics.
