#include "../interface_h/consoleManager.h"
#include "../interface_h/bufferManager.h"
#include "../../core_h/global_config.h"

#include <string>
#include "windows.h"

short ConsoleManager::consoleWidth;
short ConsoleManager::consoleHeight;
HANDLE ConsoleManager::consoleHandle;
DWORD ConsoleManager::written;

void ConsoleManager::setConsoleSize() {
    _COORD coord{ConsoleManager::consoleWidth, ConsoleManager::consoleHeight};
    SetConsoleScreenBufferSize(ConsoleManager::consoleHandle, coord);

    _SMALL_RECT rect{};
    rect.Top = 0; rect.Bottom = (SHORT)(ConsoleManager::consoleHeight - 1);
    rect.Left = 0; rect.Right = (SHORT)(ConsoleManager::consoleWidth - 1);
    SetConsoleWindowInfo(ConsoleManager::consoleHandle, TRUE, &rect);
}
void lockWindowSize(){
    HWND consoleWindow = GetConsoleWindow();
    SetWindowLong(consoleWindow, GWL_STYLE, GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);
}
void makeCursorInvisible(HANDLE consoleHandle){
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(ConsoleManager::consoleHandle,&cursorInfo);
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(ConsoleManager::consoleHandle, &cursorInfo);
}
void setUTF8Codepage(){
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
}
void ConsoleManager::ConsoleManager_init(short int width, short int height) {
    ConsoleManager::consoleWidth = width;
    ConsoleManager::consoleHeight = height;
    ConsoleManager::consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    ConsoleManager::written = 0;

    setConsoleSize();
    lockWindowSize();
    makeCursorInvisible(ConsoleManager::consoleHandle);
    setUTF8Codepage();

    SetConsoleTitleA("SeaBattle");
    system("color 0B");
}
void ConsoleManager::set_cursor_pos(short x_pos, short y_pos) {
    SetConsoleCursorPosition(ConsoleManager::consoleHandle, {x_pos, y_pos});
}
void ConsoleManager::print_str(const wchar_t* str, short length) {
    WriteConsoleW(ConsoleManager::consoleHandle, str, length, &ConsoleManager::written, NULL);
}
void ConsoleManager::print_to_pos(const wchar_t* str, short int length, short int x_pos, short int y_pos){
    SetConsoleCursorPosition(ConsoleManager::consoleHandle, {x_pos, y_pos});
    WriteConsoleW(ConsoleManager::consoleHandle, str, length, &ConsoleManager::written, NULL);
}

void ConsoleManager::clear_console() {
    std::wstring space;
    for (int j = 0; j < config::width; ++j)
        space += L" ";
    const wchar_t* space_char = space.c_str();

    for (short i = 0; i < config::height; ++i) {
        SetConsoleCursorPosition(ConsoleManager::consoleHandle, {0, i});
        WriteConsoleW(ConsoleManager::consoleHandle, space_char, config::width, &ConsoleManager::written, NULL);
    }
}

/*
void ConsoleManager::displayScreenBuffer() {
    WriteConsoleOutputCharacter(this->consoleHandle, this->screenBuffer,
                                this->consoleWidth * this->consoleHeight,
                                COORD{0, 0}, &(this->w));
}
void ConsoleManager::cleanScreenBuffer() {
    memset(this->screenBuffer, ' ', this->consoleWidth * this->consoleHeight);
}
void ConsoleManager::updateScreenBuffer(){
    cleanScreenBuffer();
    this->screenBuffer = BufferManager::convert_buffer_to_output();
    displayScreenBuffer();
}
 */