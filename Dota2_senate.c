#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(Queue* q, char val) {
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

char dequeue(Queue* q) {
    if(q->front == NULL) {
        return -1;
    }

    Node* temp = q->front;
    char val = temp->data;

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

int CheckIfSame(Queue* q) {
    if(isEmpty(q)) return 1;
    char first = q->front->data;
    Node* temp = q->front->next;
    while(temp) {
        if(temp->data != first) return 0;
        temp = temp->next;
    }
    return 1;
}

char* predictPartyVictory(char* senate) {
    Queue* q1 = createQueue();
    for(int i = 0; i < strlen(senate); i++) {
        enqueue(q1, senate[i]);
    }
    char* str = (char*)malloc(sizeof(char)*8);
    Queue* q2 = createQueue();
    int rcount=0, dcount=0;
    char temp;
    while(1) {
        while(!isEmpty(q1)) {
            temp = dequeue(q1);
            if(temp == 'R') {
                if(dcount > 0) {
                    dcount--;
                } else {
                    enqueue(q2, temp);
                    rcount++;
                }
            } else if(temp == 'D') {
                if(rcount > 0) {
                    rcount--;
                } else {
                    enqueue(q2, temp);
                    dcount++;
                }
            }
        }
        if(CheckIfSame(q2)) {
            strcpy(str, q2->front->data == 'R' ? "Radiant" : "Dire");
            return str;
        }
        Queue* tempQ = q1;
        q1 = q2;
        q2 = tempQ;
    }
}

int main() {
    char s[100];
    scanf("%s", s);
    char* result = predictPartyVictory(s);
    printf("%s\n", result);
    free(result);
    return 0;
}