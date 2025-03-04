#include <stdio.h>
void input(int *, int, int);
void display(int *, int, int);
int main()
{
    int row, col;
    printf("Enter the Row of an array : ");
    scanf("%d", &row);
    printf("Enter the column of an array : ");
    scanf("%d", &col);
    int arr[row][col];
    int *ptr = &arr[0][0];
    // call input func
    input(ptr, row, col);
    // call display function
    display(ptr, row, col);
    return 0;
}
// Input function
void input(int *ptr, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("Enter the [%d][%d] element ", i, j);
            scanf("%d", ptr);
            ptr++;
        }
    }
}
// display function
void display(int *ptr, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d ", *ptr);
            ptr++;
        }
        printf("\n");
    }
}