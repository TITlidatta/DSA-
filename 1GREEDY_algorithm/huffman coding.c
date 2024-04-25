//huffman coding

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

char msg[100];
int occr[30];
int k,d;//k keeps the track of last index of arr
int tcount=0;//track counter
int sum=0;
int spcounter=0;// to take input in  tcount
int encode[100];
struct node* charAlist[40];
struct box
{
    char x;
    int oc;
};
struct node
{
    int z;
    char y;
    struct node *parent;
    struct node *l;
    struct node *r;
};

struct sp
{
    struct node *p;
    int val;
};
struct sp track[30];
struct box arr[30];
struct node *head =NULL;

void Tree()
{
    int i,j,ll=0,lr=0;
    char just1;
    int just2;
    struct node *ptrl,*ptrr;
    int min1 = arr[0].oc;
    if(arr[0].x == '\0')
    {
        ll=1;
    }
    int min2= arr[1].oc;
    if(arr[1].x == '\0')
    {
        lr=1;
    }
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    if(ll==0)
    {
        ptrl = (struct node*)malloc(sizeof(struct node));
        ptrl->l=NULL;
        ptrl->r=NULL;
        ptr->l=ptrl;
        ptrl->z = min1;
        ptrl->y = arr[0].x;
        just1=ptrl->y;
        just2=just1 - 'A';
        charAlist[just2]=ptrl;

    }
    else
    {
        ptrl =track[tcount].p;
        tcount++;
        ptr->l=ptrl;
    }

    if(lr==0)
    {
        ptrr = (struct node*)malloc(sizeof(struct node));
        ptrr->l=NULL;
        ptrr->r=NULL;
        ptr->r=ptrr;
        ptrr->z = min2;
        ptrr->y=arr[1].x;
        just1=ptrr->y;
        just2=just1 - 'A';
        charAlist[just2]=ptrr;
    }
    else
    {
        ptrr =track[tcount].p;
        tcount++;
        ptr->r=ptrr;
    }
    ptr->z = min1+min2;
    ptr->y='\0';
    d=ptr->z;
    track[spcounter].p=ptr;
    track[spcounter].val=d;
    spcounter++;
    if(d==sum)
    {
        head=ptr;
    }
    ptrl->parent = ptr;
    ptrr->parent = ptr;
    j=0;
    while(arr[j].oc<=d && j<=k)
    {
        j++;
    }
    for(i=2;i<j;i++)
    {
        arr[i-2].oc=arr[i].oc;
        arr[i-2].x=arr[i].x;
    }
    arr[j-2].oc=d;
    arr[j-2].x ='\0';
    for(i=j;i<=k;i++)
    {
        arr[i-1].oc=arr[i].oc;
        arr[i-1].x=arr[i].x;
    }    
    k=k-1;
    return;
}

void Huffman()
{
    int i,j,temp;
    char cx;
    for(i=0;i<=k;i++)
    {
        for(j=0;j<=k-1;j++)
        {
            if(arr[j].oc> arr[j+1].oc)
            {
                temp= arr[j+1].oc;
                arr[j+1].oc=arr[j].oc;
                arr[j].oc=temp;
                cx= arr[j+1].x;
                arr[j+1].x=arr[j].x;
                arr[j].x=cx;
            }
        }
    }
    while(k>0)
    {
        Tree();
    }
    
    return;

}
int traverse(struct node *h)//to encode or decode msg
{
    int g =0,sumx=0;
    while(h->z != sum)
    {
        if(h->parent->l->y == h->y)
        {
            sumx=sumx+(pow(10,g))*0;
            g++;
        }
        else
        {
            sumx=sumx+(pow(10,g))*1;
            g++;
        }
        h=h->parent;
    }
    return sumx;
}

int main()
{
    int i,indx,c;
    struct node *temp;
    printf("Enter the length of msg :");
    scanf("%d",&indx);
    printf("Enter the msg:\n");
    scanf("%s",msg);
    printf("\n");
    for(i=0;i<26;i++)
    {
        occr[i]=0;
    }
    for(i=0;i<strlen(msg);i++)
    {
        occr[msg[i]-65]=occr[msg[i]-65]+1;
    }
    k=0;
    for(i=0;i<26;i++)
    {
        if(occr[i]>0)
        {
            arr[k].x = 65+i;
            arr[k].oc = occr[i];
            sum=sum+arr[k].oc;
            k++;
        }
        else
        {
            continue;
        }
    }
    k=k-1;
    Huffman();
    for(i=0;i<=25;i++)
    {
        encode[i]=-1;
    }

    for(i=0;i<=25;i++)
    {
        if(occr[i]>0)
        {
            temp = charAlist[i];
            c=traverse(temp);
            encode[i]=c;
        }
    }
    for(i=0;i<=25;i++)
    {
        if(encode[i]>=0)
        {
            printf("%d :  %d\n",i,encode[i]);
        }
    }
    return 0;
}