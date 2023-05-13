#include<stdio.h>
#include<stdlib.h>
int main()
{
   float moHeight,faHeight,childHeight;
   char sports,diet,sex;
   printf("依次输入性别，父母身高，是否喜爱体育锻炼，是否有良好的体育习惯\n");
   scanf("%c %f %f %c %c",&sex,&faHeight,&moHeight,&sports,&diet);
   if(sex=='M')
   {
       childHeight=(faHeight+moHeight)*0.54;
       if(sports=='Y'&&diet=='Y')
       {
           childHeight=childHeight+childHeight*0.035;
       }
       if(sports=='Y'&&diet=='N')
       {
           childHeight=childHeight+childHeight*0.02;
       }
       if(diet=='Y'&&sports=='N')
       {
           childHeight=childHeight+childHeight*0.015;
       }
   }
   if(sex=='F')
   {
       childHeight=(faHeight*0.923+moHeight)/2;
       if(sports=='Y'&&diet=='Y')
       {
           childHeight=childHeight+childHeight*0.035;
       }
       if(sports=='Y'&&diet=='N')
       {
           childHeight=childHeight+childHeight*0.02;
       }
       if(diet=='Y'&&sports=='N')
       {
           childHeight=childHeight+childHeight*0.015;
       }
   }
   printf("%.2f",childHeight);
}
