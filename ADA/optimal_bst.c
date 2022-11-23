
#include <stdio.h>
#include <limits.h>


int optimalSearchTree(int k[], int f[], int n)
{

	int c[n][n];

	// For a single key, c is equal to fuency of the key
	for (int i = 0; i < n; i++)
		c[i][i] = f[i];

	for (int L=2; L<=n; L++)
	{
		// i is row number in c[][]
		for (int i=0; i<=n-L+1; i++)
		{
			// Get column number j from row number i and
			// chain length L
			int j = i+L-1;
			int s = sum(f, i, j);
			c[i][j] = INT_MAX;

			// Try making all k in interval k[i..j] as root
			for (int r=i; r<=j; r++)
			{
			// c = c when k[r] becomes root of this subtree
			int a = ((r > i)? c[i][r-1]:0) +
					((r < j)? c[r+1][j]:0) +
					s;
			if (a < c[i][j])
				c[i][j] = a;
			}
		}
	}
	return c[0][n-1];
}

// A utility function to get sum of array elements
// f[i] to f[j]
int sum(int f[], int i, int j)
{
	int s = 0;
	for (int k = i; k <=j; k++)
	s += f[k];
	return s;
}

// Driver program to test above functions
int main()
{
	int k[] = {10, 12, 20};
	int f[] = {34, 8, 50};
	int n = sizeof(k)/sizeof(k[0]);
	printf("c of Optimal BST is %d ",
				optimalSearchTree(k, f, n));
	return 0;
}
