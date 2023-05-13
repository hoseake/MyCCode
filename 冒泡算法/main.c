 #include<stdio.h>
 int main()
 {
  int num[100];
   int i,j,max;
   for(i=0;i<4;i++)
   {
       scanf("%d",&num[i]);
   }
   for(i=0;i<3;i++)
   {
       for(j=0;j<3-i;j++)
       {
           if(num[j]<num[j+1])
           {
               max=num[j+1];
               num[j+1]=num[j];
               num[j]=max;
           }
       }
   }
   for(i=0;i<4;i++)
   {
       printf("%d ",num[i]);
   }
 }
