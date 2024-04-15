#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void merge(char* arr, int l, int r, int m) {
    int s1 = m-l+1;
    int s2 = r-m;
    char sa1[s1], sa2[s2];
    for(int i =0; i < s1; i++) sa1[i] = arr[l+i];
    for(int i =0; i < s2; i++) sa2[i] = arr[m+i+1];
    int i = 0;
    int j = 0;
    int k = l;
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
    while(i < s1) {
        arr[k] = sa1[i];
        i++;
        k++;
    } 
    while(j < s2) {
        arr[k] = sa2[j];
        j++;
        k++;
    }
} 

void mergesort(char* arr, int l, int r) {
    if(l < r) {
        int m = (r-l)/2 + l;
        mergesort(arr, l, m);
        mergesort(arr, m+1, r);
        merge(arr, l, r, m);
    }
}

bool isAnagram(char* s, char* t) {
    if(strlen(s) != strlen(t)) return false;
    mergesort(s, 0, strlen(s)-1);
    mergesort(t, 0, strlen(t)-1);
    for(int i = 0; i < strlen(s); i++) if(s[i] != t[i]) return false;
    return true;
}

int main() {
    char word1[100];
    char word2[100];
    scanf("%s", word1);
    scanf("%s", word2);
    if(isAnagram(word1, word2)) printf("YES\n");
    else printf("NO\n");
    return 0;
}