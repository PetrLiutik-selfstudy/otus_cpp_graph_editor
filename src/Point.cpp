#include "Point.h"

namespace graphics {

std::ostream& operator <<(std::ostream& os, const Point& point) {
  os << "x: " << point.x_ << " y: " << point.y_ << "\n";
  return os;
}

} // namespace graphics.
