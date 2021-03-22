// heaps are trees that can get heapified

#include <stdio.h>

struct node {
    int val;
    struct node * left;
    struct node * right;
};

struct node * root = NULL;

// creates min heap where lowest value is at the root
// O(logn)
void heapify() {
    
}