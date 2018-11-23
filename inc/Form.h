#pragma once

#include "Coords.h"

#include <functional>
#include <iostream>
#include <map>
#include <string>

namespace graphics {

/// Элемент формы.
class FormItem {
public:
  explicit FormItem(const Coords& p1, const Coords& p2) : p1_{p1}, p2_{p2}{
  }
  virtual ~FormItem() = default;

  virtual void redraw() {}


  bool operator < (const FormItem&) const {
    return false;
  }

private:
  /// Координаты нижнего левого угла элемента.
  Coords p1_;
  /// Координаты правого верхнего угла элемента.
  Coords p2_;
};

/// Элемент формы - кнопка.
class Button : public FormItem {
public:
  explicit Button(const std::string& name, const Coords& p1, const Coords& p2) :
    FormItem{p1, p2}, name_{name} {
  }

  Button(Button&&) = default;
  ~Button() = default;

  void redraw() {
    std::cout << "Button" << name_ << std::endl;
  }

private:
  /// Название кнопки.
  std::string name_;
};

/// Элемент формы - канва для рисования.
class Canvas : public FormItem {
};

/// Событие возникающее при воздействии на элемент формы.
class Event {
};

/// Тип набора элементов формы.
using form_items_t = std::map<FormItem, std::function<void(const Event& event)>>;


/**
 * @brief Класс формы.
 */
class Form  {
public:
  explicit Form(const form_items_t& items) : form_items_{items} {
  }

  virtual ~Form() = default;

private:

  /// Методы вызываемые по событиям от мыши.
  void on_mouse_left_click(const Coords&) {
  }

  void on_mouse_right_click(const Coords&) {
  }

  form_items_t form_items_;
};

} // namespace graphics.
