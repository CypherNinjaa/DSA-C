// WAP TO TRAVERSE AN ARRAY (a) one Dimensional (b) Two dimensional array ( user input of dimensions)
#include <stdio.h>
int main()
{
    int a, b; // a=row and b=column
    // Taking row & column input
    printf("Enter the row of array : ");
    scanf("%d", &a);
    printf("Enter the Column of array : ");
    scanf("%d", &b);
    // Array
    int arr[a][b];
    // taking input of array
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            printf("Enter the [%d][%d] element : ", i + 1, j + 1);
            scanf("%d", &arr[i][j]);
        }
    }
    // printing array
    printf("Your array : \n");
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}