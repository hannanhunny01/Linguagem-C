#include <stdio.h>

int median(int a, int b, int c) {
  if ((a - b) * (c - a) >= 0) {
    return a;
  } else if ((b - a) * (c - b) >= 0) {
    return b;
  } else {
    return c;
  }
}

int partition(int *arr, int low, int high) {
  int pivot = median(arr[low], arr[high], arr[(low + high) / 2]);
  int i = low - 1;
  int j = high + 1;
  while (1) {
    do {
      i++;
    } while (arr[i] < pivot);
    do {
      j--;
    } while (arr[j] > pivot);
    if (i >= j) {
      return j;
    }
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
  }
}

void quicksort(int *arr, int low, int high) {
  if (low < high) {
    int pivot_index = partition(arr, low, high);
    quicksort(arr, low, pivot_index);
    quicksort(arr, pivot_index + 1, high);
  }
}
int main(void) {
  //  int produtos[33554432];
    int * produtos = (int*)malloc(33554432*sizeof(int));
    int q_produtos;
    int count=0;
    int pagina;
    int q_por_pagina;

    scanf("%d%d%d",&q_produtos,&pagina,&q_por_pagina);
    for (int i = 0; i < q_produtos; i++){
        scanf("%d", &produtos[i]);}
    
    quicksort(produtos,0,q_produtos-1);
  //  for(int i=0; i<q_produtos;i++){
  //      printf("%d  ",produtos[i]);

   // }
  //count=count-q_por_pagina;
  
    for(int i=0; i<q_por_pagina;i++){
        if ((pagina*q_por_pagina)+i ==q_produtos){
          break;
        }
        printf("%d",produtos[((pagina*q_por_pagina)+i)]);
        printf("\n");
 //       printf("valor count %d",count);
      
    }

  
  return 0;
  }