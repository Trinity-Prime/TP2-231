#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = newNode;
    return newNode;
}

void insertHead(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != *head) temp = temp->next;
    temp->next = newNode;
    newNode->next = *head;
    *head = newNode;
}

void insertTail(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != *head) temp = temp->next;
    temp->next = newNode;
    newNode->next = *head;
}

void display(Node* head) {
    if (head == NULL) return;
    Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    Node* head = NULL;
    int n, val;
   
    printf("Combien d'elements voulez-vous inserer en queue ? ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Element %d : ", i+1);
        scanf("%d", &val);
        insertTail(&head, val);
    }

    printf("Liste apres insertion en queue : ");
    display(head);

    printf("Entrer un element a inserer en tete : ");
    scanf("%d", &val);
    insertHead(&head, val);

    printf("Liste apres insertion en tete : ");
    display(head);

    return 0;
}