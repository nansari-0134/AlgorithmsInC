#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int INF = INT_MAX;
int g[10][10];    //adjacency matrix, to store graph (max=10 nodes)
int f[10]={0};

int s[30],k=0;//for answer
//structure for priority queue
typedef struct nodestruct{
    int d,p;  //d = weight/distance; p = parent vertex
} node;

node u[30];

//----------------functions for Heap----------------
void minHeapify(int *Q,int i,int heapSize)
{
    int l = 2*i+1;
    int r = 2*i+2;
    int min = i;
    int t;

    if(l <= heapSize && (u[Q[min]].d > u[Q[l]].d))
        min = l;
    if(r <= heapSize && (u[Q[min]].d > u[Q[r]].d))
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
    u[Q[i]].d = nw;
    while(i > 0 && u[Q[i]].d < u[Q[(i-1)/2]].d)
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


//-------required functions----------------
void initialize_single_source(int n)
{
    int i;
    //making key of each node infinite and its parent as nil
    for(i=0;i<n;i++)
    {
        u[i].d=INF;
        u[i].p=-1;
    }

    //we are considering first element as our root element
    //so making key to is 0.
    u[0].d=0;
}

void relax(int U,int v,int *Q)
{
    if(u[U].d > u[v].d + g[v][U])
    {
        //decrease key
        //relax(j,t,Q);
        decreaseKey(Q,find(Q,U),u[v].d + g[v][U]);
//        printf("%d %d %d\n",U,v,find(Q,U));
        u[U].p = v;
    }
}

//--------------dijkshtra algoritm----------
void dijkshtra(int n,int e)
{
    int i,t,j;

    initialize_single_source(n);

    //making priority queue with array
    int *Q = (int*)malloc(sizeof(int)*n);
    int heapSize = n;
    for(i=0;i<n;i++)
        Q[i]=i;

    //we don't need to call build heap hear as it is already heap
    while(heapSize > 0)
    {
        t = extractMin(Q,--heapSize);
        s[k++]=t;

        for(j=0;j<n;j++)
        {
            if(g[t][j] != -1 && f[j]!= 1)
            {
                relax(j,t,Q);
//                //decrease key
                //decreaseKey(Q,find(Q,j),g[t][j]);
            }
        }
    }
}
//---------------main function-------------
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
    }
    fclose(fp);

    dijkshtra(n,e);

    printf("Shortest Path from node 0 to all vertices:\n");
    printf("Node   cost   parent node\n");
    for(i=0;i<n;i++)
        printf("%3d %6d %8d\n",i,u[i].d,u[i].p);
}
