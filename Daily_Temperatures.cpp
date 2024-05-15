#include <bits/stdc++.h>
using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) {
    vector<int> result(temperatures.size());
    stack<pair<int, int>> stk;
    int len = temperatures.size();
    stk.push({temperatures[0], 0});
    for(int i = 1; i < len; i++) {
        while(!stk.empty() && temperatures[i] > stk.top().first) {
            result[stk.top().second] = i - stk.top().second;
            stk.pop();
        }
        stk.push({temperatures[i], i});
    }
    while(!stk.empty()) {
        result[stk.top().second] = 0;
        stk.pop();
    }
    return result;
}

int main() {

    return 0;
}

