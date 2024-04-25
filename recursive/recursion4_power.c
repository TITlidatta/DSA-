#include<stdio.h>
int power(int x,int y)/*here x, y are general variable used to STORE A COPY OF THE values which are given as input while calling the function .. BUT when we give pointers as input this gives the whole address ie access to the exact variable therfore any changes done within function changes that actual variable used in main function*/
{
   if(y>0)
   {
       return x*power(x,y-1);//here function called within a function
   }   
   else//base condition
   {
       return 1;
   }
}

int main()
{
    int x,y;/*this variable x, y are just variablesw used in MAIN function*/
    int c;
    printf("enter a number whose power you want to calculate");
    scanf("%d",&x);
    printf("enter the power");
    scanf("%d",&y);
    c=power(x,y);
    printf("%d",c);
    return 0;
}