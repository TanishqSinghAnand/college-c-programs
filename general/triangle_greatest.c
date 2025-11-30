#include <stdio.h>
int main(){
    int a,b,c;
    printf("Enter 3 sides of a scalene triangles");
    scanf("%d %d %d",&a,&b,&c);
    if(a>b && b>c){
        printf("A is greatest");
    } else if( b>a && a> c){
        printf("B is greatest");
    } else{
        printf("C is greatest");
    }
    return 0;
}



/*
A-Z = 65-90
a-z = 97- 122
0-9 = 48-57
*/