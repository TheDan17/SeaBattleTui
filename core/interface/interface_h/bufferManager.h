#include <string>

#ifndef PRACTPROJ_BUFFERMANAGER_H
#define PRACTPROJ_BUFFERMANAGER_H

class BufferManager{
public:
    static char** programBuffer;
    static short int linePosition;
    static short int bufferWidth, bufferHeight;

    static void initialize_buffer(short int width, short int height);
    static void clear_buffer();
    static void free_buffer();
    static void printb(const char *output, bool is_new_line = true);
    static void printbn(const char *output, bool is_new_line = true);
    static char* convert_buffer_to_output();
};

#endif //PRACTPROJ_BUFFERMANAGER_H
