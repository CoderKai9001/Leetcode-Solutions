#include <bits/stdc++.h>
using namespace std;

void FlipColumn(vector<vector<int>>& grid, int k) {
    int len = grid.size();
    for(int i = 0; i < len; i++) {
        grid[i][k] = 1 - grid[i][k];
    }
}

void FlipRow(vector<vector<int>>& grid, int k) {
    int len = grid[0].size();
    for(int i = 0; i < len; i++) {
        grid[k][i] = 1 - grid[k][i];
    }
}

int matrixScore(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    int zero_count = 0;
    for(int i = 0; i < m; i++) {
        if(grid[i][0] == 0) {
            FlipRow(grid, i);
        }
    }
    for(int i = 0; i < n; i++) {
        zero_count = 0;
        for(int j = 0; j < m; j++) {
            if(grid[j][i] == 0) zero_count++;
        }
        if(zero_count > m/2) FlipColumn(grid, i);
    }
    // for(int i = 0; i < m; i++) {
    //     for(int j = 0; j < n; j++) {
    //         cout << grid[i][j] << " ";
    //     }
    //     cout << '\n';
    // }
    int prod = 1;
    int sum = 0;
    for(int i = n-1; i >=0; i--) {
        for(int j = 0; j < m; j++) {
           sum += (grid[j][i])*prod;
        }
        prod *= 2;
    }
    return sum;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    int res = matrixScore(grid);
    cout << '\n' << res << '\n';
    return 0;
}