#include<stdio.h>
int a[10];
int b[10];
void merge(int first,int mid,int last)
{
    int i=first,j=mid+1,k=first;
    while(i<=mid&&j<=last)
    {
        if(a[i]<a[j])
        {
            b[k]=a[i];
            i++;
        }
        else
        {
            b[k]=a[j];
            j++;
        }
        k++;
    }
    if(i>mid)
    {
        for(int l=j;l<=last;l++)
        {
            b[k]=a[l];
            k++;
        }
    }
    else
    {
         for(int l=i;l<=mid;l++)
        {
            b[k]=a[l];
            k++;
        }
    }
    for(int l=first;l<=last;l++)
    {
        a[l]=b[l];
    }
}

void mergesort(int first,int last)
{
    int mid;
    if(first<last)
    {
        mid=(first+last)/2;
        mergesort(first,mid);
        mergesort(mid+1,last);
        merge(first,mid,last);
    }
}
    

void display()
{
    //int length= sizeof(a)/sizeof(int);
    int i;
    printf("sorted array is\n");
    for(i=0;i<10;i++)
    {
        printf("%d",b[i]);
    }
}

void main()
{
    int i,first=0,last=9;
    printf("enter the elements\n");
    for(i=0;i<10;i++)
    {
        scanf("%d",&a[i]);
    }
    mergesort(first,last);
    display();
}