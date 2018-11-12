#pragma once

#include <IShape.h>

#include <list>
#include <memory>

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
   * @brief Очистить составную фигуру.
   */
  void clear() {
    shapes_.clear();
  }

  /**
   * @brief Добавить фигуру в составную.
   * @param shape - фигура.
   */
  void push(std::unique_ptr<IShape>&& shape) {
    shapes_.emplace_back(std::move(shape));
  }

  /**
   * @brief Переложить фигуры из другой составной фигуры.
   * @param other - другой составной объект.
   */
  void push_from(CompoundShape& other) {
    for(auto&& it: other.shapes_)
      shapes_.emplace_back(std::move(it));
    other.shapes_.clear();
  }

  /**
   * @brief Переложить фигуры из другой составной фигуры если выполняется предикат для точек фигуры.
   * @tparam Pred - тип предиката.
   * @param other - другой составной объект.
   * @param pred - предикат.
   */
  template<typename Pred>
  void push_from_if(CompoundShape& other, Pred pred) {
    for(auto it = other.shapes_.begin(); it != other.shapes_.end();) {
      if(pred((*it)->get_coords_chain())) {
        shapes_.emplace_back(std::move(*it));
        it = other.shapes_.erase(it);
      }
      else
        ++it;
    }
  }


  /**
   * @brief Дать тип фигуры.
   * @return тип фигуры.
   */
  ShapeType get_type() const override {
    return COMPOUND;
  }

  /**
   * @brief Дать цвет фигуры.
   * @return цвет фигуры.
   */
  Color get_color() const override {
    return WHITE;
  }

  /**
   * @brief Дать цвет фигуры.
   * @return цвет фигуры.
   */
  void set_color(Color color) override {
    for(auto& it: shapes_)
      it->set_color(color);
  }

  /**
   * @brief Переместить фигуру.
   * @param offset - смещение, на которое необходимо сдвинуть фигуру.
   */
  void move(const Coords& offset) override {
    for(auto& it: shapes_)
      it->move(offset);
  }

  /**
   * @brief Перерисовать фигуру в представлении.
   */
  void redraw(GraphicView& view) override {
    for(auto& it: shapes_)
      it->redraw(view);
  }

  /**
   * @brief Пометить фигуру как выделенную.
   * @param is_selected - фигура выделена или нет.
   */
  void mark_as_selected(bool is_selected) override {
    for(auto& it: shapes_)
      it->mark_as_selected(is_selected);
  }

  /**
   * @brief Дать координаты точек фигуры.
   * @return координаты точки фигуры.
   */
  virtual CoordsChain get_coords_chain() const override {
    return CoordsChain{};
  }

  /**
   * @brief Содержатся-ли в составной фигуре другие фигуры.
   * @return true - фигуры содержатся, false - фигуры не содержатся.
   */
  bool is_empty() {
    return shapes_.empty();
  }

private:
  /// Список фигур входящих в составную.
  std::list<std::unique_ptr<IShape>> shapes_;
};

} // namespace graphics.
