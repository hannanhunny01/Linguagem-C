#include <stdio.h>
#include <stdlib.h>

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
    for (i = 0; i < n; i++)
    {
        min_idx = i;
        for (j = i+1; j < n; j++)
        if (arr[j] < arr[min_idx])
            min_idx = j;
        if(min_idx!=i)
            swap(&arr[min_idx], &arr[i]);
    }
}

int main(){
    int v[1000];
    int count=0;
    while(scanf("%d",&v[count])!=EOF){
        count+=1;
    }

    selectionSort(v,count);
  
    for (int i =0;i<count;i++){
        printf("%d ",v[i]);
    }
    printf("\n");
    
    
    
 

    return 0;
}