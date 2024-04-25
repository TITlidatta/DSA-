#include <stdio.h>
#include<stdbool.h>

int temp[2];
bool flag = false;
void find_nums(int* arr,int size,int t)
{
    int complement[100],c,i;
    for(i=0;i<=size;i++)
    {
        complement[arr[i]] = 1;
    }
    for(i=0;i<=size;i++)
    {
        if(arr[i]<= t)
        c = t- arr[i] ;
        if (complement[c] == 1)
        {
            flag=true;
            temp[0] = arr[i];
            temp[1] = c;
        }
    }
}
int main() 
{
    int i,n,arr[10],trg;
    printf("enter the no of elements\n");
    scanf("%d", &n);
    printf("enter the array\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("enter the target ");
    scanf("%d", &trg);
    find_nums(arr,n-1,trg);
    if(flag)
    {
        printf("The numbers are\n");
        printf("%d ",temp[0]);
        printf("%d", temp[1]);
    }
    return 0;
}