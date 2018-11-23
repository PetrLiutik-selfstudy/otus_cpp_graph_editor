#pragma once

#include <string>
#include <memory>

namespace graphics {

class IView {
public:
  virtual ~IView() = default;

  /**
   * @brief Перерисовать вид.
   */
  virtual void render() const = 0;

  virtual void say_hello(const std::string& str) const = 0 ; // only for exposition
};

using view_t = std::unique_ptr<IView>;

} // namespace graphics.
