#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int> rightSideView(TreeNode* root) {
    vector<int> result;
    if(root == NULL) return result;
    queue<TreeNode*> q1;
    queue<TreeNode*> q2;
    q1.push(root);
    int temp;
    while(!q1.empty()) {
        while(!q1.empty()) {
            q2.push(q1.front());
            if(q1.size() == 1) temp = q1.front()->val;
            q1.pop();
        }
        result.push_back(temp);
        while(!q2.empty()) {
            TreeNode* tempnode = q2.front();
            if(tempnode->left != NULL) q1.push(tempnode->left); 
            if(tempnode->right != NULL) q1.push(tempnode->right); 
            q2.pop();
        }
    }
    return result;
}

int main() {

    return 0;
}