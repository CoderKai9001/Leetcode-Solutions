#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void countingsort(char* arr, int n) {
    int max_idx = 0;
    for(int i = 0; i < n; i++) if(arr[i] > arr[max_idx]) max_idx = i;
    int* countarr = (int*)calloc(arr[max_idx]+1, sizeof(int));
    for(int i = 0; i < n; i++) countarr[arr[i]]++;
    for(int i = 1; i <= arr[max_idx]; i++) countarr[i] += countarr[i-1];
    char* new_arr = (char*)malloc(sizeof(char)*n);
    for(int i = 0; i < n; i++) {
        new_arr[countarr[arr[i]] - 1] = arr[i];
        countarr[arr[i]]--;
    }
    for(int i = 0; i < n; i++) arr[i] = new_arr[i];
    free(countarr);
    free(new_arr);
}

char * sortVowels(char * s) {
    int count = 0;
    char vowel_arr[strlen(s)];
    for(int i = 0; i < strlen(s); i++) {
        if((s[i] == 'a')|| (s[i] == 'e')|| (s[i] == 'i')|| (s[i] == 'o')|| (s[i] == 'u')|| (s[i] == 'A')|| (s[i] == 'E')|| (s[i] == 'I')|| (s[i] == 'O')|| (s[i] == 'U')) {
            vowel_arr[count] = s[i];
            count++;
        }
    }
}

int main() {
    char str[100];
    scanf("%s", str);
    countingsort(str, strlen(str));
    printf("%s\n", str);
    return 0;
}