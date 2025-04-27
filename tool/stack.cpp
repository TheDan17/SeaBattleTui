#include "stack.h"

#include <cstdlib>
#include <cstdio>

struct stack* new_stack(int stack_data){
    auto* ptr = (struct stack*)malloc(sizeof(struct stack));
    ptr->next = nullptr;
    ptr->data = stack_data;
    return ptr;
}
struct stack* push_to_stack(struct stack *orig, int push_data){
    struct stack* push_stack = new_stack();
    push_stack->data = push_data;
    push_stack->next = orig;
    return push_stack;
}
void print_stack(struct stack* orig){
    struct stack* part_stack = orig;
    while (part_stack->next != nullptr){
        printf("=> %d\n", part_stack->data);
        part_stack = part_stack->next;
    }
    printf("=> %d\n", part_stack->data);
}

