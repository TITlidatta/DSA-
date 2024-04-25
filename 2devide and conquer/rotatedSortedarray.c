// Online C compiler to run C program online
#include <stdio.h>


int point(int arr[], int l,int r)
{
  int mid;
  mid =(l+r)/2;
  if(arr[mid]< arr[l] && arr[mid]<arr[r])
  {
      return point(arr,l,mid);
  }
  else if(arr[mid]>arr[l] && arr[mid]>arr[r])
  {
      return point(arr,mid ,r);
  }
  else
  {
      return mid;
  }
}

int binarySearch(int arr[], int l, int r , int key) {
    int mid = (l+r )/2;
    if(l == r)
    {
        if(arr[mid]== key)
        {
            return mid;
        }
        else
        {
            return -1;
        }
    }
    else
    {
        if(key > arr[mid])
        {
            return  binarySearch(arr,mid+1,r, key);
        }
        else
        {
            return binarySearch(arr,l,mid,key);
        }
    }
}

int main() 
{
    int n,arr[30],i,p,index,key;
    printf("Enter the size of array ");
    scanf("%d",&n);
    printf("Enter the array\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("\n Enter the key : ");
    scanf("%d",&key);
    p=point(arr,0,n-1);
    printf("the point an is %d",arr[p]);
    if(key<arr[0])
    {
        index= binarySearch(arr,p+1,n-1,key);
   }
   else
   {
       index=binarySearch(arr,0,p,key);
   }
   printf("\nthe index required is %d",index);
    return 0;
}