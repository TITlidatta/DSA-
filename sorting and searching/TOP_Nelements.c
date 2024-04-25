// Insertion sort
#include <stdio.h>
//keep that loop running index as initial key index
/*compare key with everything in the left till we find a greater element then we shift the greater element in the rightand set k as that index of the grater element.... now here if less we put key in k*/
void insertion_sort(int *arrptr,int n)
{
    int temp;
    for(int i=1;i<n;i++)
    {
        temp=*(arrptr+i);
        for(int j=i-1;j>=0;j--)
        {
            if(*(arrptr+j)>temp)
            {
                *(arrptr+j+1)=*(arrptr+j);
            }
            else
            {
                *(arrptr+j+1)=temp;
                temp=-1;
                break;
            }
        }
        if(temp !=-1)
        {
            *(arrptr+0)=temp;
        }
        
    }
}

int main() 
{
    int n,b,i,arr[100], *arrptr;
    printf("Enter the no of elements in the array\n");
    scanf("%d",&n);
    printf("Enter elements\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    arrptr=&arr[0];
    insertion_sort(arrptr,n);//since n elements last index n-1
    printf("Enter the value of N\n");
    scanf("%d",&b);
    printf("TOP N elements\n");
    for(i=0;i<b;i++)
    {
        printf("%d\n",arr[i]);
    }
    
    return 0;
}