#include<stdio.h>

int main(){

    int arr[10];
    for(int i=0; i<10; i++){
        printf("Enter element %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    printf("Length of the array is: %d\n", sizeof(arr)/sizeof(arr[0]));
    return 0;
}