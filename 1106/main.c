#include <stdio.h>
int main()
{
    char a[80];
    while(gets(a))
    {

        for(int i=0; a[i]!='\0'; i++)
        {
            if(a[i]==' ')
                continue;
            else
                printf("%c",a[i]);
        }
        printf("\n");
    }
    return 0;
}
