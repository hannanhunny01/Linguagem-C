#include <stdio.h>
#include <stdlib.h>



typedef struct celula {
   int dado;
   struct celula *prox;
} celula;

void imprime(celula *le) {
   celula *p;                         
   for (p = le->prox; p != NULL; p = p->prox){
      printf ("%d -> ", p->dado);}
      printf("NULL\n");
}

void imprime_rec (celula *le) {
   if (le->prox == NULL) {
      printf ("NULL\n");
      
   }else{
      printf ("%d -> ",le->prox->dado);
      imprime_rec (le->prox);
    
   }
}

void create(int *a,int size){
celula*last;
celula *first = malloc(sizeof(celula));
first->dado = a[0];
first->prox=NULL;
last=first;
for(int i=1;i<size;i++){
   celula *node = malloc(sizeof(celula));
   node->dado=a[i];
   node->prox=NULL;              
   last->prox=node;           
   last=node;        

}

}

void insere_inicio (celula *le, int x){
   
   celula *novo = malloc(sizeof(celula));
   novo->dado=x;
   novo->prox=le->prox;
   le->prox=novo;                    // funcao insere no segundo posicao
   
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
int remove_depois(celula *p){
    celula*temp=p->prox;
    if(p==NULL){
        return 0;
    }
    p->prox= temp->prox;
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


celula *busca (celula *le, int x){
    celula *ptr;
    ptr = le;
    while(ptr!=NULL && ptr->dado!=x){
        ptr=ptr->prox;

    }
    return ptr;
}
celula *busca_rec (celula *le, int x){
    if(le==NULL){
        return NULL;
    }
    if(le->dado==x){
        return le;
    }
    return busca_rec(le->prox,x);

}









int main(){
   int a[5] = {5,5,5,5,5};
   celula*last;
celula *first = malloc(sizeof(celula));
first->dado = a[0];
first->prox=NULL;
last=first;
for(int i=1;i<5;i++){
   celula *node = malloc(sizeof(celula));
   node->dado=a[i];
   node->prox=NULL;              
   last->prox=node;           
   last=node;        

}
insere_inicio(first,160);
insere_antes(first,33,5);
imprime(first);
remove_elemento(first,160);

imprime(first);


   


    return 0;
}