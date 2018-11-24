#pragma once

#include "IExporter.h"

#include <iostream>

namespace graphics {

/**
 * @brief Экспортер изображения в файл формата SVG.
 */
class SvgExporter : public IExporter {
public:
  explicit SvgExporter() = default;
  ~SvgExporter() override = default;

  /**
   * @brief Экспортировать изображение в файл.
   * @param filename - имя файла.
   * @param image - изображение.
   */
  bool save(std::string filename, const Document& image) override {
    std::cout << "Save image to " << filename << std::endl;
    return true;
  }
};

} // namespace graphics.
