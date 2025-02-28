#include <stdio.h>
int main(){
    int n,index;
int arr[4]={10,20,30,40};
printf("Enter the number to delete : ");
scanf("%d",&n);
for (int i = 0; i < 4; i++)
{
   if (arr[i]==n)
   {
    index=i;
   }
   
}
printf("index : %d",index);
}