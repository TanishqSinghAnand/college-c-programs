#include <stdio.h>

// 1. PRINT ARRAY
void printArray(int a[], int n)
{
    printf("\n Array : \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

// 2. INPUT ARRAY
void inputArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &a[i]);
    }
    printArray(a, n);
}

// 3. SELECTION SORT
void selectionSort(int a[], int n)
{
    int min, temp;
    for (int i = 0; i < n - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[min])
                min = j;
        }
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
    printf("\nArray after Selection Sort:\n");
    printArray(a, n);
}

// 4. BUBBLE SORT
void bubbleSort(int a[], int n)
{
    int temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    printf("\nArray after Bubble Sort:\n");
    printArray(a, n);
}

// 5. INSERTION SORT
void insertionSort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int curr = a[i];
        int prev = i - 1;

        while (prev >= 0 && a[prev] > curr)
        {
            a[prev + 1] = a[prev];
            j--;
        }
        a[prev + 1] = curr;
    }
    printf("\nArray after Insertion Sort:\n");
    printArray(a, n);
}

int main()
{
    int n;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int a[n];
    inputArray(a, n);

    int choice;
    printf("\n1. Selection Sort\n2. Bubble Sort\n3. Insertion Sort\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        selectionSort(a, n);
        break;

    case 2:
        bubbleSort(a, n);
        break;

    case 3:
        insertionSort(a, n);
        break;

    default:
        printf("Invalid choice.\n");
        return 0;
    }

    return 0;
}
