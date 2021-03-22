#include <stdlib.h>

typedef struct {
    int key;
    int data;
} hash_data_t;

#define HASH_ARRAY_SIZE (100)

hash_data_t *hash_array[HASH_ARRAY_SIZE];

// converts key to index in hash_array
int hash_function(int key) {
    return key%HASH_ARRAY_SIZE;
}

void hash_insert (int key, int data) {
    // create new hash data item
    hash_data_t *temp = (hash_data_t *)malloc(sizeof(hash_data_t));
    
    temp -> key = key;
    temp -> data = data;
    
    // find index to store the new hash item
    int hash_idx = hash_function(key);
    
    // stick hash data in first free slot
    while(hash_array[hash_idx] != NULL) {
        hash_idx++;
        hash_idx%=HASH_ARRAY_SIZE;
    }

    hash_array[hash_idx] = temp;
}

void hash_remove (hash_data_t *remove) {
    // find the data to remove
    int hash_idx = hash_function(remove->key);

    while(hash_array[hash_idx] -> key != remove->key) {
        hash_idx++;
        hash_idx%=HASH_ARRAY_SIZE;

        if(hash_idx == hash_function(remove->key)) return;
    }

    free(hash_array[hash_idx]);
    hash_array[hash_idx] = NULL;
}

hash_data_t * hash_search(int key) {
    int hash_idx = hash_function(key);

    while(hash_array[hash_idx] -> key != key) {
        hash_idx++;
        hash_idx%=HASH_ARRAY_SIZE;

        if(hash_idx == hash_function(key)) return NULL;
    }

    return hash_array[hash_idx];
}

int main() {
    return 0;
}