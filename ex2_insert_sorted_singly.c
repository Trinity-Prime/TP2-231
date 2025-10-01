#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node* next;
} Node;

Node* insert_sorted(Node* head, int val) {
    Node* newNode = malloc(sizeof(Node));
    newNode->val = val;
    if (!head || val < head->val) {
        newNode->next = head;
        return newNode;
    }
    Node* cur = head;
    while (cur->next && cur->next->val < val) {
        cur = cur->next;
    }
    newNode->next = cur->next;
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

int main() {
    int n, v;
    Node* head = NULL;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v);
        head = insert_sorted(head, v);
    }
    print_list(head);
    while (head) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
    return 0;
}