#include "../core_h/concept.h"

#include "../../tool/string/mng_string.h"
#include "../../tool/stack.h"
#include "../interface/interface_h/bufferManager.h"

#include "windows.h"
#include <io.h>
#include <fcntl.h>

void test_stack(){
    struct stack* test = new_stack(7);
    test = push_to_stack(test, 5);
    test = push_to_stack(test, 3);
    test = push_to_stack(test, 1);
    test = push_to_stack(test, -1);
    print_stack(test);
}

//todo
short int get_int_length(short int number){
    short int length = 1;
    if (number < 0)
        length += 1;
    while ((number / 10) != 0){
        length++;
        number /= 10;
    }
    return length;
}
//todo
char* convert_number_to_str(int number){
    short int number_length = get_int_length(number);
    char* number_str = new char[number_length];
    sprintf(number_str, "%d", number);
    return number_str;
}

void test_text(){
    //WriteConsoleOutputCharacterA(hCon, "str", length, cPos, NULL);
    HANDLE stdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD written = 0;
    const wchar_t* message = L"hello world";
    int length = 11;
    SetConsoleCursorPosition(stdOut, {1, 4});
    WriteConsoleW(stdOut, message, length, &written, NULL);
    SetConsoleCursorPosition(stdOut, {1, 3});
    WriteConsoleW(stdOut, message, length, &written, NULL);
    SetConsoleCursorPosition(stdOut, {7, 4});
    WriteConsoleW(stdOut, message, length, &written, NULL);
    SetConsoleCursorPosition(stdOut, {0, 4});
    WriteConsoleW(stdOut, message, length, &written, NULL);
    SetConsoleCursorPosition(stdOut, {2, 1});
    WriteConsoleW(stdOut, message, length, &written, NULL);
    SetConsoleCursorPosition(stdOut, {8, 1});
    WriteConsoleW(stdOut, L"█▇▆▅▄▃▂▁", 8, &written, NULL);
    for (int i = 0; i < 10; ++i) {
        SetConsoleCursorPosition(stdOut, {0, 1});
        WriteConsoleW(stdOut, convert_number_to_str(i), 1, &written, NULL);
        Sleep(50);
    }
}

void print_concept_game(){
    BufferManager::printb("auf");
    BufferManager::printb("aub");
    BufferManager::printb("<><><><++>+><+>+>");
    BufferManager::printb("=================");
    BufferManager::printb("█████████████████");
    BufferManager::printb("=================");
//    printf("■■■■■■■■◣ ◩  ⚡⚒♔❖♠\n");
//    printf("░▒▓▘▞▬▬▬\n█  ██\n█    ██\n████\n▐=▏▎▍▌▋▊▉█▇▆▅▄▃▂▁▀\n");
//    printf(" ◢ ◣\n ◥ ◤\n");
//    printf("██\n");
//    printf("⟩⟨▓▓\n");
//    printf("❯❮▓▓\n");
//    printf("    \n");
//    printf("░░░░\n");
//    printf("▞▃▆▀\n");
//    printf(" ▁▁\n");
//    printf("▕==▏\n");
//    printf(" ▔▔\n");
//    printf(" ▁▁▁▁▁▁▁▁▁▁\n");
//    printf("▕ ⚡Yakutsk ▏\n");
//    printf(" ▔▔▔▔▔▔▔▔▔▔\n");
//    printf(" ▁▁▁▁▁▁▁▁▁\n");
//    printf("▕ 12 ┋  3 ▏\n");
//    printf(" ▔▔▔▔▔▔▔▔▔\n");
//    printf(" Ⅰ Ⅱ 3 4 5 6 7 Ⅷ 9 Ⅹ 1112\n");
//    printf("┏━━━━━━━━━━━━━┓\n");
//    printf("┃ ◡██ ◡ ◡ ◡ ◡ ┃\n");
//    printf("┃◡ ██◡ ◡ ◡ ◡ ◡┃\n");
//    printf("┃ ◡██ ◡ ◡ ◡ ◡ ┃\n");
//    printf("┃◡ ██◡ ◡ ◡ ◡ ◡┃\n");
//    printf("┃ ◡ ◡ ◡ ◡ ◡ ◡ ┃\n");
//    printf("┃◡ ◡ ◡ ◡ ██◡ ◡┃\n");
//    printf("┃ ◡ ◡ ◡ ◡ ◡ ◡ ┃\n");
//    printf("┃◡ ◡ ◡ ◡ ◡ ◡ ◡┃\n");
//    printf("┃ ◡████◡ ◡ ◡ ◡┃\n");
//    printf("┗━━━━━━━━━━━━━┛\n");
//    printf(" 1  2  3  4  5  6  7  8  9  10 11 12 13\n");
//    printf("┏━━━━━━━━━━━━━━━━━━━┓\n");
//    printf("┃ ◡ ██  ◡  ◡  ◡  ◡  ┃\n");
//    printf("┃◡  ██ ◡  ◡  ◡  ◡  ◡┃\n");
//    printf("┃ ◡ ██  ◡  ◡  ◡  ◡  ┃\n");
//    printf("┃◡  ██ ◡  ◡  ◡  ◡  ◡┃\n");
//    printf("┃ ◡  ◡  ◡  ◡ ██  ◡  ┃\n");
//    printf("┃◡  ◡  ◡  ❯❮ ◡  ◡  ◡┃\n");
//    printf("┃ ◡ ███▒▒▒▒▒▒▒▒  ◡  ┃\n");
//    printf("┃◡  ◡  ◡  ◡  ◡  ◡  ◡┃\n");
//    printf("┃ ◡ ░░  ◡ ▒▒▒▒▒  ◡  ┃\n");
//    printf("┗━━━━━━━━━━━━━━━━━━━┛\n");
}