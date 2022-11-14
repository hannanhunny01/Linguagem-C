#include <stdio.h>

int main(){
    
    int b[5]= {1,2,3,4,5};
    printf("%d\n",*b+2);

   // printf("%d\n",&b);

    int * p = malloc(sizeof(int)*10);

    p[1] = 55;

    printf("%d\n",*(p+1));





    return 0;
}