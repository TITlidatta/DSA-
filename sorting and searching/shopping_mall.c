// Online C compiler to run C program online
#include <stdio.h>
#include<string.h>

struct PRODUCT
{
    char name[20];
    int rating;
    int popularity;
    int price;
};

void swap(struct PRODUCT *a, struct PRODUCT *b)/* here two pointers pointing to two specific structure elements of the array of structures as given as input */
{
    int x,y,temp;
    temp =a->rating;
    a->rating=b->rating;
    b->rating=temp;
    strcpy(a->name,b->name);
    x=a->popularity;
    a->popularity=b->popularity;
    b->popularity=x;
    y=a->price;
    a->price=b->price;
    b->price=y;
}

void bubbleSort_price(struct PRODUCT *arr, int n)/* arr stores the address of the 1st element of array of structures*/
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++) 
        {
            if (arr[j].price > arr[j + 1].price)
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}


void bubbleSort_rating(struct PRODUCT *arr, int n)/* arr stores the address of the 1st element of array of structures*/
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++) 
        {
            if (arr[j].rating > arr[j + 1].rating)
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void bubbleSort_popularity(struct PRODUCT *arr, int n)/* arr stores the address of the 1st element of array of structures*/
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++) 
        {
            if (arr[j].popularity > arr[j + 1].popularity)
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int main() 
{
    int n,i;
    char c;
    struct PRODUCT list[20];
    printf("Enter the number of products\n");
    scanf("%d",&n);
    printf("Enter the name ,rating, popularity, price\n");
    for( i=0;i<n;i++)
    {
        scanf("%s",list[i].name);
        scanf(" %d",&list[i].rating);
        scanf(" %d",&list[i].popularity);
        scanf(" %d",&list[i].price);
    }
    printf("Presenting for pricewise sorted products");
    printf("ascending-A or descendind -D\n");
    scanf(" %c",&c);
    bubbleSort_price(&list[0],n);
    if(c=='D')
    {
        for(i=0;i<n;i++)
        {
            printf("%s",list[i].name);
            printf(" %d",&list[i].rating);
            printf(" %d",&list[i].popularity);
            printf(" %d",&list[i].price);
            printf("\n");
        }
    }
    else
    {
        for(i=n-1;i<=0;i--)
        {
            printf("%s",list[i].name);
            printf(" %d",&list[i].rating);
            printf(" %d",&list[i].popularity);
            printf(" %d",&list[i].price);
            printf("\n");
        }
    }
        
    printf("Presenting for ratingwise sorted products");
    printf("ascending-A or descendind -D\n");
    scanf(" %c",&c);
    bubbleSort_rating(&list[0],n);
    if(c=='D')
    {
        for(i=0;i<n;i++)
        {
            printf("%s",list[i].name);
            printf(" %d",&list[i].rating);
            printf(" %d",&list[i].popularity);
            printf(" %d",&list[i].price);
            printf("\n");
        }
    }
    else
    {
        for(i=n-1;i<=0;i--)
        {
            printf("%s",list[i].name);
            printf(" %d",&list[i].rating);
            printf(" %d",&list[i].popularity);
            printf(" %d",&list[i].price);
            printf("\n");
        }
    }
        
    printf("Presenting for popularitywise sorted products");
    printf("ascending-A or descendind -D\n");
    scanf(" %c",&c);
    bubbleSort_popularity(&list[0],n);
    if(c=='D')
    {
        for(i=0;i<n;i++)
        {
            printf("%s",list[i].name);
            printf(" %d",&list[i].rating);
            printf(" %d",&list[i].popularity);
            printf(" %d",&list[i].price);
            printf("\n");
        }
    }
    else
    {
        for(i=n-1;i<=0;i--)
        {
            printf("%s",list[i].name);
            printf(" %d",&list[i].rating);
            printf(" %d",&list[i].popularity);
            printf(" %d",&list[i].price);
            printf("\n");
        }
    }
        
    return 0;
}