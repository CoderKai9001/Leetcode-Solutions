#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
typedef struct stack {
    int* data;
    int top;
} stack;

stack* CreateStack(int size) {
    stack* S = (stack*)malloc(sizeof(stack));
    S->data = (int*)malloc(sizeof(int)*size);
    S->top = -1;
    return S;
}

void push(stack* s, int val) {
    s->data[++(s->top)] = val; 
}

int pop(stack* s) {
    if(s->top == -1) {
        printf("empty:(\n");
        return -1;
    }
    int retval;
    retval = s->data[s->top--];
    return retval;
}

void printstack(stack*s) {
    for(int i = 0; i < s->top+1; i++) {
        printf("%lld ", s->data[i]);
    }
    printf("\n");
}

char** buildArray(int* target, int targetSize, int n, int* returnSize) {
    char** ans = (char**)malloc(sizeof(char*)*2*n);
    for(int i = 0; i < 2*n; i++) ans[i] = (char*)malloc(sizeof(char)*6);
    int count = 0;
    *returnSize = 0;
    for(int i = 1; i <= n; i++) {
        if(target[count] == i) {
            ans[(*returnSize)] = "Push\0";
            (*returnSize)++;
            count++;
        } else {
            ans[(*returnSize)] = "Push\0";
            (*returnSize)++;
            ans[(*returnSize)] = "Pop\0";
            (*returnSize)++;
        }
        if(count == targetSize) break;
    }
    return ans;
}

int main() {    
    int n;
    scanf("%d", &n);
    int s[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &s[i]);
    }
    int* r;
    char** C = buildArray(s, n, 50, r);
    for(int i = 0; i < *r; i++) {
        if(C[i] == NULL) continue;
        printf("%s ", C[i]);
    }
    return 0;
}
