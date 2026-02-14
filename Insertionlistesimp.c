#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* createNode(int data){
    Node* newNode= (Node*)malloc(sizeof(Node));
    newNode->data=data;
    newNode->next= NULL;
    return newNode;
}

void trie(Node** debut, int data){
    Node* newNode= createNode(data);
    if(*debut==NULL || (*debut)->data >=data){
        newNode->next= *debut;
        *debut= newNode;
        return;
    }
    Node* temp= *debut;
    while(temp->next && temp->next->data <data){
        temp= temp->next;
    }
    newNode->next= temp->next;
    temp->next= newNode;
}

void display(Node* debut){
    while(debut){
        printf("%d", debut->data);
        debut=debut->next;
    }
    printf("\n");
}

int main(){
    Node* debut=NULL;
    int n, val;
    printf("Combien d'elements voulez-vous entrer: ");
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        printf("Element %d: ", i+1);
        scanf("%d", &val);
        trie(&debut, val);
    }
    printf("Liste simplement chainee triee:");
    display(debut);
    return 0;
}