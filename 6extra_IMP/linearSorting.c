// Online C compiler to run C program online
#include <stdio.h>
#include<stdlib.h>

int main() 
{
    int j=3,k=20,temp,x,i;   
    int given[14];
    int arr[k-j+1];
    for (i = 0; i < 14; i++) 
    {
        temp=j + rand() % (k - j + 1);
        given[i]=temp;
        //printf("%d\n",given[i]);
    }
    for(i=0;i<k-j+1;i++)
    {
        arr[i]=0;
    }
    for(i=0;i<14;i++)
    {
        arr[given[i]-j]=arr[given[i]-j]+1; 
// given[3]=8   8-3 = 5     arr[5]=arr[5]+1  jtobar 8 asbe arr[5] e count increase hbe
    }
    for(i=0;i<k-j+1;i++)
    {
        while(arr[i]>0)
        {
            printf("%d\n",j+i);
            arr[i]--;
        }
    }
    return 0;
}