//matrix chain multiplication

//[2,3]*[3,4]*[4,1]*[1,5] order must be maintained otherwise we cannot multiply any random
//matrix with anyone just we need the bracketed odering ie kon part of this order age krbo

//if abs(i-j)<2 : then DP[i][j]==0 else : considering input array from index i to j that is
//matrix from i+1 to j
// bottom up
// outer most loop for len =2 to len = n  to move one by one in -->
// inner for loop for i = 0 to i=n-len+1 "\" diagonal look where col for each i = i+len
// for each box we need to find the minimums among k combinations where k is from i+1 to //col-1
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int a[30];
int MC[50][50];

int min(int a , int b)
{
    if(a<=b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

void MCmultiplication(int n)
{
    int len,i,k,j,col,x;
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=i+1;j++)
        {
            if(j>n)
            {
                break;
            }
            else
            {
                MC[i][j]=0;
            }
        }
    }
    for(len=2;len<=n;len++)
    {
        for(i=0;i<=n - len;i++)
        {
            col=i+len;
            MC[i][col] = 1000000;
            for(k=i+1;k<=col-1;k++)
            {
                MC[i][col]= min(MC[i][col],(MC[i][k]+MC[k][col]+(a[i]*a[k]*a[col])));
            }
        }
    }
    return ;
}
int main()
{
    int i, n;
    printf("Enter the no of matrices : ");
    scanf("%d",&n);
    printf("Enter the matrices order one by one \n");
    for(i=0;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    MCmultiplication(n);
    printf("The required minimum operations needed is %d",MC[0][n]);
    return 0;
}