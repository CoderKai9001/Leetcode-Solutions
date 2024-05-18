#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

void solve(TreeNode* root, TreeNode** prev, int* flag) {
    if(root == NULL) return;
    solve (root->left, prev, flag);
    if(*prev == NULL) {
        *prev = root; 
    } else {
        if(root->val <= (*prev)->val) {
            *flag = 1;
            return;
        }
        *prev = root;
    }
    solve (root->right, prev, flag);
}

bool isValidBST(TreeNode* root) {
    int flag = 0;
    TreeNode* prev = NULL;
    solve(root, &prev, &flag);
    if(flag == 1) return false;
    else return true;
}

int main() {

    return 0;
}