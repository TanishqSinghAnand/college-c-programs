#include <stdio.h>

int main(){
    char c = 'A';
    for(int i = 1; i<=4;i++){


        for(int j = 1; j<= 4-i; j++){
            printf("\t");
        }
        for(int k = 1; k<=i;k++ ){
            printf("%c\t\t",c);
            c++;
        }
        printf("\n");
    }
    return 0;
}
