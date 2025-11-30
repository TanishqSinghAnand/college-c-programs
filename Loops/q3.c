#include <stdio.h>

int main(){
    float sum = 0;
    float n ,pow=1,fact =1;
    printf("Enter n \n");
    scanf("%f",&n);
    printf("n = %d\n",n);
    for(int i = 1; i<=n ; i++){
        printf("i = %d  , pow = %d",i,pow);
        for(int j  = 1; j<=i;j++){
            pow = pow* i;
            printf("i = %d , j = %d , pow = %f\n",i,j,pow);
        }
        for(int k = 1; k<=i; k++){
            fact =fact* k;
            printf("i = %d , k = %d , fact = %f\n",i,k,fact);
        }
        sum +=  (pow/fact);
        pow = 1;
        fact = 1;
    }
    printf("Sum of series = %f",sum);
}