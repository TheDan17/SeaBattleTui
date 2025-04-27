#include "core/core_h/TaskManager.h"
#include "tool/string/mng_string.h"

#include <conio.h>

int main(int arg_c, char** args){
    TaskManager task_manager;

    std::string debug_arg = "--debug";
    if(true)//find_str_in_array(args, arg_c, (char*)debug_arg.c_str()))
        task_manager.start(true);
    else
        task_manager.start(false);

    getch();
    return 0;
}
