#include <stdio.h>
void mtxinput(int *, int, int);
void mtxdisplay(int *, int, int);
void mtxsparse(int *, int, int);
void mtxoutput(int *, int, int);
int main()
{
    // row & column
    int row, col;
    // take input row & column
    printf("Enter the row of the mtx : ");
    scanf("%d", &row);
    printf("Enter the Column of the mtx : ");
    scanf("%d", &col);
    // create mtx
    int arr[row][col];
    // create pointer
    int *ptr = &arr[0][0];
    // call function for input
    mtxinput(ptr, row, col);
    // call function for display inputed mtx
    mtxdisplay(ptr, row, col);
    // call function for sparse mtx check
    mtxsparse(ptr, row, col);
    return 0;
}
// mtx input function
void mtxinput(int *ptr, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("Enter [%d][%d] term : ", i, j);
            scanf("%d", ptr);
            ptr++;
        }
    }
}
// mtx display function
void mtxdisplay(int *ptr, int row, int col)
{
    printf("Your Mtarix : \n");
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
void mtxsparse(int *ptr, int row, int col)
{
    int zero = 0;
    int total_element = row * col;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (*(ptr + i * col + j) == 0)
            {
                zero++;
            }
            
        }
        }
    printf("It has %d zero", zero);
    if (zero > (total_element / 2))
    {
        printf("\nyour matrix is Sparse : \n");
        // if mtx is sparse then call output
        mtxoutput(ptr, row, col);
    }
    else
        printf("Matrix is not sparse : \n");
}
// if mtx is sparse then print it
void mtxoutput(int *ptr, int row, int col)
{
    printf("sparse matrix in triplet form : \n");

    // print formatting
    printf("Row\tColumn\tValue\t\n");

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (*(ptr + i * col + j) != 0)
            {
                printf("%d\t%d\t%d", i+1, j+1, *(ptr + i * col + j));
            }
        }
        printf("\n");
    }
}