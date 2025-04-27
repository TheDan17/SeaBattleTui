#ifndef PRACTPROJ_ELEMENT_H
#define PRACTPROJ_ELEMENT_H

class Layer;

class Element{
public:
    Layer* from_layer;
    short int x_pos = -1, y_pos = -1;
    bool is_focus = false;

    Element(short int x_pos, short int y_pos);
    virtual void get_input_key(short int key_code);
    virtual void print();
};

#endif //PRACTPROJ_ELEMENT_H
