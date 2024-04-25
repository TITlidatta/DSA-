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

void IPo_tree(int irr[],NODE *head,int sizeirr,int check,char x)
{
    //in the main give check as 0;x as M,head as the main root 
    int ii=0,k,j,inorderL[50],inorderR[50],checkL=-1,checkR=-1;
    NODE *temp;
    if(check==-1)
    {
    	if(x=='L')
	{	
	    head->left=NULL;
	    return;
	}
	if(x=='R')
	{	
	    head->right=NULL;
	    return;
	}
    }
    ii=sizeirr/2;
    printf("%d\n",ii);
    temp=(NODE*)malloc(sizeof(NODE));
    temp->data=irr[ii];
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
    
    IPo_tree(inorderL,temp,ii-1,checkL,'L');
    IPo_tree(inorderR,temp,k-1,checkR,'R');
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
        printf("\n 3.Exit");
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
            IPo_tree(arr1,root,n-1,0,'M');
            printf("%d",root->data);
            printf("\n%d",root->left->data);
            printf("\n%d",root->right->data);
            printf("\n%d",root->left->left->data);
            printf("\n%d",root->left->right->data);
            printf("\n%d",root->right->left->data);
            printf("\n%d",root->right->right->data);
            if(root->right->right->right==NULL)
            {
            	printf("\n true");
            }
	    else
            {
             	printf("\n false");
            }
            break;
        case 2:
            display_inorder(root);
            break;
        case 3:
            exit(0);
            break;
        default:

            printf("!!!Wrong Choice!!!");
        }
    }
    return 0;
}