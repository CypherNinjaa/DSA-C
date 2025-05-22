#include <stdio.h>
#include <stdlib.h>
void input(int *, int, int);
void print(int *, int, int);
int main()
{
    int r, c;
    printf("Enter the Row : ");
    scanf("%d", &r);
    printf("Enter the Column : ");
    scanf("%d", &c);
    system("cls");
    int arr[10][10];
    int *ptr = &arr[0][0];
    input(ptr, r, c);
    print(ptr, r, c);
    return 0;
}

void input(int *ptr, int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("Enter the [%d][%d] element : ", i + 1, j + 1);
            scanf("%d", ptr);
            ptr++;
        }
        printf("\n");
    }
    system("cls");
}
void print(int *ptr, int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            // printf("element at [%d][%d] : %d\n", i + 1, j + 1, *ptr);
            printf("%d\n",*ptr);
            ptr++;
        }
        printf("\n");
    }
}