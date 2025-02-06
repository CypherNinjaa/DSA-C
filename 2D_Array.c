#include <stdio.h>
void arrayinput(int *);
void arrayprint(int *);
int main()
{
    int arr[2][2];
    int *ptr = &arr[0][0];
    arrayinput(ptr);
    arrayprint(ptr);
    return 0;
}
void arrayinput(int *ptr)
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("Enter the [%d][%d] term : ", i, j);
            scanf("%d", ptr);
            ptr++;
        }
        printf("\n");
    }
}
void arrayprint(int *ptr)
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
         printf("%d ",*ptr);
         ptr++;
        }
        printf("\n");
    }
}