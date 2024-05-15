#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& graph, vector<vector<int>>& result, vector<int>& path, int u) {
    path.push_back(u);
    if(u == graph.size()-1)  result.push_back(path);
    else{
        for(int i = 0; i < graph[u].size(); i++) {
            dfs(graph, result, path, graph[u][i]);
        }
    }
    path.pop_back();
}

vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    vector<vector<int>> result;
    vector<int> path;
    dfs(graph, result, path, 0);
    return result;
}

int main() {

}
