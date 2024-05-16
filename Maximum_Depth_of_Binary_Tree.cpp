#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

int maxDepth(TreeNode* root) {
    if(root == NULL) return 0;
    queue<TreeNode*> q1;
    queue<TreeNode*> q2;
    int level = 0;
    q1.push(root);
    while(!q1.empty()) {
        while(!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        level++;
        while(!q2.empty()) {
            TreeNode* temp = q2.front();
            if(temp->left != NULL) q1.push(temp->left);
            if(temp->right != NULL) q1.push(temp->right);
            q2.pop();
        }
    }
    return level;
}

int main() {

    return 0;
}