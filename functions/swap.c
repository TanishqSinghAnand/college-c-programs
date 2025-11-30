#include <stdio.h>
int main() {
    int a,b;
    a=6, b=5;
    printf("Before swap main: ");
    printf("A = %d \n B = %d \n", a,b);
    swap(a,b);
    printf("After swap main : ");
    printf("A = %d \n B = %d \n", a,b);
    return 0;
}

void swap(int a, int b){
    printf("Before swap : ");
    printf("A = %d \n B = %d \n", a,b);
    int c = a;
    a=b;
    b=c;
    printf("After swap : ");
    printf("A = %d \n B = %d \n", a,b);
// void swap(int,int);
}