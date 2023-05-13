#include <stdio.h>
#include <stdlib.h>
int main()
{
    int k;
    char i[100];
    scanf("%s",i);
    for(k=0;i[k]!='\0';k++)
    {

        if(i[k]>=65&&i[k]<=90||i[k]>=97&&i[k]<=122)
        {
            printf("%c",i[k]);
        }
    }
    return 0;
}
