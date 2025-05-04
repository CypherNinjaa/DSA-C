#include <stdio.h>
int main()
{
    int arr[2][2] = {
        (1, 1),
        (2, 2),
        (3, 3),
        (4, 4)};
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("arr [%d]", i, j);
        }
        printf("\n");
    }

    return 0;
}