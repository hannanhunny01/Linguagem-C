#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
   int dado;
   struct celula *prox;
} celula;

void insere_inicio (celula *le, int x){
    celula *novo = malloc(sizeof(celula));
    novo->dado=x;
    novo->prox=le->prox;
    le->prox= novo;

}
void insere_antes (celula *le, int x, int y){
    celula *novo = malloc(sizeof(celula));
    novo->dado=x;
    celula*ptr= le->prox;

    if(ptr->dado==y){
      novo->prox=ptr;
      le->prox=novo;
      return;
     }
     if(le->prox==NULL){
      le->prox=novo;
      return;
     }
     while(ptr->prox!=NULL){
      celula*temp=ptr;
      ptr=ptr->prox;
      if (ptr->dado==y){
         novo->prox=ptr;
         temp->prox=novo;
         return;

      }
     }
     ptr->prox=novo;
   

}