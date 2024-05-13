#include <bits/stdc++.h>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    int len = nums.size();
    vector<int> left(len);
    vector<int> right(len);
    left[0] = nums[0];
    for(int i = 1; i < len; i++) {
        left[i] = nums[i]*left[i-1];
    }
    right[len-1] = nums[len-1];
    for(int i = len-2; i >= 0; i--) {
        right[i] = nums[i]*right[i+1];
    }
    vector<int> res(len);
    res[0] = right[1];
    res[len-1] = left[len-2];
    for(int i = 1; i < len-1; i++) {
        res[i] = left[i-1]*right[i+1];
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    vector<int> res(n);
    res = productExceptSelf(arr);
    for(int i = 0; i < n; i++) cout << res[i] << ", ";
    cout << '\n';
    return 0;
}