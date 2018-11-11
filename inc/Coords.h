#pragma once

#include <ostream>
#include <cmath>
#include <vector>

namespace graphics {

/**
 * @brief Класс описывающий координаты точки в 2D пространстве.
 */
class Coords {
  public:
     /**
     * @brief Конструктор.
     * @param x - координата x.
     * @param y - координата y.
     */
    explicit Coords(int x, int y) : x_{x}, y_{y} {
    }

     /**
     * @brief Конструктор со списком инициализации.
     * @param coords - координаты.
     */
    Coords(std::initializer_list<int> coords) {
      auto it = coords.begin();
      x_ = *it++;
      y_ = *it;
    }

    Coords(const Coords&) = default;
    Coords& operator = (Coords const&) = default;
    Coords& operator = (Coords&&) noexcept = default;

    ~Coords() = default;

    /**
     * @brief Оператор += (изменение координат на указанное смещение).
     * @param offset - смещение.
     * @return ссылка на себя.
     */
    Coords& operator += (const Coords& offset) {
      x_ += offset.x_;
      y_ += offset.y_;
      return *this;
    }

    /**
     * @brief Оператор равенства.
     * @param other - координаты другой точки.
     * @return true - координаты совпадают, false - не совпадают.
     */
    bool operator == (const Coords& other) const {
      return (x_ == other.x_) && (y_ == other.y_);
    }

    /**
     * @brief Проверка принадлежности точки с координатами прямоугольнику.
     * @param p1 - координаты нижней левой точки прямоугольника.
     * @param p2 - координаты верхней правой точки прямоугольника.
     * @return true - точка принадлежит прямоугольнику, false - не принадлежит.
     */
    bool belongs_to_rect(const Coords& p1, const Coords& p2) const {
      return (p1.x_ <= x_) && (p2.x_ >= x_) && (p1.y_ <= y_) && (p2.y_ >= y_);
    }

    /**
     * @brief Дать расстояние между двумя точками.
     * @param p1 - координаты первой точки.
     * @param p2 - координаты второй точки.
     * @return расстояние между точками.
     */
    friend int get_distance(const Coords& p1, const Coords& p2);

    int get_x_coord() const {
      return x_;
    }

    int get_y_coord() const {
      return y_;
    }

  private:
    /// Координата x.
    int x_;
    /// Координата y.
    int y_;
};

inline int get_distance(const Coords& p1, const Coords& p2) {
  auto dist = sqrt((p1.x_ - p2.x_) * (p1.x_ - p2.x_) + (p1.y_ - p2.y_) * (p1.y_ - p2.y_));
  return static_cast <int>(dist);
}

/// Тип цепочки координат нескольких точек.
using CoordsChain = std::vector<Coords>;

} // namespace graphics.
