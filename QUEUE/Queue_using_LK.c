#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} NODE;

NODE *front = NULL, *temp, *ptr,*rear;

void Enqueue() 
{
    temp = (NODE *)malloc(sizeof(NODE));
    rear=temp;
    if (temp == NULL)
    {
        printf("\n!!!Out of Memory Space!!!\n");
        exit(0);
    }
    printf("\nEnter the data you want to enqueue:\t");
    scanf("%d", &temp->data);
    temp->next = NULL;
    rear=temp;
    if (front == NULL)
    {
        front= temp;
    }
    else
    {
        ptr = front;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
}
void Display() 
{
    if (front== NULL)
    {
        printf("\nList is empty!!!\n");
    }
    ptr=front;
    while(ptr!=NULL)
    {
        printf("%d\t2",ptr->data);
        ptr=ptr->next;
    }
}

void Dequeue() 
{
    if (front == NULL)
    {

        printf("\nList is Empty!!!");
    }
    else if (front->next == NULL)
    {
        ptr = front;
        front = NULL;
        printf("\nThe deleted element is:%d\t", ptr->data);
        free(ptr);
        rear=front;
    }
    else
    {
        ptr=front;
        front=front->next;
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
        printf("\n 1.Enqueue");
        printf("\n 2.Dequeue");
        printf("\n 3.Display");
        printf("\n 4.Exit");
        printf("\n--------------------------------------");
        printf("\nEnter your choice:\t");

        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            Enqueue();
            break;
        case 2:
            Dequeue();
            break;
        case 3:
            Display();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("!!!Wrong Choice!!!");
        }
    }
    return 0;
}