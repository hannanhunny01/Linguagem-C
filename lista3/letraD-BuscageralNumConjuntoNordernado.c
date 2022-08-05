#include <stdio.h>
#include <stdlib.h>

int unsortedArray(int arr[],int s,int n);
  
int main(){
    int n, m, i;
    scanf("%d %d", &n, &m);
    int *arr = malloc(n * sizeof(int)), *arr2 = malloc(m * sizeof(int));
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (i = 0; i < m; i++)
    {
        scanf("%d", &arr2[i]);
    }
  

for (int i=0; i<m;i++){
 int index = unsortedArray(arr,n,arr2[i]);
  printf("%d\n",index);
}

return 0;
  


  
  
  }

int unsortedArray(int arr[],int s,int n){
for(int i=0;i<s;i+=5){  // notice the increment in i here...
    if(arr[i] == n)   
        return i;
    
/* check the next four indexes as well as if arr[i] is the last element of the array */ 
    else if( arr[i+1] == n && i+1 < s)
        return i+1;
    else if(arr[i+2] == n && i+2 < s)
        return i+2;
    else if(arr[i+3] == n && i+3 < s)
        return i+3;
    else if(arr[i+4] == n && i+4 < s)
        return i+4;
}
 return -1;
  }