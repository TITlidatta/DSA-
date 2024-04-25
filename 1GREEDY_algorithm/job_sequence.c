//job sequence

int Darr[10]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
int count;
struct node
{
    int index;
    int prf;
    int DLx;
};

struct node arr[10];

void JobSequencing()
{
    int i,j,temp;
    for(i=0;i<count;i++)
    {
        for(j=0;j<count-1;j++)
        {
            if(arr[j].prf< arr[j+1].prf)
            {
                temp= arr[j+1].prf;
                arr[j+1].prf=arr[j].prf;
                arr[j].prf=temp;
                temp= arr[j+1].DLx;
                arr[j+1].DLx=arr[j].DLx;
                arr[j].DLx=temp;
                temp= arr[j+1].index;
                arr[j+1].index=arr[j].index;
                arr[j].index=temp;
                
            }
        }
    }

   for(i=0;i<count;i++)
   {
       j=arr[i].DLx;
       while(Darr[j] != -1 && j>0)
       {
           j=j-1;
       }
       if(j ==0 && Darr[j] != -1)
       {
           continue;
       }
       else
       {
            Darr[j]=arr[i].index;
       }
   }
}

int main()
{
    int i;
    printf("Enter the number of jobs: ");
    scanf("%d",&count);
    printf("Enter the profits\n");
    for(i=0;i<count;i++)
    {
        scanf("%d",&arr[i].prf);
        arr[i].index=i;
    }
    printf("Enter the deadlines\n");
    for(i=0;i<count;i++)
    {
        scanf("%d",&arr[i].DLx);
    }
    JobSequencing();
    printf("Jobs are scheduled as shown below where -1 represents no jobs at that month  \n");
    for(i=0;i<10;i++)
    {
        printf("%d  ",Darr[i]);
    }
    return 0;
}