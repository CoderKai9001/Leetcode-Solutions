#include <bits/stdc++.h>
using namespace std;

void InsertEdge(vector<int> V[], int n1, int n2) {
    V[n1].push_back(n2);
    V[n2].push_back(n1);
}

void printGraph(vector<int> V[], int n) {
    for(int i = 0; i < n; i++) {
        cout << "vertex: " << i << " :";
        for(int j = 0; j < V[i].size(); j++) {
            cout << V[i][j] << "->";
        }
        cout << endl;
    }
}

void bfs(vector<int> V[], int n, vector<int>& visited, int startnode) {
    int queue[n];
    int front = 0;
    int rear = 0;
    visited[startnode] = 1;
    queue[rear++] = startnode;
    while(front != rear) {
        int currentnode = queue[front++];
        // cout << currentnode << "->";
        for(int j = 0; j < V[currentnode].size(); j++) {
            if(!visited[V[currentnode][j]]) {
                visited[V[currentnode][j]] = 1;
                queue[rear++] = V[currentnode][j];
            }
        }
    }
    // cout << endl;
}

bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
    vector<int> V[n];
    for(int i = 0; i < edges.size(); i++) {
        InsertEdge(V, edges[i][0], edges[i][1]);
    }
    vector<int> visited(n, 0);
    bfs(V, n, visited, source);
    if(visited[destination]) return true;
    else return false;
}

int main() {
    int n, e;
    cin >> n >> e;
    vector<int> V[n];
    int n1, n2;
    for(int i = 0; i < e; i++) {
        cin >> n1 >> n2;
        InsertEdge(V, n1, n2);
    }
    int startnode;
    cout << "enter the startnode: ";
    cin >> startnode;
    vector<int> visited(n, 0);
    bfs(V, n, visited, startnode);
    cout << "enter the startnode: ";
    cin >> startnode;
    for(int i = 0; i < visited.size(); i++) visited[i] = 0;
    bfs(V, n, visited, startnode);
    return 0;
}