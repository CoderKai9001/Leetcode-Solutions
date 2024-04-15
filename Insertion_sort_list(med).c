#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode{
    int data;
    struct ListNode* next;
}ListNode;

ListNode* createListNode(int data) {
    ListNode* N = (ListNode*)malloc(sizeof(ListNode));
    N->data = data;
    N->next = NULL;
    return N;
}

//function to create a linkedlist from an array 
ListNode* CreateListFromArray(int* arr, int n) {
    ListNode* root = createListNode(arr[0]);
    ListNode* current = root;
    for(int i = 1; i < n; i++) {
        current->next = createListNode(arr[i]);
        current = current->next;
    }
    return root;
}

struct ListNode* insertionSortList(struct ListNode* head) {
    struct ListNode dummy;
    struct ListNode *prev = &dummy, *curr = head;

    dummy.next = head;

    while (curr) {
        if (curr->next && (curr->next->data < curr->data)) {
            while (prev->next && (prev->next->data < curr->next->data)) {
                prev = prev->next;
            }

            struct ListNode *temp = prev->next;
            prev->next = curr->next;
            curr->next = curr->next->next;
            prev->next->next = temp;

            prev = &dummy;
        } else {
            curr = curr->next;
        }
    }

    return dummy.next;
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
    ListNode* root = CreateListFromArray(arr, n);
    root = insertionSortList(root);
    ListNode* current = root;
    while(current->next != NULL) {
        printf("%d->", current->data);
        current = current->next;
    }
    printf("%d\n", current->data);
    return 0;
}