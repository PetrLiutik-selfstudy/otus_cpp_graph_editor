#pragma once

#include <ostream>

namespace graphics {

/**
 * @brief Структура координат точки.
 */
class Point {
  public:
    Point(int x, int y) : x_{x}, y_{y} {
    }

    Point(const Point&) = default;
    Point& operator = (Point const&) = default;
    Point& operator = (Point&&) noexcept = default;

    ~Point() = default;

    Point& operator += (const Point& other) {
      x_ += other.x_;
      y_ += other.y_;
      return *this;
    }

    /**
     * @brief Оператор вывода в поток координат точки.
     * @param os - поток вывода.
     * @param point - точка.
     * @return
     */
    friend std::ostream& operator <<(std::ostream& os, const Point& point);

  private:
    /// Координата x.
    int x_{};
    /// Координата y.
    int y_{};
};

} // namespace graphics.
