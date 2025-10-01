#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node* next;
    struct node* prev;
} Node;

Node* insert_sorted(Node* head, int val) {
    Node* newNode = malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = NULL;
    newNode->prev = NULL;
    if (!head || val < head->val) {
        newNode->next = head;
        if (head) head->prev = newNode;
        return newNode;
    }
    Node* cur = head;
    while (cur->next && cur->next->val < val) {
        cur = cur->next;
    }
    newNode->next = cur->next;
    newNode->prev = cur;
    if (cur->next) cur->next->prev = newNode;
    cur->next = newNode;
    return head;
}

void print_list(Node* head) {
    Node* tmp = head;
    while (tmp) {
        printf("%d ", tmp->val);
        tmp = tmp->next;
    }
    printf("\n");
}

void free_list(Node* head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int n, v;
    Node* head = NULL;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v);
        head = insert_sorted(head, v);
    }
    print_list(head);
    free_list(head);
    return 0;
}