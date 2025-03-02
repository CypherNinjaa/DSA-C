#include <stdio.h>
void arrayinput(int *);
void arrayprint(int *);
int main()
{
    int arr[5];
    int *ptr = arr;
    arrayinput(ptr);
    arrayprint(ptr);
    return 0;
}
void arrayinput(int *ptr)
{
    for (int i = 0; i < 5; i++)
    {
        printf("Enter %d term : ", i);
        scanf("%d", ptr);
        ptr++;
    }
}
void arrayprint(int *ptr)
{
    for (int i = 0; i < 5; i++)
    {
        printf("%d term = %d\n", i, *ptr);
        ptr++;
    }
}