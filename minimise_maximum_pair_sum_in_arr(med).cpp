#include <bits/stdc++.h>
using namespace std;

int minPairSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int maxPairSum = 0;
    for (int i = 0; i < n / 2; ++i) {
        maxPairSum = max(maxPairSum, nums[i] + nums[n - 1 - i]);
    }
    return maxPairSum;
}

int main() {
    int n;
    cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i++) {
        int val;
        cin >> val;
        v.push_back(val);
    }
    cout <<  minPairSum(v);
    return 0;
}