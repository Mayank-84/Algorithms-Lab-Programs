#include<stdio.h>

int n,g[11][11];
void fw();

int main()
{
    int i,j;
    printf("enter the number of vertices in range of 1-10\n");
    scanf("%d",&n);
    printf("enter the adjacency matrix(enter a very big number for infinity)\n");
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            scanf("%d",&g[i][j]);
    fw();
    printf("the shortest paths are");
    for(i=1;i<=n;i++)
    {
        printf("\n|");
        for(j=1;j<=n;j++)
        {
            printf("%d ",g[i][j]);
        }
        printf("|");
    }
}

void fw()
{
    int k,i,j;
    for(k=1;k<=n;k++)
    {
        for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        {
            if(g[i][j]>(g[i][k]+g[k][j]))
                g[i][j]=(g[i][k]+g[k][j]);
        }
    }
}