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

void solve(TreeNode* root, int* count, int max) {
    if(root == NULL) return;
    if(root->val >= max) {
        max = root->val;
        *count++;
    }
    solve(root->left, count, max);
    solve(root->right, count, max);
}

int goodNodes(TreeNode* root) {
    int result = 0;
    if(root == NULL) return result;
    int max = root->val;
    solve(root, &result, max);
    return result;
}

int main() {

    return 0;
}