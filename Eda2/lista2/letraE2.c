#include <stdlib.h>

void swap(int *x, int *y) {
  int temp = *x;
  *x = *y;
  *y = temp;
}

void heapify(int *arr, int n, int i) {
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;
  if (left < n && arr[left] > arr[largest]) {
    largest = left;
  }
  if (right < n && arr[right] > arr[largest]) {
    largest = right;
  }
  if (largest != i) {
    swap(&arr[i], &arr[largest]);
    heapify(arr, n, largest);
  }
}

void heapsort(int *arr, int n) {
  for (int i = n / 2 - 1; i >= 0; i--) {
    heapify(arr, n, i);
  }
  for (int i = n - 1; i >= 0; i--) {
    swap(&arr[0], &arr[i]);
    heapify(arr, i, 0);
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
    
    heapsort(produtos,q_produtos);
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