#include<stdio.h>
#include<string.h>

struct setx
{
  int A;
  int B;
  int dist;
};

struct mst
{
    int one;
    int two;
};

struct setx set [30];
//sort based on wt or dist
int k=0;
int vert;
struct mst MST[30];
int rank[6]={0,0,0,0,0,0};
int parent[6]={0,1,2,3,4,5};
int countOfset=0;
int UltimateParent[6]={0,1,2,3,4,5};

void pathCompression()
{
    int a,h,j;
    for(a=0;a<vert;a++)
    {
        j=a;
        h=a;
        if(parent[h]!=h)
        {
            while(parent[h]!=h)
            {
                h=parent[h];
            }
            UltimateParent[j]=h;
        }
        else
        {
            UltimateParent[j]=a;
        }
    }
    
}


void unionX(int u, int v)
{
    int x,y,rankx,ranky,smaller,bigger;
    x=UltimateParent[u];
    y=UltimateParent[v];
    rankx=rank[x];
    ranky=rank[y];
    if(rankx<ranky)
    {
        smaller =x;
        bigger=y;
    }
    else
    {
        smaller=y;
        bigger=x;
    }
    parent[smaller]=bigger;
    if(rank[smaller] >= rank[bigger])
    {
        rank[bigger]=1+rank[smaller];
    }
    pathCompression();
    
    return;
}

void kruskal()
{
    int i,u,v;
    for(i=0;i<countOfset;i++)
    {
        u=set[i].A;
        v=set[i].B;
        if(UltimateParent[u]!=UltimateParent[v])
        {
            MST[k].one=u;
            MST[k].two=v;
            k++;
            unionX(u,v);
        }
    }
    return;
}

int main()
{
    int i,j,edge,q;
    char s[10];
    printf("Enter the number of vertices\n");
    scanf("%d",&vert);
    printf("enter the number of edges\n");
    scanf("%d", &edge);
    countOfset=edge;
    printf("Enter the edges in sorted manner\n");
    for(i=0;i<edge;i++)
    {  
        j=0;
        scanf("%s",s);
        set[i].A=s[j] - 48;
        set[i].B=s[j+1] - 48;
        set[i].dist=s[j+2] - 48;
        
    }
 
    kruskal();
    printf("Presenting Minimum Spanning Tree\n");
    for(i=0;i<k;i++)
    {
        printf("%d %d  ",MST[i].one,MST[i].two);
    }
    return 0;
}