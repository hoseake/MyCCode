#include<stdio.h>
int main()

{
    int select;
    printf("请输入一个行列式，用空格分开，回车换行。计算可重复运行\n");
    printf("三阶行列式请按 3\n二阶行列式请按 2\n并按回车确定\n");
    scanf("%d",&select);
    if(select!=3&&select!=2)
    {
        printf("输入有误，请重新输入：");
        scanf("%d",&select);
    }
    if (select==3)
    {
        printf("请输入三阶行列式\n");
        while(1)
        {
            int i,a[3][3],j,sum1,sum2,sum;
            for(i=0; i<3; i++)
            {
                for(j=0; j<3; j++)
                    scanf("%d",&a[i][j]);
            }
            sum1=a[0][2]*a[1][0]*a[2][1]+a[0][1]*a[1][2]*a[2][0]+a[0][0]*a[1][1]*a[2][2];
            sum2=a[2][2]*a[0][1]*a[1][0]+a[2][1]*a[1][2]*a[0][0]+a[0][2]*a[1][1]*a[2][0];
            sum=sum1-sum2;
            printf("结果为：%d\n",sum);
        }
    }
    if(select==2)
    {
        printf("请输入二阶行列式\n");
        while(1)
        {
            int i,a[2][2],j,sum1,sum2,sum;
            for(i=0; i<2; i++)
            {
                for(j=0; j<2; j++)
                    scanf("%d",&a[i][j]);
            }
            sum1=a[0][0]*a[1][1];
            sum2=a[1][0]*a[0][1];
            sum=sum1-sum2;
            printf("结果为：%d\n",sum);
        }
    }
}
