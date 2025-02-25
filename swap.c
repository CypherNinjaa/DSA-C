#include <stdio.h>
int main(){
    int a=10,b=20;
    a=a+b-(b=a);
    printf("a=%d and b=%d\n",a,b);
    
    return 0;
}