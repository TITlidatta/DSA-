#include<stdio.h>
#include<string.h>
#include<stdbool.h>

struct two
{ 
   char v;
   int dist ;
};

struct connections
{ 
    char u;
    int no;
    struct two y[10];

};

struct connections edges[20];
struct two priority[15] ;
int rear= -1, front= -1;
int distance[5]={20,20,0,20,20};

bool isEmpty()
{
    if(front== -1 && rear==-1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void Enqueue(char c , int distx)
{ 
    if(rear==-1 && front==-1)
    {
        rear =0;
        front=0;
    }
    else
    {
        rear++;
    }
    priority[rear].v= c;
    priority[rear].dist= distx;
}

char Dequeue()
{
   int i,min= 1000,k;
   char a;
   if(front==rear && front !=-1)
   {
        a=priority [front].v;
        front=-1;
        rear=-1;
        return a;
    }
    for(i=front;i<=rear;i++)
    {
        if(priority [i].dist<=min)
        {
            min =priority [i].dist ;
            a=priority [i].v;
            k=i;
        }

    }
    priority[k].v=priority[front].v;
    priority[k].dist=priority[front].dist;
    priority[front].v=a;
    priority[front].dist=min;
    front++;
    
   return a;
}

void dijkstra(char c)
{
   int z,i,val,k;
   z = c - 65;
   val= distance[z]; 
   for(i=0;i<edges[z].no;i++)
   {
        k=edges[z].y[i].v -65;
        if(val+edges[z].y[i].dist<distance[k])
        {
            distance[k]=val+edges[z].y[i].dist;
            Enqueue(edges[z].y[i].v,distance[k]);
 
        }
   }

    if(isEmpty())
    {
        return;
    }
    else
    {
        dijkstra(Dequeue());
    }

    return;

}

int main()
{
    int i,j,edge,q,vert;
    char s[10];
    printf("Enter the number of vertices\n");
    scanf("%d",&vert);
    printf("Enter the vertices\n");
    for(i=0;i<vert;i++)
    {
        scanf(" %c", &edges[i].u);
    }
    for(i=0;i<vert;i++)
    {
        printf("\n Enter the connections from %c as B4C3 etc and if no connections enter NO \n",edges[i].u);
        scanf("%s",s);
        if( strcmp(s,"NO")!=0)
        {
            q=0;
            for(j=0;j<strlen(s);j=j+2)
            {
                edges[i].y[q].v=s[j];
                edges[i].y[q].dist=s[j+1]-48;
                q++;
            }
            edges[i].no=strlen(s)/2;
        }
    }
    dijkstra('C');
    for(i=0;i<vert;i++)
    {
        printf("%d ",distance[i]);
    }
    return 0;
}