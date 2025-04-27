#include "../units_h/Layer.h"

Layer::Layer() {
    this->layer_elements = new Element* [1];
    this->elem_amount = 0;
}

void Layer::add_element(Element *new_element, bool is_focus) {
    Element** new_layer = new Element* [elem_amount+1];

    for (int i = 0; i < this->elem_amount; ++i)
        new_layer[i] = this->layer_elements[i];
    new_layer[elem_amount+1] = new_element;

    delete this->layer_elements;
    this->layer_elements = new_layer;
    this->elem_amount++;

    if(is_focus) {
        new_element->is_focus = true; // todo ?
        this->focus_element = new_element;
    }
}

void Layer::send_key_code(int key_code) {
    focus_element->get_input_key(key_code);
}

void Layer::print_layer() {
    /*
    for (int i = 0; i < elem_amount; ++i) {
        this->layer_elements[i]->print();
    }
     */
    if (focus_element != nullptr)
        focus_element->print();
}