#include <bits/stdc++.h>
using namespace std;

bool checkstrinc(vector<int>& nums, int start, int end) {
    for(int i = 0; i < start-1; i++) {
        if(nums[i] >= nums[i+1]) return false;
    }
    for(int i = end+1; i < nums.size()-1; i++) {
        if(nums[i] >= nums[i+1]) return false;
    }
    return true;
}

int incremovableSubarrayCount(vector<int>& nums) {
    int count = 0;
    for(int i = 0; i < nums.size(); i++) {
        int start = 0;
        int end = i;
        for(int j = 0; j <= i; j++) {
            start = j;
            if(checkstrinc(nums, start, end)) count++;
        }
    }
}

int main() {
    vector<int> v;
    v.push_back(10);
    v.push_back(11);
    v.push_back(12);
    v.push_back(15);
    v.push_back(21);
    v.push_back(19);
    if(checkstrinc(v, 0, 2)) cout << "yes\n";
    else cout << "no\n";
    return 0;
}