#include<stdlib.h>
#include<stdio.h>
#include<limits.h>

int INF = INT_MAX;
int g[10][10];    //adjacency matrix, to store graph (max=10 nodes)

//structure for priority queue
typedef struct nodestruct{
    int k,p;  //k = weight/key; p = parent vertex
} node;

node *u;

//to show vertex is part of MST or not
int f[10] = {0}; //0 represents that node is not a part of MST yet

//----------------functions for Heap----------------
void minHeapify(int *Q,int i,int heapSize)
{
    int l = 2*i+1;
    int r = 2*i+2;
    int min = i;
    int t;

    if(l <= heapSize && (u[Q[min]].k > u[Q[l]].k))
        min = l;
    if(r <= heapSize && (u[Q[min]].k > u[Q[r]].k))
        min = r;

    if(min != i)
    {
        t = Q[min];
        Q[min]=Q[i];
        Q[i]=t;

        minHeapify(Q,min,heapSize);
    }

}

int extractMin(int *Q,int heapSize)
{
    if(heapSize< 0)
        return -1;
    f[Q[0]] = 1;
    if(heapSize == 0)
        return Q[0];

    int min =Q[0];
    Q[0]=Q[heapSize];
    minHeapify(Q,0,heapSize);
    return min;
}

void decreaseKey(int *Q,int i,int nw)
{
    u[Q[i]].k = nw;
    while(i > 0 && u[Q[i]].k < u[Q[(i-1)/2]].k)
    {
        nw = Q[i];
        Q[i] = Q[(i-1)/2];
        Q[(i-1)/2] = nw;
        i = (i-1)/2;
    }
}
int find(int *Q, int t)
{
    int i=0;
    while(Q[i] != t)
        i++;
    return i;
}
//------------------Main function--------------

int main()
{
    FILE *fp;
    int n,e; //n=no of nodes, e = no of edges
    int i,j,k,t; //for loop

    fp = fopen("mst.txt","r");

    //get no. of nodes and edges
    fscanf(fp,"%d %d\n",&n,&e);

    //assigning -1 to each edge in graph
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            g[i][j] = -1;
        }
    }

    //reading value from file and updating edge values
    for(i=0;i<e;i++)
    {
        fscanf(fp,"%d %d %d\n",&j,&k,&t);
        g[k][t]=j;
        g[t][k]=j;
    }
    fclose(fp);
    prims(n,e);

    for(i=0;i<n;i++)
        printf("%d <- %d\n",i,u[i].p);
}

//------------------------prims algorithm----------------------
void prims(int n,int e)
{
    int i,t,j;
    //initializing for priority queue
    u = (node*)malloc(sizeof(node) * n);

    //making key of each node infinite and its parent as nil
    for(i=0;i<n;i++)
    {
        u[i].k=INF;
        u[i].p=-1;
    }

    //we are considering first element as our root element
    //so making key to is 0.
    u[0].k=0;

    //making priority queue with array
    int *Q = (int*)malloc(sizeof(int)*n);
    int heapSize = n;
    for(i=0;i<n;i++)
        Q[i]=i;

    //we don't need to call build heap hear as it is already heap
    while(heapSize > 0)
    {
        t = extractMin(Q,--heapSize);

        for(j=0;j<n;j++)
        {
            if(f[j] == 0 && g[t][j] != -1 && g[t][j] < u[j].k)
            {
                u[j].p = t;
                u[j].k = g[t][j];
                //decrease key
                decreaseKey(Q,find(Q,j),g[t][j]);
            }
        }
//        for(int k=0;k<heapSize;k++)
//                    printf("%d-%d ",Q[k],u[Q[k]].k);
//                printf("\n");
    }

}

