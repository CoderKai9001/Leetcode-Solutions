#include <stdio.h>
#include <stdlib.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    if((m == 0 && n == 0) || (n == 0 && m!= 0)) return;
    if(n != 0 && m == 0) {
        for(int i = 0; i < n; i++) nums1[i] = nums2[i];
        return;
    }
    int arr1[m], arr2[n];
    for(int i = 0; i < m; i++) arr1[i] = nums1[i];   
    for(int i = 0; i < n; i++) arr2[i] = nums2[i];
    int i = 0;
    int j = 0;
    int k = 0;
    while(i < m && j < n) {
        if(arr1[i] < arr2[j]) {
            nums1[k] = arr1[i];
            i++;
            k++;
        } else {
            nums1[k] = arr2[j];
            j++;
            k++;
        }
    }   
    while(i < m) {
        nums1[k] = arr1[i];
        i++;
        k++;
    }
    while(j < n) {
        nums1[k] = arr2[j];
        j++;
        k++;
    }
}

int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    int nums1[m+n], nums2[n];
    for(int i= 0; i < m; i++) scanf("%d", &nums1[i]);  
    for(int i= m; i < m+n; i++) nums1[i] = 0;  
    for(int i= 0; i < n; i++) scanf("%d", &nums2[i]);
    merge(nums1, 0, m, nums2, 0, n); 
    for(int i = 0; i < m+n; i++) printf("%d ", nums1[i]);
    printf("\n");
    return 0;
}