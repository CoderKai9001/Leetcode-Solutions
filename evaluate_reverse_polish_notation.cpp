#include <bits/stdc++.h>
using namespace std;

int evalRPN(vector<string>& tokens) {
    int n = tokens.size();
    if(n == 1) {
        return stoi(tokens[0]);
    }
    stack<string> stk;
    for(int i = n-1; i >= 0; i--) {
        stk.push(tokens[i]);
    }
    int num1, num2;
    num1 = stoi(stk.top());
    stk.pop();
    num2 = stoi(stk.top());
    stk.pop();
    cout << num1 << ", " << num2 << '\n';
    stack<int> stk2;
    while(!stk.empty()) {
        if(stk.top() != "+" && stk.top() != "-" && stk.top() != "*" && stk.top() != "/") {
            if(num1 != -5555) stk2.push(num1);
            num1 = num2;
            num2 = stoi(stk.top());
            stk.pop();
        }
        else {
            if(stk.top() == "+") {
                num2 = (num1 + num2);
                if(!stk2.empty()) {
                    num1 = stk2.top();
                    stk2.pop();
                } else {
                    num1 = -5555;
                }
                stk.pop();
            } else if(stk.top() == "-") {
                num2 = (num1 - num2);
                if(!stk2.empty()) {
                    num1 = stk2.top();
                    stk2.pop();
                } else {
                    num1 = -5555;
                }
                stk.pop();
            } else if(stk.top() == "*") {
                num2 = (num1 * num2);
                if(!stk2.empty()) {
                    num1 = stk2.top();
                    stk2.pop();
                } else {
                    num1 = -5555;
                }
                stk.pop();
            } else if(stk.top() == "/") {
                num2 = (num1 / num2);
                if(!stk2.empty()) {
                    num1 = stk2.top();
                    stk2.pop();
                } else {
                    num1 = -5555;
                }
                stk.pop();
            }
        }
    }
    return num2;
}

int main() {

    return 0;
}