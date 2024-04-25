// Online C compiler to run C program online
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
}NODE;
 
NODE *root=NULL, *ptr, *temp;
bool flag=false;

void create(int v,int k,char ch, NODE *ptrxx, NODE *temp1)
{
    if(ptrxx==NULL && ptrxx !=root)
    {
        return;
    }

    if(root==NULL)
    {
        root=temp1;
    }
    else
    {
        if(ptrxx->data==k)
        {
            if(ch=='L')
            {
                ptrxx->left=temp1;
            }
            else
            {
                ptrxx->right=temp1;
            }
        }
        else
        {
            create(v,k,ch,ptrxx->right,temp1);
            create(v,k,ch,ptrxx->left,temp1);
        }
    }
}

void display_inorder(NODE *ptry)
{
    if(ptry==NULL)
    {
        return;
    }
    else
    {
        display_inorder(ptry->left);
        printf("%d ",ptry->data);
        display_inorder(ptry->right);
    }
}

void display_postorder(NODE *ptrz)
{
    if(ptrz==NULL)
    {
        return;
    }
    else
    {
        display_postorder(ptrz->left);
        display_postorder(ptrz->right);
        printf("%d ",ptrz->data);
    }
}

void display_preorder(NODE *ptrw)
{
    if(ptrw==NULL)
    {
        return;
    }
    else
    {
        printf("%d ",ptrw->data);
        display_preorder(ptrw->left);
        display_preorder(ptrw->right);

    }      
}

int traverse(int k,NODE *point)//traverse_to_find_presence_in_that_direction
{
    if((point->left->data==k) || (point->right->data==k))
    {
        return 1;
    }
    else
    {
        return 0+ traverse(k,point->left) + traverse(k,point->right);
    }
}

char search_left_right(int k, NODE *pointer)//presence in the right or left subtree
{
    if (traverse(k,pointer->left)==1)
    {
        return 'L';
    }
    else
    {
        return 'R';
    }
}

int max(int a,int b)
{
    if(a>=b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int height(NODE *p)
{
    if(p==NULL)
    {
        return 0;
    }
    else
    {
        return 1 +max(height(p->left),height(p->right));
    }
}

int count_leaf_nodes(NODE *px)
{
    if(px->left==NULL && px->right==NULL)
    {
        return 1;
    }
    else
    {
        return 0 +count_leaf_nodes(px->left) +count_leaf_nodes(px->right);
        
    }
}

NODE* LCA(NODE *pt,int a, int b)
{
  if(pt==NULL)
  {
      return NULL;
  }
  else if(pt->data==a)
  {
      return pt;
  }
  else if(pt->data==b)
  {
      return pt;
  }
  else
  {
    if(LCA(pt->left,a,b)==NULL & LCA(pt->right,a,b)==NULL)
    {
        return NULL;
    }
    else if(LCA(pt->left,a,b)==NULL)
    {
        return LCA(pt->right,a,b);
    }
    else if(LCA(pt->right,a,b)==NULL)
    {
        return LCA(pt->left,a,b);
    }
    else
    {
        return pt;
    }
  }
}

void path_left(int a, int b,NODE *tempo)
{
    //tempo=LCA(root,a,b);
    if(tempo->data==a || tempo->data==b)
    {
        printf("%d ->",tempo->data);
        return;
    }
    else
    {
        path_left(a,b,tempo->left);
        printf("%d ->",tempo->data);
        return;
    }
}
void path_right(int a, int b,NODE *t)
{
    //t=LCA(root,a,b);
    if(t->data==a || t->data==b)
    {
        printf("%d",t->data);
        return;
    }
    else
    {
        printf("%d ->",t->data);
        path_right(a,b,t->right);
        return;
    }
}
void path(int a, int b, NODE *ptp)
{
    path_left(a,b,ptp);//here ptp is the LCA
    path_right(a,b,ptp->right);
}

int main() 
{
  
    int v,choice,k;
    char ch;
    NODE *tosee;
    while (1)
    {
        printf("\n******************** MENU *******************");
        printf("\n 1.Create");
        printf("\n 2.Display_inorder");
        printf("\n 3.Display_postorder");
        printf("\n 4.Display_preorder");
        printf("\n 5.count leaf nodes");
        printf("\n 6.find LCA");
        printf("\n 7.path");
        printf("\n 8.height");
        printf("\n 9.Exit");
        printf("\n--------------------------------------");
        printf("\nEnter your choice:\t");

        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the node value to whom you want to extend.\n");
            scanf("%d",&k);
            printf("Enter L or R\n ");
            scanf(" %c",&ch);
            temp=(NODE*)malloc(sizeof(NODE));
            printf("Enter the value to insert\n");
            scanf("%d",&v);
            temp->data=v;
            create(v,k,ch,root,temp);
            break;
        case 2:
            display_inorder(root);
            break;
        case 3:
            display_postorder(root);
            break;
        case 4:
            display_preorder(root);
            break;
        case 5:
            count_leaf_nodes(root);
            break;
        case 6:
            tosee=LCA(root,13,6);
            printf("%d",tosee->data);
            break;
        case 7:
            path(13,6,tosee);
            break;
        case 8:
            printf("%d",height(root));
            break;
        case 9:
            exit(0);
            break;
        default:

            printf("!!!Wrong Choice!!!");
        }
    }
    return 0;
}