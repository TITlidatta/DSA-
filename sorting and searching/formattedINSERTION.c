#include<stdio.h>
#include<stdlib.h>

void insertion_sort(int *arrptr,int n)
{
    int temp;
    for(int i=1;i<n;i++)
    {
        temp=*(arrptr+i);
        for(int j=i-1;j>=0;j--)
        {
            if(*(arrptr+j)>temp)
            {
                *(arrptr+j+1)=*(arrptr+j);
            }
            else
            {
                *(arrptr+j+1)=temp;
                temp=-1;
                break;
            }
        }
        if(temp !=-1)
        {
            *(arrptr+0)=temp;
        }
        
    }
}

//run this code using ./a.out file_reading_sample.txt
int main (int argc , char* argv[])
{
    if (argc != 2)
    {
        printf("incorrect number of arguments\n");
        printf("given arguments are as follows:\n");
        for(int i =0; i <argc; i++)
            printf("%s\n", argv[i]);
        exit(0);
    }
    FILE* fp = fopen (argv[1], "r"); //first line int the line is the size
    int size, i=0, *arr;
    if (fp)
    {
        fscanf(fp, "%d", &size);
        arr = (int*)malloc(sizeof(int)*size);
        while (!feof(fp) && i < size)
            fscanf(fp, "%d", &arr[i++]);
        if(i!=size) 
        {
            printf("insufficient number of inputs, expected %d inputs\n",size); 
            exit(0);
        }
        fclose(fp);
    }
    else
    {
        perror("FILE open error");
        exit(0);
    }
    insertion_sort(arr,size);
    for (i = 0; i <size; i++)
        printf("%d ", arr[i]);
    printf("\n");
    free(arr);

}