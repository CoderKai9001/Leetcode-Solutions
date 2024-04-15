#include <bits/stdc++.h>
using namespace std;

int countNegatives(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    int i = 0;
    int j = m-1;
    int sum = 0;
    while(j >= 0 && i < m) {
        if(grid[j][i] < 0) {
            sum += n-i;
            j--;
        } else {
            i++;
        }
    }
    return sum;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }
    cout << countNegatives(v) << endl;
}