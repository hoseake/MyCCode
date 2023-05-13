#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*int x,y;
    {
        scanf("%d",&x);
        if(x<1)
           {
                y=x;
        printf("%d",y);
           }
           if(x>=1&&x<10)
           {
               y=2*x-1;
                printf("%d",y);
           }
           if(x>=10)
           {
               y=3*x-11;
                printf("%d",y);
           }*/
        char a;
        printf("START\n");
         while(scanf("%c",&a)!=EOF)
         {

                if(a>='F'&&a<='Z')
                a=a-5;
                if(a>='A'&&a<='E')
                    a=a+21;
                printf("%c",a);
         }
         printf("END");

//        printf("%c",a);
//           int h,j,k;
//           for(h=0;h<4;h++)
//        {
//               for(j=3;j>0;j--)
//               {
//                   printf(" ");
//               }
//               for(k=0;k<4;k++)
//               {
//                   printf("%%");
//               }
//               printf("\n");
//        }
//





return 0;
    }




