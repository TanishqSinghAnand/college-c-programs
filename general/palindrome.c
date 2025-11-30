#include <stdio.h>

int main(){
    int a, rev=0, org;
    printf("Enter a number : ");
    scanf("%d",&a);
    org=a;
    for(int i = 0; a!= 0; i++){
        rev = (rev*10) + (a%10);
        printf("%d\n",rev);
        a /=10;
    }
    if(org == org){
        printf("palindrome");
    } else{
        printf("🥀");
    }
    return 0;
}