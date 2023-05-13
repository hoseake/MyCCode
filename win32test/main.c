#include <Windows.h>
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
{
    MessageBox(
        NULL,
        TEXT("随便提示一些内容就可以了！哈哈哈！"),		// 内容
        TEXT("一个圆！"),		// 标题名称
        0);
       return 0;
   }
