// a stack is a LIFO data structure. We push a node to the stack and pop it from the top.
#include <stdlib.h>
#include <stdio.h>
struct node {
    int val;
    struct node * next;
};

struct stack {
    int depth;
    struct node * top;
};

struct stack my_stack;

void stack_init() {
    my_stack.depth = 0;
    my_stack.top = NULL;
}

void stack_push (int val) {
    struct node * temp = (struct node *)malloc(sizeof(struct node));
    temp->next = my_stack.top;
    temp->val = val;
    my_stack.depth++;
    my_stack.top = temp;
}

struct node * stack_pop () {
    if (my_stack.depth == 0) return NULL;

    struct node* ret = my_stack.top;

    my_stack.top = my_stack.top->next;
    my_stack.depth--;

    return ret;
}

int get_stack_depth() {
    return my_stack.depth;
}

int main() {
    stack_init();
    for(int i = 0; i < 10; i++) {
        stack_push(i);
        printf("Node: %d Depth: %d\n", i, my_stack.depth);
    }
    printf("\n");
    while(my_stack.depth > 0) {
        struct node *temp = stack_pop();

        printf("Node: %d Depth: %d\n", temp->val, my_stack.depth);
    }
    return 0;
}