#include <bits/stdc++.h>
using namespace std;

void insertNode(vector<int> V[], int n1, int n2, vector<int>& count) {
    V[n1].push_back(n2);
    count[n2]++;
}

int findJudge(int n, vector<vector<int>>& trust) {
    vector<int> V[n];
    vector<int> count(n+1, 0);
    for(int i = 0; i < trust.size(); i++) insertNode(V, trust[i][0]-1, trust[i][1]-1, count);
    for(int i = 0; i < n; i++) {
        if(V[i].size() == 0 && count[i] == n-1) return i+1;
    }
    return -1;
}

void printgraph(vector<int> V[], int n) {
    for(int i = 0; i < n; i++) {
        cout << "vertex " <<i << ": ";
        for(int j = 0; j < V[i].size(); j++) {
            cout << V[i][j] << "->";
        }
        cout << endl;
    }
}

int main() {
    int n, e;
    cin >> n >> e;
    vector<int> V[n];
    int n1, n2;
    vector<vector<int>> edges(e);
    for(int i = 0; i < e; i++) {
        cin >> n1 >> n2;
        edges[i].push_back(n1);
        edges[i].push_back(n2);
    }
    cout << findJudge(n, edges) << endl;
    return 0;
}