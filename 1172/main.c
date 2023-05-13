#include <stdio.h>
#include <stdlib.h>
int main()
{
  int n,a,b,d=0;
  while(scanf("%d",&n)!=EOF)
  {
    for(a=2;a<=n;a++)
  {
      int c=0;
      for(b=2;b<a;b++)
      {
          if(a%b==0)
          {
            c=1;
          }
      }
  if(c==0)
  {
      d++;
  }
  }
  printf("%d\n",d);
  }

}


