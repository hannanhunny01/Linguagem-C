#include <stdio.h>
#include<stdlib.h>


// onde k e o posicao de 

void merge(int *a ,int n1,int *arr,int *k){

  if (n1==0){
      return;
    }
    int i=0;
    int j=0;
    int m =0;  // m for iteracao de  temp array 
    int temp[*k+n1];
    
     while (i < n1 && j < *k) {
        if (a[i] <= arr[j]) {
            temp[m] = a[i];
            i++;m++;
        }
        else {
            temp[m] = arr[j];
            j++;m++;
        }
        
    }
    while (i < n1) {
        temp[m] = a[i];
        i++;m++;
    }
 
    while (j < *k) {
        temp[m] = arr[j];
        j++;m++;
    }
  // copiando temp 
    for(int i=0; i<m;i++){
      arr[i]=temp[i];
      
    }
     *k = m;

   return;


}

int main(){
  int v[1000000];
  int pos_atual=0;
  
  int size_temp;

  scanf("%d",&pos_atual);
  for(int i=0;i<pos_atual;i++){
    scanf("%d",&v[i]);
  }
  int *ptr =&pos_atual;
  
  int j=0;
  do{
    scanf("%d",&size_temp);
    int *arr = (int*)malloc(sizeof(int)*size_temp);
    for(int i=0;i<size_temp;i++){
      scanf("%d",&arr[i]);

    }
    merge(arr,size_temp,v,ptr);
    j+=1;
    
    
     
  } while(j<7);

  for (int i=0; i<pos_atual; i++){
    printf("%d   ",v[i]);
  }
  printf("\n");



   


    return 0;
}