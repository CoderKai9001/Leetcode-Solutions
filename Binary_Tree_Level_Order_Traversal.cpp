#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if(root == NULL) return result;
    queue<TreeNode*> q1;
    queue<TreeNode*> q2;
    q1.push(root);
    vector<int> temp;
    while(!q1.empty()) {
        while(!q1.empty()) {
            temp.push_back(q1.front()->val);
            q2.push(q1.front());
            q1.pop();
        }
        result.push_back(temp);
        temp.clear();
        while(!q2.empty()) {
            TreeNode* temp = q2.front();
            if(temp->left != NULL) q1.push(temp->left);
            if(temp->right != NULL) q1.push(temp->right);
            q2.pop();
        }
    }
    return result;
}

int main() {

    return 0;
}