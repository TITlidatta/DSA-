// Online C compiler to run C program online
#include <stdio.h>
#include<math.h>
#include <stdlib.h>

void TowerofHanoiO(char x, char y, char z,int n)// from x to z using y
{

    if(n<=0)
    {
        return;
    }
    TowerofHanoiO(x,z,y,n - 1);
    printf("Moving top disk from %c to %c \n",x,z);
    TowerofHanoiO(y,x,z,n - 1);
    
}

void TowerofHanoiN(char x, char y1,char y2, char z,int n)
{
    if(n<=0)
    {
        return;
    }
    int k = n/2;
    TowerofHanoiN(x,y2,y1,z,k);
    TowerofHanoiO(x,y1,z,n - k - 1);
    printf("Moving top  disk from %c to %c \n",x,y1);
    TowerofHanoiO(z,x,y1,n - k - 1);
    TowerofHanoiN(y2,y1,x,z,k);
    
}


int main() 
{
    int n;
    printf("Enter the number of disk :");
    scanf("%d",&n);
    TowerofHanoiN('A','B','C','D',n);// A to C where B is helper
    return 0;
}