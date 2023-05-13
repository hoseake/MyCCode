#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define  MAXSIZE   100 /*线性表的最大长度*/
typedef int Status;
typedef int SElemType; /* SElemType类型根据实际情况而定，这里假设为int */
/* 顺序栈结构 */
typedef struct
{
    SElemType data[MAXSIZE];
    int top; /* 用于栈顶指针 */
}SqStack;


SqStack *InitStack()
{
    SqStack *S=(SqStack *)malloc(sizeof(SqStack));
    S->top=-1;
    return S;
}
/* 插入元素e为新的栈顶元素 */
Status Push(SqStack *S,SElemType e)
{
        if(S->top == MAXSIZE -1)return ERROR; /* 栈满 */
        S->top++;  /* 栈顶指针加1 */
        S->data[S->top]=e;
        return OK;
}
/* 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR */
Status Pop(SqStack *S,SElemType *e)
{
        if(S->top==-1)return ERROR;
        *e=S->data[S->top];  /* 将要删除的栈顶元素赋值给e */
        S->top--;    /* 栈顶指针减1 */
        return OK;
}
void Dec2R(int r, int d)//十进制数d转化为r进制数
{
    int x = 0 ;
    SqStack* s= InitStack() ;
    while(d > 0)
    {
        Push(s, d % r) ;
        d = d / r ;
    }
    while(s->top != -1)
    {
        Pop(s, &x) ;
        printf("%d", x) ;
    }
    printf("\n") ;
    free(s);
}


int main()
{
    Dec2R(2,13);
    return 0;
}
