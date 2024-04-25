// Online C compiler to run C program online
#include <stdio.h>
int swap(char *x,char *y)
{
    char temp;
    temp=*x;
    *x=*y;
    *y=temp;
    return 0;
}
int reverseString(char *a,int i,int size)//FOGO 0GOF
{
    //base condition:
    if(i>((size-1)/2))
    {
       int j;
       for(j=0;j<size;j++)
       {
           printf("%c",*(a+j));
       }
        
    }
      else
    {
        swap(a+i,a+((size-1)-i));//here 3-i//0123
        reverseString(a,i+1,size);
    }
    return 0;
}
int main()
{
    char arr[4];
    char *a;
    //size 9=012345678//  8/2 ie (size-1)/2 for loop goes in function
    /*08       17     26     35     44
    0(8-0) 1(8-1)  2(8-2) 3(8-3)   4(8-4)*/
    printf("Enter the string of character elements");
    scanf("%s",arr);
    a=&arr[0];
    reverseString(a,0,4);
    return 0;
}