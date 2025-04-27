#include "../core_h/TaskManager.h"

#include "../core_h/audio.h"
#include "../core_h/global_config.h"
#include "../core_h/data.h"
#include "../core_h/concept.h"

#include "../interface/interface_h/consoleManager.h"
#include "../interface/interface_h/bufferManager.h"

#include "../interface/units/units_h/Element.h"
#include "../interface/units/units_h/InteractList.h"

#include "conio.h"
#include <string>

///
//T//askList::TaskList(std::string* titles, TaskLayer* tasks){
    //this->task_titles = new ConsoleList1(titles);
    //this->tasks = data::test_funcs;
    //this->
//}
void TaskList::select_up(){
    //this->task_titles->selectUp();
}
void TaskList::select_down(){
    //this->task_titles->selectDown();
}
void TaskList::start_task(){

}

TaskManager::TaskManager() {
    //this->console_manager = new ConsoleManager(config::width, config::height);
    //this->tasks = new TaskList(data::test_titles, data::test_funcs);
    //this->task_layer = new Layer();
    //this->task_layer->add_element((Element*)new ConsoleList1(test_titles));
    //this->is_list_task = true;
}
void TaskManager::set_list_task(){

}
void TaskManager::change_task(void_func new_task){

}


void TaskManager::start_loop(bool is_debug) { // todo layers
    if (is_debug) {
        //ConsoleManager::clear_console();

        Layer task_layer;
        InteractList* task_list = new InteractList(data::test_titles, 3, 0, 0);
        task_layer.add_element(task_list, true);

        bool is_menu = true; // todo States
        void (*present_func)() = nullptr;
        ConsoleManager::ConsoleManager_init(config::width, config::height);
        //BufferManager::initialize_buffer(config::width, config::height);

        //ConsoleList1 test_list(test_titles);
        while (true) { // todo path bar
            /*
            if (present_func == nullptr) {
                //test_list.print();
            } else {
                //BufferManager::printb(test_titles[test_list.select_index].c_str());
                //BufferManager::printb("=========================");
                //present_func();
            }
            //consManager.updateScreenBuffer();
            if (present_func != nullptr) {
                present_func();
            }
             */
            task_layer.print_layer();

            int input_char_code = getch();
            task_layer.send_key_code(input_char_code);

            ////ConsoleManager::clear_console();
            //BufferManager::clear_buffer();
            //BufferManager::printb(GET_VARIABLE_NAME(input_char_code)); // todo var debug item
            /*
            if (present_func == nullptr) {
                if (input_char_code == KEY_UP_CODE) {
                    //test_list.selectUp();
                    play_select_sound();
                }
                if (input_char_code == KEY_DOWN_CODE) {
                    //test_list.selectDown();
                    play_select_sound();
                }
                if (input_char_code == KEY_ENTER_CODE) {
                    //present_func = test_funcs[test_list.select_index];
                }
                if (input_char_code == KEY_Q_CODE)
                    break;
            } else {
                if (input_char_code == KEY_Q_CODE) {
                    present_func = nullptr;
                }
            }
             */
        }
    } else {
        //start_game();
    }
}

void TaskManager::start(bool is_debug) {
    start_loop(is_debug);
}
