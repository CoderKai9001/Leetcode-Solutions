#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    double distanceToOrigin(int x, int y) {
        return sqrt((double)(x*x) + (double)(y*y));
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<pair<double, int>, int>, vector<pair<pair<double, int>, int>>, greater<pair<pair<double, int>, int>>> pq;
        for(int i = 0; i < points.size(); i++) {
            pq.push({{distanceToOrigin(points[i][0], points[i][1]), points[i][0]}, points[i][1]});
            cout << pq.top().first.first << " " << pq.top().first.second << " " << pq.top().second << "\n";
        }
        vector<vector<int>> result;
        while(k--) {
            vector<int> temp(2);
            temp[0] = pq.top().first.second;
            temp[1] = pq.top().second;
            pq.pop();
            result.push_back(temp);
        }
        return result;
    }
};

int main() {

    return 0;
}