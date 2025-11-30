#include <stdio.h>

int main() {
    int a, b;
    float result;
    int choice;

    do {
        printf("\nEnter 2 numbers: \n");
        // Simplified input without checks
        scanf("%d%d", &a, &b);

        do {
            printf("\n--- Calculator ---\n");
            printf("Enter 1 for Add\n");
            printf("Enter 2 for Sub\n");
            printf("Enter 3 for Mul\n");
            printf("Enter 4 for Div\n");
            printf("Enter 5 to exit program\n");
            printf("Enter 6 to input new numbers\n");
            printf("Enter your choice: ");
            
            // Simplified choice input without checks
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    result = a + b;
                    printf("\nResult: %d + %d = %.0f\n", a, b, result);
                    break;
                case 2:
                    result = a - b;
                    printf("\nResult: %d - %d = %.0f\n", a, b, result);
                    break;
                case 3:
                    result = a * b;
                    printf("\nResult: %d * %d = %.0f\n", a, b, result);
                    break;
                case 4:
                    // Keep the basic division by zero check
                    if (b != 0) {
                        result = (float)a / b;
                        printf("\nResult: %d / %d = %.2f\n", a, b, result);
                    } else {
                        printf("\nError: Cannot divide by zero!\n");
                    }
                    break;
                case 5:
                    printf("\nExiting calculator.\n");
                    return 0;
                case 6:
                    break; 
                default:
                    printf("\nInvalid choice. Please select 1 through 6.\n");
            }
        // Repeat operation selection unless 6 is chosen (new numbers) or 5 (exit)
        } while (choice != 6 && (choice < 1 || choice > 4));

    } while (1);

    return 0;
}