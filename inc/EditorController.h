#pragma once

#include "IShape.h"
#include "EditorModel.h"
#include "ShapeFactory.h"

//#include "SvgExporter.h"
//#include "SvgImporter.h"

#include <memory>
#include <string>

namespace graphics {

/**
 * @brief Класс контроллера редактора.
 */
class EditorController {
public:
  explicit EditorController() = default;
  ~EditorController() = default;

  /**
   * @brief Создание отображения графического редактора.
   * @tparam T - тип отображения.
   * @tparam Args - тип аргументов используемых при создании отображения.
   * @param args - аргументы используемые при создании отображения.
   */
  template<typename T, typename... Args>
  void create_view(Args&&... args) {
    model_.add_view(std::make_unique<T>(model_, *this, std::forward<Args>(args)...));
  }


  void handle_input(char input) {
    if(input == '+')
      model_.increment() ;
    else if(input == '-')
      model_.decrement() ;
  }



  // note: model_.associated_views() gives (non-mutable) access to the associated views:
  // for instance:
  void say_hello_to_all() const {
    for(const auto& view : model_.associated_views())
      view->say_hello("controller");
  }


  /**
   * @brief Создание новой фигуры.
   * @param type - тип фигуры.
   * @param points - координаты точек, необходимых для построения фигуры.
   */
  void create_shape(ShapeType type, const CoordsChain& points) {
    selected_.mark_as_selected(false);
    document_.push_from(selected_);
    auto shape = shape_factory_.create_shape(type, color_, points);
    document_.push(std::move(shape));
    update_views();
  }

private:
  /// Модель графического редактора.
  EditorModel model_;

  /// Фабрика фигур.
  ShapeFactory shape_factory_{};
};


///**
// * @brief Класс контроллера редактора.
// */
//class EditorController {
//  public:
//    explicit EditorController(EditorModel& model, GraphicView& view) {
//    }
//    ~EditorController() = default;

//    /**
//     * @brief Создать новый документ.
//     */
//    void create_new_document() {
//      model_.create_new_document();
//    }

//    /**
//     * @brief Очистить документ.
//     */
//    void clear_document() {
//      model_.clear_document();
//    }

//    /**
//     * @brief Сохранение документа в файл в формате SVG.
//     * @param filename - имя файла.
//     */
//    void save_svg_document(const std::string& filename) {
//      model_.save_document(std::make_shared<SvgExporter>(), filename);
//    }

//    /**
//     * @brief Загрузка документа из файла
//     * @param filename - имя файла.
//     */
//    void load_svg_document(const std::string& filename) {
//      model_.load_document(std::make_shared<SvgImporter>(), filename);
//    }

//    /**
//     * @brief Выбор цвета рисования фигур.
//     * @param color - цвет.
//     */
//    void choose_color(Color color) {
//      model_.choose_color(color);
//    }

//    /**
//     * @brief Нарисовать отрезок.
//     * @param p1 - координата начала отрезка.
//     * @param p2 - координата конца отрезка.
//     */
//    void add_line(const Coords& p1, const Coords& p2) {
//      model_.create_shape(LINE, {p1, p2});
//    }

//    /**
//     * @brief Нарисовать ломаную линию.
//     * @param points - точки ломанной линии.
//     */
//    void add_polyline(const CoordsChain& points) {
//      model_.create_shape(POLYLINE, points);
//    }

//    /**
//     * @brief Нарисовать прямоугольник.
//     * @param p1 - координата нижней левой точки прямоугольника.
//     * @param p2 - координата верхней правой точки прямоугольника.
//     */
//    void add_rectangle(const Coords& p1, const Coords& p2) {

//    }

//    /**
//     * @brief Нарисовать окружность.
//     * @param c - координаты центра окружности.
//     * @param r - точка лежащая на окружности (для задания радиуса).
//     */
//    void add_circle(const Coords& c, const Coords& r) {
//      model_.create_shape(CIRCLE, {c, r});
//    }

//    /**
//     * @brief Выделить фигуру.
//     * @param p - координата точки принадлежащей выделяемой фигуре.
//     */
//    bool select_shape(const Coords& p) {
//      return model_.select_shape(p);
//    }

//    /**
//     * @brief Выделить фигуру(ы) в пределах указанного прямоугольника.
//     * @param p1 - координата нижней левой точки прямоугольника.
//     * @param p2 - координата верхней правой точки прямоугольника.
//     */
//    bool select_shape(const Coords& p1, const Coords& p2) {
//      return model_.select_shape(p1, p2);
//    }

//    /**
//     * @brief Отменить выделение фигуры.
//     */
//    void deselect_shape() {
//      model_.deselect_shape();
//    }

//    /**
//     * @brief Изменить цвет выделенной фигуры.
//     * @param offset - смещение.
//     */
//    void change_shape_color(Color color) {
//      model_.change_shape_color(color);
//    }

//    /**
//     * @brief Передвинуть выделенную фигуру(ы).
//     * @param offset - смещение.
//     */
//    void move_shape(const Coords& offset) {
//      model_.move_shape(offset);
//    }

//    /**
//     * @brief Удалить выбраную фигуру(ы).
//     */
//    void remove_shape() {
//      model_.remove_shape();
//    }

//  private:

//    EditorModel model_;

//};

} // namespace graphics.
