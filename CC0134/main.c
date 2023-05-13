#include <stdio.h>
int main()
{
    int n,a[100],b,c,i,e,h,f,g;
    scanf("%d",&n);
    h=n;
    for(i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    for(b=0; b<n; b++)
    {
        for(c=b + 1; c<n; c++)
        {
            if(a[b]==a[c])
            {
                for(int temp = c; temp<n-1; temp++)
                    a[temp]=a[temp+1];
                n--;
                c--;
            }
        }
    }
    printf("%d\n",n);
    for (e = 0; e < n - 1; e++)
    {
        for (f = 0; f < n - 1 - e; f++)
        {
            if (a[f] > a[f+1])
            {
                int t = a[f+1];
                a[f+1] = a[f];
                a[f] = t;
            }
        }
    }
    for(g=0; g<n; g++)
        printf("%d ",a[g]);
    return 0;
}
