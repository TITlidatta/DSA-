#include <stdio.h>
int count=0;
void merge(int* arrptr,int low,int mid,int high)
{
    if(low>=high)
    {
        return;
    }
    int temp[100],i,k,b=0;
    int left=low;
    int right=mid+1;
    while(left<=mid && right<=high)
    {
        if(*(arrptr+left)<= *(arrptr+right))
        {
            temp[b]= *(arrptr+left);
            left++;
        }
        else
        {
            temp[b]=*(arrptr+right);
            right++;
            count++;
        }
        b++;
    }
    k=count;
    if(left<=mid)
    {
      count=count-k;  
    }
    while(left<=mid) 
    {
        temp[b]=*(arrptr+left);
        left++;
        count++;
        b++;
    }
    while(right<=high)
    {
        temp[b]=*(arrptr+right);
        right++;
        b++;
    }

   for (int i = 0; i <= high - low; i++) {
       *(arrptr +low + i) = temp[i];  
   }
}

void partition_merge_into_sorted(int *arrptr,int low,int high)
{ 
    if(low==high)
    {
        return;
    }
    else
    {
        int mid=(high+low)/2;
        partition_merge_into_sorted(arrptr,low,mid);
        partition_merge_into_sorted(arrptr,mid+1,high);
        merge(arrptr,low,mid,high);
        return;
    }
}

int main() 
{
    int arr[100],i,n, *arrptr;
    printf("Enter the no of elements in the array\n");
    scanf("%d",&n);
    printf("Enter elements\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    arrptr=&arr[0];
    partition_merge_into_sorted(arrptr,0,n-1);
    printf("Sorted array\n");
    for(i=0;i<n;i++)
    {
        printf("%d\n",arr[i]);
    }
    printf(" count %d ", count);
    return 0;
}