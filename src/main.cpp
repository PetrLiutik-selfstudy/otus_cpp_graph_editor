#include "EditorController.h"
#include "ver.h"

#include <iostream>

int main()
{
  std::cout << "graph_editor version: "
            << ver_major() << "."
            << ver_minor() << "."
            << ver_patch() << std::endl;

  graphics::EditorController editor;

  // Создание нового рисунка.
  std::cout << "Create new image:" << std::endl;
  editor.create_new_image();

  // Добавление отрезка и ломаной.
  std::cout << "\nAdd red line and blue polyline:";
  editor.choose_color(graphics::RED);
  editor.add_line({1, 2}, {7, 8});
  editor.choose_color(graphics::BLUE);
  editor.add_polyline({{3, 3}, {7, 7}, {1, 9}});

  // Выделение отрезка и ломаной, их перемещение и смена цвета.
  editor.select_shape({0, 0}, {18, 18});
  editor.change_shape_color(graphics::GREEN);
  editor.move_shape({-5, 5});
  editor.deselect_shape();

  // Добавление окружности.
  editor.choose_color(graphics::RED);
  editor.add_circle({0, 0}, {0, 10});

  // Выделение окружности, и ее удаление.
  editor.select_shape({0, 10});
  editor.remove_shape();

  // Сохранение в файл.
  editor.save_image_as_svg("image.svg");

  // Загрузка из файла.
  editor.load_image_as_svg("image.svg");

  return 0;
}
