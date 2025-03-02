#include <stdio.h>

// Function prototypes
void input(int *, int);
void display(int *, int);
void insertion(int *, int *, int, int);
void delete_element(int *, int *);

int main()
{
    int arr[50]; // Maximum size 50
    int *ptr = arr;
    int index, value, choice;
    int size;
    int *sizes = &size;

    while (1)
    {
        printf("\n1. Enter size of array\n2. Enter elements to array\n3. Display array\n4. Insert value to array\n5. Delete element from array\n6. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the size of array: ");
            scanf("%d", &size);
            break;
        case 2:
            input(ptr, size);
            break;
        case 3:
            display(ptr, size);
            break;
        case 4:
            insertion(ptr, sizes, index, value);
            break;
        case 5:
            delete_element(ptr, sizes);
            break;
        case 6:
            return 0;
        default:
            printf("Invalid input!\n");
            break;
        }
    }

    return 0;
}

// Array input function
void input(int *ptr, int size)
{
    if (size <= 0)
    {
        printf("Enter valid size!\n");
        return;
    }
    for (int i = 0; i < size; i++)
    {
        printf("Enter element [%d]: ", i + 1);
        scanf("%d", ptr);
        ptr++;
    }
}

// Display function
void display(int *ptr, int size)
{
    printf("Array: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", *ptr);
        ptr++;
    }
    printf("\n");
}

// Insertion function
void insertion(int *ptr, int *sizes, int index, int value)
{
    if (*sizes >= 50)
    {
        printf("Array is full! Cannot insert more elements.\n");
        return;
    }

    printf("Enter the value to insert: ");
    scanf("%d", &value);
    printf("Enter index (0 to %d) to insert: ", *sizes);
    scanf("%d", &index);

    if (index < 0 || index > *sizes)
    {
        printf("Invalid index!\n");
        return;
    }

    // Shift elements to the right to create space
    for (int i = *sizes; i > index; i--)
    {
        ptr[i] = ptr[i - 1];
    }

    // Insert new value
    ptr[index] = value;
    (*sizes)++;

    printf("Inserted successfully!\n");
}

// Delete function
void delete_element(int *ptr, int *sizes)
{
    if (*sizes <= 0)
    {
        printf("First, enter elements in the array!\n");
        return;
    }

    int value, index = -1;
    printf("Enter element to delete: ");
    scanf("%d", &value);

    // Find the element index
    for (int i = 0; i < *sizes; i++)
    {
        if (ptr[i] == value)
        {
            index = i;
            break;
        }
    }

    if (index == -1)
    {
        printf("Element not found!\n");
        return;
    }

    // Shift elements left to fill the gap
    for (int i = index; i < *sizes - 1; i++)
    {
        ptr[i] = ptr[i + 1];
    }

    (*sizes)--;

    printf("%d deleted successfully!\n", value);
}
