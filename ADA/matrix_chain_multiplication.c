
#include <stdio.h>
#include<stdlib.h>
#include<limits.h>

int INF = INT_MAX;

int m[30][30];
int s[30][30];

int min(long a,long b)
{
    if(a>b)
        return b;
    return a;
}


int MatrixChainOrder(int p[], int n)
{

    int m[n][n];

    int i, j, k, L, q;

    // cost is zero when multiplying one matrix.
    for (i = 1; i < n; i++)
        m[i][i] = 0;

    // L is chain length.
    for (L = 2; L < n; L++) {
        for (i = 1; i < n - L + 1; i++)
        {
            j = i + L - 1;
            m[i][j] = INF;
            for (k = i; k <= j - 1; k++)
            {
                // q = cost/scalar multiplications
                q = m[i][k] + m[k + 1][j]
                    + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                {
                    m[i][j] = q;
                    s[i][j]=k;
                }

            }
        }
    }

    return m[1][n - 1];
}

void print_optimal_parens(int i,int j)
{
    //printf("%d %d\n",i,j);
    if(i==j)
    {
         printf("A%d ",i);
         return;
    }
    else{
        printf("( ");
        print_optimal_parens(i,s[i][j]);
        print_optimal_parens(s[i][j]+1,j);
        printf(") ");
    }
}

int main()
{
	int arr[] = { 1, 2, 3, 4 ,3};
	int n = sizeof(arr) / sizeof(arr[0]);
	for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)
            m[i][j]=-1;
	printf("Minimum number of multiplications is : %d",MatrixChainOrder(arr, n));
//	printf("\n");
//	for(int i=0;i<10;i++)
//    {
//        for(int j=0;j<10;j++)
//            printf("%7d ",m[i][j]);
//        printf("\n");
//    }
//    	printf("\n");
//	for(int i=0;i<10;i++)
//    {
//        for(int j=0;j<10;j++)
//            printf("%7d ",s[i][j]);
//        printf("\n");
//    }
    printf("\n");
    printf("Solution : ");
    print_optimal_parens(1,n-1);
}

