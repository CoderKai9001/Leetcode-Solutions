#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void MaxHeapify(int* arr, int size, int idx) {
    int l = idx*2+1;
    int r = idx*2+2;
    int largest = idx;
    if(l < size && arr[l] > arr[largest]) largest = l;
    if(r < size && arr[r] > arr[largest]) largest = r;
    if(largest != idx) {
        swap(&arr[largest], &arr[idx]);
        MaxHeapify(arr, size, largest);
    }
}

void convertToHeap(int* arr, int size) {
    for(int i = size/2-1; i >= 0; i--) MaxHeapify(arr, size, i);
} 

void deleteMaxKTimes(int* arr, int size, int k) {
    for(int i = 0; i < k-1; i++) {
        swap(&arr[0], &arr[size-1]);
        size--;
        MaxHeapify(arr, size, 0);
    }
}

int findKthLargest(int* nums, int numsSize, int k) {
    convertToHeap(nums, numsSize);
    deleteMaxKTimes(nums, numsSize, k);
    return nums[0];
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
    int k;
    scanf("%d", &k);
    printf("%d\n", findKthLargest(arr, n, k));
    for(int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
    return 0;
}