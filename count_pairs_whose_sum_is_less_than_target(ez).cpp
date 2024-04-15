#include <bits/stdc++.h>
using namespace std;

int countPairs(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int count = 0;
    int l = 0;
    int r = nums.size()-1;
    while(l < r) {
        if(nums[l]+nums[r] < target) {
            count += r-l;
            l++;
        }
        if(nums[l]+nums[r] >= target) {
            r--;
        }
    }
    return count;
}

int main() {
    int n, tar;
    cin >> n;
    cin >> tar;
    vector<int> v;
    int val;
    for(int i=0; i<n; i++) {
        cin >> val;
        v.push_back(val);
    }
    cout << countPairs(v, tar) << endl;
    return 0;
}