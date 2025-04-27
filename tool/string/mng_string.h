#include <string>

#ifndef PRACTPROJ_MNG_STRING_H
#define PRACTPROJ_MNG_STRING_H

struct string_arr {
    char** strings;
    short int string_count;
};

short int get_char_str_length(const char* str);
short int get_wchar_str_length(wchar_t* str);
short int get_string_arr_length(std::string arr[]);
char** malloc_words_arr(std::string words[]);
short int find_char(char* src, char search_char);

bool compare_str(char* first, char* second);
bool find_str_in_array(char** str_list, int size, char* str);

#endif //PRACTPROJ_MNG_STRING_H
