#include <stdio.h>

int main(){
    // Program to print the fibonacci series

    int n2nd= 0, n1st = 1, next = 0, total;
    printf("Enter the number of terms : ");
    scanf("%d", &total);

    while(total > 0){
        next = n2nd + n1st;
        printf("%d ", next);
        n2nd = n1st;
        n1st = next;
        total--;
    }

    return 0;
}