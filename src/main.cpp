#include "Application.h"
#include "ver.h"

#include <iostream>

int main()
{
  std::cout << "graph_editor version: "
            << ver_major() << "."
            << ver_minor() << "."
            << ver_patch() << std::endl;

//  graphics::EditorController editor;

//  // Создание нового рисунка.
//  editor.create_new_document();

//  // Добавление отрезка и ломаной.
//  editor.choose_color(graphics::RED);
//  editor.add_line({1, 2}, {7, 8});
//  editor.choose_color(graphics::BLUE);
//  editor.add_polyline({{3, 3}, {7, 7}, {1, 9}});

//  // Выделение отрезка и ломаной, их перемещение и смена цвета.
//  editor.select_shape({0, 0}, {18, 18});
//  editor.change_shape_color(graphics::GREEN);
//  editor.move_shape({-5, 5});
//  editor.deselect_shape();

//  // Добавление окружности.
//  editor.choose_color(graphics::RED);
//  editor.add_circle({0, 0}, {0, 10});

//  // Выделение окружности, и ее удаление.
//  editor.select_shape({0, 10});
//  editor.remove_shape();

//  // Сохранение в файл.
//  editor.save_document_as_svg("document.svg");

//  // Загрузка из файла.
//  editor.load_document_as_svg("document.svg");

//  class text_view : public graphics::GraphicView
//  {
//    public:
//      using GraphicView::GraphicView ;
//      text_view( graphics::EditorModel& m, graphics::EditorController& c, std::string id ) : GraphicView(m,c), id(id) {}

//      virtual void render() const override
//      {
//          static const char* const text[] = { "zero", "one", "two", "three", "four", "five", "six" } ;
//          static constexpr int MAXN = sizeof(text) / sizeof( text[0] ) - 1 ;
//          static_assert( graphics::EditorModel::min_n == 0 && graphics::EditorModel::max_n == MAXN, "stale code: model has changed" ) ;

//          std::cout << "text_view (" << id << "): '" << text[ model_.number() ] << "'\n\n" ;
//      }

//      virtual void say_hello(const std::string& source ) const override
//      { std::cout << "text_view (" << id << "): '" << source << "' says hello\n" ; }

//      const std::string id = "noname" ;
//  };

//  graphics::EditorController controller;
//  controller.create_view<graphics::GraphicView>();
////  controller.create_view<text_view>("daffy") ;

//  for(char c : { '+', '+', '+', '?', '+', '-', '$', '-' })
//    controller.handle_input(c) ;

//  controller.say_hello_to_all() ;


  graphics::EditorApp editor_app;
  editor_app.run();

  return 0;
}
