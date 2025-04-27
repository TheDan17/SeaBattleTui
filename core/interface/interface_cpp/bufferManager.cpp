#include "../interface_h/bufferManager.h"

#include "../../../tool/string/mng_string.h"

#include <cstring>

char** BufferManager::programBuffer = nullptr;
short int BufferManager::linePosition;
short int BufferManager::bufferWidth, BufferManager::bufferHeight;

void BufferManager::initialize_buffer(short width, short height) {
    bufferWidth = width; bufferHeight = height;
    programBuffer = (char**) new char*[bufferHeight];
    for (int i = 0; i < bufferHeight; ++i) {
        programBuffer[i] = new char[bufferWidth];
    }
    clear_buffer();
}
void BufferManager::clear_buffer() {
//    for (int i = 0; i < bufferHeight; ++i) {
//        for (int j = 0; j < bufferWidth; ++j) {
//            programBuffer[i][j] = ' ';
//        }
//    }
//    linePosition = 0;
    for (int i = 0; i < bufferHeight; ++i) {
        memset(programBuffer[i], ' ', bufferWidth);
    }
    linePosition = 0;
}
void BufferManager::free_buffer(){
    delete programBuffer;
    programBuffer = nullptr;
}
void BufferManager::printbn(const char* const_output, bool is_new_line) {
    int output_length = get_char_str_length(const_output);
    char* output = new char[output_length];
    strncpy(output, const_output, output_length);

    short int new_line_pos = find_char(output, '\n');
    if (new_line_pos != -1){
        short int position = 0;
        while (new_line_pos != -1){
            memmove(programBuffer[linePosition], output+position, new_line_pos-position);
            position = new_line_pos + 1;
            new_line_pos = find_char(output+position, '\n');
            linePosition++;
        }
        memmove(programBuffer[linePosition], output+position, output_length-position);
    } else {
        memmove(programBuffer[linePosition], output, output_length); // x coord?
    }
    if (is_new_line)
        linePosition++;
}
void BufferManager::printb(const char* output, bool is_new_line) {
    int output_length = get_char_str_length(output);
    memmove(programBuffer[linePosition], output, output_length); // x coord?
    if (is_new_line)
        linePosition++;
}
char* BufferManager::convert_buffer_to_output() {
    char* converted_buffer = new char [bufferHeight * bufferWidth];
    short int iteration = 0;
    while (iteration < bufferHeight) {
        memmove(converted_buffer + iteration * bufferWidth, programBuffer[iteration], bufferWidth);
        iteration++;
    }
    return converted_buffer;
}