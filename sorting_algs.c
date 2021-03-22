#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_SIZE (100)
#define MAX_NUMBER_SIZE (10000)

static int sort_this[ARRAY_SIZE];

static void populate_array(int *arr, int arr_size);
static void print_arr(int *arr, int arr_size);

void merge(int *arr, int start_idx, int mid_idx, int end_idx) {
    int tmp1_size = mid_idx-start_idx+1;
    int tmp2_size = end_idx-mid_idx;
    int temp1[tmp1_size];
    int temp2[tmp2_size];

    for(int i = 0; i < tmp1_size; i++) {
        temp1[i] = arr[start_idx+i];
    }
    for(int i = 0; i < tmp2_size; i++) {
        temp2[i] = arr[mid_idx+i+1];
    }

    int tmp1_idx = 0;
    int tmp2_idx = 0;
    for(int i = start_idx; i <= end_idx; i++) {
        if((tmp1_idx < tmp1_size) && (tmp2_idx < tmp2_size)) {
            if(temp1[tmp1_idx] <= temp2[tmp2_idx]) {
                arr[i] = temp1[tmp1_idx];
                tmp1_idx++;
            }
            else {
                arr[i] = temp2[tmp2_idx];
                tmp2_idx++;
            }
        }
        else if(tmp1_idx < tmp1_size) {
            arr[i] = temp1[tmp1_idx];
            tmp1_idx++;
        }
        else if(tmp2_idx < tmp2_size) {
            arr[i] = temp2[tmp2_idx];
            tmp2_idx++;
        }
    }
}

// Divide and conquer where two sorted halves are merged into one 
// At first the two halves aren't sorted but going deeper down you eventually 
// have an array small enough that it is just a single index so it's sorted
// Once everything gets remerged the sort is correct
void merge_sort(int *arr, int start_idx, int end_idx) {    
    if(start_idx >= end_idx) return;

    int mid_idx = (start_idx+(end_idx-1))/2;
    merge_sort(arr, start_idx, mid_idx);
    merge_sort(arr, mid_idx+1, end_idx);
    merge(arr, start_idx, mid_idx, end_idx);
}

int partition(int *arr, int low, int high) {
    int pivot = arr[low];
    int pivot_alias = low;

    for(int i = low; i <= high; i++) {
        if(arr[i] < pivot) {
            int temp = arr[i];
            arr[i] = pivot;
            arr[pivot_alias] = temp;
            pivot_alias = i;
        }
    }

    return pivot_alias;
}

void quick_sort(int *arr, int low, int high) {
    if(low > high) return;

    int pivot = partition(arr, low, high);
    quick_sort(arr, low, pivot-1);
    quick_sort(arr, pivot+1, high);
}

int main() {
    printf("==============BEFORE SORT==============\n");
    populate_array(sort_this, ARRAY_SIZE);
    print_arr(sort_this, ARRAY_SIZE);
    
    // merge_sort(sort_this, 0, ARRAY_SIZE-1);
    quick_sort(sort_this, 0, ARRAY_SIZE-1);

    printf("==============AFTER SORT==============\n");
    print_arr(sort_this, ARRAY_SIZE);
    return 0;
}

static void populate_array(int *arr, int arr_size) {
    for(int i = 0; i < arr_size; i++) {
        arr[i] = rand()%MAX_NUMBER_SIZE;
        // arr[i] = arr_size-i;
    }
}

static void print_arr(int *arr, int arr_size) {
    for(int i = 0; i < arr_size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}