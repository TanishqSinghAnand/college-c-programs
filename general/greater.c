#include <stdio.h>

void main(){
    int a,b;

    printf("Enter 2 numbers : \n");
    scanf("%d %d",&a,&b);
    if(a>b){
        printf("A is greater, a = %d \n",a);
    } else {
        printf("B is greater\n");
    }
    // return 0;
}