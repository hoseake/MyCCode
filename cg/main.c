#include <stdio.h>
int main()
{
    int N;
    float sum=0;
    scanf("%d",&N);
    int i;
    float *num=(float *)malloc(sizeof(float)*N);
    for(i=0;i<N;i++)
    {
        scanf("%f",&num[i]);
    }
    for(i=0;i<N;i++)
    {
        sum+=num[i];
    }
    printf("average = %.2f\n",sum/N);
    for(i=0;i<N-1;i++)
    {
        for(int j=1;j<N;j++)
        {
            if(num[i]<num[j])
            {
                float t=num[i];
                num[i]=num[j];
                num[j]=t;
            }
        }
    }
    printf("max = %.2f\n",num[0]);
    for(i=0;i<N-1;i++)
    {
        for(int j=1;j<N;j++)
        {
            if(num[i]>num[j])
            {
                float t=num[i];
                num[i]=num[j];
                num[j]=t;
            }
        }
    }
    printf("min = %.2f\n",num[0]);
}



