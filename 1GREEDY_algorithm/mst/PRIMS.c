#include <stdio.h>
#include <string.h>

struct prim
{
    char A;
    char B;
    int distx;
};

struct neew
{
    char u;
    int dist;
};
struct mstx
{
    char a;
    char d;
};

struct connections
{
    char x;
    int no;
    struct neew y[10];
};

struct connections edges[30];
struct prim queue[30];
struct mstx MST[20];
int k=0;
int front=-1, rear=-1;
int visited[30];

int isEmpty()
{

    if(front==-1 && rear==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void Enqueue(char v, char t, int z)
{
    if(front == -1 && rear ==-1)
    {
        front =0;
        rear=0;
    }
    else
    {
        rear++;
    }
    queue[rear].A=v;
    queue[rear].B=t;
    queue[rear].distx=z;
}

struct prim Dequeue()
{
    int i,track,end,min=1000;
    if(front==rear && front != -1)
    {
        track = front;
        front =-1;
        rear=-1;
        return queue[track];
    }
    else
    {
      for(i=front;i<=rear;i++)
      {
          if(queue[i].distx<min)
          {
              min=queue[i].distx;
              track=i;
          }
      }
     char one=queue[front].A;
     char two=queue[front].B;
     int three=queue[front].distx;
     queue[front].A=queue[track].A;
     queue[front].B=queue[track].B;
     queue[front].distx=queue[track].distx;
     queue[track].A=one;
     queue[track].B=two;
     queue[track].distx=three;
     end=front;
     front++;
     return queue[end];
    }
}
//works on undirected graph
void prims(char c,char parent)
{
    int f,w,l;
    struct prim s;
    f=c-65;
    if(parent != 'X' && visited[f] ==0)
    {
        MST[k].a=parent;
        MST[k].d=c;
        k++;
    }
    if(visited[f]==1)
    {
        return;
    }
    visited[f]=1;
    for(l=0;l<edges[f].no;l++)
    {
        w=edges[f].y[l].u -65;
        if(visited[w]==0)
        {
            Enqueue(c,edges[f].y[l].u,edges[f].y[l].dist);
        }
    }
    if(isEmpty()==0)
    {
        s=Dequeue();
        prims(s.B,s.A);
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
        scanf(" %c", &edges[i].x);
    }
    for(i=0;i<vert;i++)
    {
        printf("\n Enter the connections from %c as B4C3 etc and if no connections enter NO \n",edges[i].x);
        scanf("%s",s);
        if( strcmp(s,"NO")!=0)
        {
            q=0;
            for(j=0;j<strlen(s);j=j+2)
            {
                edges[i].y[q].u=s[j];
                edges[i].y[q].dist=s[j+1]-48;
                q++;
            }
            edges[i].no=strlen(s)/2;
        }
    }

    prims('A','X');
    for(i=0;i<k;i++)
    {
        printf("\n %c %c ",MST[i].a,MST[i].d);
    }
    return 0;
}