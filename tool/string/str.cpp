#include "str.h"
#include "mng_string.h"

Str::Str(std::wstring input_str) {
    struct str output_str = {input_str.c_str(), (short)input_str.length()};
    this->string = output_str;
}
Str::Str(wchar_t *input_wstr) {
    short int length = get_wchar_str_length(input_wstr);
    struct str output_wstr = {input_wstr, };
}
short Str::get_length() {
    return this->string.length;
}
const wchar_t* Str::get_text() {
    return this->string.text;
}
