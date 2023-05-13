#include <malloc.h>
#include <stdio.h>
#include <string.h>
#define  MAXSIZE   512 /*线性表的最大长度*/
typedef char ElemType;//字符串定义为顺序表
typedef  struct
{
    ElemType  data[MAXSIZE];
    int  length;  /*当前表的长度*/
}SeqList;
SeqList *Inits()
{
    SeqList *L=(SeqList *)malloc(sizeof(SeqList));
    L->length=0;
    return L;
}
int Pushs(SeqList *L,ElemType e)
{
    int k;
    if (L->length==MAXSIZE){printf("The stack is overflow!");return 0;}  //*空间已满，不能入栈
    L->data[L->length]=e;//*入栈，尾插法
    L->length++;//*表长加1,L->length仍然是表的长度
    return 1;
}
int Pops(SeqList *L,ElemType *e)
{
    int  k;
    if(L->length==0)return 0;//*栈空出栈失败
    *e=L->data[L->length-1]; //*出栈，尾删法
    L->length--;
    return 1;
}

int Lc(char c)
{
    int i;
    char ss[7]="([{)]}";
    for(i=0;i<6;i++)if(ss[i]==c)break;
    return i;
}
int ExpMatch(char s[])//判断表达式括号匹配
{
  SeqList *L=NULL;
  char c;
  int m,j,n,i=0;
  n=strlen(s);
  L=Inits();
  for(i=0;i<n;i++)
  {
      m=Lc(s[i]);
      if(m==6)continue;
      if(m<3)Pushs(L,s[i]);
      else
      {
          Pops(L,&c);
          if(Lc(c)!=m-3){free(L);return 0;}
      }
  }
  if(L->length==0){free(L);return 1;}
  free(L);
  return 0;
}
int IsOp(char c)//判断运算符
{
    if(c=='+'||c=='-'||c=='*'||c=='/')return 1;
    return 0;
}
char Precede(char c1,char c2)//运算符优先级
{
    if((c1=='+'||c1=='-')&&(c2=='*'||c2=='/'))return 1;
    return 0;
}
int TwoResult(char op,int a,int b)//两数运算的函数
{
    switch(op)
    {
        case '+':return a+b;
        case '-':return a-b;
        case '*':return a*b;
        case '/':return a/b;
    }
}
int MtoSuffix(char ss[],char sm[])/*实现中缀表达式sm向后缀表达式ss转化，数据元素间加空格分隔*/
{
  SeqList *L=NULL;
  char c;
  int i,n;
  L=Inits();
  i=0;n=0;
  while(sm[i])
  {
      if(sm[i]>='0'&&sm[i]<='9')ss[n++]=sm[i];/*遇数字直接输出成后缀表达式项*/
      if(sm[i]=='(')Pushs(L,sm[i]);/*遇左括号入栈*/
      if(sm[i]==')')/*遇右括号出栈运算符成后缀表达式项，直至左括号，左括号出栈丢弃*/
      {
          ss[n++]=0x20;//添加空格分隔符
          while(Pops(L,&c)){if(c=='(')break;ss[n++]=c;}
      }
      if(IsOp(sm[i]))/*遇运算符分等级情况处理*/
      {
          ss[n++]=' ';/*遇运算符添加空格作分隔符，便于兼容数的识别*/
          while(Pops(L,&c))/*遇运算符出栈运算符成后缀表达式项，直至栈顶运算符等级更低或遇左括号*/
          {
              if(Precede(c,sm[i])||c=='(')
              {
                  Pushs(L,c);
                  break;
              }
              else ss[n++]=c;
          }
          Pushs(L,sm[i]);
      }
      i++;
  }
  while(Pops(L,&c))ss[n++]=c;
  ss[n]=0;
}

typedef struct Node//定义数的链栈
{
    int data;
    struct Node *next;
}LNode;
LNode *InitStack()
{
    LNode  *head;
    head=(LNode *)malloc(sizeof(LNode));
    head->next=NULL;
    return head;
}
void RuinList(LNode *L)
{
    LNode *p,*q;
    p=L;
    while(p)
    {
        q=p->next;
        free(p);
        p=q;
    }
    L=NULL;
}
/* 实现带头链表的栈Push 、Pop函数*/
void Pushi(LNode *L,int e)
{
    LNode *p;
    p=(LNode *)malloc(sizeof(LNode));

    p->data=e;
    p->next=L->next;
    L->next=p;
}
void Popi(LNode *L,int *e)
{
    LNode *p=L->next;
    if(p==NULL)return -1;
    L->next=p->next;
    *e=p->data;
    free(p);
}
int Expression(char s[])/*实现中缀表达式求值*/
{
  LNode *L=NULL;
  int i=0,x=0,r,y,z;
  L=InitStack();
  while(s[i])
  {
      if(s[i]>='0'&&s[i]<='9')
      {
          x=x*10+s[i]-'0';
          i++;
          continue;
      }
      if(s[i-1]>='0'&&s[i-1]<='9'&&i>0){Pushi(L,x);x=0;}
      if(IsOp(s[i]))//if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/')
      {
          Popi(L,&z);
          Popi(L,&y);
          r=TwoResult(s[i],y,z);//出栈顺序与栈中先后位置相反
          Pushi(L,r);
      }
      i++;
  }
  Popi(L,&x);
  RuinList(L);
  return x;

}

int main()
{
	char exp[128],ss[256];
	gets(exp);
    if(!ExpMatch(exp)){printf("Match error!!!");return 0;}
    MtoSuffix(ss,exp);
    printf("\n后缀表达式:%s = %d\n",ss,Expression(ss));
	return 1;
}
