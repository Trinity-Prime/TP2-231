#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node* next;
} Node;

Node* insert_head(Node* last, int val) {
    Node* newNode = malloc(sizeof(Node));
    newNode->val = val;
    if (!last) {
        newNode->next = newNode;
        return newNode;
    }
    newNode->next = last->next;
    last->next = newNode;
    return last;
}

Node* insert_tail(Node* last, int val) {
    Node* newNode = malloc(sizeof(Node));
    newNode->val = val;
    if (!last) {
        newNode->next = newNode;
        return newNode;
    }
    newNode->next = last->next;
    last->next = newNode;
    return newNode;
}

void print_list(Node* last) {
    if (!last) return;
    Node* p = last->next;
    do {
        printf("%d ", p->val);
        p = p->next;
    } while (p != last->next);
    printf("\n");
}

void free_list(Node* last) {
    if (!last) return;
    Node* p = last->next;
    Node* next;
    do {
        next = p->next;
        free(p);
        p = next;
    } while (p != last->next);
}

int main() {
    Node* last = NULL;
    int n, v, m, w;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v);
        last = insert_tail(last, v);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &w);
        last = insert_head(last, w);
    }
    print_list(last);
    free_list(last);
    return 0;
}