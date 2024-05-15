#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
    int len = s.size();
    int start = 0, end = 0, maxLength = 0;
    unordered_map<char, int> mp;
    while(end < len) {
        if(mp.find(s[end]) != mp.end()) {
            start = max(start, mp[s[end]] + 1);
        }
        mp[s[end]] = end;
        maxLength = max(maxLength, end - start + 1);
        end++;
    }
    return maxLength;
}

int main() {

    return 0;
}