#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 4
int main()
{
    while(1)
{
    printf("计算三元线性方程组！\n");
        int b[MAXSIZE];
        int a[MAXSIZE][MAXSIZE];
        int D,D1,D2,D3;
        float X1,X2,X3;
        int Dsum1,Dsum2,D1sum1,D1sum2,D2sum1,D2sum2,D3sum1,D3sum2;
        printf("请依次输入常数项b1，b2，b3\n");
        for(int i=0; i<3; i++)
        {
            scanf("%d",&b[i]);
        }
        printf("请依次输入每项系数a11~a33\n");
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
        Dsum1=a[0][2]*a[1][0]*a[2][1]+a[0][1]*a[1][2]*a[2][0]+a[0][0]*a[1][1]*a[2][2];
        Dsum2=a[2][2]*a[0][1]*a[1][0]+a[2][1]*a[1][2]*a[0][0]+a[0][2]*a[1][1]*a[2][0];
        D=Dsum1-Dsum2;
        if(D!=0)
        {
            D1sum1=a[0][2]*b[1]*a[2][1]+a[0][1]*a[1][2]*b[2]+b[0]*a[1][1]*a[2][2];
            D1sum2=a[2][2]*a[0][1]*b[1]+a[2][1]*a[1][2]*b[0]+a[0][2]*a[1][1]*b[2];
            D1=D1sum1-D1sum2;
            X1=D1/D;
            D2sum1=a[0][2]*a[1][0]*b[2]+b[0]*a[1][2]*a[2][0]+a[0][0]*b[1]*a[2][2];
            D2sum2=a[2][2]*b[0]*a[1][0]+b[2]*a[1][2]*a[0][0]+a[0][2]*b[1]*a[2][0];
            D2=D2sum1-D2sum2;
            X2=D2/D;
            D3sum1=b[0]*a[1][0]*a[2][1]+a[0][1]*b[1]*a[2][0]+a[0][0]*a[1][1]*b[2];
            D3sum2=b[2]*a[0][1]*a[1][0]+a[2][1]*b[1]*a[0][0]+b[0]*a[1][1]*a[2][0];
            D3=D3sum1-D3sum2;
            X3=D3/D;
            printf("解得:\nX1 = %f\nX2 = %f\nX3 = %f\n",X1,X2,X3);
        }
        else
            printf("该三元线性方程组无解！\n");
    }
    return 0;
}
