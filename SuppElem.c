#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *prev, *next;
}Node;
typedef struct Node *liste;
Node* createNode(int data){
    Node *newNode= (Node*)malloc(sizeof(Node));
    newNode->data=data;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

void inserteEnd(Node **debut, int data){
    Node* newNode = createNode(data);
    if(*debut==NULL){
        *debut=newNode;
        return;
    }
    Node* temp = *debut;
    while(temp->next)temp=temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

void SuppOccu(liste *debut, int key){
    Node* temp= *debut;
    while (temp)
    {
        if(temp->data == key){
            Node* del=temp;
            if(temp->prev) temp->prev->next = temp->next;
            if(temp->next) temp->next->prev = temp->prev;
            if(temp == *debut) *debut= temp->next;
            free(del);
        }
        else{
            temp= temp->next;
        }
    }
    
}

void display(Node *debut){
    while(debut){
        printf("%d", debut->data);
        debut= debut->next;
    }
    printf("\n");
}

int main(){
    Node* debut = NULL;
    int n, val, x;
    printf("Combien d'elements voulez-vous inserer: ");
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        printf("Element %d : ",i+1);
        scanf("%d", &val);
        inserteEnd(&debut, val);
    }

    printf("Liste initiale:");
    display(debut);
    printf("Entrer l'element a supprimer:");
    scanf("%d", &x);
    SuppOccu(&debut, x);
    printf("Liste apres suppression: ");
    display(debut);
    return 0;
}