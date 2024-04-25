// Branch and bound - 15 puzzle problem
#include <stdio.h>
int arr[4][4];

void puzzle(int x, int y,char revert)
{
    int min = 99,tempx,i,k,j,c;
    char a;
    char s[4]={'R','L','U','D'};
    for(k=0;k<4;k++)
    {
        if(s[k] != revert)
        {
            if(s[k]=='R')
            {
                if(y+1>=4)
                {
                    continue;
                }
                arr[x][y]=arr[x][y+1];
                arr[x][y+1]=0;
                c=0;
                for(i=0;i<4;i++)
                {
                    for(j=0;j<4;j++)
                    {
                        if(((i!=3 || j!=3) && arr[i][j] !=(4*i +j+1)) || (i==3 && j==3 && arr[i][j]!=0))
                        {
                            //printf("%d %d\n",i,j);
                            c=c+1;
                        }
                    }
                }
                if(c<=min)
                {
                    min=c;
                    a='R';
                }
                arr[x][y+1]=arr[x][y];
                arr[x][y]=0;
            }
            if(s[k]=='L')
            {
                if(y-1<0)
                {
                    continue;
                }
                arr[x][y]=arr[x][y-1];
                arr[x][y-1]=0;
                c=0;
                for(i=0;i<4;i++)
                {
                    for(j=0;j<4;j++)
                    {
                        if(((i!=3 || j!=3) && arr[i][j] !=(4*i +j+1)) || (i==3 && j==3 && arr[i][j]!=0))
                        {
                            //printf("%d %d\n",i,j);
                            c=c+1;
                        }
                    }
                }
                if(c<=min)
                {
                    min=c;
                    a='L';
                }
                arr[x][y-1]=arr[x][y];
                arr[x][y]=0;
            }
            if(s[k]=='U')
            {
                if(x-1<0)
                {
                    continue;
                }
                arr[x][y]=arr[x-1][y];
                arr[x-1][y]=0;
                c=0;
                for(i=0;i<4;i++)
                {
                    for(j=0;j<4;j++)
                    {
                        if(((i!=3 || j!=3) && arr[i][j] !=(4*i +j+1)) || (i==3 && j==3 && arr[i][j]!=0))
                        {
                            //printf("%d %d\n",i,j);
                            c=c+1;
                        }
                    }
                }
                if(c<=min)
                {
                    min=c;
                    a='U';
                }
                arr[x-1][y]=arr[x][y];
                arr[x][y]=0;
            }
            if(s[k]=='D')
            {
                if(x+1>=4)
                {
                    continue;
                }
                arr[x][y]=arr[x+1][y];
                arr[x+1][y]=0;
                c=0;
                for(i=0;i<4;i++)
                {
                    for(j=0;j<4;j++)
                    {
                        if(((i!=3 || j!=3) && arr[i][j] !=(4*i +j+1)) || (i==3 && j==3 && arr[i][j]!=0))
                        {
                            //printf("%d %d\n",i,j);
                            c=c+1;
                        }
                    }
                }
                if(c<=min)
                {
                    min=c;
                    a='D';
                }
                arr[x+1][y]=arr[x][y];
                arr[x][y]=0;
            }
        }
    }
    if(a=='R')
    {
        arr[x][y]=arr[x][y+1];
        arr[x][y+1]=0;   
        y=y+1;
    }
    if(a=='L')
    {
        arr[x][y]=arr[x][y-1];
        arr[x][y-1]=0;
        y=y-1;
    }
        if(a=='U')
    {                
        arr[x][y]=arr[x-1][y];
        arr[x-1][y]=0;
        x=x-1;
    }
        if(a=='D')
    {
        arr[x][y]=arr[x+1][y];
        arr[x+1][y]=0;
        x=x+1;
    }
    if(min==0)
    {
        //printf("%d",min);
        printf("%c\n",a);
        return;
    }
    else
    { 
       // printf("%d",min);
        printf("%c\n",a);
        puzzle(x,y,a);
        return;
    }
}

int main()
{
    int i,j,x,y;
    printf("Enter the matrix :\n");
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    printf("specify the position where there is a blank : ");
    printf("Enter i : ");
    scanf("%d",&x);
    printf("Enter j : ");
    scanf("%d",&y);
    puzzle(x,y,'x');

    return 0;
}
