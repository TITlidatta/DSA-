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
 
NODE *root=NULL, *ptr;
bool flag=false;

void IPo_tree(int irr[],int prr[],NODE *head,int sizeprr,int sizeirr,int check,char x)
{
    //in the main give check as 0;x as M,head as the main root 
    int ii=0,k,j,inorderL[50],postorderL[50],inorderR[50],postorderR[50],checkL=-1,checkR=-1;
    NODE *temp;
    if(check==-1)
    {
        head=NULL;
        return;
    }
    temp=(NODE*)malloc(sizeof(NODE));
    temp->data=prr[sizeprr];
    if(root==NULL)
    {
        root=temp;
    }
    else
    {
        if(x=='L')
        {
            head->left=temp;
        }
        else if(x=='R')
        {
            head->right=temp;
        }
    }
    
    while(irr[ii]!=prr[sizeprr])
    {
        ii=ii+1;
    }
    for(j=0;j<=ii-1;j++)
    {
        inorderL[j]=irr[j];
        checkL++;
    }
    //last index of inorder of left side =ii-1
    k=0;
    for(j=ii+1;j<=sizeirr;j++)
    {
        inorderR[k]=irr[j];
        checkR++;
        k++;
    }
    //last index of inorder of last index of right side = k-1
    for(j=0;j<=ii-1;j++)
    {
        postorderL[j]=prr[j];
    }
    //last index of preorder of left side =ii-1
    k=0;
    for(j=ii;j<sizeprr;j++)
    {
        postorderR[k]=prr[j];
        k++;
    }
    //last index of preorder of last index of right side = k-1
    
    IPo_tree(inorderL,postorderL,temp,ii-1,ii-1,checkL,'L');
    IPo_tree(inorderR,postorderR,temp,k-1,k-1,checkR,'R');
    return;
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

int main() 
{
  
    int v,choice,k,i,n,arr1[15],arr2[15];
    char ch;
    NODE *tosee;
    while (1)
    {
        printf("\n**** MENU ***");
        printf("\n 1.Create");
        printf("\n 2.Display_inorder");
        printf("\n 3.Display_postorder");
        printf("\n 4.Display_preorder");
        printf("\n 5.Exit");
        printf("\n--------------------------------------");
        printf("\nEnter your choice:\t");

        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the size of the array\n");
            scanf("%d",&n);
            printf("Enter the inorder\n");
            for(i=0;i<n;i++)
            {
                scanf("%d",&arr1[i]);
            }
            printf("Enter the postorder\n");
            for(i=0;i<n;i++)
            {
                scanf("%d",&arr2[i]);
            }
            IPo_tree(arr1,arr2,root,n-1,n-1,0,'M');
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
            exit(0);
            break;
        default:

            printf("!!!Wrong Choice!!!");
        }
    }
    return 0;
}