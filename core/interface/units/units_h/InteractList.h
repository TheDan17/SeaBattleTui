#include <string>

#include "Element.h"

#ifndef PRACTPROJ_INTERACTLIST_H
#define PRACTPROJ_INTERACTLIST_H

class InteractList : public Element{
public:
    std::wstring* titles = nullptr;
    short int length;
    short int* select_array = nullptr;
    short int select_index = -1;

    bool is_main_list = true;
    InteractList* next_list = nullptr;
    InteractList* prev_list = nullptr;

    InteractList(std::wstring* titles, const short length, short int x_pos, short int y_pos);
    void selectUp();
    void selectDown();

    void print() override;
    void get_input_key(short int key_code) override;
};

#endif //PRACTPROJ_INTERACTLIST_H
