// Online C compiler to run C program online
#include <stdio.h>

int C[100][100];
int D[100][100];

int level;

int min2(int ii, int n)
{
    int mi=100000;
    int j;
    for(j=0;j<=n;j++)
    {
        if(j!=0 && j!=ii)
        {
            if(mi>D[ii][j])
            {
                mi = D[ii][j];
            }
        }
    }
    return mi;
}

int min(int ii, int jj, int n)
{
    int mi=100000;
    int i =jj,j;
    for(j=0;j<=n;j++)
    {
        if(j!=0 && j!=ii && j!=jj)
        {
            if(mi>D[i][j])
            {
                mi = D[i][j];
            }
        }
    }
    return mi;
}

void TravellingSalesman(int n)
{
    int i,j;
    if(level ==n)
    {
        for(i=1;i<=n;i++)
        {
            D[i][0] = C[0][i] + min2(i,n);
        }
        return;
    }
    else
    {
        for(i=0;i<=n;i++)
        {
            for(j=0;j<=n;j++)
            {
                if(i!=j && j!=0)
                {
                    D[i][j]= C[i][j] + min(i,j,n);
                }
            }
        }
        level++;
        return TravellingSalesman(n);
    }
}

int main() 
{
    int n,i,j,minx=20000;
    printf("Enter the number of vertices : ");
    scanf("%d",&n);
    printf("Enter the adjacency matrix weights from i to j ");
    for(i=0;i<n;i++)
    {
        printf("for row %d\n",i);
        for(j=0;j<n;j++)
        {
            scanf("%d",&C[i][j]);
            if(j==0 && i!=0)
            {
                D[i][j]=C[i][j];
            }
        }
        printf("\n");
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i!=j && j!=0)
            {
                D[i][j]=C[i][j] + C[j][0];
            }
        }
        printf("\n");
    }
    level = 2;
    TravellingSalesman(n-1);
    for(i=1;i<n;i++)
    {
        if(minx>D[i][0])
        {
            minx=D[i][0];
        }
    }
    printf("The required answer is %d ",minx);
    return 0;
}