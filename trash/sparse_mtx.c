#include <stdio.h>

// Function Prototypes
void mtxinput(int *, int, int);
void mtxdisplay(int *, int, int);
void mtxsparse(int *, int, int);
void mtxoutput(int *, int, int);

int main()
{
    // Row & Column
    int row, col;

    // Take input for row & column
    printf("Enter the number of rows : ");
    scanf("%d", &row);
    printf("Enter the number of columns : ");
    scanf("%d", &col);

    // Create matrix
    int arr[row][col];

    // Pointer to first element
    int *ptr = &arr[0][0];

    // Call function for input
    mtxinput(ptr, row, col);

    // Call function for displaying the input matrix
    mtxdisplay(ptr, row, col);

    // Call function to check if matrix is sparse
    mtxsparse(ptr, row, col);

    return 0;
}

// Matrix input function
void mtxinput(int *ptr, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("Enter [%d][%d] term: ", i, j);
            scanf("%d", ptr);
            ptr++;
        }
    }
}

// Matrix display function
void mtxdisplay(int *ptr, int row, int col)
{
    printf("\nYour Matrix:\n");
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

// Sparse matrix check function
void mtxsparse(int *ptr, int row, int col)
{
    int zero = 0;
    int total_elements = row * col;

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

    printf("\nIt has %d zeros.\n", zero);

    if (zero > (total_elements / 2))
    {
        printf("Your matrix is Sparse:\n");
        // If the matrix is sparse, call output function
        mtxoutput(ptr, row, col);
    }
    else
    {
        printf("Matrix is not sparse.\n");
    }
}

// Output the sparse matrix in triplet form
void mtxoutput(int *ptr, int row, int col)
{
    printf("\nSparse Matrix in Triplet Form:\n");
    printf("Row\tColumn\tValue\n");

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (*(ptr + i * col + j) != 0)
            {
                printf("%d\t%d\t%d\n", i + 1, j + 1, *(ptr + i * col + j));
            }
        }
    }
}
