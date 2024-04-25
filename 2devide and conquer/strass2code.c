#include <stdio.h>
#include<stdlib.h>

int* add(int* arr, int* brr, int n) 
{
    int i, j;
    int* tempx = (int*)malloc(n * n * sizeof(int));

    for (i=0;i<n;i++) 
    {
        for (j=0;j<n;j++) 
        {
            *(tempx + i*n + j) = *(arr + i*(n) + j) + *(brr + i*(n) + j);
        }
    }
    return tempx;
}

int* sub(int* arr, int* brr, int n)
{
    int i, j;
    int* tempy = (int*)malloc(n * n * sizeof(int));

    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            *(tempy + i*n + j) = *(arr + i*(n) + j) - *(brr + i*(n) + j);
        }
    }
	
    return tempy;
}


int* Strassans(int* arr,int* brr,int n)
{
    int x= n/2,i,j;
    x=x+1;
    int k=n/2;
	int* res = (int*)malloc((n + 1) * (n + 1) * sizeof(int));
    if(n==1)
    {
      
	   for(i=0;i<=n;i++)
	   { 
	      for(j=0;j<=n;j++)
	      {
	      	*(res+i*(n+1)+j) = 0;
            for (int l = 0; l < 2; l++)
			 {
                *(res+i*(n+1)+j) += *(arr +i*(n+1)+l) * *(brr +l*(n+1)+j) ;
            }
		  }
	   }
	    return res;
	}
	if(k<1)
	{
		return NULL;
	}

    int* A = (int*)malloc((k+1)*(k+1) * sizeof(int));
    int* B = (int*)malloc((k+1)*(k+1) * sizeof(int));
    int* C = (int*)malloc((k+1)*(k+1) * sizeof(int));
    int* D = (int*)malloc((k+1)*(k+1) * sizeof(int));
    int* E = (int*)malloc((k+1)*(k+1) * sizeof(int));
    int* F = (int*)malloc((k+1)*(k+1) * sizeof(int));
    int* G = (int*)malloc((k+1)*(k+1) * sizeof(int));
    int* H = (int*)malloc((k+1)*(k+1) * sizeof(int));

    for(i=0;i<=k;i++)
    {
        for(j=0;j<=k;j++)
        {
            *(A+i*(k+1)+j)= *(arr+ i*(n+1)+j);
            *(E+i*(k+1)+j)= *(brr+ i*(n+1)+j);
        }
    }
        
    for(i=0;i<=k;i++)
    {
        for(j=k+1;j<=n;j++)
        {
            *(B+i*(k+1)+(j-(k+1)))= *(arr+ i*(n+1)+j);
            *(F+i*(k+1)+(j-(k+1)))= *(brr+ i*(n+1)+j);
        }
    }

    for(i=k+1;i<=n;i++)
    {
        for(j=0;j<=k;j++)
        {
			*(C+(i-(k+1))*(k+1)+j)= *(arr+ i*(n+1)+j);
    		*(G+(i-(k+1))*(k+1)+j)= *(brr+ i*(n+1)+j);
        }
    }
    
    for(i=k+1;i<=n;i++)
    {
        for(j=k+1;j<=n;j++)
        {
    		*(D+(i-(k+1))*(k+1)+(j-(k+1)))= *(arr+ i*(n+1)+j);
            *(H+(i-(k+1))*(k+1)+(j-(k+1)))= *(brr+ i*(n+1)+j);
        }
    }
    
    int* temp  = sub(F, H, x);
    int* temp1 = add(A, B, x);
    int* temp2 = add(C, D, x);
    int* temp3 = sub(G, E, x);
    int* temp4 = add(A, D, x);
    int* temp5 = add(E, H, x);
    int* temp6 = sub(B, D, x);
    int* temp7 = add(G, H, x);
    int* temp8 = sub(A, C, x);
    int* temp9 = add(E, F, x);

    int* p1 = Strassans(A, temp, x - 1);
    free(temp);
    int* p2 = Strassans(temp1, H, x - 1);
    free(temp1);
    int* p3 = Strassans(temp2, E, x - 1);
    free(temp2);
    int* p4 = Strassans(D, temp3, x - 1);
    free(temp3);
    int* p5 = Strassans(temp4, temp5, x - 1);
    free(temp4);
    free(temp5);
    int* p6 = Strassans(temp6, temp7, x - 1);
    free(temp6);
    free(temp7);
    int* p7 = Strassans(temp8, temp9, x - 1);
    free(temp8);
    free(temp9);
    
    int* C11 = sub(add(add(p5, p4, x), p6, x), p2, x);
    int* C12 = add(p1, p2, x);
    int* C21 = add(p3, p4, x);
    int* C22 = sub(add(p1, p5, x), add(p3, p7, x), x);
    
    free(p1);
    free(p2);
    free(p3);
    free(p4);
    free(p5);
    free(p6);
    free(p7);

	 
    for(i=0;i<=k;i++)
    {
        for(j=0;j<=k;j++)
        {
            *(res + i*(n+1) + j)= *(C11 + i*(k+1) +j);
        }
    }
    
    for(i=0;i<=k;i++)
    {
        for(j=k+1;j<=n;j++)
        {
            *(res + i*(n+1) + j) = *(C12 + i*(k+1) +(j-(k+1)));
        }
    }
    
    for(i=k+1;i<=n;i++)
    {
        for(j=0;j<=k;j++)
        {
            *(res + i*(n+1) + j) = *(C21 + (i-(k+1))*(k+1) +j);
        }
    }
    
    for(i=k+1;i<=n;i++)
    {
        for(j=k+1;j<=n;j++)
        {
            *(res + i*(n+1) + j) = *(C22 + (i-(k+1))*(k+1) +(j-(k+1)));
        }
    }
    
         
    free(C11);
    free(C12);
    free(C21);
    free(C22);
    
    return res;
}

int main() 
{
    int* ptr;
    int i,j,n;
    printf("Enter the order\n");
    scanf("%d",&n);
    int* arr = (int*)malloc((n+1)* (n+1) * sizeof(int));
    int* brr = (int*)malloc((n+1)* (n+1) * sizeof(int));
    printf("Enter the 1st array\n");
    for (i=0;i<n;i++) 
    {
        for (j=0;j<n;j++) 
        {
            scanf("%d",(arr+i*(n+1)+j));
        }
    }
    printf("Enter the 2nd array\n");
    for (i=0;i<n;i++) 
    {
        for (j=0;j<n;j++) 
        {
            scanf("%d",(brr+i*(n+1)+j));
        }
    }
    
    for(i=n;i<n+1;i++)
    {
        for(j=0;j<n+1;j++)
        {
            *(arr+i*(n+1)+j)=0;
            *(brr+i*(n+1)+j)=0;
        }
    }
    
    for(i=0;i<n;i++)
    {
        for(j=n;j<n+1;j++)
        {
            *(arr+i*(n+1)+j)=0;
            *(brr+i*(n+1)+j)=0;
        }
    }
    
    ptr = Strassans(arr,brr,n);
    
    for (i=0;i<n;i++) 
    {
       for (j=0;j<n;j++) 
        {
           printf("%d ", *(ptr + i*(n+1)+j));
        }
       printf("\n");
    }
    return 0;
}