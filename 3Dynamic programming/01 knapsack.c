//01 knapsack
/*B[i][j]] represents the max profit when it is CONSIDERED / THOUGHT THAT I MIGHT TAKE ALL ITEMS I0 to Ii when the weight of the bag is j kgs - NOW IN THAT CONSIDEREATION I MIGHT OR MIGHT NOT CONSIDER THAT Ii th item in the final conclusion ...that was just an assumption and its decided by */
   /*max((  max profit without taking Ii for sure but seeking what is the max profit when ASSUMED all from Ii-1  to I0 ), (profit when Ii is TAKEN FOR SURE THEREFORE Profit of Ii + [max profit when Weight net j - weight of Ii is remaining and we are ASSUMING THAT ALL OTHER ITEMS ARE TAKEN FROM Io to Ii-1]))*/
   
#include<stdio.h>
#include<stdlib.h>
int B[100][100];
int W[30];
int P[30];
int I[10]={0,0,0,0,0,0,0,0,0,0};

int max(int a , int b)
{
    if(a>=b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
void knapsack(int n,int WK)
{
    int i,j,p;
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=WK;j++)
        {
            if(i==0 || j ==0)
            {
                B[i][j]=0;
            }
            else if(W[i]>j)
            {
                B[i][j]=B[i-1][j];
            }
            else
            {
                p=P[i] + B[i-1][j-W[i]];
                B[i][j]= max(B[i-1][j],p);
            }
        }
    }
    i=n;
    j=WK;
    while(i>0 && j>0)
    {
        if(B[i][j] == B[i-1][j])
        {
            I[i]=0;
            i=i-1;
        }
        else
        {
            I[i]=1;
            j=j - W[i];
            i=i-1;
        }
    }
    return;
}

int main()
{
    int n,i,WK;
    printf("Enter the no of items : ");
    scanf("%d",&n);
    printf("Enter the knapsack weight : ");
    scanf("%d",&WK);
    printf("Enter the profits \n");
    W[0]=0;
    P[0]=0;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&P[i]);
    }
    printf("Enter the weights \n");
    for(i=1;i<=n;i++)
    {
        scanf("%d",&W[i]);
    }
    knapsack(n,WK);
    printf("max profit is %d\n",B[n][WK]);
    printf("The items taken are:\n");
    for(i=0;i<=n;i++)
    {
        if(I[i]==1)
        {
            printf("Item no %d\n",i);
        }
    }
    return 0;
}