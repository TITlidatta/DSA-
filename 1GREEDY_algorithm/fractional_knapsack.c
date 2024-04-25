//fractional knapsack
#include<stdio.h>

float Netprofit;
float WeightMain; 
float P[10];
float w[10];
int itemn;
float frc[10]={0,0,0,0,0,0,0,0,0,0};
struct node
{
    int index;
    float pwx;
};
struct node arr[10];

void fractionalKnapsack()
{
    int i,j,k;
    float c,temp; 
    for(i=0;i<itemn;i++)
    {
        c = P[i]/w[i];
        arr[i].pwx = c; 
        arr[i].index=i;
    }
    
    for(i=0;i<itemn;i++)
    {
        for(j=0;j<itemn-1;j++)
        {
            if(arr[j].pwx < arr[j+1].pwx)
            {
                temp =arr[j].pwx;
                k =arr[j].index;
                arr[j].pwx = arr[j+1].pwx; 
                arr[j].index = arr[j+1].index; 
                arr[j+1].pwx= temp;
                arr[j+1].index = k;
            }
        }
    }
    
    i=0;
    while(i<itemn && WeightMain >0)
    {
        k = arr[i].index; 
        if(w[k]<=WeightMain)
        {
            Netprofit=Netprofit+P[k];
            frc[k]=1;
            WeightMain = WeightMain - w[k];
        }
        else
        {
            c=WeightMain/w[k];
            frc[k]=c;
            c=P[k]*c;
            Netprofit=Netprofit+c; 
            WeightMain = 0;
        }
        i++;
    }
}

int main()
{
    int i;
    printf("Enter the weight of the knapsack: ");
    scanf("%f",&WeightMain);
    printf("Enter the no of items\n"); 
    scanf("%d", &itemn);
    printf("\nEnter the weights\n"); 
    for(i=0;i<itemn; i++)
    {
        scanf("%f",&w[i]);
    }
    printf("\nEnter the profits\n");
    for(i=0;i<itemn;i++)
    {
        scanf("%f",&P[i]);
    }
    fractionalKnapsack();
    printf("the fractions taken are\n"); 
    for (i=0;i<itemn; i++)
    {
        printf("%f  ", frc[i]);
    }
    printf("\nThe net profit is %f", Netprofit); 
    return 0;
}