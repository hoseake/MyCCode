#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct Node
{
    ElemType data;
    struct Node *next;
} LNode;

LNode *createh(int n)
{
    LNode  *head,*pnew;
    int i;
    head=(LNode *)malloc(sizeof(LNode));
    head->next=NULL;

    //for(i=0;i<n;i++)Insert_LinkList(head,1,i*i);

    for(i=0;i<n;i++)
    {
        pnew=(LNode *)malloc(sizeof(LNode));
        scanf("%d",&pnew->data);
        //pnew->data=i*i;

        pnew->next=head->next;//头插法关键语句
        head->next=pnew;//头插法关键语句
    }
    return head;
}

LNode *Inscreate(int n)
{
    LNode  *head;
    int i;
    head=(LNode *)malloc(sizeof(LNode));
    head->next=NULL;

    //for(i=0;i<n;i++)Insert_LinkList(head,i+1,i*i);
    for(i=0;i<n;i++)Insert_LinkList(head,1,i*i);

    return head;
}

LNode *create(int n)
{
    LNode  *head,*pnew,*prear;
    int i;
    head=(LNode *)malloc(sizeof(LNode));
    head->next=NULL;

    //for(i=0;i<n;i++)Insert_LinkList(head,i+1,i*i);

    prear=head;
    for(i=0;i<n;i++)
    {
        pnew=(LNode *)malloc(sizeof(LNode));
        //scanf("%d",&pnew->data);
        pnew->data=i*i;

	    prear->next=pnew;//尾插法关键语句
        prear=pnew;//尾插法关键语句
    }
    pnew->next=NULL;
    return head;
}

void travel(LNode *head)
{
    LNode *p=head->next;/* p指向第一个元素结点*/
	while(p!=NULL)/* 循环链尾判断实现链表结点遍历*/
	{
	    p->data;  //当前结点数据元素值
		p=p->next;
	}
}

void printl(LNode *head)
{
    LNode *p=head->next;/* p指向第一个元素结点*/
	while(p!=NULL )
	{
	    printf("%d ",p->data);  //输出一结点的信息

		p=p->next;
	}
}

int  ListLength(LNode *head)
{
   LNode *p=head->next; /* p指向第一个元素结点*/
   int  i=0;          /*计数器i*/
   while(p!=NULL)
   {
       i++;

       p=p->next;
   }
   return  i;
}

LNode * GetElem(LNode *head, int  i)/*在单链表head中查找第i个元素结点，找到返回其指针，否则返回空*/
{
    LNode *p=head;
    int  j=0;     /*结点计数器j */
    while(p->next!=NULL&&j<i){p=p->next;j++;}
    if(j==i)return p;
    return NULL;
}

LNode  *LocateElem(LNode *head,ElemType x)/*在单链表head中查找值为x的结点，找到后返回其指针，否则返回空*/
{
    LNode  *p=head;
    while(p->next!=NULL&&p->data!=x)p=p->next;
    if(p->data==x) return p;
    return NULL;
}

void  Insert_LinkList( LNode *head, int i, ElemType  x)
{
    LNode *pre,*s;

    pre=GetElem(head,i-1);   /*查找第i-1个结点*/
    if(pre==NULL){printf("\nPosition Error\n");return; }


    s=(LNode *)malloc(sizeof(LNode)); /*申请填装结点*/
    s->data=x;

    s->next=pre->next;  /*新结点插入在第i-1个结点的后面*/

    pre->next=s;
}

void Del_LinkList(LNode *head,int i)
{
    LNode *pre,*r;

    pre=GetElem(head,i-1);   /*查找第i-1个结点*/
    if(pre==NULL||pre->next==NULL){printf("\nPosition Error\n");return;}/*第i或者第i-1个结点不存在*/


    r=pre->next;       /*r指向第i个结点*/

    pre->next=r->next; /*从链表中删除*/
    free(r);           /*释放*r */
 }

void del(LNode *head,ElemType x)
{
    LNode *pre,*p;
	p=head;
    while(p->next!=NULL&&p->data!=x)
    {pre=p;p=p->next;} /*查找值为X的数据元素结点*/
	if(p->data==x){pre->next=p->next;free(p);} /*找到删除*/
	else printf("Delete error!\n");
}

void ConverseLink(LNode *head)
{
    LNode *p,*q;
    p=head->next;
    head->next=NULL;
    while(p!=NULL)
    {
        q=p; p=p->next;
q->next=head->next;
        head->next=q;

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

int main()
{
    LNode *head=NULL;
    head=create(5);
    printl(head);
    printf("\nHello world!\n");
    ConverseLink(head);
    printl(head);
free(head);

    //FreeAll(head);
    return 0;
}
