#include <stdio.h>
void deletion(int *, int, int);
int main()
{
    int arr[5] = {10, 20, 30, 40, 50};
    int n = 5;
    int index;
    int *ptr = arr;
    printf("original Array : ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\nEnter index to delete (0-4) : ");
    scanf("%d", &index);
    deletion(ptr, index, n);
    return 0;
}
void deletion(int *ptr, int index, int n)
{
    for (int i = index; i < n - 1; i++)
    {
        ptr[i] = ptr[i + 1];
        
    }
    n--;
    printf("Array after deletion : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ",ptr[i]);
    }
    
}