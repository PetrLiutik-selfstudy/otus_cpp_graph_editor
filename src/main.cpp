#include "Application.h"
#include "ver.h"


#include <iostream>

int main()
{
  std::cout << "graph_editor version: "
            << ver_major() << "."
            << ver_minor() << "."
            << ver_patch() << std::endl;

  // Создание и запуск приложения графического редактора.
  graphics::Application editor_app;
  editor_app.start();

  return 0;
}
