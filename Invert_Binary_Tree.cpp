#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

TreeNode* insert(TreeNode* root, int val) {
    TreeNode* new_TreeNode = new TreeNode(val);
    if(root == NULL) {
        root = new_TreeNode;
        return root;
    }
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        TreeNode* temp = q.front();
        q.pop();
        if(temp->left == NULL) {
            temp->left = new_TreeNode;
            return root;
        } else if(temp->right == NULL) {
            q.push(temp->left);
            temp->right = new_TreeNode;
            return root;
        } else {
            q.push(temp->left);
            q.push(temp->right);
        }
    }
    return root;
}

void inorder(TreeNode* root) {
    if(root == NULL) return;
    inorder(root->left);
    cout << root->data << "->";
    inorder(root->right);
}
 //! soln start:
void solve(TreeNode* root) {
    if(root == NULL) return;
    solve(root->left);
    solve(root->right);
    if(root->left != NULL && root->right != NULL) {
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
    } else if(root->left != NULL && root->right == NULL) {
        root->right = root->left;
        root->left = NULL;
    } else if(root->left == NULL && root->right != NULL) {
        root->left = root->right;
        root->right = NULL;
    }
}

TreeNode* invertTree(TreeNode* root) {
    solve(root);
    return root;
}
//! soln end:
int main() {
    TreeNode* root = NULL;
    root = insert(root, 4);
    root = insert(root, 2);
    root = insert(root, 7);
    root = insert(root, 1);
    root = insert(root, 3);
    root = insert(root, 6);
    root = insert(root, 9);
    inorder(root);
    cout << '\n';
    root = invertTree(root);
    inorder(root);
    cout << '\n';                                    
    return 0;
}