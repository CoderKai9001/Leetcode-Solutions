#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

void solve(TreeNode* root, int* count, int* result, int k) {
    if(root == NULL) return;
    solve(root->left, count, result, k);
    if(*count == k) {
        *result = root->val;
        (*count)++;
        return;
    } else (*count)++;
    solve(root->right, count, result, k);
}

int kthSmallest(TreeNode* root, int k) {
    int count = 0;
    int result = -1;
    solve(root, &count, &result, k-1);
    return (result);
}

int main() {

    return 0;
}