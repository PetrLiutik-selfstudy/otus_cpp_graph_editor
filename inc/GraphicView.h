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
  explicit GraphicView() = default;
  ~GraphicView() = default;

  /**
   * @brief Очистка графического представления.
   */
  void clear() {
    std::cout << "\nView has been cleared\n";
    screen_.clear();
  }

  /**
   * @brief Рисование фигуры.
   * @param type - тип фигуры.
   * @param color - цвет.
   * @param points - ткоординаты точек фигуры.
   * @param is_selected - фигура выделена.
   */
  void draw(ShapeType type, Color color, const CoordsChain& points, bool is_selected) {
    std::string str{"Shape: "};

    if(is_selected)
      str += "selected ";

    if(WHITE == color)
      str += "white ";
    else if(RED == color)
      str += "red ";
    else if(GREEN == color)
      str += "green ";
    else if(BLUE == color)
      str += "blue ";
    else if(BLACK == color)
      str += "black ";

    if(LINE == type)
      str += "line ";
    else if(POLYLINE == type)
      str += "polyline ";
    else if(RECTANGLE == type)
      str += "rectangle ";
    else if(CIRCLE == type)
      str += "circle ";

    for(const auto& it: points) {
      str += "{";
      str += std::to_string(it.get_x_coord());
      str += ",";
      str += std::to_string(it.get_y_coord());
      str += "}";
      str += " ";
    }
    str += "\n";

    screen_.emplace_back(str);
  }

  /**
   * @brief Обновление графического представления.
   */
  void refresh() {
    for(auto it: screen_) {
      std::cout << it;
    }
  }

private:
  std::vector<std::string> screen_{};
};

} // namespace graphics.
