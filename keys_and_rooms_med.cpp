#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<int>>& V, int n1, int n2) {
    V[n1].push_back(n2);
}

bool canVisitAllRooms(vector<vector<int>>& rooms) {
    vector<int> visited(rooms.size(), 0);
    int stack[rooms.size()];
    int top = -1;
    stack[++top] = 0;
    visited[0] = 1;
    while(top != -1) {
        int currentnode = stack[top--];
        for(int i = 0; i < rooms[currentnode].size(); i++) {
            if(!visited[rooms[currentnode][i]]) {
                visited[rooms[currentnode][i]] = 1;
                stack[++top] = rooms[currentnode][i];
            }
        }
    }
    for(int i = 0; i < visited.size(); i++) {
        if(visited[i] != 1) return false;
    }
    return true;
}

int main() {
    int n, e;
    cout << "enter number of vertices: ";
    cin >> n;
    cout << "enter number of edges: ";
    cin >> e;
    vector<vector<int>> rooms(n);
    int n1, n2;
    for(int i = 0; i < e; i++) {
        cin >> n1 >> n2;
        addEdge(rooms, n1, n2);
    }
    if(canVisitAllRooms(rooms)) cout << "yes\n";
    else cout << "no\n";
    return 0;
}