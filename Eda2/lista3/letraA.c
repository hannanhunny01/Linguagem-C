#include <stdio.h>
#include <stdlib.h>

int v[1001];
int main(){

       

      int size;
      scanf("%d",&size);

      int best =0, ans =0;
      for (int i=0;i<size;i++){

        int x;
        scanf(" %d",&x);
         //  increase value at v[x] by 1

        if(++v[x]>best){
            best=v[x];
            ans=x;

        }else if(v[x]== best && ans<x){

            ans = x;
        }
        



      }
        printf("%d\n",ans);

    return 0;
}