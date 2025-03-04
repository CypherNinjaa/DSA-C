#include <stdio.h>
void input(int *, int);
void display(int *, int);
void update(int *, int *);
void delete(int *, int *);
int main()
{
    int size, choice;
    printf("Enter the size of array : ");
    scanf("%d", &size);
    int arr[50];
    int *ptr = arr;
    while (1)
    {
        printf("1. Insert element\n2. Dispaly array\n3. Update element\n4. Delete\n5. Exit\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            input(ptr, size);
            break;
        case 2:
            display(ptr, size);
            break;
        case 3:
            update(ptr, &size);
            break;
        case 4:
            delete (ptr, &size);
            break;
        case 5:
            return 0;
        default:
            printf("Invalid choice!\n");
            break;
        }
    }
    return 0;
}
// input function
void input(int *ptr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("Enter the [%d] element : ", i + 1);
        scanf("%d", ptr);
        ptr++;
    }
    printf("Array filled up!\n");
}
// display function
void display(int *ptr, int size)
{
    printf("Array : ");
    for (int i = 0; i < size; i++)
    {
        printf(" %d ", *ptr);
        ptr++;
    }
    printf("\n");
}
// update function
void update(int *ptr, int *size)
{
    int n, index;
    if (*size <= 0)
    {
        printf("Please enter element first1\n");
    }
    else
    {
        printf("Enter the element to update : ");
        scanf("%d", &n);
        printf("Enter index : ");
        scanf("%d", &index);
    }
    for (int i = *size; i >= index; i--)
    {
        ptr[i] = ptr[i - 1];
    }
    ptr[index] = n;
    (*size)++;
    printf("Inserted successfully\n");
}
// delete function;
void delete(int *ptr, int *size)
{
    int n, index = -1;
    printf("Enter the number to delete : ");
    scanf("%d", &n);
    for (int i = 0; i < *size; i++)
    {
        if (ptr[i] == n)
        {
            index = i;
            break;
        }
    }
    if (index == -1)
    {
        printf("Element not found!\n");
    }
    else
    {
        for (int i = index; i < *size; i++)
        {
            ptr[i] = ptr[i + 1];
        }
        (*size)--;
        printf("Deleted successfully!\n");
    }
}