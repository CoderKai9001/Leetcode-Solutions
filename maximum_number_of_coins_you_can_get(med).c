#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int* arr, int low, int high) {
    //let high be pivot
    int l = low;
    int r = high;
    int pivot_val = arr[high];
    while(l < r) {
        while(arr[l] > pivot_val && l < high) l++;
        while(arr[r] <= pivot_val && r > low) r--;
        if(l < r) swap(&arr[l], &arr[r]);
    }
    swap(&arr[high], &arr[l]);
    return l;
}

void quicksort(int* arr, int low, int high) {
    if(low < high) {
        int part_idx = partition(arr, low, high);
        quicksort(arr, low, part_idx-1);
        quicksort(arr, part_idx+1, high);
    }
}

int maxCoins(int* piles, int pilesSize) {
    quicksort(piles, 0, pilesSize-1);
    for(int i = 0; i < pilesSize; i++) printf("%d ", piles[i]);
    printf("\n");
    int k = pilesSize/3;
    int sum = 0;
    for(int i = 1; i < pilesSize; i+=2) {
        if(k == 0) return sum;
        sum += piles[i];
        k--;
    }
    return sum;
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
    printf("%d\n", maxCoins(arr, n));
    return 0;
}