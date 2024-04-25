#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} NODE;

NODE *head = NULL, *temp, *ptr,*top,*yptr;

void Push() 
{
    temp = (NODE *)malloc(sizeof(NODE));
    if (temp == NULL)
    {
        printf("\n!!!Out of Memory Space!!!\n");
        exit(0);
    }
    printf("\nEnter the data you want to push:\t");
    scanf("%d", &temp->data);
    temp->next = NULL;
    top=temp;
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
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

void Display() 
{
    if (head == NULL)
    {
        printf("\nList is empty!!!\n");
    }
    yptr=top;
    while(yptr!=head)
    {
        printf("%d\n",yptr->data);
        NODE*previous=help();
        yptr=previous;
    }
    printf("%d",head->data);
}

int IsEmpty()
{
    if(top==head)
    {
        printf("Empty");
    }
    else
    {
        printf("Not Empty");
    }
    return 0;
}
void Pop() 
{
    if (head == NULL)
    {

        printf("\nList is Empty!!!");
    }
    else if (head->next == NULL)
    {
        ptr = head;
        head = NULL;
        printf("\nThe deleted element is:%d\t", ptr->data);
        free(ptr);
        top=head;
    }
    else
    {
        ptr = head;
        while (ptr->next != NULL)
        {
            temp = ptr;
            ptr = ptr->next;
        }
        top=temp;
        temp->next = NULL;
        printf("\nThe deleted element is:%d\t", ptr->data);
        free(ptr);
    }
}



int main()
{
      int choice;
    while (1)
    {
        printf("\n******************** MENU *******************");
        printf("\n 1.Push");
        printf("\n 2.Pop");
        printf("\n 3.Display");
        printf("\n 4.Is empty");
        printf("\n 5.Exit");
        printf("\n--------------------------------------");
        printf("\nEnter your choice:\t");

        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            Push();
            break;
        case 2:
            Pop();
            break;
        case 3:
            Display();
            break;
        case 4:
            IsEmpty();
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("!!!Wrong Choice!!!");
        }
    }
    return 0;
}
