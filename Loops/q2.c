#include <stdio.h>

int main()
{
    for (int i = 1; i <= 4; i++)
    {
        // if(i==5){
        //     break;
        // }
        for (int j = 1; j <= i; j++)
        {
            printf("*");
        }
        for (int k = 1; k < 9 - (2 * i); k++)
        {
            printf(" ");
        }
        for (int m = 1; m <= i; m++)
        {
            if (m == 4)
            {
                break;
            }
            printf("*");
        }
        printf("\n");
    
    return 0;
}