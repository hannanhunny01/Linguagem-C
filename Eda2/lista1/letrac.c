#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
   int dado;
   struct celula *prox;
} celula;

int remove_depois(celula *p){
    celula*temp=p->prox;
    if(p==NULL){
        return 1;
    }
    p->prox= temp->prox;
}


void remove_elemento (celula *head, int x){
    celula*ptr1,*ptr2;
    ptr1=head->prox;
    if(ptr1->dado==x){
        head->prox=ptr1->prox;
        return;
    }
    ptr2=ptr1;
    while(ptr1->prox!=NULL){ 
        ptr1=ptr1->prox;
        
        if(ptr1->dado==x){
            ptr1= ptr1->prox;
            ptr2->prox = ptr1;
            return;
        }
        ptr2=ptr1;
    }

}
void remove_todos_elemento (celula *head, int x){
    if(head->prox!=NULL){
        if(head->prox->dado!=x){
            remove_todos_elemento(head->prox,x);
        }
        else{
            head->prox=head->prox->prox;
        }
    }

}
