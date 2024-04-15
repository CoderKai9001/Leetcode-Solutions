#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isAnagram(char* s, char* t) {
    int freq_arr[26] = {0};
    int i = 0;
    while(s[i] != '\0' || t[i] != '\0') {
        if(s[i]=='\0' || t[i]=='\0') return false;
        freq_arr[s[i]-'a']++;
        freq_arr[t[i]-'a']--;
        i++;
    }
    for(int i = 0; i < 26; i++) if(freq_arr[i] != 0) return false;
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