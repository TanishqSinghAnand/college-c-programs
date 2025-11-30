#include <stdio.h>
int main(){
    int a,b,c;
    printf("Enter 3 sides of triangles");
    scanf("%d %d %d",&a,&b,&c);
    if(a==b && b==c){
        printf("Equilateral Triangle");
    } else if( a==b && a!= c){
        printf("Iso");
    } else if(a!=b && b!=c && c!=a){
        printf("Scalene");
    }
    return 0;
}