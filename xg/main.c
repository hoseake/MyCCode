#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<signal.h>
#define _CRT_SECURE-NO-WARNINGS
struct student
{
    long int id;
    char name[20];
    int age;
    char sex[1];
    float Cscore;
    float Mscore;
    float Escore;
    float sum;
};//单独写某一种数据结构
struct Node
{
    //int data;
    struct student data;
    struct Node *next;
};
struct Node* createList();//创建表头 表头一般不放东西
struct Node * createNode(struct student data);//创建节点
void insertNodeByhead(struct Node * headNode,struct student data);//插入节点
void printflist(struct Node* headNode);//打印节点
struct Node* searchInfoByData(struct Node*headNode,int* id);//查找节点
void deleteAppoinNode(struct Node* headNode,int* id);//删除节点
void rankCNode1(struct Node * headNdoe);//语文成绩排序
void rankMNode1(struct Node * headNode);//数学成绩排序
void rankENode1(struct Node * headNode);//英语成绩排序
void rankSNode1(struct Node * headNode);//总成绩排序
void rankSNode2(struct Node * headNode);//总成绩排序(升序)
void rankCNode2(struct Node * headNode);//语文成绩排序(升序)
void rankMNode2(struct Node * headNode);//数学成绩排序(升序)
void rankENode2(struct Node * headNode);//英语成绩排序(升序)
//void judgeNode(struct Node * headNode,int *id);//判断学号是否重复
void menu()//菜单设计
{
    printf("-------------学生管理系统---------------\n");
    printf("\t1.录入信息\n");
    printf("\t2.浏览信息\n");
    printf("\t3.修改信息\n");
    printf("\t4.删除信息\n");
    printf("\t5.查找信息\n");
    printf("\t6.成绩排列(降序)\n");
    printf("\t7.成绩排序(升序)\n");
    printf("\t8.退出系统\n");
    printf("----------------------------------------\n");
}
//交互，选择所选的序号进行操作
struct Node* list=NULL;
void keyDown()
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
        printf("正常退出\n");
        system("pause");
        exit(0);
        break;
    case 1:

        printf("-----------录入信息------------\n");
 A:       printf("请输入学生学号:(请输入9位数值)");
        scanf("%ld",&data.id);
        fflush(stdin);



        while(data.id<100000000||data.id>999999999)
        {
            printf("输入错误,请重新输入学号:");
            scanf("%ld",&data.id);
        fflush(stdin);
        }
        result = searchInfoByData(list,data.id);
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
        printf("请输入学生的性别:(M或者W)");
        scanf("%s",data.sex);
        fflush(stdin);
        while(c)
        {
            if(*data.sex=='M')
            {
                c=0;
            }
            else if(*data.sex=='W')
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
        scanf("%f",&data.Cscore);
        fflush(stdin);
        while(data.Cscore<0||data.Cscore>100)
        {
            printf("请重新输入语文成绩:");
            scanf("%f",&data.Cscore);
            fflush(stdin);
        }
        printf("请输入学生的数学成绩:");
        scanf("%f",&data.Mscore);
        fflush(stdin);
        while(data.Mscore<0||data.Mscore>100)
        {
            printf("请重新输入数学成绩:");
            scanf("%f",&data.Mscore);
            fflush(stdin);
        }
        printf("请输入英语成绩:");
        scanf("%f",&data.Escore);
        fflush(stdin);
        while(data.Escore<0||data.Escore>100)
        {
            printf("请重新输入英语成绩:");
            scanf("%f",&data.Escore);
            fflush(stdin);
        }
        insertNodeByhead(list,data);
        }
        else
        {
            printf("该学号已存在，重新输入\n");
            goto A;
        }

        break;
    case 2:
        printf("-----------浏览信息------------\n");
        printflist(list); //打印
        break;
    case 3:
        printf("-----------修改信息------------\n");
        printf("请输入你要修改的学号:");
        scanf("%ld",&data.id);
        result = searchInfoByData(list,data.id);
        if(result==NULL)
            printf("查无此人!无法修改\n");
        else
        {
 B:           printf("请输入新学生学号");
            scanf("%ld",&result->data.id);
            fflush(stdin);
            while(result->data.id<100000000||result->data.id>999999999)
            {
                printf("输入错误,请重新输入学号:");
                scanf("%ld",&result->data.id);
            fflush(stdin);
            }
            jieguo = searchInfoByData(list,result->data.id);
            if(jieguo!=NULL)
        {
            printf("该学号已经存在，请重新修改：\n");
            goto B;
        }
        else
        {
            printf("请输入新学生的姓名：");
            scanf("%s",result->data.name);
            fflush(stdin);
            printf("请输入新学生的年龄：");
            scanf("%d",&result->data.age);
            fflush(stdin);
            while(result->data.age<0||result->data.age>100)
            {
                printf("请重新输入年龄:");
                scanf("%d",&result->data.id);
                fflush(stdin);
            }

            printf("请输入新学生的性别");
            scanf("%s",result->data.sex);
            fflush(stdin);
            while(c)
            {
                if(*result->data.sex=='M')
                {
                    c=0;
                }
                else if(*result->data.sex=='W')
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

            printf("请输入新学生的语文成绩:");
            scanf("%f",&result->data.Cscore);
            fflush(stdin);
            while(result->data.Cscore<0||result->data.Cscore>100)
            {
                printf("请重新输入语文成绩:");
                scanf("%f",&result->data.Cscore);
                fflush(stdin);
            }

            printf("请输入新学生的数学成绩:");
            scanf("%f",&result->data.Mscore);
            fflush(stdin);
            while(result->data.Mscore<0||result->data.Mscore>100)
            {
                printf("请重新输入数学成绩:");
                scanf("%f",&result->data.Mscore);
                fflush(stdin);
            }

            printf("请输入新学生的英语成绩:");
            scanf("%f",&result->data.Escore);
            fflush(stdin);
            while(result->data.Escore<0||result->data.Escore>100)
            {
                printf("请重新输入英语成绩:");
                scanf("%f",&result->data.Escore);
                fflush(stdin);
            }
            printf("修改成功！");
        }

        }
        break;
    case 4:

        printf("-----------删除信息------------\n");
        printf("请输入你要删除的学号:(9位数)");
        scanf("%ld",&data.id);
        fflush(stdin);
            while(data.id<100000000||data.id>999999999)
            {
                printf("输入错误,请重新输入学号:");
                scanf("%ld",&data.id);
        fflush(stdin);
            }
        deleteAppoinNode(list,data.id);
        break;
    case 5:
        printf("-----------查找信息------------\n");
        printf("请输入你要查找的学号:(9位数)\n");
        scanf("%ld",&data.id);
        fflush(stdin);
            while(data.id<100000000||data.id>999999999)
            {
                printf("输入错误,请重新输入学号:");
                scanf("%ld",&data.id);
        fflush(stdin);
            }
        result = searchInfoByData(list,data.id);
        if(result==NULL)
            printf("查无此人!\n");
        else
        {
            printf("学生的id:%ld\n",result->data.id);
            printf("学生的姓名:%s\n",result->data.name);
            printf("学生的年龄:%d\n",result->data.age);
            printf("学生的性别:%s\n",result->data.sex);
            printf("学生的语文成绩:%.2f\n",result->data.Cscore);
            printf("学生的数学成绩:%.2f\n",result->data.Mscore);
            printf("学生的英语成绩:%.2f\n",result->data.Escore);
            printf("学生的总成绩:%.2f\n",result->data.sum);
        }
        break;
    case 6:
 C:       printf("----------成绩排列(降序)----------\n");
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
D:        printf("----------成绩排列(升序)----------\n");
        printf("\t1.语文成绩排列\n");
        printf("\t2.数学成绩排列\n");
        printf("\t3.英语成绩排列\n");
        printf("\t4.总成绩排列\n");
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
list=createList();
   signal(SIGINT, SIG_IGN);
    system("color 0a");
    while(1)
    {
      menu();
        keyDown();
        system("pause");
        system("cls");
    }


    return 0;
}
//开始数据设计

//创建表头 表头一般不放东西

struct Node* createList()
{
//    结构体变量表示
    struct Node *headNode = (struct Node*)malloc(sizeof(struct Node));
    headNode->next = NULL;
    return headNode;
}
//创建节点
struct Node * createNode(struct student data)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}

//void judgeNode(struct Node * headNode,int *id)//判断学号是否重复
//{
//    struct Node* posNode=headNode->next;
//   if(posNode==NULL)
//   {
//       printf("数据不够\n");
//       return;
//   }
//   while(posNode->data.id!=id)
//   {
//     posNode=posNode->next;
//     if(posNode->data.id==id)
//     {
//         printf("有重复学号");
//         return;
//     }
//
//   }return;
//}

//插入节点
void insertNodeByhead(struct Node * headNode,struct student data)
{
    struct Node* newNode=createNode(data);
//  表头发插入
    newNode->next=headNode->next;
    headNode->next=newNode;
}

//指定位置删除
void deleteAppoinNode(struct Node* headNode,int* id)
{
    struct Node* posNode = headNode->next;
    struct Node* posFrontNode=headNode;
    if(posNode == NULL)
    {
        printf("数据为空，无法删除！\n");
        return;
    }
    while(posNode->data.id!=id)
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
struct Node* searchInfoByData(struct Node*headNode,int* id)
{
    struct Node* pMove = headNode->next;
    if(pMove==NULL)
        return NULL;
    while(pMove->data.id!=id)
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
        printf("学号:%ld\n",pMove->data.id);
        printf("姓名:%s\n",pMove->data.name);
        printf("年龄:%d\n",pMove->data.age);
        printf("性别:%s\n",pMove->data.sex);
        printf("语文成绩:%.2f\n",pMove->data.Cscore);
        printf("数学成绩:%.2f\n",pMove->data.Mscore);
        printf("英语成绩:%.2f\n",pMove->data.Escore);
        printf("总成绩:%.2f\n",pMove->data.Cscore+pMove->data.Mscore+pMove->data.Escore);
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
            if(posNodehead->data.Cscore<posNodehead->next->data.Cscore)
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
            if(posNodehead->data.Cscore>posNodehead->next->data.Cscore)
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
            if(posNodehead->data.Mscore<posNodehead->next->data.Mscore)
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
            if(posNodehead->data.Mscore>posNodehead->next->data.Mscore)
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
            if(posNodehead->data.Escore<posNodehead->next->data.Escore)
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
            if(posNodehead->data.Escore>posNodehead->next->data.Escore)
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
