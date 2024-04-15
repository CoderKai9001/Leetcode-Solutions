#include <bits/stdc++.h>
using namespace std;

void insertEdge(vector<vector<int>>& V, int n1, int n2) {
    V[n1][n2] = 1;
    V[n2][n1] = 1;
}

void dfs(vector<vector<int>>& matrix, vector<int>& visited, int startnode) {
    int stk[matrix.size()];
    int top = -1;
    stack<int> s;
    s.push(startnode);
    visited[startnode] = 1;
    while(!s.empty()) {
        int currentnode = s.top();
        s.pop();
        for(int i = 0; i < matrix[currentnode].size(); i++) {
            if(matrix[currentnode][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                s.push(i);
            }
        }
    }
}

int findCircleNum(vector<vector<int>>& isConnected) {
    vector<int> visited(isConnected.size(), 0);
    int count = 0;
    for(int i = 0; i < isConnected.size(); i++) {
        if(!visited[i]) {
            dfs(isConnected, visited, i);
            count++;
        }
    }
    return count;
}

int main() {
    int n;
    int e;
    cout << "enter number of vertices: ";
    cin >> n;
    cout << "enter number of edges: ";
    cin >> e;
    vector<vector<int>> V(n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            V[i].push_back(0);
        }
    }
    int n1, n2;
    for(int i = 0; i < e; i++) {
        cin >> n1 >> n2;
        insertEdge(V, n1, n2);
    }
    cout << findCircleNum(V);
    return 0;
}