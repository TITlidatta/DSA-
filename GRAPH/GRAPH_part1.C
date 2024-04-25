#include <stdio.h>
#include <string.h>
#include <stdbool.h>

struct connections
{
    char x;
    char y[10];
};

struct connections edges[100], *start;
char queue[20];
int visited[20];
int front = -1, rear = -1;


bool is_empty()
{
    if(front == -1 && rear ==-1)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

void enqueue(char c)
{
    if(front == -1 && rear == -1)
    {
        rear=front=0;
        queue[rear]=c;
    }
    else
    {
        queue[++rear] = c ;
    }
    
    return ;
}

char dequeue()
{
    char got;
    if (is_empty())
    {
        return '0';
    }
    else
    {
        if(front==rear && front != -1)
        {
            got = queue[front];
            front = rear = -1;
        }
        else
        {
            got = queue[front];
            front ++ ;
        }
        return got;
    }
}
    
void bfs(char c)
{
    int l= c-65;
    int k;
    for(k=0;k< strlen(edges[l].y);k++)
    {
        int check = edges[l].y[k] - 65;
        if(visited[check]==0)
        {
            visited[check] = 1;
            enqueue(edges[l].y[k]);
        }
    }
    printf(" %c", dequeue());
    if (is_empty())
    {
        return;
    }
    else
    {
        bfs(queue[front]);
    }
}
/*void dfs()
void connected_componenets()
void cycle_in_undirected_graph()
void number_of_distinct_islands()
void bipartite_graph()
void toposort()
void dikjstra()
void prims()
void khans()
void bellman_ford()
void floyd_warshal()
void kruskal()
void strongly_connected_components()*/

int main()
{
 
    int i,j,edge,vert;
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
    visited[0]=1;
    enqueue('A');
    bfs('A');
    return 0;
}