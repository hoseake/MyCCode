#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*int n,i,m=0;
    char s[100];
    scanf("%d",&n);
    {
        scanf("%c",&s[i]);
    }
    for(i=0; i<n; i++)
    {

        if(s[i]=='i'&&s[i+1]=='g'&&s[i+2]=='n'&&s[i+3]=='b')
        {
            m++;
        }
    }
    printf("%d",m);*/

    int g,T,i,sum;
    long sum1,n;
    scanf("%d",&T);
    for(i=0; i<T; i++)
    {
        sum=0,sum1=0;
        scanf("%ld",&n);
        for(g=1; g<=n; g++)
        {
            sum = sum + (2*g-1);
            sum1 += sum;
        }
        sum1 = sum1%998244353;
        printf("%ld\n",sum1);
    }
    return 0;
}




/*int n,i,k=0,m=0;
char a[10];
float sum,sum1,sum2;
scanf("%d",&n);
for(i=0;i<n;i++)
{
    scanf("%c",&a[i]);
}
for(i=0;i<n;i++)
{
    if(n%2==1)
    {
      if(a[(n/2)+1]=='N')
        m=2;

    }sum+=m;
     if(n%2==0)
    {
        if(a[i]=='N')
            m=1;
    }sum+=m;*/
    /*if((a[0]=='N')||(a[n-1]=='N'))
    {
        m++;
        n--;
        sum1=m;
    }
    else if(a[i+1]=='N')
    {

        k++;
        n--;
        sum2=k*2;
    }*/
//return 0;
//}
//sum=sum1+sum2;
//printf("%.0f",sum);

//}

/*int main()
{
    int n,i,m=0;
    char s[100];
    scanf("%d",&n);
    for(i=0;i<n;i+4)
    {
        if(s[i]=='i'&&s[i]!='\0')
        {
            if(s[i+1]=='g'&&s[i+1]!='\0')
            {
                if(s[i+2]=='n'&&s[i+2]!='\0')
                {
                    if(s[i+3]=='b'&&s[i+3]!='\0')
                    {

                    }
                    m++;
                }
            }
        }
    }
    printf("%d",m);
    return 0;
}*/
