#pragma once

#include "GraphicView.h"
#include "IExporter.h"
#include "IImporter.h"
#include "IView.h"

#include <memory>
#include <string>

namespace graphics {

/**
 * @brief Класс приложения графического редактора.
 */
class Application {
public:
  /**
   * @brief Конструктор.
   */
  explicit Application() {
    auto form_items = configure_form();
    controller_.create_view<graphics::GraphicView>(form_items);
  }

  ~Application() = default;

  /**
   * @brief Основной рабочий процесс приложения.
   */
  void start() {
    controller_.start();
  }

private:

  /**
   * @brief Конфигурирование основной формы редактора (представления).
   * @return - элементы формы.
   */
  form_items_t configure_form() {
    form_items_t form_items;

    form_items.emplace_back(Canvas{Coords{80, 80}, Coords{880, 680}, std::bind(&EditorController::on_put_point, &controller_)});

    form_items.emplace_back(Button{"New document",   Coords{100, 40}, Coords{120, 60}, std::bind(&EditorController::on_create_new_document, &controller_)});
    form_items.emplace_back(Button{"Clear document", Coords{130, 40}, Coords{150, 60}, std::bind(&EditorController::on_clear_document, &controller_)});
    form_items.emplace_back(Button{"Load document",  Coords{160, 40}, Coords{180, 60}, std::bind(&EditorController::on_load_svg_document, &controller_)});
    form_items.emplace_back(Button{"Save document",  Coords{190, 40}, Coords{210, 60}, std::bind(&EditorController::on_save_svg_document, &controller_)});

    form_items.emplace_back(Button{"Red",            Coords{200, 40}, Coords{220, 60}, std::bind(&EditorController::on_choose_red, &controller_)});
    form_items.emplace_back(Button{"Green",          Coords{220, 40}, Coords{240, 60}, std::bind(&EditorController::on_choose_green, &controller_)});
    form_items.emplace_back(Button{"Blue",           Coords{260, 40}, Coords{280, 60}, std::bind(&EditorController::on_choose_blue, &controller_)});

    form_items.emplace_back(Button{"Line",           Coords{300, 40}, Coords{320, 60}, std::bind(&EditorController::on_choose_line, &controller_)});
    form_items.emplace_back(Button{"Polyline",       Coords{330, 40}, Coords{350, 60}, std::bind(&EditorController::on_choose_poly, &controller_)});
    form_items.emplace_back(Button{"Rectangle",      Coords{360, 40}, Coords{380, 60}, std::bind(&EditorController::on_choose_rect, &controller_)});
    form_items.emplace_back(Button{"Circle",         Coords{390, 40}, Coords{410, 60}, std::bind(&EditorController::on_choose_circle, &controller_)});

    form_items.emplace_back(Button{"Select shape",   Coords{420, 40}, Coords{430, 60}, std::bind(&EditorController::on_select_shape, &controller_)});

    return form_items;
  }

  /// Контроллер графического редактора.
  graphics::EditorController controller_;
};

} // namespace graphics.
