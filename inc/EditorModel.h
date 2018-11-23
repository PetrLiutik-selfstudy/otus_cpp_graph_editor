#pragma once

#include "IView.h"
#include "IShape.h"
#include "CompoundShape.h"


////#include "GraphicView.h"
//#include "ShapeFactory.h"
//#include "IImporter.h"
//#include "IExporter.h"

#include <string>
#include <list>
#include <memory>
#include <vector>



namespace graphics {

/**
 * @brief Класс модели графического редактора.
 */
class EditorModel {
public:
  explicit EditorModel() = default;
  ~EditorModel() = default;




  // data management, access and validation

  // number
  static constexpr int min_n = 0 ;
  static constexpr int max_n = 6 ;

  int number() const { return number_ ; }
  void number( int n ) { if( valid_number(n) ) number_ = n ; }
  void increment() { if( number_ < max_n ) { ++number_ ; update_views() ; } }
  void decrement() { if( number_ > min_n ) { --number_ ; update_views() ; } }
  static bool valid_number( int number ) { return number >= min_n && number <= max_n ; }

  // ...

  // TODO: persistence support
  std::istream& read( std::istream& stm ) ;
  std::ostream& write( std::istream& stm ) ;

  // associated views
  void add_view(view_t&& view) {
    views_.push_back(std::move(view));
    views_.back()->render();
  }

  const std::vector<view_t>& associated_views() const { return views_ ; }





  /**
   * @brief Выбор цвета рисования фигур.
   * @param color - цвет.
   */
  void choose_color(Color color) {
    color_ = color;
  }

  /**
   * @brief Выделить фигуру.
   * @param p - координата точки принадлежащей выделяемой фигуре.
   * @return true - фигура была выделена, false - нет выделенных фигур.
   */
  bool select_shape(const Coords& p) {
    shapes_.push_from(selected_);
    selected_.push_from_if(shapes_, [&p](const CoordsChain& points) {
      for(const auto& it: points)
        if(it == p)
          return true;
      return false;
    });

    if(!selected_.is_empty()) {
      selected_.mark_as_selected(true);
      update_views();
      return true;
    }
    return false;
  }

  /**
   * @brief Выделить фигуру(ы) в пределах указанного прямоугольника.
   * @param p1 - координаты нижней левой точки прямоугольника.
   * @param p2 - координаты верхней правой точки прямоугольника.
   * @return true - фигура была выделена, false - нет выделенных фигур.
   */
  bool select_shape(const Coords& p1, const Coords& p2) {
    shapes_.push_from(selected_);
    selected_.push_from_if(shapes_, [&p1, &p2](const CoordsChain& points) {
      for(const auto& it: points)
        if(it.belongs_to_rect(p1, p2))
          return true;
      return false;
    });

    if(!selected_.is_empty()) {
      selected_.mark_as_selected(true);
      update_views();
      return true;
    }
    return false;
  }

  /**
   * @brief Отменить выделение фигуры.
   */
  void deselect_shape() {
    selected_.mark_as_selected(false);
    shapes_.push_from(selected_);
    update_views();
  }

  /**
   * @brief Изменить цвет выделенной фигуры.
   * @param color - цвет.
   */
  void change_shape_color(Color color) {
    selected_.set_color(color);
    update_views();
  }

  /**
   * @brief Передвинуть выделенную фигуру(ы).
   * @param offset - смещение.
   */
  void move_shape(const Coords& offset) {
    selected_.move(offset);
    update_views();
  }

  /**
   * @brief Удалить выбраную фигуру(ы).
   */
  void remove_shape() {
    selected_.clear();
    update_views();
  }



private:
  /**
   * @brief Обновление графических представлений.
   */
  void update_views() {
    for(auto& view: views_)
      view->render();
  }

  int number_ = ( min_n + max_n ) / 2 ;

  /// Cоставной объект, содержащий все фигуры.
  CompoundShape shapes_{};

  /// Составной объект, содержащий выделенные фигуры.
  CompoundShape selected_{};

  /// Графическое представление.
  std::vector<view_t> views_;

  /// Цвет отрисовки фигур.
  Color color_{BLACK};
};


///**
// * @brief Класс модели графического редактора.
// */
//class EditorModel {
//public:
//  explicit EditorModel() = default;
//  ~EditorModel() = default;


//  /**
//   * @brief Создать номый документ.
//   */
//  void create_new_document() {
//    shapes_.clear();
//    selected_.clear();
//    view_.clear();
//  }

//  /**
//   * @brief Очистить документ.
//   */
//  void clear_document() {
//    shapes_.clear();
//    selected_.clear();
//    view_.clear();
//  }

//  /**
//   * @brief Загрузить документ из файла.
//   * @param importer - импортер документа.
//   * @param filename - имя файла.
//   */
//  void load_document(std::shared_ptr<IImporter> importer, const std::string& filename) {
//    clear_document();
//    importer->load(filename, shapes_);
//    update_views();
//  }

//  /**
//   * @brief Сохранить документ в файл.
//   * @param exporter - экспортер документа.
//   * @param filename - имя файла.
//   */
//  void save_document(std::shared_ptr<IExporter> exporter, const std::string& filename) {
//    exporter->save(filename, shapes_);
//  }

//  /**
//   * @brief Создание новой фигуры.
//   * @param type - тип фигуры.
//   * @param points - координаты точек, необходимых для построения фигуры.
//   */
//  void create_shape(ShapeType type, const CoordsChain& points) {
//    selected_.mark_as_selected(false);
//    shapes_.push_from(selected_);
//    auto shape = shape_factory_.create_shape(type, color_, points);
//    shapes_.push(std::move(shape));
//    update_views();
//  }

//  /**
//   * @brief Выбор цвета рисования фигур.
//   * @param color - цвет.
//   */
//  void choose_color(Color color) {
//    color_ = color;
//  }

//  /**
//   * @brief Выделить фигуру.
//   * @param p - координата точки принадлежащей выделяемой фигуре.
//   * @return true - фигура была выделена, false - нет выделенных фигур.
//   */
//  bool select_shape(const Coords& p) {
//    shapes_.push_from(selected_);
//    selected_.push_from_if(shapes_, [&p](const CoordsChain& points) {
//      for(const auto& it: points)
//        if(it == p)
//          return true;
//      return false;
//    });

//    if(!selected_.is_empty()) {
//      selected_.mark_as_selected(true);
//      update_views();
//      return true;
//    }
//    return false;
//  }

//  /**
//   * @brief Выделить фигуру(ы) в пределах указанного прямоугольника.
//   * @param p1 - координаты нижней левой точки прямоугольника.
//   * @param p2 - координаты верхней правой точки прямоугольника.
//   * @return true - фигура была выделена, false - нет выделенных фигур.
//   */
//  bool select_shape(const Coords& p1, const Coords& p2) {
//    shapes_.push_from(selected_);
//    selected_.push_from_if(shapes_, [&p1, &p2](const CoordsChain& points) {
//      for(const auto& it: points)
//        if(it.belongs_to_rect(p1, p2))
//          return true;
//      return false;
//    });

//    if(!selected_.is_empty()) {
//      selected_.mark_as_selected(true);
//      update_views();
//      return true;
//    }
//    return false;
//  }

//  /**
//   * @brief Отменить выделение фигуры.
//   */
//  void deselect_shape() {
//    selected_.mark_as_selected(false);
//    shapes_.push_from(selected_);
//    update_views();
//  }

//  /**
//   * @brief Изменить цвет выделенной фигуры.
//   * @param color - цвет.
//   */
//  void change_shape_color(Color color) {
//    selected_.set_color(color);
//    update_views();
//  }

//  /**
//   * @brief Передвинуть выделенную фигуру(ы).
//   * @param offset - смещение.
//   */
//  void move_shape(const Coords& offset) {
//    selected_.move(offset);
//    update_views();
//  }

//  /**
//   * @brief Удалить выбраную фигуру(ы).
//   */
//  void remove_shape() {
//    selected_.clear();
//    update_views();
//  }

//private:

//  /// Перерисовка представления.
//  void update_views() {
//    view_.clear();
//    shapes_.update_views(view_);
//    selected_.update_views(view_);
//    view_.refresh();
//  }


//  /// Документ - составной объект, содержащий все фигуры.
//  CompoundShape shapes_{};

//  /// Составной объект содержащий выделенные фигуры.
//  CompoundShape selected_{};

//  /// Графическое представление.
//  GraphicView view_{};

//  /// Цвет отрисовки фигур.
//  Color color_{BLACK};

//  /// Фабрика фигур.
//  ShapeFactory shape_factory_{};
//};

} // namespace graphics.
