#pragma once

#include <string>
#include <memory>

namespace graphics {

/**
 * @brief Интерфейс графического представления.
 */
class IView {
public:
  virtual ~IView() = default;

  /**
   * @brief Перерисовать вид.
   */
  virtual void render() = 0;
};

using view_t = std::unique_ptr<IView>;

} // namespace graphics.
