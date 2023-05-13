#include <stdio.h>
#include <stdlib.h>

int main()
{
   int a,b,c;
   while(scanf("%d %d %d",&a,&b,&c)!=EOF)
   {
       if(a+b==c)
       {
           printf("Accepted\n");
       }
       else
       {
           printf("Wrong Answer\n");
       }
   }
   return 0;
}
