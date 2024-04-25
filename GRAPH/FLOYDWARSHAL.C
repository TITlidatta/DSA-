#include<stdio.h>
#include<string.h>

struct new
{ 
     char A;
     char B;
     int wt;
};

struct new edges[30];
int distance[5][5];
int vert;
int no;

void floyd_warshal()
{
    int i,j,k;
    for(k=0;k<vert;k++)
    {
    for(i=0;i<vert;i++)
    {
        for(j=0;j<vert;j++)
        { 
           if(distance [i][j]>distance[i][k] +distance[k][j])
           {
              distance [i][j]=distance[i][k]   
                     +distance[k][j] ;
           }
       }
     }
    }
   return;
}


int main()
{
    int i,j,m,n,edge,q;
    char s[10];
    printf("Enter the number of vertices\n");
    scanf("%d",&vert);
    printf("\nEnter the number of edges\n");
    scanf("%d",&edge);
    no=edge;
    printf("\n Enter the edges as BE4");
    for(i=0;i<edge;i++)
    {
        scanf("%s",s);
        edges[i].A=s[0];
        m=s[0]-65;
        edges[i].B=s[1];
        n=s[1]-65;
        edges[i].wt=s[2]-48;
        distance[m][n]=s[2]-48;
    }
    for(i=0;i<vert;i++)
    {
        for(j=0;j<vert;j++)
        {
            if(i==j)
            {
                distance[i][j]=0;
            }
            else if(distance[i][j]==0)
            {
                distance[i][j]=1000;
            }
        }
    }
    floyd_warshal();
    printf("Here is floyd warshal\n\n");
    for(i=0;i<vert;i++)
    {
        for(j=0;j<vert;j++)
        {
           printf("%d ",distance[i][j]);
        }
        printf("\n");
    }

    return 0;
}