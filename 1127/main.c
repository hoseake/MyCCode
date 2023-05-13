#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t;
    while(scanf("%d",&t)!=EOF)
    {
        if(t<0||t>100)
        {
            printf("Score is error!\n");
        }
        else if(t>=90&&t<=100)
            printf("A\n");
        else if(t>=80&&t<=89)
            printf("B\n");
        else if(t>=70&&t<=79)
            printf("C\n");
        else if(t>=60&&t<=69)
            printf("D\n");
        else
            printf("E\n");
    }
    return 0;
}
