#include<stdio.h>

void sort(float p[],float w[],int items)
{
    int i, j,temp;  
    for (i = 0; i < items-1; i++)      
    {
        for (j = 0; j < items-i-1; j++)  
            if ((p[j]/w[j]) < (p[j+1]/w[j+1]))  
                {
                    temp=p[j];
                    p[j]=p[j+1];
                    p[j+1]=temp;

                    temp=w[j];
                    w[j]=w[j+1];
                    w[j+1]=temp;
                } 
    }
    printf("sorted arrays are\n");
    // for(i=0;i<items;i++)
    // {
    //     printf("p- %f w- %f \n",p[i],w[i]);
    // }
}
 void main(){
     int i,noofobjects,capacity;
     printf("enter max items \n");
     scanf("%d",&noofobjects);
     float x[noofobjects],p[noofobjects],w[noofobjects],profit=0;
     printf("enter profits for %d items\n",noofobjects);
     for(i=0;i<noofobjects;i++)
     {
         scanf("%f",&p[i]);
         x[i]=0.0;
     }
     printf("enter weights for %d items\n",noofobjects);
     for(i=0;i<noofobjects;i++)
     {
         scanf("%f",&w[i]);
     }
     sort(p,w,noofobjects);
     printf("enter capacity of knapsack\n");
     scanf("%d",&capacity);
    int  m=capacity;
    for(i=0;i<noofobjects;i++)
    {
        if(w[i]<=m)
        {
            x[i]=1;
            m=m-w[i];
            profit=profit+p[i];
        }
        else
        {
            break;
        }
    }
    if(i<=noofobjects)
    {
        x[i]=(m/w[i]);
        profit=profit+((m/w[i])*p[i]);
    }
    printf("profit is %f\n",profit);
    printf("solution vector is \n");
    for(i=0;i<noofobjects;i++)
    {
        printf("%f ",x[i]);
    }
 }