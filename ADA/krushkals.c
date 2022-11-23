#include<stdio.h>
#include<stdlib.h>

//structure to store edges of graph
typedef struct graphNode
{
    int from,to,w;
} graph;

graph g[30];
//---------------disjoint set-------------
//structure of set element
typedef struct setNode
{
    int p;          //parent
    int rank;       //for rank
} node;

node x[10];
//functions
void make_set(int i)
{
    x[i].p=i;
    x[i].rank=0;
}

int find_set(int i)
{
    if(x[i].p != i)
        x[i].p = find_set(x[i].p);
    return x[i].p;
}

void link(int i,int j)
{
    if(x[i].rank > x[j].rank)
        x[j].p = i;
    else
    {
        x[i].p = j;
        if(x[i].rank == x[j].rank)
            x[j].rank +=1;
    }
}

void union_sets(int i,int j)
{
    link(find_set(i),find_set(j));
}

//---------------merge sort---------------
void merge(int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    //printf("%d %d  -- %d %d %d\n",n1,n2,l,m,r);
    /* create temp arrays */
    graph L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
    {
        L[i].w = g[l + i].w;
        L[i].from = g[l + i].from;
        L[i].to = g[l + i].to;
        //printf("%d %d %d - %d\n",L[i].from,L[i].to,L[i].w,i);
    }
    for (j = 0; j < n2; j++)
    {
        R[j].w = g[m + 1 + j].w;
        R[j].from = g[m + 1 + j].from;
        R[j].to = g[m + 1 + j].to;
        //printf("%d %d %d - %d\n",R[j].from,R[j].to,R[j].w,j);
    }

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i].w <= R[j].w) {
            g[k].w = L[i].w;
            g[k].from = L[i].from;
            g[k].to = L[i].to;
            i++;
        }
        else {
            g[k].w = R[j].w;
            g[k].from = R[j].from;
            g[k].to = R[j].to;
            j++;
        }
        //printf("%d - %d\n",g[k].w,k);
        k++;
    }

    /* Copy the remaining elements of L[], if there
    are any */
    while (i < n1) {
        g[k].w = L[i].w;
        g[k].from = L[i].from;
        g[k].to = L[i].to;
        i++;
        //printf("%d - %d\n",g[k].w,k);
        k++;
    }

    /* Copy the remaining elements of R[], if there
    are any */
    while (j < n2) {
        g[k].w = R[j].w;
        g[k].from = R[j].from;
        g[k].to = R[j].to;
        j++;
        //printf("%d - %d\n",g[k].w,k);
        k++;
    }
}

void mergesort(int l,int r)
{
    if(l>=r)
        return;
    int mid = (l+r)/2;
    mergesort(l,mid);
    mergesort(mid+1,r);
    merge(l,mid,r);
}

//-----------------krushkal's algorithm---------
int krushkal(graph *A,int v,int e)
{
    int i,k=0;
    for(i=0;i<v;i++)
    {
        make_set(i);
    }
    mergesort(0,e-1);

    for(i=0;i<e;i++)
    {
        if(find_set(g[i].from) != find_set(g[i].to))
        {
            A[k].from = g[i].from;
            A[k].to = g[i].to;
            A[k].w = g[i].w;
            k++;
            union_sets(g[i].from,g[i].to);
        }
    }
    return k;
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

    //reading value from file and updating edge values
    for(i=0;i<e;i++)
    {
        fscanf(fp,"%d %d %d\n",&j,&k,&t);
        g[i].from=k;
        g[i].to = t;
        g[i].w = j;
    }
    fclose(fp);

    graph A[30];
    k = krushkal(A,n,e);
    printf("Edges in MST:\n");
    printf("From  To\n");
    for(i=0;i<k;i++)
    {
        printf("%4d %2d\n",A[i].from,A[i].to);
    }
}
