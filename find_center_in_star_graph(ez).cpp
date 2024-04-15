#include <bits/stdc++.h>
using namespace std;

int findCenter(vector<vector<int>>& edges) {
    if(edges[0][0] == edges[1][0]) return edges[0][0];
    else if(edges[0][0] == edges[1][1]) return edges[0][0];
    else if(edges[0][1] == edges[1][0]) return edges[0][1];
    else if(edges[0][1] == edges[1][1]) return edges[0][1];
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> V(n);
    int var;
    for(int i = 0; i < n; i++) {
        cin >> var;
        V[i].push_back(var);
        cin >> var;
        V[i].push_back(var);
    }
    cout << findCenter(V) << endl;
    return 0;
}