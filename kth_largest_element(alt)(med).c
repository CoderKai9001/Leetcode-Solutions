#include <stdio.h>

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
        while(l < high && arr[l] < pivot_val) l++;
        while(r >= low && arr[r] >= pivot_val) r--;
        if(l < r) swap(&arr[l], &arr[r]);
    }
    swap(&arr[high], &arr[l]);
    return l;
}

int find(int* arr, int n, int k, int low, int high) {
    if(low <= high) {
        int part_idx = partition(arr, low, high);
        if(part_idx < k) return find(arr, n, k, part_idx+1, high);
        else if(part_idx > k) return find(arr, n, k, low, part_idx-1);
        else return arr[part_idx];
    }
}

int findKthLargest(int* nums, int numsSize, int k) {
    return find(nums, numsSize, k, 0, numsSize-1);
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int arr[n];
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
    printf("%d\n", findKthLargest(arr, n, n-k+1));
}