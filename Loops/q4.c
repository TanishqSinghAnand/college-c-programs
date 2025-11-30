#include <stdio.h>
#include <stdbool.h>

bool check_arm(int a){
    int sum = 0;
    int org = a;
    for(int i = 0; a>0; i++){
        int d = a%10;
        sum += d*d*d;
        a/=10;
    }
    if(sum == org){
        return true;
    }else{
        return false;
    }

}

int main(){
    printf("All armstrong numbers from 1 to 1k : \n");
    for(int i = 1; i<=1000; i++){
        if(check_arm(i)){
            printf("%d\n",i);
        }
    }
    return 0;
}