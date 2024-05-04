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

int maxDepth(char* s) {
    stack* S = CreateStack(strlen(s)+1);
    int max = 0;
    int count = 0;
    for(int i = 0; i < strlen(s); i++) {
        if(s[i] == '(' || s[i] == ')') {
            push(S, s[i]);
        }
    }
    while(S->top != -1) {
        int popped = pop(S);
        if(popped == ')') {
            count++;    
            if(max < count) max = count;
        }   
        if(popped == '(') count--;
    }
    return max;
}

int main() {
    char s[100];
    scanf("%s", s);
    printf("%lld\n", maxDepth(s));
    return 0;
}