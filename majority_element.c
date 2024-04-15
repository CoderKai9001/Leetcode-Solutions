#include <stdio.h>

void merge(int* arr, int l, int r, int m) {
    int s1 = m-l+1;
    int s2 = r-m;
    int sa1[s1];
    int sa2[s2];
    // set subarrays
    for(int i=0; i < s1; i++) sa1[i] = arr[l+i];
    for(int i=0; i < s2; i++) sa2[i] = arr[m+1+i];

    int i = 0;//index of first subarray
    int j = 0;// index of second subarray
    int k = l;// index of array start 

    // add in ascending order
    while(i < s1 && j < s2) {
        if(sa1[i] < sa2[j]) {
            arr[k] = sa1[i];
            i++;
            k++;
        } else {
            arr[k] = sa2[j];
            j++;
            k++;
        }
    }
    // add remaining elements of sub-array1 [ when sa1 > sa2 ]
    while(i < s1) {
        arr[k] = sa1[i];
        i++;
        k++;
    }
    // add remaining elements of sub-array2 [ when sa2 > sa1 ]
    while(j < s2) {
        arr[k] = sa2[j];
        j++;
        k++;
    }
}

void mergesort(int* arr, int l, int r) {
    if(l < r) {
        int m = (r-l)/2 + l;
        // break array to subarrays.
        mergesort(arr, l, m);
        mergesort(arr, m+1, r);
        
        //merge subarrays
        merge(arr, l, r, m);
    }
}

int majorityElement(int* nums, int numsSize) {
    int majority;
    int count = 0;
    int max_count = 0;
    mergesort(nums, 0, numsSize-1);
    if(numsSize == 1) {
        return nums[0];
    }
    for(int i = 0; i < numsSize-1; i++) {
        if(nums[i] == nums[i+1]) {
            count++;
            if(max_count < count) {
                max_count = count;
                majority = nums[i];
            }
        } else {
            count = 0;
        }
    } 
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);

    return 0;
}