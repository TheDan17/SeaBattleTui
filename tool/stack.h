#ifndef PRACTPROJ_STACK_H
#define PRACTPROJ_STACK_H

struct stack {
    int data;
    struct stack *next;
};

struct stack* new_stack(int stack_data = 0);
struct stack* push_to_stack(struct stack *orig, int push_data);
void print_stack(struct stack* orig);

#endif //PRACTPROJ_STACK_H
