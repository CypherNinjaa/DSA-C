#include <stdio.h>
void input(int *, int, int);
void display(int *, int, int);
void Deletion(int *, int, int);
int main()
{
    int row, column, choice;
    int arr[50][50]; // max size 50
    int *ptr = &arr[0][0];
    while (1)
    {
        printf("1. Enter size of array\n2. Enter Element of Array\n3. Display Array\n4. Delete an Array element\n5. Exit\n Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the Row of array : ");
            scanf("%d", &row);
            printf("Enter the column of Array : ");
            scanf("%d", &column);
            break;
        case 2:
            input(ptr, row, column);
            break;
        case 3:
            display(ptr, row, column);
            break;
        case 4:
            Deletion(ptr, row, column);
            break;
            case 5:
            return 0;
        default:
            break;
        }
    }

    return 0;
}
// Input function
void input(int *ptr, int row, int column)
{
    if (row <= 0 && column <= 0)
    {
        printf("First, Enter size of array!");
        return;
    }
    else
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                printf("Enter the [%d][%d] element : ", i + 1, j + 1);
                scanf("%d", ptr);
                ptr++;
            }
        }
    }
    printf("size updated!\n");
    
}
// diplay function
void display(int *ptr, int row, int column)
{
    if (row <= 0 && column <= 0)
    {
        printf("Enter element first\n");
        return;
    }
    else
    {
        printf("Array: \n");
        for (int i = 0; i < column; i++)
        {
            for (int j = 0; j < row; j++)
            {
                printf("%d ", *ptr);
                ptr++;
            }
            printf("\n");
        }
    }
}
// Dletion or updation Function
void Deletion(int *ptr, int row, int column)
{
    int element;
    if (row < 0 && column < 0)
    {
        printf("Please enter element first");
        return;
    }
    else
    {
        printf("Enter element to delete : ");
        scanf("%d", &element);
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                if (*ptr == element)
                {
                    *ptr=0;
                }
                ptr++;
            }
        }
    }
    printf("Deleted Succesfully!\n");
    
}