#include "../interface/interface_h/consoleManager.h"
#include "../../.backup/list.h"
#include "../interface/units/units_h/Layer.h"
#include "../interface/units/units_h/Element.h"

#include "../../tool/tools.h"
#include "global_config.h"

#ifndef PRACTPROJ_TASKMANAGER_H
#define PRACTPROJ_TASKMANAGER_H

class TaskLayer{
    Layer* layer;
    void send_key();
};

class TaskDriver{
    bool is_working = false;
    TaskLayer* to_layer;
    void start_loop();
};

class Task{
    TaskLayer task_layer;
    TaskDriver task_driver;
};

class TaskList : public TaskLayer{
public:
    Task* tasks;

    TaskList(std::string titles[], void_func* funcs);
    void select_up();
    void select_down();
    void start_task();
};

class TaskManager{
public:
    TaskList* task_list;
    Task* menu_task;
    bool is_task_working;

    TaskManager();
    void set_list_task();
    void change_task(void_func new_task);
    void start_loop(bool is_debug);
    void start(bool is_debug = true);
};

#endif //PRACTPROJ_TASKMANAGER_H
