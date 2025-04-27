#include <string>

#ifndef PRACTPROJ_STR_H
#define PRACTPROJ_STR_H

struct str{
    const wchar_t* text;
    short int length;
};
class Str{
private:
    struct str string;
public:
    Str(std::wstring input_str);
    Str(wchar_t* input_wstr);
    const wchar_t* get_text();
    short int get_length();
};

#endif //PRACTPROJ_STR_H
