#include <stdio.h>   // Including the standard input-output header file for functions like printf.
#include <stdlib.h>  // Including the standard library header for functions like malloc and exit.

/**
 * Counts the number of positive numbers in a dynamic array.
 *
 * @param arr: A pointer to the dynamic array.
 * @param size: The size of the dynamic array.
 * @return: The number of positive numbers in the array.
 */
int countPositiveNumbers(int* arr, int size) {
    // Base case: if the size is zero, there are no positive numbers.
    if (size == 0) {
        return 0;
    }

    // Recursive case: check if the first element is positive and add 1 to the count.
    // Then, recursively call the function with the remaining elements.
    int count = countPositiveNumbers(arr + 1, size - 1);
    if (*arr > 0) {
        count++;
    }

    return count;  // Returning the count of positive numbers.
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Dynamically allocate memory for the array.
    int* arr = (int*) malloc(size * sizeof(int));

    if (arr == NULL) {  // Checking for unsuccessful memory allocation.
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);  // Exiting the program with a failure status.
    }

    // Filling the array with random numbers.
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100 - 50;  // Generating random numbers between -50 and 49.
    }

    // Counting the number of positive numbers in the array.
    int positiveCount = countPositiveNumbers(arr, size);

    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("Number of positive numbers: %d\n", positiveCount);

    // Remember to free allocated memory to avoid memory leaks.
    free(arr);

    return 0;
}