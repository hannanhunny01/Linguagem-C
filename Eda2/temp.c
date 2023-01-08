void merge(int *arr,int e,int meio,int d ){
  int *vetorauxliar = malloc((d-e+1)*sizeof(int));
  int i =e;
  int j = meio+1;
  int k=0;
  while(i<=meio && j<=d){
    if(arr[i]<=arr[j]){
      vetorauxliar[k++]=arr[i++];
      
    } else{
      vetorauxliar[k++]=arr[j++];      //x++  usar x primeiro depois x++
    }
  }
  while(i<=meio){
    vetorauxliar[k++]=arr[i++];
  }
  while(j<=d){
        vetorauxliar[k++]=arr[j++];

  }
  k=0;
  for(i=e; i<=d; i++){
      arr[i] = vetorauxliar[k++];
    }
  
}
void mergesort(int arr[],int e,int d){
  if (e<=d){
    return;
    }
    int meio = (e+d)/2;
    mergesort(arr, e, meio);
    mergesort(arr, meio+1, d);
    merge(arr,e,meio,d);    //pega os dois vetores e junta
    
  
}

