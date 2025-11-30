#include <stdio.h>

// 1. INPUT ARRAY
void inputArray(int a[], int n){
    for(int i = 0; i < n; i++){
        printf("Enter element %d: ", i+1);
        scanf("%d", &a[i]);
    }
}

// 2. PRINT ARRAY
void printArray(int a[], int n){
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

// 3. LINEAR SEARCH
int linearSearch(int a[], int n, int key){
    for(int i = 0; i < n; i++){
        if(a[i] == key)
            return i;
    }
    return -1;
}

// 4. BINARY SEARCH (array must be sorted)
int binarySearch(int a[], int n, int key){
    int low = 0, high = n - 1, mid;

    while(low <= high){
        mid = (low + high) / 2;

        if(a[mid] == key)
            return mid;
        else if(key < a[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int main(){
    int a[50], n, key;

    printf("Enter size of array: ");
    scanf("%d", &n);

    inputArray(a, n);

    printf("\nArray elements are:\n");
    printArray(a, n);

    printf("\nEnter element to search: ");
    scanf("%d", &key);

    // --- Linear Search ---
    int pos = linearSearch(a, n, key);
    if(pos != -1)
        printf("Linear Search: Element found at index %d\n", pos);
    else
        printf("Linear Search: Element NOT found\n");

    // --- Binary Search ---
    // (Assuming array is already sorted for binary search)
    pos = binarySearch(a, n, key);
    if(pos != -1)
        printf("Binary Search: Element found at index %d\n", pos);
    else
        printf("Binary Search: Element NOT found\n");

    return 0;
}
