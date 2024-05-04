#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

typedef struct TreeNode TreeNode;

typedef struct Node {
    TreeNode* data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

TreeNode* CreateTreeNode(int data) {
    TreeNode* T = (TreeNode*)malloc(sizeof(TreeNode));
    T->left = NULL;
    T->right = NULL;
    T->val = data;
    return T;
}

Node* createnode(TreeNode* N) {
    Node* new = (Node*)malloc(sizeof(Node));
    new->data = N;
    new->next = NULL;
    return new;
}

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(Queue* q, TreeNode* val) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = val;
    temp->next = NULL;

    if(q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }

    q->rear->next = temp;
    q->rear = temp;
}

TreeNode* dequeue(Queue* q) {
    if(q->front == NULL) {
        return NULL;
    }

    Node* temp = q->front;
    TreeNode* val = temp->data;

    q->front = q->front->next;

    if(q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);

    return val;
}

int isEmpty(Queue* q) {
    return q->front == NULL;
}

void printqueue(Queue* Q) {
    if(Q->front == NULL) return;
    for(Node* i = Q->front; i != Q->rear->next; i = i->next) {
        printf("%d ", i->data->val);
    }
    printf("\n");
}

int deepestLeavesSum(struct TreeNode* root) {
    int levelsum = 0;
    if(root == NULL) return levelsum;

    Queue* Q = createQueue();
    Queue* Q2 = createQueue();
    enqueue(Q, root);
    TreeNode* temp;

    while(1) {
        levelsum = 0;
        while(Q->front != NULL) {
            temp = dequeue(Q);
            levelsum += temp->val;
            if(temp->left != NULL) {
                enqueue(Q2, temp->left);
            }
            if(temp->right != NULL) {
                enqueue(Q2, temp->right);
            }
        }
        if(Q2->front == NULL && Q2->rear == NULL) break;
        while(Q2->front != NULL) {
            temp = dequeue(Q2);
            enqueue(Q, temp);
        }
    }
    return levelsum;
}

int main() {
    TreeNode* root = CreateTreeNode(6);
    root->left = CreateTreeNode(7);
    root->right = CreateTreeNode(8);
    root->left->left = CreateTreeNode(2);
    root->left->right = CreateTreeNode(7);
    root->right->left = CreateTreeNode(1);
    root->right->right = CreateTreeNode(3);
    root->left->left->left = CreateTreeNode(9);
    root->left->right->left = CreateTreeNode(1);
    root->left->right->right = CreateTreeNode(4);
    root->right->right->right = CreateTreeNode(5);
    printf("%d\n",deepestLeavesSum(root));
    return 0;
}