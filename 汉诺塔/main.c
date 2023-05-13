//#include <stdio.h>
//#include <stdlib.h>
//int count=0;
//int main()
//{
//    int n;
//    scanf("%d",&n);
//    hannuo(n);
//    printf("%d",count);
//    return 0;
//}
//void hannuo(int n)
//{
//    if(n==1)
//    {
//        count++;
//    }
//    else
//    {
//        hannuo(n-1);
//        count++;
//        hannuo(n-1);
//    }
//}

#include <stdio.h>
#include <stdlib.h>
int count=0;
int main()
{
    int n;
    scanf("%d",&n);
    hannuo(n,'A','B','C');
    printf("%d",count);
    return 0;
}
void hannuo(int n,char x,char y,char z)
{
    if(n==1)
    {
        printf("%c------>%c\n",x,z);
        count++;
    }
    else
    {
        hannuo(n-1,x,z,y);
        printf("%c->%c\n",x,z);
        count++;
        hannuo(n-1,y,x,z);
    }
}

