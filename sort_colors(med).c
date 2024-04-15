#include <stdio.h>

void sortColors(int* nums, int numsSize) {
    int zero_count = 0;
    int one_count = 0;
    int two_count = 0;
    for(int i = 0; i < numsSize; i++) {
        if(nums[i] == 0) zero_count++;
        else if(nums[i] == 1) one_count++;
        else if(nums[i] == 2) two_count++;
    }
    for(int i = 0; i < zero_count; i++) nums[i] = 0;
    for(int i = zero_count; i < zero_count+one_count; i++) nums[i] = 1;
    for(int i = zero_count+one_count; i < zero_count+one_count+two_count; i++) nums[i] = 2;
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
    sortColors(arr, n);
    for(int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
    return 0;
}