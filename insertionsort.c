
//LAB-2 
// Insertion sort
#include<stdio.h>

void isort(int a[],int length)
{
        int i,j,key;
                for(j=1;j<length;j++)
                {
                        key=a[j];
                        i=j-1;
                        while(i>-1&&a[i]>key)
                        {
                                a[i+1]=a[i];
                                i=i-1;
                        }
                        a[i+1]=key;
                }
}

int main()
{
    int a[10],i,length;
    printf("enter length \n");
    scanf("%d",&length);
    printf("enter array \n");
    for(i=0;i<length;i++)
    scanf("%d",&a[i]);
    isort(a,length);
    printf("sorted array is \n");
    for(i=0;i<length;i++)
    printf("%d ",a[i]);
} 