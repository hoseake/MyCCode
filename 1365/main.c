#include <stdio.h>
#include <stdlib.h>

int main()
{
   int a;
   for(a=10;a<=1000;a++)
   {
       if(a%2==0&&a%3==0&&a%7==0)
        printf("%d\n",a);
   }
    return 0;
}
