#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int val;
    int frequency;
} node;

node* createnode(int val) {
    node* N = (node*)malloc(sizeof(node));
    N->frequency = 1;
    N->val = val;
    return N;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int* arr, int low, int high) {
    int l = low;
    int r = high;
    int pivot_val = arr[high];
    while(l < r) {
        while(l < high && arr[l] > pivot_val) l++;
        while(r > low && arr[r] <= pivot_val) r--;
        if(l < r) swap(&arr[l], &arr[r]);
    }
    swap(&arr[l], &arr[high]);
    return l;
}

void quicksort(int* arr, int low, int high) {
    if(low < high) {
        int part_idx = partition(arr, low, high);
        quicksort(arr, low, part_idx-1);
        quicksort(arr, part_idx+1, high);
    }
}

int partitionnode(node** arr, int low, int high) {
    int l = low;
    int r = high;
    int pivot_val = arr[high]->frequency;
    while(l < r) {
        while(l < high && arr[l]->frequency > pivot_val) l++;
        while(r > low && arr[r]->frequency <= pivot_val) r--;
        if(l < r) {
            node* temp = arr[l];
            arr[l] = arr[r];
            arr[r] = temp;
        }   
    }
    node* temp = arr[l];
    arr[l] = arr[high];
    arr[high] = temp;
    return l;
}

void quicksortnode(node** arr, int low, int high) {
    if(low < high) {
        int part_idx = partitionnode(arr, low, high);
        quicksortnode(arr, low, part_idx-1);
        quicksortnode(arr, part_idx+1, high);
    }
}

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    node* arr[numsSize];
    quicksort(nums, 0, numsSize-1);
    for(int i = 0; i < numsSize; i++) arr[i] = NULL;
    arr[0] = createnode(nums[0]);
    int count = 0;
    for(int i = 1; i < numsSize; i++) {
        if(nums[i] == nums[i-1]) arr[count]->frequency++;
        else {
            count++;
            arr[count] = createnode(nums[i]);
        }
    }
    quicksortnode(arr, 0, count);
    int* result = (int*)malloc(sizeof(int)*k);
    for(int i = 0; i < k; i++) result[i] = arr[i]->val;
    *returnSize = k;
    return result;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int arr[n];
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
    int returnSize;
    int* p = topKFrequent(arr, n, k, &returnSize);
    for(int i = 0 ; i < returnSize; i++) printf("%d ", p[i]);
    printf("\n");
    free(p);
    return 0;
}