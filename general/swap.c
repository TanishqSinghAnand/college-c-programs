// #include <stdio.h>

int main(){
    int a,b;
    printf("Enter 2 number ");
    scanf("%d %d",&a,&b);
    printf("Before rev : \nA = %d\nB = %d\n",a,b);
    a=a+b;
    b=a-b;
    a=a-b;
    printf("After rev : \nA = %d\nB = %d",a,b);
    return 0;
}