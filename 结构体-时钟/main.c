#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
int hour,minute,second;
struct clock
{
    int hour;
    int minute;
    int second;
};
typedef struct clock CLOCK;
void time(void)//小时 分钟 秒计算程序
{
    second++;
    if(second==60)
    {
        second=0;
        minute++;
    }
    if(minute==60)
    {
        minute=0;
        hour++;
    }
    if(hour==24)
    {
        hour=0;
    }

}
void show(void)
{
    printf("%2d : %2d : %2d\r",hour,minute,second);//显示时间
}
//void delay(void)
//{
//    long t;
//    for(t=0;t<50000000;t++)
//    {
//        //空循环起延迟作用
//    }
//}
int main()
{
    hour=minute=second=0;
    long i;
    for(i=0;i<500000;i++)
    {
        time();
        show();
        Sleep(1000);//windows.h库中的延时函数，一千毫秒位一秒
    }
    return 0;
}
