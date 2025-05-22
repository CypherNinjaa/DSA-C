#include <stdio.h>
#include <stdlib.h>
void insert(int *, int);
void deletion(int *, int *);
void insertion(int *, int *);
void display(int *, int);
int main()
{
    int size, choice;
    printf("enter the Size of array (less than 41): ");
    scanf("%d", &size);
    int arr[40];
    int *ptr = arr;
    system("cls");
    while (1)
    {
        printf("\n1. Insert element\n2. Display array\n3. insertion(at index)\n4. deletion(operation)\n5. Exit\nEnter your choice : ");
        scanf("%d", &choice);
        system("cls");
        switch (choice)
        {
        case 1:
            insert(ptr, size);
            break;
        case 2:
            display(ptr, size);
            break;
        case 3:
            insertion(ptr, &size);
            break;
        case 4:
            deletion(ptr, &size);
            break;
        case 5:
            return 0;
            break;
        default:
            printf("Invalid Choice! please try again.........\n");
            break;
        }
    }

    return 0;
}
// insert function
void insert(int *ptr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("Enter the [%d] element : \n", i + 1);
        scanf("%d", ptr);
        ptr++;
    }
    system("cls");
    printf("Element inserted!\n");
}
// display function
void display(int *ptr, int size)
{
    if (size == 0)
    {
        printf("please insert element!\n");
        return;
    }
    else
    {
        printf("Array : ");
        for (int i = 0; i < size; i++)
        {
            printf("%d ", *ptr);
            ptr++;
        }
        printf("\n");
    }
}
// insertion operation
void insertion(int *ptr, int *size)
{
    if (*size == 0)
    {
        printf("please insert element!\n");
        return;
    }
    else
    {
        int index, element;
        printf("Enter the index : ");
        scanf("%d", &index);
        printf("Enter the element to insert : ");
        scanf("%d", &element);
        for (int i = *size; i >= index; i--)
        {
            ptr[i] = ptr[i - 1];
        }
        ptr[index] = element;
        (*size)++;
        system("cls");
        printf("inserted successfully!\n");
    }
}

// deletion operation
void deletion(int *ptr, int *size)
{
    if (*size == 0)
    {
        printf("Please insert element first!\n");
        return;
    }
    else
    {
        int element, index = -1;
        printf("Enter the element to delete : ");
        scanf("%d", &element);
        for (int i = 0; i < *size; i++)
        {
            if (ptr[i] == element)
            {
                index = i;
                break;
            }
        }
        if (index == -1)
        {
            printf("Element not Found!\n");
            return;
        }
        else
        {
            for (int i = index; i < *size - 1; i++)
            {
                ptr[i] = ptr[i + 1];
            }
            (*size)--;
            system("cls");
            printf("Deleted successfully\n");
        }
    }
}