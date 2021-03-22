#include <stdlib.h>
#include <stdio.h>

struct tree_node{
    int val;
    struct tree_node *left;
    struct tree_node *right;
};

static struct tree_node *root = NULL;

void tree_append(int val) {
    // create new node
    struct tree_node *new_node = (struct tree_node *)malloc(sizeof(struct tree_node));
    new_node->val = val;
    new_node->left = NULL;
    new_node->right = NULL;

    // traverse down the tree 
    if(root == NULL) {
        root = new_node;
    }
    else {
        struct tree_node *alias = root;
        struct tree_node *follow = alias;
        while(alias != NULL) {
            follow = alias;
            if(val <= alias->val) {
                alias = alias->left;
            }
            else {
                alias = alias -> right;
            }
        }
        if(val <= follow->val) {
            follow->left = new_node;
        }
        else {
            follow->right = new_node;
        }
    }
}

void tree_remove(int val) {
    struct tree_node *alias = root;
    struct tree_node *follow = alias;

    // TODO: special case if root is getting removed

    while(alias->val != val) {
        follow = alias;
        if(val < alias->val) {
            alias = alias -> left;
        }
        else {
            alias = alias -> right;
        }
    }
}

int main() {
    for(int i = 0; i < 5; i++) {
        tree_append(i); 
    }
    printf("%d\n", root->val);
    printf("%d\n", root->right->val);
    printf("%d\n", root->right->right->val);
    
    return 0;
}