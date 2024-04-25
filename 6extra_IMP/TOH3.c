void TowerofHanoiO(char A, char B, char C,int n)// from x to z using y
{

    if(n<=0)
    {
        return;
    }
    TowerofHanoiO(A,C,B,n - 1); // move n-1 disk from A to B using C
    printf("Moving a disk from %c to %c \n",A,C);
    TowerofHanoiO(B,A,C,n - 1);// move n-1 disk from B to C using A 
    
}

int main() 
{
    int n;
    printf("Enter the number of disk :");
    scanf("%d",&n);
    TowerofHanoiO('A','B','C',n);// A to C where B is helper
    return 0;
}    