#include <stdio.h>

// --------------------------------------------------
// FUNCTION 1: PRINT ARRAY (Passing array to function)
// --------------------------------------------------
void printArray(int a[], int n){
    printf("Array elements: ");
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

// --------------------------------------------------
// FUNCTION 2: INPUT ARRAY
// --------------------------------------------------
void inputArray(int a[], int n){
    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
}

// --------------------------------------------------
// FUNCTION 3: CALL BY VALUE
// --------------------------------------------------
void callByValue(int x){
    x = x + 10;
    printf("Inside callByValue, x = %d (changed)\n", x);
}

// --------------------------------------------------
// FUNCTION 4: CALL BY REFERENCE
// --------------------------------------------------
void callByReference(int *x){
    *x = *x + 10;
    printf("Inside callByReference, x = %d (changed)\n", *x);
}

// --------------------------------------------------
// FUNCTION 5: FACTORIAL USING RECURSION
// --------------------------------------------------
int factorial(int n){
    if(n == 0)
        return 1; // base case
    return n * factorial(n - 1);
}

// --------------------------------------------------
// FUNCTION 6: FIBONACCI USING RECURSION
// --------------------------------------------------
int fibonacci(int n){
    if(n == 0 || n == 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// --------------------------------------------------
// FUNCTION 7: SUM OF DIGITS USING RECURSION
// --------------------------------------------------
int sumDigits(int n){
    if(n == 0)
        return 0;
    return (n % 10) + sumDigits(n / 10);
}

// --------------------------------------------------
// FUNCTION 8: REVERSE NUMBER USING RECURSION
//
// Trick: Build reverse from last digit upward
// Example: reverse(123) -> 3, then 32, then 321
//
// We carry a "rev" accumulator to store the reversed number
// --------------------------------------------------
int reverseNumber(int n, int rev){
    if(n == 0)
        return rev;
    return reverseNumber(n / 10, rev * 10 + (n % 10));
}

// --------------------------------------------------
// MAIN PROGRAM (FULL DEMONSTRATION)
// --------------------------------------------------
int main(){

    // ----------------------------------------------
    // Passing arrays
    // ----------------------------------------------
    int arr[5];
    inputArray(arr, 5);
    printArray(arr, 5);

    // ----------------------------------------------
    // Call by value vs reference
    // ----------------------------------------------
    int a = 10;

    printf("\n--- Call by Value ---\n");
    printf("Before: a = %d\n", a);
    callByValue(a);
    printf("After callByValue: a = %d (unchanged)\n", a);

    printf("\n--- Call by Reference ---\n");
    printf("Before: a = %d\n", a);
    callByReference(&a);
    printf("After callByReference: a = %d (changed)\n", a);

    // ----------------------------------------------
    // Recursion Examples
    // ----------------------------------------------
    int n;

    printf("\nEnter a number for factorial: ");
    scanf("%d", &n);
    printf("Factorial = %d\n", factorial(n));

    printf("\nEnter index for Fibonacci: ");
    scanf("%d", &n);
    printf("Fibonacci(%d) = %d\n", n, fibonacci(n));

    printf("\nEnter number to find sum of digits: ");
    scanf("%d", &n);
    printf("Sum of digits = %d\n", sumDigits(n));

    // ----------------------------------------------
    // Reverse Number using Recursion
    // ----------------------------------------------
    printf("\nEnter a number to reverse: ");
    scanf("%d", &n);
    printf("Reversed Number = %d\n", reverseNumber(n, 0));

    return 0;
}
