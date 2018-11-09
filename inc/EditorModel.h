#pragma once

#include "IShape.h"
#include "CompoundShape.h"

#include <ostream>
#include <string>
#include <map>
#include <thread>

namespace graphics {

class ImageModel {
  public:
    explicit ImageModel() {
    }
    ~ImageModel() = default;


  private:


    /// Составной объект содержащий все фигуры изображения.
    CompoundShape image_;

    /// Составной объект содержащий выделенные фигуры.
    CompoundShape selected_;
};

} // namespace graphics.
