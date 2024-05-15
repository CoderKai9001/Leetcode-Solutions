#include <bits/stdc++.h>
using namespace std;

bool isValid(string s) {
    stack<char> stk;
    int len = s.size();
    for(int i = 0; i < len; i++) {
        if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
            stk.push(s[i]);
        } else if(s[i] == ')') {
            if(stk.empty() || stk.top() != '(') return false;
            else stk.pop();
        } else if(s[i] == '}') {
            if(stk.empty() || stk.top() != '{') return false;
            else stk.pop();
        } else if(s[i] == ']') {
            if(stk.empty() || stk.top() != '[') return false;
            else stk.pop();
        }
    }
    if(stk.empty()) return true;
    else return false;
}

int main() {

    return 0;
}