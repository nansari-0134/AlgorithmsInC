#include <stdio.h>
#include<stdlib.h>
#include<string.h>

int c[50][50];
char b[50][50];

void lcs_length(char *x,char *y)
{
    int m = strlen(x);
    int n = strlen(y);
    int i,j;
    for(i=1;i<=m;i++)
        c[i][0]=0;
    for(j=0;j<=n;j++)
        c[0][j]=0;

    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(x[i-1]==y[j-1])
            {
                c[i][j]=c[i-1][j-1]+1;
                b[i][j]= '\\';
            }
            else if(c[i-1][j] >= c[i][j-1])
            {
                c[i][j]=c[i-1][j];
                b[i][j]= '|';
            }
            else
            {
                c[i][j]=c[i][j-1];
                b[i][j]= '-';
            }
        }
    }
}

void print_lcs(char *x,int i,int j)
{
    if(i==0 || j==0)
    {
        return;
    }
    if(b[i][j]=='\\')
    {
        print_lcs(x,i-1,j-1);
        printf("%c",x[i-1]);
    }
    else if(b[i][j]=='|')
    {
        print_lcs(x,i-1,j);
    }
    else
        print_lcs(x,i,j-1);
}

int main()
{
    char x[] = {'A','B','C','B','D','A','B','\0'};
    char y[] = {'B','D','C','A','B','A','\0'};
    int m = strlen(x);
    int n = strlen(y);
    lcs_length(x,y);
    printf("Length of longest common Subsequence: %d",c[m][n]);
    printf("\nLCS: ");
    print_lcs(x,m,n);
}
