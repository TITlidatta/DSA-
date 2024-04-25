// Online C compiler to run C program online
#include <stdio.h>
#include<math.h>
#include <stdlib.h>

float point(float var, float meu, float low, float high )
{
   float eval1,eval2,mid,emid,c,val1,val2;
   mid=(low+high)/2;
   val1=mid-1;
   val2= mid+1;
   //printf("%f",mid);
   printf(" %f %f, %f",low,high, fabs(high-low));
    if(fabs(high-low)<0.01)
   { 
       //printf("here");
       return mid;
   }
   
   c=pow((val1 - meu)/var, 2);
   c = -c/2;
   eval1= (1/(var*(sqrt(2*3.14))))*(pow(2.73,c));
   //printf("%f\n",eval1);
   c=pow((val2 - meu)/var, 2);
   c = -c/2;
   eval2= (1/(var*(sqrt(2*3.14))))*(pow(2.73,c));
   //printf("%f\n",eval2);
   c=pow((mid - meu)/var, 2);
   c = -c/2;
   emid= (1/(var*(sqrt(2*3.14))))*(pow(2.73,c));
   
   
   if(eval1<=emid && emid<=eval2)
   {
       return point(var,meu,mid,high);
   }
   else if (eval1>=emid && emid>=eval2)
   {
       return point(var, meu,low,mid);
   }
   else
   {
       return mid;
   }

}//calculate with meu = -2 var = 0.7