#include "../units_h/InteractList.h"

#include "../../../core_h/global_config.h"
#include "../../interface_h/consoleManager.h"
#include "../../../../tool/string/str.h"
#include "../../../core_h/audio.h"


InteractList::InteractList(std::wstring *titles, const short length, short x_pos, short y_pos):Element(x_pos, y_pos){
    this->titles = titles;
    this->length = length;
    this->x_pos = x_pos;
    this->y_pos = y_pos;

    this->select_index = 0;
    this->select_array = new short int [length]();
    this->select_array[0] = LIST_SELECTED_CODE;
}

void InteractList::selectUp() {
    // old
    if (this->select_index > 0) {
        this->select_index--;
        this->select_array[this->select_index] = LIST_SELECTED_CODE;
        this->select_array[this->select_index + 1] = LIST_EMPTY_CODE;
    }
}
void InteractList::selectDown() {
    // old
    if (this->select_index < (this->length - 1)) {
        this->select_index++;
        this->select_array[this->select_index] = LIST_SELECTED_CODE;
        this->select_array[this->select_index - 1] = LIST_EMPTY_CODE;
    }
}

void InteractList::print() {
//    const wchar_t* testt = L"Hello world";
//    Str test(testt);
//    ConsoleManager::print_to_pos(test.get_text(), test.get_length(), 0, 0);

    auto* current_symbol = new wchar_t[1];
    for (short i = 0; i < this->length; ++i) {
        if (this->select_array[i] == LIST_SELECTED_CODE)
            current_symbol[0] = LIST_SELECTED_SYMBOL;
        else
            current_symbol[0] = LIST_EMPTY_SYMBOL;
        std::wstring current_symbol_str(current_symbol, 1);

        std::wstring title_std = current_symbol_str + std::to_wstring(i+1) + L") " + this->titles[i];
        ConsoleManager::print_to_pos(title_std.c_str(), title_std.length(), this->x_pos, this->y_pos+i);
    }
    delete[] current_symbol;
}
void InteractList::get_input_key(short key_code) {
    switch (key_code) {
        case KEY_ENTER_CODE:
            break;
        case KEY_Q_CODE:
            break;
        case KEY_DOWN_CODE:
            selectDown();
            play_select_sound(); // todo
            break;
        case KEY_UP_CODE:
            selectUp();
            play_select_sound(); // todo
            break;
        default:
            Str except_message (L"Wrong key");
            ConsoleManager::set_cursor_pos(0, ConsoleManager::consoleHeight-1);
            ConsoleManager::print_str(except_message.get_text(), except_message.get_length());
    }
}