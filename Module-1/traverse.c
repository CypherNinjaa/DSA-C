#include <stdio.h>
int main()
{
    int size;
    printf("Enter the size of array : ");
    scanf("%d", &size);
    int arr[size];
    // taking input
    for (int i = 0; i < size; i++)
    {
        printf("Enter the [%d] element : ", i + 1);
        scanf("%d", &arr[i]);
    }
    // displaying array
    printf("Array : ");
    for (int i = 0; i < size; i++)
    {
        printf("%d \n", arr[i]);
    }
    return 0;
}