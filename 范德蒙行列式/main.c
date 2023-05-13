#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXSIZE 50
int main()
{
    int j,c=1;
    int h[MAXSIZE];
    int p[MAXSIZE][MAXSIZE];
    long int result=1.0;
    while(1)
    {
        printf("请输入行列式阶数：");
        scanf("%d",&j);
        printf("请输入行列式基准行（空格分开）：");
        for(int i=0; i<j; i++)
        {
            p[0][i]=1;
        }
        for(int i=0; i<j; i++)
        {
            scanf("%d",&h[i]);
        }
        for(int x=1; x<j; x++)
        {
            for(int i=0; i<j; i++)
            {
                p[x][i]=pow(h[i],c);
            }
            c++;
        }
        int k=j-1;
        for(k; k>=0; k--)
        {
            int l=k-1;
            for(l; l>=0; l--)
            {
                result=result*(h[k]-h[l]);
            }
        }
        for(int x=0; x<j; x++)
        {
            for(int i=0; i<j; i++)
            {
                printf("%d ",p[x][i]);
            }
            printf("\n");
        }
        printf("此范德蒙行列式结果为：%ld\n",result);
        result=1;
        c=1;
    }
    return 0;
}
