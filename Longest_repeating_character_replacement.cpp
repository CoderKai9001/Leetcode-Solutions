#include <bits/stdc++.h>
using namespace std;

    int characterReplacement(string s, int k) {
    unordered_map<char, int> alphabets;
    int res = 0, start = 0, end = 0, maxim = 0, len = s.size();
    while (end < len) {
        maxim = max(maxim, alphabets[s[end]]+1);
        alphabets[s[end]] = 1 + alphabets[s[end]];
        if ((end - start + 1) - maxim <= k) {
            res = max(res, (end - start + 1));
            end++;
        } else {
            alphabets[s[start]] -= 1;
            start++;
            end++;
        }
    }
    return res;
}

int main() {

    return 0;
}