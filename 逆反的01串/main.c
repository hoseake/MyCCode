#include <stdio.h>
#include <stdlib.h>

int main()
{
    char a;
    while(scanf("%c",&a)!=EOF)
    {
        if(a=='1')
            a=a-1;
        else if(a=='0')
            a=a+1;
        printf("%c",a);

    }
  printf("\n");

    return 0;
}
