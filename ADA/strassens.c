#include<stdio.h>
#include<math.h>
#include<stdlib.h>


int a[32][32];
int b[32][32];

void add(int n,int **c){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

void sub(int n,int **c){
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++){
                c[i][j]= a[i][j] - b[i][j];
        }
    }
}

void  multiply(int **c,int **d,int n,int n2,int **nw){
    if(n == 1){
        nw[0][0] = c[0][0] *d[0][0];
    }
    else {
        int i,j;
        int nn =n/2;
        int **c11 = malloc(nn * nof(int *));
        for(i=0;i<nn;i++){
            c11[i]= malloc(nn*nof(int));
        }
        int **c12 = malloc(nn * nof(int *));
        for(i=0;i<nn;i++){
            c12[i]= malloc(nn * nof(int));
        }
        int **c21 = malloc(nn * nof(int *));
        for(i=0;i<nn;i++){
            c21[i]= malloc(nn * nof(int));
        }
        int **c22 = malloc(nn * nof(int *));
        for(i=0;i<nn;i++){
            c22[i]= malloc(nn*nof(int));
        }
        int **d11 = malloc(nn * nof(int *));
        for(i=0;i<nn;i++){
            d11[i]= malloc(nn*nof(int));
        }
        int **d12 = malloc(nn * nof(int *));
        for(i=0;i<nn;i++){
            d12[i]= malloc(nn*nof(int));
        }
        int **d21 = malloc(nn * nof(int *));
        for(i=0;i<nn;i++){
            d21[i]= malloc(nn*nof(int));
        }
        int **d22 = malloc(nn * nof(int *));
        for(i=0;i<nn;i++){
            d22[i]= malloc(nn*nof(int));
        }
        int **m1 = malloc(nn * nof(int *));
        for(i=0;i<nn;i++){
            m1[i]= malloc(nn*nof(int));
        }
        int **m2 = malloc(nn * nof(int *));
        for(i=0;i<nn;i++){
            m2[i]= malloc(nn*nof(int));
        }
        int **m3 = malloc(nn * nof(int *));
        for(i=0;i<nn;i++){
            m3[i]= malloc(nn*nof(int));
        }
        int **m4 = malloc(nn * nof(int *));
        for(i=0;i<nn;i++){
            m4[i]= malloc(nn*nof(int));
        }
        int **m5 = malloc(nn * nof(int *));
        for(i=0;i<nn;i++){
            m5[i]= malloc(nn*nof(int));
        }
        int **m6 = malloc(nn * nof(int *));
        for(i=0;i<nn;i++){
            m6[i]= malloc(nn*nof(int));
        }
        int **m7 = malloc(nn * nof(int *));
        for(i=0;i<nn;i++){
            m7[i]= malloc(nn * nof(int));
        }
        for(i=0;i<nn;i++){
            for(j=0;j<nn;j++){
                c11[i][j]=c[i][j];
                c12[i][j]=c[i][j+nn];
                c21[i][j]=c[i+nn][j];
                c22[i][j]=c[i+nn][j+nn];
                d11[i][j]=d[i][j];
                d12[i][j]=d[i][j+nn];
                d21[i][j]=d[i+nn][j];
                d22[i][j]=d[i+nn][j+nn];
            }
        }
        int **temp1 = malloc(nn * nof(int *));
        for(i=0;i<nn;i++){
            temp1[i]= malloc(nn*nof(int));
        }
        int **temp2 = malloc(nn * nof(int *));
        for(i=0;i<nn;i++){
            temp2[i]= malloc(nn*nof(int));
        }

        add(c11,c22,nn,temp1);
        add(d11,d22,nn,temp2);
        multiply(temp1,temp2,nn,n,m1);
        free(temp1);
        free(temp2);

        int **temp3 = malloc(nn * nof(int *));
        for(i=0;i<nn;i++){
            temp3[i]= malloc(nn*nof(int));
        }
        add(c21,c22,nn,temp3);
        multiply(temp3,d11,nn,n,m2);
        free(temp3);


        int **temp4 = malloc(nn * nof(int *));
        for(i=0;i<nn;i++){
            temp4[i]= malloc(nn*nof(int));
        }
        sub(d12,d22,nn,temp4);
        multiply(c11,temp4,nn,n,m3);
        free(temp4);


        int **temp5 = malloc(nn * nof(int *));
        for(i=0;i<nn;i++){
            temp5[i]= malloc(nn*nof(int));
        }
        sub(d21,d11,nn,temp5);
        multiply(c22,temp5,nn,n,m4);
        free(temp5);


        int **temp6 = malloc(nn * nof(int *));
        for(i=0;i<nn;i++){
            temp6[i]= malloc(nn*nof(int));
        }
        add(c11,c12,nn,temp6);
        multiply(temp6,d22,nn,n,m5);
        free(temp6);

        int **temp7 = malloc(nn * nof(int *));
        for(i=0;i<nn;i++){
            temp7[i]= malloc(nn*nof(int));
        }
        int **temp8 = malloc(nn * nof(int *));
        for(i=0;i<nn;i++){
            temp8[i]= malloc(nn*nof(int));
        }
        sub(c21,c11,nn,temp7);
        add(d11,d12,nn,temp8);
        multiply(temp7,temp8,nn,n,m6);
        free(temp7);
        free(temp8);

        int **temp9 = malloc(nn * nof(int *));
        for(i=0;i<nn;i++){
            temp9[i]= malloc(nn*nof(int));
        }
        int **temp10 = malloc(nn * nof(int *));
        for(i=0;i<nn;i++){
            temp10[i]= malloc(nn*nof(int));
        }
        sub(c12,c22,nn,temp9);
        add(d21,d22,nn,temp10);
        multiply(temp9,temp10,nn,n,m7);
        free(temp9);
        free(temp10);


        int **te1 = malloc(nn * nof(int *));
        for(i=0;i<nn;i++){
            te1[i]= malloc(nn*nof(int));
        }
        int **te2 = malloc(nn * nof(int *));
        for(i=0;i<nn;i++){
            te2[i]= malloc(nn*nof(int));
        }
        int **te3 = malloc(nn * nof(int *));
        for(i=0;i<nn;i++){
            te3[i]= malloc(nn*nof(int));
        }
        int **te4 = malloc(nn * nof(int *));
        for(i=0;i<nn;i++){
            te4[i]= malloc(nn*nof(int));
        }
        int **te5 = malloc(nn * nof(int *));
        for(i=0;i<nn;i++){
            te5[i]= malloc(nn*nof(int));
        }
        int **te6 = malloc(nn * nof(int *));
        for(i=0;i<nn;i++){
            te6[i]= malloc(nn*nof(int));
        }
        int **te7 = malloc(nn * nof(int *));
        for(i=0;i<nn;i++){
            te7[i]= malloc(nn*nof(int));
        }
        int **te8 = malloc(nn * nof(int *));
        for(i=0;i<nn;i++){
            te8[i]= malloc(nn*nof(int));
        }

        add(m1,m7,nn,te1);
        sub(m4,m5,nn,te2);
        add(te1,te2,nn,te3);    //c11

        add(m3,m5,nn,te4);//c12
        add(m2,m4,nn,te5);//c21

        add(m3,m6,nn,te6);
        sub(m1,m2,nn,te7);

        add(te6,te7,nn,te8);//c22

        int a=0;
        int b=0;
        int c=0;
        int d=0;
        int e=0;
        int nn2= 2*nn;
        for(i=0;i<nn2;i++){
            for(j=0;j<nn2;j++){
                if(j>=0 && j<nn && i>=0 && i<nn){
                    nw[i][j] = te3[i][j];
                }
                if(j>=nn && j<nn2 && i>=0 && i<nn){
                    a=j-nn;
                    nw[i][j] = te4[i][a];
                }
                if(j>=0 && j<nn && i>= nn && i < nn2){
                    c=i-nn;
                    nw[i][j] = te5[c][j];
                }
                if(j>=nn && j< nn2 && i>= nn && i< nn2 ){
                    d=i-nn;
                    e=j-nn;
                    nw[i][j] =te8[d][e];
                }
            }
        }
    free(m1);
    free(m2);
    free(m3);
    free(m4);
    free(m5);
    free(m6);
    free(m7);
    free(te1);
    free(te2);
    free(te3);
    free(te4);
    free(te5);
    free(te6);
    free(te7);
    free(te8);
    free(c11);
    free(c12);
    free(c21);
    free(c22);
    free(d11);
    free(d12);
    free(d21);
    free(d22);
    }
}

void main(){
    int n,p,i,j;
    printf("Enter n of matrix\n");
    scanf("%d",&n);
    int tempS = n;

    if(n & n-1 != 0){
        p = log(n)/log(2);
        n = pow(2,p+1);
    }

    printf("Enter elements of 1st matrix\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("Enter elements of 2nd matrix\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
        {
            scanf("%d",&b[i][j]);
        }
    }
    int nw[32][32];

    strassen(a,b,n,n,nw);

    if(tempS<n)
        n =tempS;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d   ",nw[i][j]);
        }
        printf("\n");
    }
}

