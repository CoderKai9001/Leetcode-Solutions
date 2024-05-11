#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    int len = nums.size();
    int start = 0;
    int end = len-1;
    vector<pair<int, int>> V(len);
    for(int i = 0; i < len; i++) {
        V[i].first = nums[i];
        V[i].second = i;
    }
    sort(V.begin(), V.end());
    for(int i = 0; i < len; i++) {
        cout << "{" << V[i].first << ", " << V[i].second << "}" << "\n";
    }
    while(start < end) {
        if(V[start].first + V[end].first < target) start++;
        else if(V[start].first + V[end].first > target) end--;
        else break;
    }
    vector<int> result(2);
    result[0] = V[start].second;
    result[1] = V[end].second;
    return result;
}

int main() {
    int n, tar;
    cin >> n >> tar;
    vector<int> V(n);
    for(int i = 0; i < n; i++) cin >> V[i];
    vector<int> res(2);
    res = twoSum(V, tar);
    cout << res[0] << "  " << res[1] << "\n";
    return 0;
}