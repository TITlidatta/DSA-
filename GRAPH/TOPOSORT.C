#include <stdio.h>
#include <string.h>
#include<stdbool.h>

struct connections
{
    char x;
    char y[10];
};

struct connections edges[100];
int visited[20];
int vert;
char stack[30];
int top =-1;

void dfs(char c)
{
      int M,i,k;
      M= c - 65;
      visited[M]=1;
      for(i=0;i< strlen(edges[M].y);i++)
      {
               k= edges[M].y[i] - 65;
               if(visited[k]==0)
               {
                      dfs(edges[M].y[i]);
               }
      }
     top++;
     stack[top]=c;
      return;
}
 
void topoSort_DAG()
{
    int i;
    printf("toposort\n");
    for(i=0;i<vert;i++)
    { 
        if(visited[i]==0)
        {
            dfs(edges[i].x);
        }
    }
}


int main()
{
 
    int i,j,edge;
    char s[10];
    printf("Enter the number of vertices\n");
    scanf("%d",&vert);
    printf("Enter the vertices\n");
    for(i=0;i<vert;i++)
    {
        scanf(" %c", &edges[i].x);
    }
    for(i=0;i<vert;i++)
    {
        printf("\n Enter the connections from %c and if no connections enter NO ",edges[i].x);
        scanf("%s",s);
        if( strcmp(s,"NO")!=0)
        {
            for(j=0;j<strlen(s);j++)
            {
                edges[i].y[j]=s[j];
            }
        }
    }
    topoSort_DAG();
    for(i=top;i>=0;i--)
    {
        printf(" %c ", stack[i]);
    }
    return 0;
}