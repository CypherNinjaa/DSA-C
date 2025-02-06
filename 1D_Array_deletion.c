#include <stdio.h>

int main()
{
    int arr[5] = {10, 20, 30, 40, 50}; // Initial array
    int n = 5;                         // Number of elements
    int index;

    // Display the original array
    printf("Original Array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    // Input the index to delete
    printf("\nEnter the index to delete (0-4): ");
    scanf("%d", &index);

    // Shift elements to the left to overwrite the deleted element
    for (int i = index; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    n--; // Decrease the logical size of the array

    // Display the array after deletion
    printf("Array after deletion: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
