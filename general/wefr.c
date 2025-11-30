//  WAP to enter any char and check if that char is vowel or not
// #include <stdio.h>

int main(){
    char c ;
    printf("Enter char :\n");
    scanf("%c",&c);
    if(c=='a' ||c=='e' ||c=='i' ||c=='o' ||c=='u' ){
        printf("its a vowel");
    }
    else{
        printf("not a vowel");
    }
    return 0;
}