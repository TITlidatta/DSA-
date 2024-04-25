/*Some Operations on Doubly Linked List*/
#include<stdlib.h>
#include <stdio.h>

/* Function prototypes */
void create();
void display();
void insert_begin();
void insert_end();
void insert_pos();
void delete_begin();
void delete_end();
void delete_pos();

/*Create node*/
typedef struct node
{
    struct node *prev;
    int data;
    struct node *next;
}NODE;

NODE *head=NULL,*temp,*ptr;

int main() /*main() function*/
{
    int choice;
    while(1)
    {
        printf("\n******************** MENU *******************");
        printf("\n 1.Create");
        printf("\n 2.Display");
        printf("\n 3.Insert at the beginning");
        printf("\n 4.Insert at the end");
        printf("\n 5.Insert at specified position");
        printf("\n 6.Delete from beginning");
        printf("\n 7.Delete from the end");
        printf("\n 8.Delete from specified position");
        printf("\n 9.Exit");
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
                insert_begin();
                break;
            case 4:
                insert_end();
                break;
            case 5:
                insert_pos();
                break;
            case 6:
                delete_begin();
                break;
            case 7:
                delete_end();
                break;
            case 8:
                delete_pos();
                break;
            case 9:
                exit(0);
                break;
            default:
                printf("!!!Wrong Choice!!!");
        }
    }
   return 0;
} /*End of main()*/

void create() /* Definition of create() function*/
{
    temp=(NODE*)malloc(sizeof(NODE));
    if(temp==NULL)
    {
        printf("\n!!!Out of Memory Space!!!\n");
    }
    printf("\nEnter the data value for the node:\t");
    scanf("%d",&temp->data);
    temp->next=NULL;
    temp->prev=NULL;
    if(head==NULL)
    {
        head=temp;
    }
    else    
    {
        ptr=head;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=temp;
        temp->prev=ptr;
    }
    display();
}

void display() /* Definition of display() function*/
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
void insert_begin()
{
    temp=(NODE *)malloc(sizeof(NODE));
    if(temp==NULL)
    {
        printf("\n!!!Out of Memory Space:!!!\n");
    }
    printf("\nEnter the data value for the node:\t" );
    scanf("%d",&temp->data);
    temp->next =NULL;
    temp->prev=NULL;
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        temp->next=head;
        head->prev=temp;
        head=temp;
    }
    display();
}

void insert_end() /* Definition of insert_end() function*/
{
    temp=(NODE *)malloc(sizeof(NODE));
    if(temp==NULL)
    {
        printf("\n!!!Out of Memory Space!!!\n");
    }
    printf("\nEnter the data value for the node:\t" );
    scanf("%d",&temp->data );
    temp->next =NULL;
    temp->prev=NULL;
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        ptr=head;
        while(ptr->next !=NULL)
        {
            ptr=ptr->next ;
        }
        temp->prev=ptr;
        ptr->next =temp;
    }
    display();
}

void insert_pos() /* Definition of insert_pos() function*/
{
    int i, pos;
    temp=(NODE *)malloc(sizeof(NODE));
    if(temp==NULL)
    {
        printf("\n!!!Out of Memory Space!!!\n");
    }
    printf("\nEnter the position for the new node to be inserted:\t");
    scanf("%d",&pos);
    printf("\nEnter the data value of the node:\t");
    scanf("%d",&temp->data) ;
    temp->next=NULL;
    temp->prev=NULL;
    if(pos==1)
    {
        temp->next=head;
        head->prev=temp;
        head=temp;
    }
    else
    {
        for(i=1,ptr=head;i<pos-1;i++)
        { 
            ptr=ptr->next;
            if(ptr==NULL)
            {
                printf("\nPosition not found!!!\n");
            }
        }
        temp->next =ptr->next ;
        ptr->next->prev=temp;
        ptr->next=temp;
        temp->prev=ptr;
    }
    display();
}


void delete_begin() /* Definition of delete_begin() function*/
{
    if(head==NULL)
    {
        printf("\nList is Empty!!!\n");
    }
    else
    {
        ptr=head;
        head->next->prev=NULL;
        head=head->next ;
        printf("\nThe deleted element is :%d\t",ptr->data);
        free(ptr);
    }
    display();
}


void delete_end() /* Definition of delete_end() function*/
{
    if(head==NULL)
    {
        printf("\nList is Empty!!!");
    }
    else if(head->next ==NULL)
    {
        ptr=head;
        head=NULL;
        printf("\nThe deleted element is:%d\t",ptr->data);
        free(ptr);
    }
    else
    {
        ptr=head;
        while(ptr->next!=NULL)
        {
            temp=ptr;
            ptr=ptr->next;
        }
        temp->next=NULL;
        printf("\nThe deleted element is:%d\t",ptr->data);
        free(ptr);
    }
    display();
}


void delete_pos() /* Definition of delete_pos() function*/
{
    int i,pos;
    if(head==NULL)
    {
        printf("\nThe List is Empty!!!\n");
    }
    else
    {
        printf("\nEnter the position of the node to be deleted:\t");
        scanf("%d",&pos);
        if(pos==1)
        {
            ptr=head;
            head->next->prev=NULL;
            head=head->next ;
            printf("\nThe deleted element is:%d\t",ptr->data );
            free(ptr);
        }
        else
        {
            ptr=head;
            for(i=1;i<pos;i++)
            {
                temp=ptr;
                ptr=ptr->next ;
                if(ptr==NULL)
                {
                    printf("\nPosition not Found:\n");
                }
            }
            temp->next =ptr->next;
            ptr->next->prev=temp;
            printf("\nThe deleted element is:%d\t",ptr->data );
            free(ptr);
            }
        }
        
    display();
}