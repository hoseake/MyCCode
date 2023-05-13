#include <stdio.h>
#include <stdlib.h>
int main()
{
    int j,k,l,m;
    int i;
//    for(i = 0;i<=10;i++)
//    {
//        printf("OK\n");
//    }
//    j = 3;
//    do{
//        printf("Nope\n");
//        j++;
//    }while(j<=2);
//
//    k = 0;
//    while(k<2)
//    {
//        printf("Right\n");
//        k++;
//    }
//
//
//    i = 101;
//    while(i<=100); //死循环
    //i++;
//    for(l=1;l<=100;l++);//延时
//    printf("%d\n",l); //问：为什么l = 101
//
    for(m=1;m<=5;m++)
    {
        //printf("%d          ",m);
        if(m==3)
        {
            continue;
        }
        printf("%d          ",m);
    }
//    for(i = 1;i<=10;i++)
//    {
//        printf("NOPE   ");
//        for(j = 1;j<=10;j++)
//        {
//            printf("OK  ");
//        }
//    }

    return 0;
}
