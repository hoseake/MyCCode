#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#define NULL 0
struct student
{
    char num[20];
    char name[20];
    float cscore;
    float mscore;
    float escore;
};//数据结构体
typedef struct Node
{
    //int data;
    struct student data;
    struct Node *next;
} LNode;
LNode *create(int n);
void printl(LNode *head);
void LocateByNum(LNode *head);
int s=0;
int main()
{
    int n;
    printf("\n\n\t|********欢迎进入学生信息管理系统*******************|\n");
    printf("\t|*********1.录入学生信息****************************|\n");
    printf("\t|*********2.显示学生信息****************************|\n");
    printf("\t|*********3.查询学生信息****************************|\n");
    printf("\t|*********4.修改学生信息****************************|\n");
    printf("\t|*********5.添加学生信息****************************|\n");
    printf("\t|*********6.删除学生信息****************************|\n");
    printf("\t|*********7.按总分排名次****************************|\n");
    printf("\t|*********0.退出************************************|\n");
    while(1)
    {
        int s;
        LNode *Head;
        printf("请输入想要操作功能的序号：");
        scanf("%d",&s);
        switch(s)
        {
        case 1:
            printf("请输入录入学生数量：");
            scanf("%d",&n);
            Head=create(n);
            break;
        case 2:
            printf("学号             姓名    语文成绩       数学成绩         英语成绩\n");
            printl(Head);
            break;
        case 3:
            printf("请输入要查询的学号:");
            LocateByNum(Head);
            break;
        case 4:
            printf("请输入要修改数据对应的学号：");
            change(Head);
            break;
        case 5:
            Insert(Head,n);
            break;
        case 6:
            DeleteByNum(Head);
            break;
        case 7:

            break;
        case 0:
            FreeAll(Head);
            system("cls");
            exit(0);
            break;
        }
    }

}
LNode *create(int n)
{
    char tnum[20];
    LNode  *head,*pnew,*prear;
    int i;
    head=(LNode *)malloc(sizeof(LNode));
    head->next=NULL;
    //for(i=0;i<n;i++)Insert_LinkList(head,i+1,i*i);
    prear=head;
    for(i=0; i<n; i++)
    {
        pnew=(LNode *)malloc(sizeof(LNode));
A:
        printf("请输入第%d个学生学号：",i+1);
        scanf("%s",tnum);
        if (strspn(tnum,"0123456789")==strlen(tnum))
        {
            strcpy(pnew->data.num,tnum);
        }
        else
        {
            printf("学号输入有误!\n");
            goto A;
        }
        printf("请输入第%d个学生姓名：",i+1);
        scanf("%s",pnew->data.name);
        printf("请输入第%d个学生语文成绩：",i+1);
        scanf("%f",&pnew->data.cscore);
        printf("请输入第%d个学生数学成绩：",i+1);
        scanf("%f",&pnew->data.mscore);
        printf("请输入第%d个学生英语成绩：",i+1);
        scanf("%f",&pnew->data.escore);
        prear->next=pnew;
        prear=pnew;
    }
    pnew->next=NULL;
    return head;
}
void printl(LNode *head)
{
    LNode *p=head->next;/* p指向第一个元素结点*/
    while(p!=NULL )
    {
        printf("%s      %s     %f       %f        %f\n",p->data.num,p->data.name,p->data.cscore,p->data.mscore,p->data.escore);
        p=p->next;
    }
}
void LocateByNum(LNode *head)
{
    char tnum[20];
    int i=0;
    LNode  *p=head->next;
    scanf("%s",tnum);
    while(p!=NULL)
    {
        if(strcmp(p->data.num,tnum)==0)
        {
            printf("学号             姓名    语文成绩       数学成绩         英语成绩\n");
            printf("%s      %s     %f       %f        %f\n",p->data.num,p->data.name,p->data.cscore,p->data.mscore,p->data.escore);
            i=1;
            break;
        }
        p=p->next;
    }
    if(i==0)
        printf("没有该学号信息！\n");
}
LNode * GetElem(LNode *head, int  i)/*在单链表head中查找第i个元素结点，找到返回其指针，否则返回空*/
{
    LNode *p=head;
    int  j=0;     /*结点计数器j */
    while(p->next!=NULL&&j<i)
    {
        p=p->next;
        j++;
    }
    if(j==i)
        return p;
    return NULL;
}
void DeleteByNum(LNode *head)
{
    char tnum[20];
    int i=0;
    LNode  *p=head->next;
    scanf("%s",tnum);
    LNode *pre;
    while(p->next!=NULL)
    {
        s++;
        if(strcmp(p->data.num,tnum)==0)
        {
            i=1;
            break;
        }
        pre=p;
        p=p->next;
    } /*查找值为X的数据元素结点*/
    if(i=1)
    {
        pre->next=p->next;    /*找到删除*/
        free(p);
    }
    else
    {
        printf("没有该学号信息！\n");
        return;
    }
}
void FreeAll(LNode *head)
{
    LNode *q,*p=head;
    while(p!=NULL)
    {
        q=p->next;
        free(p);
        p=q;
    }
    head=NULL;
}
void  Insert( LNode *head, int i)
{
    LNode *pre,*s;
    s=(LNode *)malloc(sizeof(LNode)); /*申请填装结点*/
    char tnum[20];
    pre=GetElem(head,i-1);   /*查找第i-1个结点*/
    if(pre==NULL)
    {
        printf("插入错误！");
        return;
    }
C:
    printf("请输入第%d个学生学号：",i+1);
    scanf("%s",tnum);

    if (strspn(tnum,"0123456789")==strlen(tnum))
    {
        strcpy(s->data.num,tnum);
    }
    else
    {
        printf("学号输入有误!\n");
        goto C;
    }
    printf("请输入第%d个学生姓名：",i+1);
    scanf("%s",s->data.name);
    printf("请输入第%d个学生语文成绩：",i+1);
    scanf("%f",&s->data.cscore);
    printf("请输入第%d个学生数学成绩：",i+1);
    scanf("%f",&s->data.mscore);
    printf("请输入第%d个学生英语成绩：",i+1);
    scanf("%f",&s->data.escore);

    s->next=pre->next;  /*新结点插入在第i-1个结点的后面*/

    pre->next=s;
}
void change(LNode *head)
{
    char tnum[20];
    int i=0,select;
    LNode  *p=head->next;
    scanf("%s",tnum);
    while(p!=NULL)
    {
        if(strcmp(p->data.num,tnum)==0)
        {
            printf("请选择要修改的数据：");
            printf("1.姓名   2.语文成绩   3.数学成绩   4.英语成绩\n你的选择：");
            scanf("%d",&select);
            switch(select)
            {
            case 1:
                printf("请输入学生姓名：");
                scanf("%s",p->data.name);
                break;
            case 2:
                printf("请输入学生语文成绩：");
                scanf("%f",&p->data.cscore);
                break;
            case 3:
                printf("请输入学生数学成绩：");
                scanf("%f",&p->data.mscore);
                break;
            case 4:
                printf("请输入学生英语成绩：");
                scanf("%f",&p->data.escore);
                break;
            }
            i=1;
            break;
        }
        p=p->next;
    }
    if(i==0)
        printf("没有该学号信息！\n");
}
