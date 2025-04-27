#include "mng_string.h"

#include <cstring>

short int get_string_arr_length(std::string arr[]){
    size_t i = 0;
    while (!arr[i].empty())
        ++i;
    return (short int)i;
}
short int get_char_str_length(const char* str){
    short int length = 0;
    while (str[length] != '\0')
        length++;
    return length;
}
short int get_wchar_str_length(wchar_t* wstr){
    short int length = 0;
    while (wstr[length] != '\0')
        length++;
    return length;
}
char** malloc_words_arr(std::string words[]){
    int words_count = get_string_arr_length(words);
    char** dynamic_words = (char**) malloc(sizeof(char*));
    for (int i = 0; i < words_count; ++i) {
        dynamic_words[i] = (char*) malloc(sizeof(char)*words[i].length());
        strcpy(dynamic_words[i], words[i].c_str());
    }
    return dynamic_words;
}
short int find_char(char* src, char search_char){
    short int index = 0;
    while (src[index] != '\0') {
        if (src[index] == search_char)
            return index;
        index++;
    }
    return -1;
}

bool compare_str(char* first, char* second){
    int index = 0;
    while(first[index] != '\0' || second[index] != '\0'){
        if (first[index] != second[index])
            return false;
    }
    return true;
}
bool find_str_in_array(char** str_list, int size, char* str){
    for (int i = 0; i < size; ++i) {
        if (compare_str(str_list[i], str))
            return true;
    }
    return false;
}