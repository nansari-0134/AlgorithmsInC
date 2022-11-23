#include<stdio.h>
#include<stdlib.h>

int* Count_sort(int *arr, int n, int j)
{
    int f[10]={0} ;
    int i;
    int sum=0;
    for(i=0;i<n;i++)
    {
        f[(arr[i]/j)%10]++;
    }

    for(i =0; i<10;i++)
    {
        sum = sum + f[i];
        f[i] = sum;
    }

    int *new_arr;//new array to store the result.
    new_arr = (int *)malloc(sizeof(int) *n);

    int pos;
    for(i=n-1; i>=0 ;i-- )
    {
            pos = f[(arr[i]/j)%10]-1;
            new_arr[ pos ] = arr[ i ];
            f [(arr[i]/j)%10]--;
    }
    return new_arr;
}

int largest(int *arr,int n)
{
    int i,max=arr[0];
    for(i=1;i<n;i++)
    {
        if(max<arr[i])
            max=arr[i];
    }
    return max;
}

int* radixsort(int *arr, int n)
{
    int i;
    int max = largest(arr, n);
    int j = 1;
    printf("Array after each iteration:\n");
    while(max > j)
    {
        arr = Count_sort(arr, n, j);
        j= j* 10;

        for(i=0;i<n;i++)
            printf("%d ",arr[i]);
        printf("\n");
    }
    return arr;
}

int main()
{
    int *arr,n,i;

    //input
    printf("Enter Size of Array: ");
    scanf("%d",&n);
    arr = (int*)malloc(sizeof(int)*n);

    printf("Enter %d elements of array:\n",n);
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);

    arr = radixsort(arr,n);

    printf("Final Array:\n");
    for(i=0;i<6;i++)
        printf("%d ",arr[i]);
}
