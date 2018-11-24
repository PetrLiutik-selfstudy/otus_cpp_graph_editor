#pragma once

#include <CompoundShape.h>

namespace graphics {

/**
 * @brief Класс документа.
 */
class Document {
public:
  explicit Document() = default;
  Document(const Document&) = default;
  ~Document() = default;

  /**
   * @brief Очистка документа.
   */
  void clear() {
    shapes_.clear();
  }

  CompoundShape& get_data() {
    return shapes_;
  }

  void set_data(CompoundShape& shapes) {
  }

private:
  /// Фигуры входящие в документ.
  CompoundShape shapes_;
};

} // namespace graphics.
