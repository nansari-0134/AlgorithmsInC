#include<stdlib.h>
#include<stdio.h>
int INF = 999;
int a[9][9];    //adjacency matrix, to store graph
int p[9][9];    //parent/path matrix

void algo(int n)
{
    for(int k = 1; k<=n; k++)
    {
        for(int i = 1; i<=n; i++)
        {
            for(int j = 1; j<=n; j++)
            {
                if(i != j)
                {
                    if((a[i][k]+a[k][j] < a[i][j]) && a[i][k]!=INF && a[k][j]!=INF)
                    {
                        a[i][j] = a[i][k]+a[k][j];
                        p[i][j] = p[i][k];
                    }
                }
            }
        }
    }
}

void path(int src,int dest)
{
    int k=p[src][dest];
    if(k==-1)
    printf("path not possible");
    printf("%d ",src);
    while(k != dest)
    {
        printf("%d ",k);
        k = p[k][dest];
    }
    printf("%d ",dest);
}

int main()
{
    FILE *fp;
    int n,e; //n=no of nodes, e = no of edges
    int i,j,k,t; //for loop

    fp = fopen("g.txt","r");

    //get no. of nodes and edges
    fscanf(fp,"%d %d\n",&n,&e);

    //assign Infinite to each node
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(i==j)
                a[i][j]=0;
            else
                a[i][j]=INF;
            p[i][j]=-1;
        }
    }


    for(i=0;i<e;i++)
    {
        fscanf(fp,"%d %d %d\n",&j,&k,&t);
        //printf("%d %d %d\n",j-1,k-1,t);
        //printf("a[%d][%d]=%d\n",j-1,k-1,t);
        a[j][k]=t;
        p[j][k]=k;
    }
    fclose(fp);
    printf("\nCost Matrix(Initial):\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            printf("%4d ",a[i][j]);
        }
        printf("\n");
    }

    //All pairs shortest path algorithm call
    algo(n);

    printf("\nCost Matrix:\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            printf("%4d ",a[i][j]);
        }
        printf("\n");
    }

    printf("Parent/Path matrix:\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            printf("%2d ",p[i][j]);
        }
        printf("\n");

    }

    //printing all paths
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(i==j)
                continue;
            else
            {
                printf("\nPath from %d to %d :",i,j);
                path(i,j);
            }
        }
    }
}
