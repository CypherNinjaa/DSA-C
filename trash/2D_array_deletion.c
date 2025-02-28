#include <stdio.h>
int main()
{
    int arr[2][2] = {{10, 20}, {30, 40}};
    int n = 2;
    int element;

    printf("original array : \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("enter element to delete : ");
    scanf("%d", &element);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == element)
            {
                arr[i][j] = 0;
            }
        }
    }
    printf("Array after deletion : \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}