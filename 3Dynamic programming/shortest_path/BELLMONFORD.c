#include<stdio.h>
#include<string.h>

struct new
{ 
     char A;
     char B;
     int wt;
};

struct new edges[30];
int distance[5]={100,100,0,100,100};
int vert;
int no;

void bellmon_ford()
{ 
   int i,j,f,g;
   for(i=0;i<vert-1;i++)
   {
        for(j=0;j<no;j++)
        {
           f=edges[j].A -65;
           g=edges[j].B- 65;
           if(distance[f]+edges[j].wt<distance[g])
           {
              distance[g]=distance[f]+edges[j].wt;
           }
        }
    }
 return ;
}


int main()
{
    int i,j,edge,q;
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
        edges[i].B=s[1];
        edges[i].wt=s[2]-48;
    }
    bellmon_ford();
    for(i=0;i<vert;i++)
    {
        printf("%d ",distance[i]);
    }
    return 0;
}