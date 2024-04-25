#include <stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}NODE;
 
 NODE *head1=NULL,*head2=NULL,*temp,*ptr;
 void create(NODE*head) 
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
    if(head==NULL)
    {
        printf("NULL");
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
    }
}

void display(NODE *headd)
{
    if(headd==NULL)
    {
        printf("\nList is empty!!!\n");
    }
    else
    {
        ptr=headd;
        printf("\nThe List elements are:\n\n");
        while(ptr!=NULL)
        {
            printf("%d\t",ptr->data );
            ptr=ptr->next ;
        }
        printf("NULL");
    }
}

void sort(NODE *Head) /* Definition of sort() function*/
{
    int temp;
    NODE *ptr1, *ptr2;
    ptr1=Head;
    if(ptr1==NULL)
    {
        printf("\nList not found!!!");
    }
    while(ptr1->next!=NULL)
    {
        ptr2=ptr1->next;
        while(ptr2!=NULL)
        {
            if(ptr1->data>ptr2->data)
            {
                temp=ptr1->data;
                ptr1->data=ptr2->data;
                ptr2->data=temp;
            }
            ptr2=ptr2->next;
        }
        ptr1=ptr1->next;
    }
    display(Head);
}

void merge_sort(NODE *head1,NODE *head2)
{
    if(ptr->next!=NULL)
    {
        ptr=ptr->next;
        merge_sort(head1,head2);
    }
    else
    {
        ptr->next=head2;
        free(head2);
        sort(head1);
    }
}

int main()
{
    
    int choice;
    int ch;
    while(1)
    {
        printf("\n******************** MENU *******************");
        printf("\n 1.Create");
        printf("\n 2.Display");
        printf("\n 3.merge and sort");
        printf("\n 4.exit");
        printf("\n--------------------------------------");
        printf("\nEnter your choice:\t");

        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("if you want to enter to 1st linkedlist enter 1 else 2");
                scanf("%d",&ch);
                if(ch==1)
                { 
                    create(head1);
                }
                else
                {
                    create(head2);
                }
                break;
            case 2:
                printf("\nif you want to display 1st linkedlist enter 1 else 2\n");
                scanf("%d",&ch);
                if(ch==1)
                { 
                    display(head1);
                }
                else
                {
                    display(head2);
                }
                break;
            case 3:
                ptr=head1;
                merge_sort(head1,head2);
                display(head1);
                break;
            case 4:
                exit(0);
                break;
        }        
      
    }    
    return 0;
}