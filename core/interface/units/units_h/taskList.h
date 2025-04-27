#include "Element.h"
#include "Layer.h"
#include "InteractList.h"

#ifndef PRACTPROJ_TASKLAYER_H
#define PRACTPROJ_TASKLAYER_H

class TaskList : public Element{
    InteractList title_list;

    TaskList(wchar_t** titles);
};

#endif //PRACTPROJ_TASKLAYER_H
