#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next, *prev;
}Node;

Node* createNode(int data){
    Node* newNode= (Node*)malloc(sizeof(Node));
    newNode->data=data;
    newNode->next=newNode->prev= NULL;
    return newNode;
}

void trie(Node** debut, int data){
    Node* newNode= createNode(data);
    if(*debut== NULL || (*debut)->data >=data){
        newNode->next=*debut;
        if(*debut)(*debut)->prev=newNode;
        *debut=newNode;
        return;
    }
    Node*temp= *debut;
    while(temp->next && temp->next->data <data) temp=temp->next;
    newNode->next= temp->next;
    if(temp->next) temp->next->prev=newNode;
    temp->next= newNode;
    newNode->prev= temp;
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
    printf("Liste doublement chainee triee:");
    display(debut);
    return 0;
}