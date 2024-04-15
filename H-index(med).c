#include <stdio.h>
#include <stdlib.h>

void countingsort(int* arr, int n) {
    int max_idx = 0;
    for(int i = 0; i < n; i++) if(arr[i] > arr[max_idx]) max_idx = i;
    int* countarr = (int*)calloc(arr[max_idx]+1, sizeof(int));
    for(int i = 0; i < n; i++) countarr[arr[i]]++;
    for(int i = 1; i <= arr[max_idx]; i++) countarr[i] += countarr[i-1];
    int* new_arr = (int*)malloc(sizeof(int)*n);
    for(int i = 0; i < n; i++) {
        new_arr[n - countarr[arr[i]]] = arr[i];
        countarr[arr[i]]--;
    }
    for(int i = 0; i < n; i++) arr[i] = new_arr[i];
    free(countarr);
    free(new_arr);
}

int hIndex(int* citations, int citationsSize) {
    int citationreq = 1;
    countingsort(citations, citationsSize);
    // for(int i = 0; i < citationsSize; i++) printf("%d ", citations[i]);
    // printf("\n");
    int min_till_now = citations[0];
    for(int i = 0; i < citationsSize; i++) {
        if(citations[i] < min_till_now) {
            min_till_now = citations[i];
        }
        if(citationreq > min_till_now) break;
        citationreq++;
    }
    return citationreq-1;
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
    printf("H-index: %d\n", hIndex(arr, n));
    return 0;
}