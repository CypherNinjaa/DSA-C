#include <stdio.h>
#include <stdlib.h>
void input(int *, int);
void print(int *, int);
int main()
{
    int size;
    printf("Enter the size of array : ");
    scanf("%d", &size);
    system("cls");
    int arr[50];
    int *ptr = arr;
    input(ptr, size);
    print(ptr, size);
    return 0;
}

void input(int *ptr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("Enter the %d element : ", i + 1);
        scanf("%d", ptr);
        ptr++;
    }
    system("cls");
}

void print(int *ptr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("Element [%d] : %d\n", i, *ptr);
        ptr++;
    }
}