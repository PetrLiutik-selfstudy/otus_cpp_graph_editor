#pragma once

#include "IImporter.h"

#include <iostream>

namespace graphics {

/**
 * @brief Ипортераизображения из файла в формате SVG.
 */
class SvgImporter : public IImporter {
public:
  explicit SvgImporter() = default;
  ~SvgImporter() override = default;

  /**
   * @brief Импортировать изображение из файла.
   * @param filename - имя файла.
   * @param image - изображение.
   */
  bool load(std::string filename, CompoundShape& image) override {
    std::cout << "Load image from " << filename << std::endl;
    return true;
  }
};

} // namespace graphics.
