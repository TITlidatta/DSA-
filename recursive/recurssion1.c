// Online C compiler to run C program online
#include <stdio.h>
int arraysum(int arr[],int i)/* this is function definition so we wrote in the input definition int arr[], but in the calling of function when we are passing any array we will just pass the array name as the array see line 13 and line 27*/
{
    if (i==0)
    {
        return arr[i];
    }
    
    else 
    {
        //return something+arraysum(something);
        int sum=arr[i]+arraysum(arr,i-1);
        return sum;
    }
}    

int main() 
{
  int arr[4],i;
  printf("enter array");
  for(i=0;i<4;i++)
  {
      scanf("%d",&arr[i]);
  }
  //  i=0  arr[i]=arr[0]
  int c=arraysum(arr,3); //12+8+5+9
  printf("%d",c);

    return 0;
}