#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        int len = stones.size();
        for(int i = 0; i < len; i++) {
            pq.push(stones[i]);
        }
        int x, y;
        while(pq.size() != 1) {
            x = pq.top();
            pq.pop();
            y = pq.top();
            pq.pop();
            if(x-y > 0) pq.push(x-y);
            else pq.push(y-x);
        }
        return pq.top();
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> V(n);
    for(auto it = V.begin(); it < V.end(); it++) {
        cin >> *it;
    }
    Solution obj;
    cout << obj.lastStoneWeight(V) << endl;
}