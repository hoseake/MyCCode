#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<signal.h>
#define _CRT_SECURE-NO-WARNINGS
struct student
{
    long int num;
    char name[20];
    int age;
    char sex[1];
    float cscore;
    float mscore;
    float escore;
    float sum;
    float ave;
};//数据结构体
struct Node
{
    //int data;
    struct student data;
    struct Node *next;
};//链表结构体
struct Node* makelist();//创建表头 表头一般不放东西
struct Node * makenode(struct student data);//创建节点
void inputnode(struct Node * headNode,struct student data);//插入节点
void printflist(struct Node* headNode);//打印节点
struct Node* searchbyID(struct Node*headNode,int* num);//查找节点
void deletebyID(struct Node* headNode,int* num);//删除节点
void rankCNode1(struct Node * headNdoe);//语文排序
void rankMNode1(struct Node * headNode);//数学排序
void rankENode1(struct Node * headNode);//英语排序
void rankSNode1(struct Node * headNode);//总成绩排序
void rankSNode2(struct Node * headNode);//总成绩排序(升序)
void rankCNode2(struct Node * headNode);//语文排序(升序)
void rankMNode2(struct Node * headNode);//数学排序(升序)
void rankENode2(struct Node * headNode);//英语排序(升序)
void menu()//菜单设计
{
    printf("***************学生管理系统*************\n");
    printf("*\t\t1.录入数据             *\n");
    printf("*\t\t2.浏览数据             *\n");
    printf("*\t\t3.修改修改             *\n");
    printf("*\t\t4.删除数据             *\n");
    printf("*\t\t5.查找数据             *\n");
    printf("*\t\t6.成绩排列(降序)       *\n");
    printf("*\t\t7.成绩排序(升序)       *\n");
    printf("*\t\t8.退出系统             *\n");
    printf("****************************************\n");
}
//交互，选择所选的序号进行操作
struct Node* list=NULL;
void menuselect()
{
    int c=1;
    int a=0;//判断排序的方式
    int choice=0;
    struct Node * result=NULL;
    struct Node * jieguo=NULL;
    struct student data;
    fflush(stdin);
    scanf("%d",&choice);
    fflush(stdin);
    switch(choice)
    {
    case 8:
        system("pause");
        exit(0);
        break;
    case 1:

        printf("**********录入数据**********\n");
 A:       printf("请输入学生学号:(请输入8位数值)");
        scanf("%ld",&data.num);
        fflush(stdin);



        while(data.num<10000000||data.num>99999999)
        {
            printf("学号错误,请重新输入学号:");
            scanf("%ld",&data.num);
        fflush(stdin);
        }
        result = searchbyID(list,data.num);
        if(result==NULL)
        {
        printf("请输入学生的姓名:");
        scanf("%s",data.name);
        fflush(stdin);
        printf("请输入学生的年龄:");
        scanf("%d",&data.age);
        fflush(stdin);
        while(data.age<0||data.age>100)
        {
            printf("请重新输入年龄:");
            scanf("%d",&data.age);
            fflush(stdin);
        }
        printf("请输入学生的性别:(m或者f)");
        scanf("%s",data.sex);
        fflush(stdin);
        while(c)
        {
            if(*data.sex=='f')
            {
                c=0;
            }
            else if(*data.sex=='m')
            {
                c=0;
            }
            else
            {
                printf("请重新输入性别:");
                scanf("%s",data.sex);
                fflush(stdin);
            }
        }
        printf("请输入学生的语文成绩:");
        scanf("%f",&data.cscore);
        fflush(stdin);
        while(data.cscore<0||data.cscore>150)
        {
            printf("请重新输入语文成绩:");
            scanf("%f",&data.cscore);
            fflush(stdin);
        }
        printf("请输入学生的数学成绩:");
        scanf("%f",&data.mscore);
        fflush(stdin);
        while(data.mscore<0||data.mscore>150)
        {
            printf("请重新输入数学成绩:");
            scanf("%f",&data.mscore);
            fflush(stdin);
        }
        printf("请输入英语成绩:");
        scanf("%f",&data.escore);
        fflush(stdin);
        while(data.escore<0||data.escore>150)
        {
            printf("请重新输入英语成绩:");
            scanf("%f",&data.escore);
            fflush(stdin);
        }
        inputnode(list,data);
        }
        else
        {
            printf("该学号已存在，重新输入\n");
            goto A;
        }

        break;
    case 2:
        printf("**********浏览数据**********\n");
        printflist(list); //打印
        break;
    case 3:
        printf("**********修改数据********\n");
        printf("请输入你要修改的学号:");
        scanf("%ld",&data.num);
        result = searchbyID(list,data.num);
        if(result==NULL)
            printf("查无此人!\n");
        else
        {
 B:           printf("请输入学号");
            scanf("%ld",&result->data.num);
            fflush(stdin);
            while(result->data.num<10000000||result->data.num>99999999)
            {
                printf("输入错误,请重新输入学号:");
                scanf("%ld",&result->data.num);
            fflush(stdin);
            }
            jieguo = searchbyID(list,result->data.num);
            if(jieguo!=NULL)
        {
            printf("该学号已经存在，请重新修改：\n");
            goto B;
        }
        else
        {
            printf("请输入姓名：");
            scanf("%s",result->data.name);
            fflush(stdin);
            printf("请输入年龄：");
            scanf("%d",&result->data.age);
            fflush(stdin);
            while(result->data.age<0||result->data.age>100)
            {
                printf("请重新输入年龄:");
                scanf("%d",&result->data.num);
                fflush(stdin);
            }

            printf("请输入性别");
            scanf("%s",result->data.sex);
            fflush(stdin);
            while(c)
            {
                if(*result->data.sex=='f')
                {
                    c=0;
                }
                else if(*result->data.sex=='m')
                {
                    c=0;
                }
                else
                {
                    printf("请重新输入性别:");
                    scanf("%s",result->data.sex);
                    fflush(stdin);
                }
            }

            printf("请输入语文成绩:");
            scanf("%f",&result->data.cscore);
            fflush(stdin);
            while(result->data.cscore<0||result->data.cscore>150)
            {
                printf("请重新输入语文成绩:");
                scanf("%f",&result->data.cscore);
                fflush(stdin);
            }

            printf("请输入数学成绩:");
            scanf("%f",&result->data.mscore);
            fflush(stdin);
            while(result->data.mscore<0||result->data.mscore>100)
            {
                printf("请重新输入数学成绩:");
                scanf("%f",&result->data.mscore);
                fflush(stdin);
            }

            printf("请输入英语成绩:");
            scanf("%f",&result->data.escore);
            fflush(stdin);
            while(result->data.escore<0||result->data.escore>100)
            {
                printf("请重新输入英语成绩:");
                scanf("%f",&result->data.escore);
                fflush(stdin);
            }
            printf("修改成功！");
        }

        }
        break;
    case 4:

        printf("**********删除数据**********\n");
        printf("请输入你要删除的学号:(8位数)");
        scanf("%ld",&data.num);
        fflush(stdin);
            while(data.num<10000000||data.num>99999999)
            {
                printf("输入错误,请重新输入学号:");
                scanf("%ld",&data.num);
        fflush(stdin);
            }
        deletebyID(list,data.num);
        break;
    case 5:
        printf("**********查找数据**********\n");
        printf("请输入你要查找的学号:(8位数)\n");
        scanf("%ld",&data.num);
        fflush(stdin);
            while(data.num<10000000||data.num>99999999)
            {
                printf("输入错误,请重新输入学号:");
                scanf("%ld",&data.num);
        fflush(stdin);
            }
        result = searchbyID(list,data.num);
        if(result==NULL)
            printf("查无此人!\n");
        else
        {
            printf("学生的学号:%ld\n",result->data.num);
            printf("学生的姓名:%s\n",result->data.name);
            printf("学生的年龄:%d\n",result->data.age);
            printf("学生的性别:%s\n",result->data.sex);
            printf("学生的语文成绩:%.2f\n",result->data.cscore);
            printf("学生的数学成绩:%.2f\n",result->data.mscore);
            printf("学生的英语成绩:%.2f\n",result->data.escore);
            printf("学生的总成绩:%.2f\n",result->data.sum=result->data.cscore+result->data.mscore+result->data.escore);
            printf("平均分:%.2f\n",result->data.ave=result->data.sum/3.0);
        }
        break;
    case 6:
 C:       printf("**********成绩排列(降序)**********\n");
        printf("\t1.语文成绩排列\n");
        printf("\t2.数学成绩排列\n");
        printf("\t3.英语成绩排列\n");
        printf("\t4.总成绩排列\n");
        scanf("%d",&a);
        fflush(stdin);
        switch(a)
        {
        case 1:
            rankCNode1(list);
            printflist(list);
            break;
        case 2:
            rankMNode1(list);
            printflist(list);
            break;
        case 3:
            rankENode1(list);
            printflist(list);
            break;
        case 4:
            rankSNode1(list);
            printflist(list);
            break;
        default:
            printf("选择错误，重新输入！\n");
            system("pause");
            goto C;

        }
        break;
    case 7:
D:        printf("**********成绩排列(升序)**********\n");
        printf("\t  1.语文成绩排列\n");
        printf("\t  2.数学成绩排列\n");
        printf("\t  3.英语成绩排列\n");
        printf("\t  4.总成绩排列\n");
        scanf("%d",&a);
        fflush(stdin);
        switch(a)
        {
printflist(list);
        case 1:
            rankCNode2(list);
            printflist(list);
            break;
        case 2:
            rankMNode2(list);
            printflist(list);
            break;
        case 3:
            rankENode2(list);
            printflist(list);
            break;
        case 4:
            rankSNode2(list);
            printflist(list);
            break;
        default:
            printf("选择错误，重新输入！\n");
            system("pause");
            goto D;

        }
        break;
        signal(SIGINT, SIG_IGN);
        system("color 0a");
    default:
        printf("选择错误，重新输入！\n");
        break;
    }
}
int main()
{
list=makelist();
   signal(SIGINT, SIG_IGN);
    system("color 0a");
    while(1)
    {
      menu();
        menuselect();
        system("pause");
        system("cls");
    }
    return 0;
}
//开始数据设计

//创建表头 表头一般不放东西

struct Node* makelist()
{
//    结构体变量表示
    struct Node *headNode = (struct Node*)malloc(sizeof(struct Node));
    headNode->next = NULL;
    return headNode;
}
//创建节点
struct Node * makenode(struct student data)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}
void inputnode(struct Node * headNode,struct student data)
{
    struct Node* newNode=makenode(data);
//  表头发插入
    newNode->next=headNode->next;
    headNode->next=newNode;
}

//指定位置删除
void deletebyID(struct Node* headNode,int* num)
{
    struct Node* posNode = headNode->next;
    struct Node* posFrontNode=headNode;
    if(posNode == NULL)
    {
        printf("数据为空，无法删除！\n");
        return;
    }
    while(posNode->data.num!=num)
    {
        posFrontNode=posNode;
        posNode=posFrontNode->next;
        if(posNode==NULL)
        {
            printf("没有找到指定位置无法删除！\n");
            return;
        }
    }
    posFrontNode->next=posNode->next;
    free(posNode);
}
//查找节点
struct Node* searchbyID(struct Node*headNode,int* num)
{
    struct Node* pMove = headNode->next;
    if(pMove==NULL)
        return NULL;
    while(pMove->data.num!=num)
    {
        pMove=pMove->next;
        if(pMove==NULL)
        {
            return pMove;
        }
    }
    return pMove;
}
//打印链表
void printflist(struct Node * headNode)
{
    struct Node *pMove=headNode->next;
//    数据处理
    while(pMove!=NULL)
    {
        printf("学号:%ld\n",pMove->data.num);
        printf("姓名:%s\n",pMove->data.name);
        printf("年龄:%d\n",pMove->data.age);
        printf("性别:%s\n",pMove->data.sex);
        printf("语文成绩:%.2f\n",pMove->data.cscore);
        printf("数学成绩:%.2f\n",pMove->data.mscore);
        printf("英语成绩:%.2f\n",pMove->data.escore);
        printf("总成绩:%.2f\n",pMove->data.sum=pMove->data.cscore+pMove->data.mscore+pMove->data.escore);
        printf("平均分:%.2f\n",pMove->data.ave=pMove->data.sum/3.0);
        printf("\n");
        pMove=pMove->next;
    }
    printf("\n");
}
void rankCNode1(struct Node * headNode)//语文成绩排序(降序)
{
    struct Node *posNodehead=headNode->next;
    struct Node *tallyNode=headNode;
    while(posNodehead!=NULL)
    {
        while(posNodehead->next!=NULL)
        {
            if(posNodehead->data.cscore<posNodehead->next->data.cscore)
            {
                struct student temp=posNodehead->data;
                posNodehead->data=posNodehead->next->data;
                posNodehead->next->data=temp;
            }
            posNodehead=posNodehead->next;
        }
        posNodehead=tallyNode->next;
        tallyNode=posNodehead;
    }
}
void rankCNode2(struct Node * headNode)//语文成绩排序(升序)
{
    struct Node *posNodehead=headNode->next;
    struct Node *tallyNode=headNode;
    while(posNodehead!=NULL)
    {
        while(posNodehead->next!=NULL)
        {
            if(posNodehead->data.cscore>posNodehead->next->data.cscore)
            {
                struct student temp=posNodehead->data;
                posNodehead->data=posNodehead->next->data;
                posNodehead->next->data=temp;
            }
            posNodehead=posNodehead->next;
        }
        posNodehead=tallyNode->next;
        tallyNode=posNodehead;
    }
}
void rankMNode1(struct Node * headNode)//数学成绩排序(降序)
{
    struct Node *posNodehead=headNode->next;
    struct Node *tallyNode=headNode;
    while(posNodehead!=NULL)
    {
        while(posNodehead->next!=NULL)
        {
            if(posNodehead->data.mscore<posNodehead->next->data.mscore)
            {
                struct student temp=posNodehead->data;
                posNodehead->data=posNodehead->next->data;
                posNodehead->next->data=temp;
            }
            posNodehead=posNodehead->next;
        }
        posNodehead=tallyNode->next;
        tallyNode=posNodehead;
    }
}
void rankMNode2(struct Node * headNode)//数学成绩排序(升序)
{
    struct Node *posNodehead=headNode->next;
    struct Node *tallyNode=headNode;
    while(posNodehead!=NULL)
    {
        while(posNodehead->next!=NULL)
        {
            if(posNodehead->data.mscore>posNodehead->next->data.mscore)
            {
                struct student temp=posNodehead->data;
                posNodehead->data=posNodehead->next->data;
                posNodehead->next->data=temp;
            }
            posNodehead=posNodehead->next;
        }
        posNodehead=tallyNode->next;
        tallyNode=posNodehead;
    }
}
void rankENode1(struct Node * headNode)//英语成绩排序(降序)
{
    struct Node *posNodehead=headNode->next;
    struct Node *tallyNode=headNode;
    while(posNodehead!=NULL)
    {
        while(posNodehead->next!=NULL)
        {
            if(posNodehead->data.escore<posNodehead->next->data.escore)
            {
                struct student temp=posNodehead->data;
                posNodehead->data=posNodehead->next->data;
                posNodehead->next->data=temp;
            }
            posNodehead=posNodehead->next;
        }
        posNodehead=tallyNode->next;
        tallyNode=posNodehead;
    }
}
void rankENode2(struct Node * headNode)//英语成绩排序(升序)
{
    struct Node *posNodehead=headNode->next;
    struct Node *tallyNode=headNode;
    while(posNodehead!=NULL)
    {
        while(posNodehead->next!=NULL)
        {
            if(posNodehead->data.escore>posNodehead->next->data.escore)
            {
                struct student temp=posNodehead->data;
                posNodehead->data=posNodehead->next->data;
                posNodehead->next->data=temp;
            }
            posNodehead=posNodehead->next;
        }
        posNodehead=tallyNode->next;
        tallyNode=posNodehead;
    }
}
void rankSNode1(struct Node * headNode)//总成绩排序(降序)
{
    struct Node *posNodehead=headNode->next;
    struct Node *tallyNode=headNode;
    while(posNodehead!=NULL)
    {
        while(posNodehead->next!=NULL)
        {
            if(posNodehead->data.sum<posNodehead->next->data.sum)
            {
                struct student temp=posNodehead->data;
                posNodehead->data=posNodehead->next->data;
                posNodehead->next->data=temp;
            }
            posNodehead=posNodehead->next;
        }
        posNodehead=tallyNode->next;
        tallyNode=posNodehead;
    }
}
void rankSNode2(struct Node * headNode)//总成绩排序(升序)(有问题)
{
    struct Node *posNodehead=headNode->next;
    struct Node *tallyNode=headNode;
    while(posNodehead!=NULL)
    {
        while(posNodehead->next!=NULL)
        {
            if(posNodehead->data.sum>posNodehead->next->data.sum)
            {
                struct student temp=posNodehead->data;
                posNodehead->data=posNodehead->next->data;
                posNodehead->next->data=temp;
            }
            posNodehead=posNodehead->next;
        }
        posNodehead=tallyNode->next;
        tallyNode=posNodehead;
    }
}
