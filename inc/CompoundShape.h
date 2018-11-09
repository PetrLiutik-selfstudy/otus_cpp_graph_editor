#pragma once

#include <IShape.h>

#include <list>

namespace graphics {

/**
 * @brief Класс составной фигуры.
 */
class CompoundShape : public IShape {
  public:
    explicit CompoundShape() = default;

    CompoundShape(const CompoundShape&) = delete;
    CompoundShape(CompoundShape&&) = delete;

    ~CompoundShape() = default;

    CompoundShape& operator = (const CompoundShape&) = delete;
    CompoundShape& operator = (CompoundShape&&) = delete;



    /**
     * @brief Дать тип фигуры.
     * @return тип фигуры.
     */
    ShapeType get_type() const {
      return COMPOUND;
    }

    /**
     * @brief Дать характерные точки фигуры.
     * @return характерные точки фигуры.
     */
    virtual PointChain get_point_chain() const {
    }

    /**
     * @brief Дать цвет фигуры.
     * @return цвет фигуры.
     */
    Color get_color() const {
      return WHITE;
    }

    /**
     * @brief Переместить фигуру.
     * @param offset - смещение, на которое необходимо сдвинуть фигуру.
     */
    void move(const Point& offset) {
      for(auto& it: shapes_)
        it.move(offset);
    }

    /**
     * @brief Перерисовать фигуру в представлении.
     */
    void redraw(GraphicView& view) {
      for(auto& it: shapes_)
        it.redraw(view);
    }

  private:
    /// Список фигур входящих в составную.
    std::list<IShape> shapes_;
};

} // namespace graphics.
