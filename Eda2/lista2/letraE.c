// mergesort algorithm



#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
  
/* This function takes last element as pivot, places
the pivot element at its correct position in sorted
array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot */
int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // pivot
    int i
        = (low
           - 1); // Index of smaller element and indicates
                 // the right position of pivot found so far
  
    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than the pivot
        if (arr[j] < pivot) {
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
  
/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void quickSort(int arr[], int low, int high)
{
    if (low < high) {
        /* pi is partitioning index, arr[p] is now
        at right place */
        int pi = partition(arr, low, high);
  
        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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
    
    quickSort(produtos,0,q_produtos-1);
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


  