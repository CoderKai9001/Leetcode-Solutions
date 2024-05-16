#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if((root->val < p->val && root->val > q->val) || (root->val > p->val && root->val < q->val) || (root->val == p->val) || (root->val == q->val)) return root;
    else if(root->val < p->val && root->val < q->val) return lowestCommonAncestor(root->right, p, q);
    else if(root->val > p->val && root->val > q->val) return lowestCommonAncestor(root->left, p, q);
    return NULL; // pointless. Just to get rid of the eye-sore of a warning.
}

int main() {

    return 0;
}