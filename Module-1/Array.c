#include <stdio.h>

int main()
{
    int n = 6; // Number of rows and columns

    for (int i = 0; i < n; i++)
    { 
        for (int j = 0; j < n; j++)
        {                  
            if (j < n - i) 
                printf("%d\t", j + 1);
            else 
                printf("0\t");
        }
        printf("\n"); 
    }

    return 0;
}
