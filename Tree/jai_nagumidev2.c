/*1.insert a key in BST
2. diameter of Binary tree=max(lh,rh)
3. max path sum
4. search in BST
5.BFS*/
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
NODE* queue[30];
int rear,front,newlin=0;

void BST_insertKey(NODE *bstp,int val1)
{
    if(bstp==NULL && bstp !=root)
    {
        return;
    }
    if(root==NULL)
    {
        temp=(NODE*)malloc(sizeof(NODE));
        temp->right=NULL;
        temp->left=NULL;
        temp->data=val1;
        root=temp;
    }
    else
    {
        if(bstp->data<val1)
        {
            if(bstp->right!=NULL)
            {
                BST_insertKey(bstp->right,val1);
            }
            else
            {
                temp=(NODE*)malloc(sizeof(NODE));
                temp->right=NULL;
                temp->left=NULL;
                temp->data=val1;
                bstp->right=temp;
                return;
            }
        }
        else if(bstp->data>val1)
        {
            if(bstp->left!=NULL)
            {
                BST_insertKey(bstp->left,val1);
            }
            else
            {
                temp=(NODE*)malloc(sizeof(NODE));
                temp->right=NULL;
                temp->left=NULL;
                temp->data=val1;
                bstp->left=temp;
                return;
            }
        }
    }
}
//__________________________________________________________
int search_BST(NODE*bstp2,int val2)
{
    if(bstp2==NULL)
    {
        return 0;
    }
    if(bstp2->data==val2)
    {
        return 1;
    }
    if(bstp2->data>val2)
    {
        return 0+search_BST(bstp2->left,val2);
    }
    if(bstp2->data<val2)
    {
        return 0+search_BST(bstp2->right,val2);
    }
}
//--------------------------------------------------------------------------
/*int rear=-1, front=-1;
NODE* queue[15];
int newlin=0;  globally*/
int dequeue()
{
    int ans;
    ans=queue[front]->data;
    front++;
    return ans;
}
bool isemptyqueue()
{
    if(front>rear || front==rear==-1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void enqueue(NODE *pointbfs)
{
    rear++;
    queue[rear]=pointbfs;
}
void BFS()
{
    int x,y,i;
    y=front;
    x=rear-front;
    if(isemptyqueue())
    {
        return;
    }
    newlin++;
    for(i=y;i<=x+y;i++)
    {
        if(queue[i]->left!=NULL)
        {
            enqueue(queue[i]->left);
        }
        if(queue[i]->right!=NULL)
        {
            enqueue(queue[i]->right);
        }
        if(newlin%2!=0)
        { 
            printf("\n");
        }
        printf("%d ",dequeue());
        if(newlin%2!=0)
        { 
            printf("\n");
        }
    }
    BFS();
    return;
}
//_____________________________________________________________________________
/*longest node traverse gives max path but if values are lower or something MAXP handles that and we return the maximum path weight through that node we are talking about and MAXP checks itself with a current node's right path +left path+ node weight*/
/*also  GLOBAL MAXP computes recent maximum weighted U path through a particular node with the old value stored in it and updates*/

int Maximum_pathsum(NODE *ptpp)
{
    int leftsum,rightsum,MAXP;
    if(ptpp==NULL)
    {
        return 0;
    }
    leftsum=Maximum_pathsum(ptpp->left);
    rightsum=Maximum_pathsum(ptpp->right);
    MAXP=max(MAXP,ptpp->data+leftsum+rightsum);
    return ptpp->data+max(leftsum,rightsum);
}
/* in the main print maxp after calling this func with root*/
//------------------------------------------------------------------------
//longest possible path of any two nodes  -- path travel node no count
int diameter(NODE *ptpz)
{
    int MAXD;
    if(ptpz==NULL)
    {
        return 0;
    }
    int leftH=diameter(ptpz->left);
    int rightH=diameter(ptpz->right);
    MAXD=max(MAXD,1+leftH+rightH);
    return 1+max(leftH,rightH);
}
//-------------------------------------------------------------------
/* in the main             
NODE *sun=LCA_bst(root,2,6);
printf("%d",sun->data);*/

NODE* LCA_bst(NODE *pbstt, int a, int b)
{
    if (pbstt == NULL)
    {
        return; 
    }
    else
    {
        if(pbstt->data>a && pbstt->data>b)
        {
            LCA_bst(pbstt->left,a,b);
        }
        else if(pbstt->data<a && pbstt->data<b)
        {
            LCA_bst(pbstt->right,a,b);
        }
        else
        {
            return pbstt;
        }
    }
}
//----------------------------------------------------------------------
/*in the main function if flag = true after function call print true else print false*/
int absx(int a,int b)
{
    if(a>=b)
    {
        return a-b;
    }
    else
    { 
        return b-a;
    }
}
int check_BalancedTree(NODE *p)
{
    int z;
    if(p==NULL)
    {
        return 0;
    }
    else
    {
        z=absx(height(p->left),height(p->right));
        if(z>1)
        {
            flag=false;
        }
        return 1 +max(height(p->left),height(p->right));;
    }
}
//---------------------------------------------------------------------------
/*if we get only sorted inorder we can construct any kind of bst taking anyone as head but to create a balanced bst we have to consider the middle as head 
/// to create any other bst unique bst we need its post or preorder along with its inorder to determine its head and flow - NOTE SORTED pre or post gives inorder*/ 
