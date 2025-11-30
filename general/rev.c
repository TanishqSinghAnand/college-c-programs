// Reverse of a 5 digit number
// #include <stdio.h>
int main(){
    int a,b;
    int sum=0;
    printf("Enter 5 digit number ");
    scanf("%d",&a);
    b=10000*(a%10);
    sum+= a%10;
    printf("%d",a%10);
    a/=10;
    b+=1000*(a%10);
    sum+= a%10;
    a/=10;
    b+=100*(a%10);
    sum+= a%10;
    a/=10;
    b+=10*(a%10);
    sum+= a%10;
    a/=10;
    b+=(a%10);
    sum+= a%10;
    a/=10;
    printf("Reversed number = %d",b);
    printf("\nSum of digits = %d",sum);
    return 0;
}