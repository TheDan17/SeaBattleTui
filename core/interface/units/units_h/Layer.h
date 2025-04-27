#include "Element.h"

#ifndef PRACTPROJ_LAYER_H
#define PRACTPROJ_LAYER_H

class Layer{
public:
    Element** layer_elements = nullptr;
    short int elem_amount = -1;
    Element* focus_element = nullptr;

    Layer();

    void add_element(Element* new_element, bool is_focus = false);
    void send_key_code(int key_code);
    void print_layer();
};

#endif //PRACTPROJ_LAYER_H
