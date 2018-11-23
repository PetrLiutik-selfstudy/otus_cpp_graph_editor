#pragma once

#include "Application.h"
#include "GraphicView.h"
#include "IExporter.h"
#include "IImporter.h"
#include "IView.h"

#include <memory>
#include <string>

namespace graphics {

void on_event(const Event&) {

}

/**
 * @brief Класс редактора.
 */
class EditorApp {
public:
  explicit EditorApp() {

    form_items_t form_items;
    form_items.emplace(Button{"New document", Coords{100, 100}, Coords{120, 120}}, std::bind(&EditorApp::create_new_document, this));
    form_items.emplace(Button{"Clear document", Coords{130, 100}, Coords{150, 120}}, std::bind(&EditorApp::clear_document, this));
//    form_items.emplace(Button{"Load document", Coords{170, 100}, Coords{190, 120}}, std::bind(&EditorApp::load_document, this));
//    form_items.emplace(Button{"Save document", Coords{100, 100}, Coords{120, 120}}, std::bind(&EditorApp::save_document, this));


    controller_.create_view<graphics::GraphicView>(form_items);
  }

  ~EditorApp() = default;


  void run() {
    for(char c : { '+', '+', '+', '?', '+', '-', '$', '-' })
      controller_.handle_input(c) ;

    controller_.say_hello_to_all() ;
  }


    /**
     * @brief Создать номый документ.
     */
    void create_new_document() {
//      document_.clear();
//      selected_.clear();
//      view_.clear();
    }

    /**
     * @brief Очистить документ.
     */
    void clear_document() {
//      document_.clear();
//      selected_.clear();
//      view_.clear();
    }

    /**
     * @brief Загрузить документ из файла.
     * @param importer - импортер документа.
     * @param filename - имя файла.
     */
    void load_document(std::shared_ptr<IImporter> importer, const std::string& filename) {
//      clear_document();
//      importer->load(filename, document_);
//      redraw();
    }

    /**
     * @brief Сохранить документ в файл.
     * @param exporter - экспортер документа.
     * @param filename - имя файла.
     */
    void save_document(std::shared_ptr<IExporter> exporter, const std::string& filename) {
//      exporter->save(filename, document_);
    }


private:

  graphics::EditorController controller_;
};

} // namespace graphics.
