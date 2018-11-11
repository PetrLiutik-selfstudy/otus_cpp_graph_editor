#pragma once

#include "CompoundShape.h"

#include <string>

namespace graphics {

/**
 * @brief Интерфейс экспортера изображения в файл.
 */
class IExporter {
public:
  virtual ~IExporter() = default;

  /**
   * @brief Экспортировать изображение в файл.
   * @param filename - имя файла.
   * @param image - изображение.
   */
  virtual bool save(std::string filename, const CompoundShape& image) = 0;
};

} // namespace graphics.
