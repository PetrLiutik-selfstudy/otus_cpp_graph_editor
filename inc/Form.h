#pragma once

#include "Coords.h"

#include <functional>
#include <iostream>
#include <string>
#include <vector>

namespace graphics {

/**
 * @brief Элемент формы.
 */
class FormItem {
public:
  /**
   * @brief Конструктор элемента формы.
   * @param p1 - координата нижнего левого угла.
   * @param p2 - координата нижнего правого угла.
   * @param on_event - фукция обратного вызова при событии над элементом формы.
   */
  explicit FormItem(const Coords& p1, const Coords& p2, std::function<void()> on_event) :
    p1_{p1}, p2_{p2}, on_event_{on_event} {
  }

  virtual ~FormItem() = default;

  /**
   * @brief Перерисовка элемента формы.
   */
  virtual void redraw() {
  }

private:
  /// Координаты нижнего левого и правого верхнего угла элемента.
  Coords p1_;
  Coords p2_;

  /// Обратный вызова при событии над элементом формы.
  std::function<void()> on_event_;
};

/// Тип набора элементов формы.
using form_items_t = std::vector<FormItem>;

/**
* @brief Элемент формы - кнопка.
*/
class Button : public FormItem {
public:
  /**
   * @brief Конструктор кнопки.
   * @param name - название кнопки.
   * @param p1 - координата нижнего левого угла.
   * @param p2 - координата нижнего правого угла.
   * @param on_event - фукция обратного вызова при событии над элементом формы.
   */
  explicit Button(const std::string& name, const Coords& p1, const Coords& p2, std::function<void()> on_event) :
    FormItem{p1, p2, on_event}, name_{name} {
  }

private:
  /// Название кнопки.
  std::string name_;
};


/**
* @brief Элемент формы - канва для рисования.
*/
class Canvas : public FormItem {
public:
  /**
   * @brief Конструктор канвы.
   * @param p1 - координата нижнего левого угла.
   * @param p2 - координата нижнего правого угла.
   * @param on_event - фукция обратного вызова при событии над элементом формы.
   */
  explicit Canvas(const Coords& p1, const Coords& p2, std::function<void()> on_event) : FormItem{p1, p2, on_event} {
  }
};


/**
 * @brief Класс формы.
 */
class Form  {
public:
  /**
   * @brief Конструтор формы.
   * @param items - элементы формы.
   */
  explicit Form(const form_items_t& items) : form_items_{items} {
  }
  virtual ~Form() = default;

  /**
   * @brief Перерисовка формы.
   */
  void redraw() {
    for(auto& it: form_items_)
      it.redraw();
  }

private:
  /// Элементы формы.
  form_items_t form_items_;
};

} // namespace graphics.
