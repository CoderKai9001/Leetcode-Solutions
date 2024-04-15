#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int val;
    struct ListNode *next;
}ListNode;

ListNode* createNode(int val) {
    ListNode* N = (ListNode*)malloc(sizeof(ListNode));
    N->next = NULL;
    N->val = val;
    return N;
}

void merge(ListNode* head, ListNode* l, ListNode* r, ListNode* m) {
    ListNode* sa1 = createNode(l->val);
    ListNode* sa2 = createNode(m->next->val);
    ListNode* temp = l;
    ListNode* sa1head = sa1;
    while(temp != m) {
        sa1->next = createNode(temp->next->val);
        sa1 = sa1->next;
        temp = temp->next;
    }
    sa1 = sa1head;
    temp = m->next; 
    ListNode* sa2head = sa2;
    while(temp != r->next) {
        sa2->next = createNode(temp->next->val);
        sa2 = sa2->next;
        temp = temp->next;
    }
    sa2 = sa2head;
    ListNode* N = head;
    while(sa1 != NULL && sa2 != NULL) {
        if(sa1->val < sa2->val) {
            N->val = sa1->val;
            sa1 = sa1->next;
            N = N->next;
        } else {
            N->val = sa2->val;
            sa2 = sa2->next;
            N = N->next;
        }
    }
    while(sa1 != NULL) {
        N->val = sa1->val;
        sa1 = sa1->next;
        N = N->next;
    }
    while(sa2 != NULL) {
        N->val = sa2->val;
        sa2 = sa2->next;
        N = N->next;
    }
    // while(sa1 != NULL) {
    //     printf("%d->", sa1->val);
    //     sa1 = sa1->next;
    // }
    // printf("\n");

    // while(sa2 != NULL) {
    //     printf("%d->", sa2->val);
    //     sa2 = sa2->next;
    // }
    // printf("\n");

}

ListNode* findMid(ListNode* l, ListNode* r) {
    ListNode* slow = l;
    ListNode* fast = l;
    while(fast != r) {
        slow = slow->next;
        fast = fast->next;
        if(fast != r) fast = fast->next;
    }
    return slow;
}

void mergesort(ListNode* l, ListNode* r) {
    if(l != NULL && l->next != r) {
        ListNode* mid = findMid(l, r);
        mergesort(l, mid);
        mergesort(mid->next, r);
        merge(l, l, r, mid);
    }
}

int main() {
    ListNode* N = createNode(14);
    N->next = createNode(13);
    N->next->next = createNode(11);
    N->next->next->next = createNode(12);
    N->next->next->next->next = createNode(10);
    ListNode* temp = N;
    while(temp != NULL) {
        printf("%d->", temp->val);
        temp = temp->next;
    }
    temp = N;
    while(temp->next != NULL) temp = temp->next;
    mergesort(N, temp);
    temp = N;
    while(temp != NULL) {
        printf("%d->", temp->val);
        temp = temp->next;
    }
    return 0;
}