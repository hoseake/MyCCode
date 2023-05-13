#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
typedef struct node//创建结构体
{
    int value;//定义结构体的数据部分
    struct node *next;//定义结构体的指针部分
} lnode;//机构体名称
int main()
{
    lnode *head=(lnode *)malloc(sizeof(lnode));//开辟一个头指针，并为其开辟动态内存
    lnode *flag=head;//使头节点等于头指针所位于的内存位置
    scanf("%d",&flag->value);//输入节点包含的数据
    while(flag->value!=0)//当数据输入0时结束
    {
        flag->next=(lnode *)malloc(sizeof(lnode));//为上一个节点创建指针部分，并为其开辟动态内存
        flag=flag->next;//使当前循环节点等于上个节点所指的指针位置
        scanf("%d",&flag->value);//为当前循环节点输入数据
    }
    flag->next=NULL;//使最后一个节点的指针部分等于空，也就是结束链表
    flag=head;//使节点回到头节点位置
    while(flag!=NULL)//当节点为空节点时，终止打印
    {
        printf("%d ",flag->value);//逐个打印每个节点的数据
        flag=flag->next;//每次循环使节点向后推进一位
    }
    return 0;
}
