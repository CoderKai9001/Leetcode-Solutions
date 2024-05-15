#include <bits/stdc++.h>
using namespace std;

void solve(vector<int>& height, int left, int right, int* max) {
    if(left >= right) return;
    int minim;
    (height[left] < height[right]) ? minim = left : minim = right;
    int area = height[minim]*(right-left);
    if(area > *max) *max = area;
    cout << *max << '\n';
    if(left == minim) solve(height, left+1, right, max);
    else solve(height, left, right-1, max);
    return;
}

int maxArea(vector<int>& height) {
    int max = 0;
    int left = 0;
    int right = height.size()-1;
    solve(height, left, right, &max);
    return max;
}

int main() {
    int n;
    cin >> n;
    vector<int> height(n);
    for(int i = 0; i < n; i++) cin >> height[i];
    int max = maxArea(height);
    return 0;
}