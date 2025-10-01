#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node* next;
} Node;

Node* insert_end(Node* head, int val) {
    Node* newNode = malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = NULL;
    if (!head) return newNode;
    Node* tmp = head;
    while (tmp->next) tmp = tmp->next;
    tmp->next = newNode;
    return head;
}

Node* remove_occ(Node* head, int val) {
    while (head && head->val == val) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
    Node* cur = head;
    while (cur && cur->next) {
        if (cur->next->val == val) {
            Node* temp = cur->next;
            cur->next = cur->next->next;
            free(temp);
        } else {
            cur = cur->next;
        }
    }
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
    int n, x, v;
    Node* head = NULL;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v);
        head = insert_end(head, v);
    }
    scanf("%d", &x);
    head = remove_occ(head, x);
    print_list(head);
    while (head) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
    return 0;
}