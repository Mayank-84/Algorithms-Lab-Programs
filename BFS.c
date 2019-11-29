#include<stdio.h>
#include<stdlib.h>

#define max 100

int g[max][max],visited[max],queue[max];
int front=-1,rear=-1,novertex;

void insert(int v)
{
    if(front==-1)
    {
        front=0;
    }
    rear=rear+1;
    queue[rear]=v;
}

int delete()
{
    int temp;
    if(front==-1||front>rear)
    {
        exit(1);
    }
    else{
        temp=queue[front];
        front=front+1;
        return temp;
    }
}

int empty()
{
    if(front==-1||front>rear)
        return 1;
    else
    {
        return 0;
    }
}

void bfs(int v)
{
    int i,j,u=v;
    visited[v]=1;
    do{
        i=u;
        for(j=0;j<novertex;j++)
        {
            if(g[i][j]!=0)
            {
                if(visited[j]==0)
                {
                    insert(j);
                    visited[j]=1;
                }
            }
        }
        int temp= empty();
        if(temp==1)
            return;
        temp=delete();
        printf(" %d",temp);
    }while(1);
}

void bft()
{
    printf("bft\n");
    int i,j;
    for(i=0;i<novertex;i++)
    {
        visited[i]=0;
    }
    for(i=0;i<novertex;i++)
    {
        if(visited[i]==0)
        {
            bfs(i);
        }
    }
}

void main()
{
    int i,j;
    printf("enter the no. of vertices\n");
    scanf("%d",&novertex);
    printf("enter the adjacency matrix\n");
    for(i=0;i<novertex;i++)
    {
        for(j=0;j<novertex;j++)
        {
            scanf("%d",&g[i][j]);
        }
    }
    bft();
}
