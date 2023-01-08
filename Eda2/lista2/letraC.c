#include <stdio.h>
#include <stdlib.h>


struct letters
{
  int index;
  char  letra;
  int vezes;
};




void merge(struct letters arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 
    /* create temp arrays */
    struct letters L[n1], R[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i].vezes >= R[j].vezes) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there
    are any */
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
    are any */
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void mergeSort(struct letters arr[], int l, int r)
{
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;
 
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
 
        merge(arr, l, m, r);
    }
}




void maker(char *array ,int pos_atual, int tamanho_de_array,int repeticoes_de_alfa,struct letters v[],int *pos_de_index_struct);


int main(){

   struct letters vofL[100000];

   char v[100000];
   int tamanho=0;
   while(scanf("%c",&v[tamanho])!=EOF){
        tamanho+=1;
    }

    for(int i =0; i<tamanho ;i++){

    }
    

    
    int indexofstruct=0;
    int *ptr = &indexofstruct;
   maker(v,0,tamanho-1,1,vofL,ptr);
   mergeSort(vofL,0,indexofstruct-1);
   

   for(int i=0; i<indexofstruct;i++){
    printf("%d  %c  %d",vofL[i].vezes,vofL[i].letra,vofL[i].index);
    printf("\n");
   }

    return 0;
}


void maker(char *array ,int pos_atual, int tamanho_de_array,int repeticoes_de_alfa,struct letters v[],int *pos_de_index_struct){
  if(pos_atual==tamanho_de_array){
    
    return;
  }
    if(array[pos_atual]== array[pos_atual+1]){
        maker(array,pos_atual+1,tamanho_de_array,repeticoes_de_alfa+1,v,pos_de_index_struct);

    }

    else{
        v[*pos_de_index_struct].vezes=repeticoes_de_alfa;
        v[*pos_de_index_struct].letra=array[pos_atual];
        v[*pos_de_index_struct].index=pos_atual-repeticoes_de_alfa+1;
        *pos_de_index_struct=*pos_de_index_struct+1;
        maker(array,pos_atual+1,tamanho_de_array,1,v,pos_de_index_struct);
    }


     
   


                    
}
