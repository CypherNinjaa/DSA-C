#include <stdio.h>
int arrayinput(int*);
int arrayprint(int*);
int main(){
    int arr[5];
    int* ptr=arr;
    arrayinput(ptr);
    arrayprint(ptr);
    return 0;
}
int arrayinput(int* ptr){
    for (int i = 0; i < 5; i++)
    {
        printf("Enter %d term : ",i);
        scanf("%d",ptr);
        ptr++;
    }
    return 0;
}
int arrayprint(int* ptr){
    for (int i = 0; i <5; i++)
    {
       printf("%d term = %d\n",i,*ptr);
       ptr++;
    }
    return 0;
}