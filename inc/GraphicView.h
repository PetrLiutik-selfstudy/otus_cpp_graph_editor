#pragma once

#include "IShape.h"

#include <string>
#include <iostream>
#include "EditorModel.h"
#include "EditorController.h"
#include "Form.h"
#include "IView.h"

namespace graphics {

/**
 * @brief Класс представления графического редактора.
 */
class GraphicView : public Form, public IView {
public:
  GraphicView(EditorModel& model, EditorController& controller, const form_items_t& form_items) :
    Form{form_items}, model_{model}, controller_{controller}  {
  }

  /**
   * @brief Перерисовка представления.
   */
  void render() override {
    // Загрузка данных для перерисовки фигур из модели.
    //...
    // Перерисовка элементов формы.
    redraw();
  }

protected:
  /// Модель.
  EditorModel& model_;
  /// Контроллер.
  EditorController& controller_;
};

} // namespace graphics.
