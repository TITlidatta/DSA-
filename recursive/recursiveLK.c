// Online C compiler to run C program online
#include <stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}NODE;
 
 NODE *head=NULL,*temp,*ptr,*countptr,*prev=NULL, *post, *revptr, *p,*xptr,*yptr;
 int i=0,i1=1;
 void create() 
{
    temp=(NODE*)malloc(sizeof(NODE));
    if(temp==NULL)
    {
        printf("\n!!!Out of Memory Space!!!\n");
        exit(0);
    }
    printf("\nEnter the data value for the node:\t");
    scanf("%d",&temp->data);
    temp->next=NULL;
    yptr=temp;
    if(head==NULL)
    {
        head=temp;
        countptr=head;
        revptr=head;
        xptr=head;
    }
    else
    {
        ptr=head;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=temp;
    }
}

void display()
{
    if(head==NULL)
    {
        printf("\nList is empty!!!\n");
    }
    else
    {
        ptr=head;
        printf("\nThe List elements are:\n\n");
        while(ptr!=NULL)
        {
            printf("%d\t",ptr->data );
            ptr=ptr->next ;
        }
        printf("NULL");
    }
}

int count_nodes()
{
    int c;
    if(head==NULL)
    {
        printf("No node");
        return 0;
    }
    else
    {
        if(countptr==NULL)
        {
            c=i;
            i=0;
            countptr=head;
            return c;
        }
        else
        {
            countptr=countptr->next;
            i++;
            return i+count_nodes();
        }
    }
}

void reverse() 
{
    if(head==NULL)
    {
        printf("\nList is too short to reverse!!!\n");
    }

    else
    {
       
        if(revptr!=NULL)
        {
            post=revptr->next;//post updating
            revptr->next=prev;//connecting ptr to prev
            prev=revptr;//updating prev
            revptr=post;//updating ptr
            reverse();
        }
        if(revptr==NULL)
        {
            head=prev;
        }
    }
}
int middle_node(int n)
{
    if(head==NULL)
    {
        printf("No node");
        return 0;
    }
    else
    {
        if(i1<n+1/2)
        {
            p=countptr;
            countptr=countptr->next;
            i1++;
            middle_node(n);
        }
        else
        {
            i1=1;
            countptr=head;
            printf("the element is%d ",p->data);
        }
    }
    return 0;
    
}
NODE* help()
{
    NODE* use;
    use=head;
    while(use->next!=yptr)
    {
        use=use->next;
    }
    
    return use;
}

void palindrome()
{

    if(xptr->data!=yptr->data)
    {
        printf("false");
    }
    else if(xptr->next==yptr || xptr==yptr)
    {
        if(xptr->next==yptr)
        {
            if(xptr->data==yptr->data)
            {
                printf("true");
            }
        }
        else
        {
            printf("true");
        }
    }
    else
    {
        xptr=xptr->next;
        NODE* previous=help();
        yptr=previous;
        palindrome();
    }
}

int main() 
{
    int choice,x;
    while(1)
    {
        printf("\n******************** MENU *******************");
        printf("\n 1.Create");
        printf("\n 2.Display");
        printf("\n 3.count nodes");
        printf("\n 4.reverse");
        printf("\n 5.find middle node");
        printf("\n 6.palindrome check");
        printf("\n 7.exiting");
        printf("\n--------------------------------------");
        printf("\nEnter your choice:\t");

        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                create();
                break;
            case 2:
                display();
                break;
            case 3:
                x=count_nodes();
                printf("No of nodes is %d",x);
                break;
            case 4:
                reverse();
                display();
                break;
            case 5:
                middle_node(count_nodes());
                break;
            case 6:
                palindrome();
                break;
            case 7:
                exit(0);
                break;
            default:
                printf("!!!Wrong Choice!!!");
                
        }
    }    
        
    return 0;
}