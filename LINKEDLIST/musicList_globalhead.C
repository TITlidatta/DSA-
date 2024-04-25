#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*Create node*/
typedef struct node
{
    char title[100];
    char artist[100];
    struct node *next;
}song;

void addSong(char Title[],char Artist[]);
void display();
void deleteSong(char Title[]);
void searchSong(char Title[]);
int playplaylist();
song  *head=NULL,*temp, *ptr;

int main() 
{
    char Title[100], Artist[100];
    int choice;
    while (1)
    {
        printf("\n******************** MENU *******************");
        printf("\n 1.ADD song");
        printf("\n 2.Display");
        printf("\n 3.delete song");
        printf("\n 4.Exit");
        printf("\n 5. Search");
        printf("\n 6.play playlist");
        printf("\n--------------------------------------");
        printf("\nEnter your choice:\t");

        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter title");
            scanf("%s", Title);
            printf("\nEnter artist");
            scanf("%s", Artist);
            addSong(Title, Artist);
            break;
        case 2:
            display();
            break;
        case 3:
            printf("Enter title");
            scanf("%s", Title);
            deleteSong(Title);
            break;
        case 4:
            exit(0);
            break;
        case 5:
            printf("Enter title");
            scanf("%s", Title);
            searchSong(Title);
            break;
        case 6:
            playplaylist();
            break;
        default:
            printf("!!!Wrong Choice!!!");
        }
    }
 return 0;
} 
void addSong(char Title[],char Artist[])
{
    temp = (song *)malloc(sizeof(song));
    strcpy(temp->title,Title);
    strcpy(temp->artist,Artist);
    
    temp->next = NULL;
    if (temp == NULL)
    {
        printf("\n!!!Out of Memory Space!!!\n");
        exit(0);
    }

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

void display() 
{
    if (head == NULL)
    {
        printf("\nList is empty!!!\n");
    }
    else
    {
        ptr = head;
        printf("\nThe List elements are:\n\n");
        while (ptr != NULL)
        {
            printf("%s\t", ptr->title);
            printf("%s\n", ptr->artist);
            ptr = ptr->next;
        }
        printf("NULL");
    }
}

void deleteSong(char Title[]) 
{
    int i;
    if (head == NULL)
    {
        printf("\nThe List is Empty!!!\n");
    }
    else if((strcmp(head->title,Title)==0)&& (head->next==NULL))
    {
        temp=head;
        head=head->next;
        free(temp);
        printf("deleted task");
    }
    else
    {
        ptr = head;

        while (ptr!=NULL)
        {
            if (strcmp(ptr->title,Title)==0)
            {
                break;
            }
            temp = ptr;
            ptr = ptr->next;
        }
        if (ptr == NULL)
        {
            printf("\nSong not Found:\n");
        }
        temp->next = ptr->next;
        printf("\nSong deleted");
        free(ptr);
    }
}

void searchSong(char Title[]) 
{
    int i=1;

    if (head == NULL)
    {
        printf("\nList is empty!!!!\n");
    }
    else
    {
        ptr = head;
        while (ptr != NULL)
        {
            if (strcmp(ptr->title,Title)==0)
            {
                printf("\nValue is found at position %d", i);
                break;
            }
            ptr = ptr->next;
            i=i+1;
        }
    }
    if(ptr==NULL)
    {
        printf("-1");
    }
}

int playplaylist()
{
    char str[5];
    if(head==NULL)
    {
        printf("No playlist to play");
    }
    else
    {
        ptr=head;
        while(ptr!=NULL)
        {   
            printf("playing %s by %s",ptr->title,ptr->artist);
            printf("\nNEXT?\t Yes or No\n");
            scanf("%s",str);
            if(strcmp(str,"Yes")==0)
            {
                ptr=ptr->next;
            }   
            else
            {
                break;
            }
        }
    }
    return 0;
}
