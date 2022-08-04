#include <stdio.h>
  //# e = elemen looking for , l =ledft index , r =right index
  int binary_search(int a[],int e, int l ,int r);


int main() {
  int limitofarray, numbers;
  int limitofnumbers,numbers2;

  printf("Type limit: ");
  
  scanf("%d%d", &limitofarray,&limitofnumbers);
  
  int *arr = (int *)malloc(limitofarray * sizeof(int));
  
  int *arr2 =(int *)malloc(limitofnumbers * sizeof(int));

  for (int i = 0; i < limitofarray; i++) {
    scanf("%d", &numbers);
    arr[i] = numbers;
  }
  
  for (int i = 0; i < limitofnumbers; i++) {
    scanf("%d", &numbers2);
    arr2[i] = numbers2;
  }
  
  //for (int i = 0; i < limitofarray; i++) {
//    printf("%d", arr[i]);
 // }
  for(int j=0;j<limitofnumbers;j++){
    
   printf("%d\n",binary_search(arr, arr2[j], 0,limitofarray));
  
  
    }



  

}
 int binary_search(int a[],int e, int l ,int r){
    int mid =l+(r-1)/2;
    if(l>r){
      return -1;
    }
    if (a[mid] ==e){
      return mid;
    }
    else if(a[mid]>e){
      return binary_search(a,e,l,mid-1);
    }else{
      return binary_search(a,e,mid+1,r);
    }
  }
