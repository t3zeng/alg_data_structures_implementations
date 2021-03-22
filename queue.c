// a queue is a FIFO data structure. We enqueue a node to the queue and dequeue it from the beginning.

#include <stdlib.h>
#include <stdio.h>

struct node {
    int val;
    struct node * next;
};

struct queue {
    int size;
    struct node* first;
    struct node* last;
};

struct queue my_queue = {
    .size = 0, 
    .first = NULL, 
    .last = NULL
};


void enqueue(int val) {
    struct node * temp = (struct node*)malloc(sizeof(struct node));
    temp->val = val;
    temp->next = NULL;

    if(my_queue.size == 0) {
        my_queue.first = temp;
    } else {
        my_queue.last->next = temp;
    }
    my_queue.size++;
    my_queue.last = temp;
}

struct node * dequeue () {
    struct node * ret = my_queue.first;

    my_queue.size--;
    my_queue.first = my_queue.first->next;
    if(my_queue.size == 0) {
        my_queue.last = NULL;
    } 

    return ret;
}

int main() {
    for(int i = 0; i < 10; i++) {
        enqueue(i);
        printf("Node: %d Size: %d\n", i, my_queue.size);
    }
    printf("\n");
    while(my_queue.size > 0) {
        struct node * temp = dequeue();
        printf("Node: %d Size: %d\n", temp->val, my_queue.size);
    }
    return 0;
}