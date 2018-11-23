#pragma once

#include "IShape.h"

#include <string>
#include <iostream>
#include "EditorModel.h"
#include "EditorController.h"
#include "Form.h"
#include "IView.h"

namespace graphics {

/**
 * @brief Класс представления графического редактора.
 */
class GraphicView : private Form, public IView {
public:
  GraphicView(EditorModel& model, EditorController& controller, const form_items_t& form_items) :
    Form{form_items}, model_{model}, controller_{controller}  {
  }

  /**
   * @brief Перерисовка представления.
   */
  void render() const override {
    std::cout << "view: " << model_.number() << '\n';
  }

  void say_hello(const std::string& str) const override {
    std::cout << "view: '" << str << "' says hello\n";
  }

protected:
  /// Модель.
  EditorModel& model_;
  /// Контроллер.
  EditorController& controller_;
};




//struct view_base // polymorphic class (object oriented)
//{
//    using pointer = std::unique_ptr<view_base> ;

//    virtual ~view_base() = default ;
//    virtual void render() const = 0 ;
//    virtual void say_hello( std::string source ) const = 0 ; // only for exposition
//};

//struct view : view_base
//{
//  view( model& m, controller& c ) : model_(m), controller_(c)  {}

//  // retrieve the information from the model and display it
//  virtual void render() const override { std::cout << "view: " << model_.number() << '\n' ; }

//  virtual void say_hello( std::string source ) const override
//  { std::cout << "view: '" << source << "' says hello\n" ; }


//  protected:
//      model& model_ ; // and to the model

//      controller& controller_ ; // optional: the view holds a reference to its controller
//      // this is required if the view directly accepts user input requesting a change
//      // in the data and it needs to forward the request to the associated controller
//};





///**
// * @brief Класс представления графического редактора.
// */
//class GraphicView {
//public:
//  explicit GraphicView(EditorModel& model) : model_(model) {
//  }

//  ~GraphicView() = default;

//  void render() {
//    std::cout << "Model Data = " /*<< model_.data()*/ << std::endl;
//  }

//  /**
//   * @brief Очистка графического представления.
//   */
//  void clear() {
//    std::cout << "\nView has been cleared\n";
//    screen_.clear();
//  }

//  /**
//   * @brief Рисование фигуры.
//   * @param type - тип фигуры.
//   * @param color - цвет.
//   * @param points - ткоординаты точек фигуры.
//   * @param is_selected - фигура выделена.
//   */
//  void draw(ShapeType type, Color color, const CoordsChain& points, bool is_selected) {
//    std::string str{"Shape: "};

//    if(is_selected)
//      str += "selected ";

//    if(WHITE == color)
//      str += "white ";
//    else if(RED == color)
//      str += "red ";
//    else if(GREEN == color)
//      str += "green ";
//    else if(BLUE == color)
//      str += "blue ";
//    else if(BLACK == color)
//      str += "black ";

//    if(LINE == type)
//      str += "line ";
//    else if(POLYLINE == type)
//      str += "polyline ";
//    else if(RECTANGLE == type)
//      str += "rectangle ";
//    else if(CIRCLE == type)
//      str += "circle ";

//    for(const auto& it: points) {
//      str += "{";
//      str += std::to_string(it.get_x_coord());
//      str += ",";
//      str += std::to_string(it.get_y_coord());
//      str += "}";
//      str += " ";
//    }
//    str += "\n";

//    screen_.emplace_back(str);
//  }

//  /**
//   * @brief Обновление графического представления.
//   */
//  void refresh() {
//    for(auto it: screen_) {
//      std::cout << it;
//    }
//  }

//private:

//  EditorModel& model_;

//  std::vector<std::string> screen_{};
//};

} // namespace graphics.
