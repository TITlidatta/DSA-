// Online C compiler to run C program online
#include <stdio.h>

void swap(int *ptr1,int *ptr2)
{
    int temp=*ptr1;
    *ptr1=*ptr2;
    *ptr2=temp;
}
int smaller_pivot_greater_arrangementfunc(int *arrptr,int low ,int high )
{ 
    int pivot=*(arrptr+low);
    int i=low+1;
    int j=high;
    while(i<=j)
    {
        while(*(arrptr+i)<pivot && i<=high)/*finding the index of element greater than pivot from the left*//*also not less than equal cause equal hole ar pichone die ki hbe rather okhnei thak ----- ask if needed*/
        {
            i++;
        }
        while(*(arrptr+j)>=pivot && j>=low+1)/*finding the index of the element smaller than pivot from*/ 
        {
            j--;
        }
            
         if(i<j)/*if i exceeds j but still in loop because condition is checked in the last after completing one loop once entered*/
         {
             swap((arrptr + i), (arrptr + j));// if 
         }

    }
    swap((arrptr+j),(arrptr+low));//remond me of pivot
    return j ;
}

void Quick_sort(int *arrptr,int low,int high)
{
   if(low==high || low>high)
   {
       return;
   }
   
   int partition=smaller_pivot_greater_arrangementfunc(arrptr,low,high);
   Quick_sort(arrptr,low,partition-1);
   Quick_sort(arrptr,partition+1,high);
}

int main()
{
    int n,i, arr[100], *arrptr;
    printf("Enter the no of elements of the array\n");
    scanf("%d",&n);
    printf("Enter\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    arrptr=&arr[0];
    Quick_sort(arrptr,0,n-1);
    printf("Sorted array\n");
    for(i=0;i<n;i++)
    {
        printf("%d\n",arr[i]);
    }

    return 0;
}