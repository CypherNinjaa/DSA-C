#include <stdio.h>
void input(int *, int);
void display();
int main()
{
    int size;
    printf("Enter the size of array : ");
    scanf("%d", &size);
    int arr[size];
    int *ptr = arr;
    // call input function
    input(ptr, size);
    // call display function
    display(ptr, size);
    return 0;
}
// input function
void input(int *ptr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("Enter the [%d] element : ",i);
        scanf("%d", ptr);
        ptr++;
    }
}
// Display function
void display(int *ptr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("element at [%d] index : %d\n",i,*ptr);
        ptr++;
    }
}