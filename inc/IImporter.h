#pragma once

#include "CompoundShape.h"

#include <string>

namespace graphics {

/**
 * @brief Интерфейс ипортера изображения из файла.
 */
class IImporter {
public:
  virtual ~IImporter() = default;

  /**
   * @brief Импортировать изображение из файла.
   * @param filename - имя файла.
   * @param image - изображение.
   */
  virtual bool load(std::string filename, CompoundShape& image) = 0;
};

} // namespace graphics.
