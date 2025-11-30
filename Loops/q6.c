// power of number using do while loop
#include <stdio.h>

int main(){
    int pow , base, res=1;
    printf("Enter base : \n");
    scanf("%d",&base);
    printf("Enter power : \n");
    scanf("%d",&pow);
    do{
        res*=base;
        pow --;
    } while(pow>0);

    printf("answer = %d", res);
}