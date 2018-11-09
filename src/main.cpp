#include <iostream>

#include "ver.h"

#include <iostream>

int main()
{
  std::cout << "graph_editor version: "
            << ver_major() << "."
            << ver_minor() << "."
            << ver_patch() << std::endl;



  return 0;
}
