//activity selection 

int AS[10]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
int count;
int F;
struct node
{
    int index;
    int st;
    int ft;
};

struct node arr[10];

void ActivitySelection()
{
    int i,j,k,temp;

    for(i=0;i<count;i++)
    {
        for(j=0;j<count-1;j++)
        {
            if(arr[j].ft> arr[j+1].ft)
            {
                temp= arr[j+1].ft;
                arr[j+1].ft=arr[j].ft;
                arr[j].ft=temp;
                temp= arr[j+1].st;
                arr[j+1].st=arr[j].st;
                arr[j].st=temp;
                temp= arr[j+1].index;
                arr[j+1].index=arr[j].index;
                arr[j].index=temp;
                
            }
        }
    }
    F = arr[0].ft;
    AS[0]=arr[0].index;
    k=1;
    printf("%d ",AS[0]);
   for(i=1;i<count;i++)
   {
       if(arr[i].st>=F)
       {
           AS[k]=arr[i].index;
           F=arr[i].ft;
           k++;
       }
   }
}

int main()
{
    int i;
    printf("Enter the number of activities: ");
    scanf("%d",&count);
    printf("Enter the start times\n");
    for(i=0;i<count;i++)
    {
        scanf("%d",&arr[i].st);
        arr[i].index=i;
    }
    printf("Enter the finish times\n");
    for(i=0;i<count;i++)
    {
        scanf("%d",&arr[i].ft);
    }
    ActivitySelection();
    printf("Activities are scheduled as shown below where 0 represents no  activity after that \n");
    for(i=0;i<10;i++)
    {
        printf("%d  ",AS[i] +1 );
    }
    return 0;
}
