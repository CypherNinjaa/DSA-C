#include <stdio.h>

int main()
{
    int n = 12345; // Example number
    
    while (n)printf("%d", n % 10), n /= 10;

    printf("\n"); // To move to the next line after printing all digits
    return 0;
}