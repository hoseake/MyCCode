#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m,n,o,p;
    scanf("%d %d",&m,&n);
    for(o=m;o>0;o--)
    {
        if(m%o==0&&n%o==0)
        {
            printf("%d\n",o);
            break;
        }
    }
    for(p=m;;p++)
    {
        if(p%m==0&&p%n==0)
        {
            printf("%d",p);
           return 0;
        }
    }

}
