#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
int x;
struct Node * next;

}Node;



void insert_end(Node** root,int value){

    Node* new_node = malloc(sizeof(Node));
    if(new_node==NULL){
        exit(1);
    }
    new_node->next =NULL;
    new_node->x =value;
    if(*root==NULL){      // if root is null
        *root = new_node;
        return;
    }

    Node *current = *root;
    while (current->next!=NULL)
    {
      current = current->next;
    }
    current->next = new_node;
    


}

void deAllocate(Node **root){

    Node * curr = *root;
    while (curr != NULL){
      Node *aux =  curr;
      curr=curr->next;
      free(aux);

    }
    

    *root = NULL;
   



}


int main(){

  //  Node root;
  //  root.x =15;
 //   root.next =malloc(sizeof(Node));
 //   root.next->x =-2;
 //   root.next->next= malloc(sizeof(Node));
 //   root.next->next->x = 4343;
 //   root.next->next->next = NULL;
    
    Node* root = malloc(sizeof(Node));
    root->x=15;
    root->next=NULL;

    insert_end(&root,-2);
    insert_end(&root,-20);

    

   // Node *current = &root;
   // while(current!= NULL){
    //    printf("%d\n",current->x);
    //    current = current->next;  // 
   // }


    for(Node* current = root; current!=NULL;current= current->next){
          printf("%d\n",current->x);
    }



    //printf("%d",root.x);
    //printf("%d",root.next->x);
  //  free(root.next->next);
   // free(root.next);
    
    return 0;


}
//     array          linklist
//    int i =0;        Node *current = &root (primeiro);
//    i <n              current !=NULL
//    i++               current = current -> next;