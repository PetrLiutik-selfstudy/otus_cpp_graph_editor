#pragma once

#include "Document.h"
#include "EditorModel.h"
#include "Form.h"
#include "SvgExporter.h"
#include "SvgImporter.h"

#include <memory>
#include <string>

namespace graphics {

/**
 * @brief Класс контроллера редактора.
 */
class EditorController {
public:
  explicit EditorController() = default;
  ~EditorController() = default;

  /**
   * @brief Создание представления графического редактора.
   * @tparam T - тип представления.
   * @tparam Args - тип аргументов используемых при создании представления.
   * @param args - аргументы используемые при создании представления.
   */
  template<typename T, typename... Args>
  void create_view(Args&&... args) {
    model_.add_view(std::make_unique<T>(model_, *this, std::forward<Args>(args)...));
  }

  /**
   * @brief Обработка пользовательского события "выбран отрезок".
   */
  void on_choose_line() {
    shape_type_ = LINE;
  }

  /**
   * @brief Обработка пользовательского события "выбрана ломаная".
   */
  void on_choose_poly() {
    shape_type_ = POLYLINE;
  }

  /**
   * @brief Обработка пользовательского события "выбран прямоугольник".
   */
  void on_choose_rect() {
    shape_type_ = RECTANGLE;
  }

  /**
   * @brief Обработка пользовательского события "выбран прямоугольник".
   */
  void on_choose_circle() {
    shape_type_ = CIRCLE;
  }

  /**
   * @brief Обработка пользовательского события "выбран красный цвет из палитры".
   */
  void on_choose_red() {
    shape_color_ = RED;
  }

  /**
   * @brief Обработка пользовательского события "выбран зеленый цвет из палитры".
   */
  void on_choose_green() {
    shape_color_ = GREEN;
  }

  /**
   * @brief Обработка пользовательского события "выбран синий цвет из палитры".
   */
  void on_choose_blue() {
    shape_color_ = BLUE;
  }

  /**
   * @brief Обработка пользовательского события "нарисовать фигуру".
   */
  void on_draw_shape() {
    model_.create_shape(shape_type_, shape_color_, shape_points_);
  }

  /**
   * @brief Обработка пользовательского события "добавить/выбрать точку фигуры".
   */
  void on_put_point() {
    if(!is_selecting_)
      shape_points_.push_back(Coords{});
    else
      model_.select_shape(Coords{});
  }

  /**
   * @brief Обработка пользовательского события "выбрать фигуру".
   */
  void on_select_shape() {
    is_selecting_ = true;
  }

  /**
   * @brief Создать номый документ.
   */
  void on_create_new_document() {
    doc_.clear();
  }

  /**
   * @brief Очистить документ.
   */
  void on_clear_document() {
    doc_.clear();
  }

  /**
   * @brief Загрузить документ из файла.
   */
  void on_load_svg_document() {
    importer_->load(filename_, doc_);
    model_.add_shapes(doc_.get_data());
  }

  /**
   * @brief Сохранить документ в файл.
   */
  void on_save_svg_document() {
    doc_.set_data(model_.get_shapes());
    exporter_->save(filename_, doc_);
  }

  /**
   * @brief Основной рабочий процесс.
   */
  void start() {
  }


private:
  /// Тип рисуемой фигуры.
  ShapeType shape_type_{LINE};
  /// Цвет рисуемой фигуры.
  Color shape_color_{RED};
  /// Координаты точек рисуемой фигуры.
  CoordsChain shape_points_;
  /// Режим выбора фигур.
  bool is_selecting_{};
  /// Модель графического редактора.
  EditorModel model_{};
  /// Документ.
  Document doc_{};
  /// Имя файла.
  std::string filename_{};
  /// Импортер документа.
  std::unique_ptr<IImporter> importer_{};
  /// Экспортер документа.
  std::unique_ptr<IExporter> exporter_{};
};

} // namespace graphics.
