#include <bits/stdc++.h>
using namespace std;

bool comp(pair<char, int> p1, pair<char, int> p2) {
    if(p1.first < p2.first) return true;
    else return false;
}

string sortVowels(string s) {
    vector<char> vc;
    vector<int> vi;
    for(int i = 0; i < s.length(); i++) {
        if((s[i] == 'a')||(s[i] == 'e')||(s[i] == 'i')||(s[i] == 'o')||(s[i] == 'u')||(s[i] == 'A')||(s[i] == 'E')||(s[i] == 'I')||(s[i] == 'O')||(s[i] == 'U')) {
            pair<char, int> p = {s[i], i};
            vc.push_back(p.first);
            vi.push_back(p.second);
        }
    }
    sort(vc.begin(), vc.end());
    sort(vi.begin(), vi.end());
    for(int i = 0; i < vi.size(); i++) s[vi[i]] = vc[i];
    return s;
}

int main() {
    string s;
    cin >> s;
    cout << sortVowels(s) << endl;
    return 0;
}