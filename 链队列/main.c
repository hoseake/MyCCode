#include <stdio.h>
#include <stdlib.h>
typedef int QElemType; //* QElemType类型根据实际情况而定，这里假设为int
typedef struct   //* 结点结构
{
   QElemType data;
   struct QNode *next;
}QNode,*QueuePtr;

typedef struct    //* 队列的链表结构
{
   QueuePtr front,rear;      //* 队头、队尾指针
}LinkQueue;

//* 初始化一个空队列Q
LinkQueue *InitQueue()
{
    LinkQueue *Q=(LinkQueue *)malloc(sizeof(LinkQueue ));
    QNode  *head;
    head=(QNode *)malloc(sizeof(QNode));
    head->next=NULL;
    Q->front=head;
  Q->rear=head;
  return  Q;
}
//* 销毁队列Q
void FreeQueue(LinkQueue *Q)
{
    QNode *q,*p;
    if(Q==NULL)return;
    p=Q->front;
    while(p!=NULL)
    {
        q=p->next;
        free(p);
        p=q;
    }
    free(Q);
    Q=NULL;
}
//* 插入元素e为Q的新的队尾元素 */typedef int Status;
int EnQueue(LinkQueue *Q,QElemType e)
{
  QueuePtr s=(QueuePtr)malloc(sizeof(QNode));
  if(!s)exit(1);         //* 存储分配失败
  s->data=e;
  s->next=NULL;
  Q->rear->next=s;   //* 把拥有元素e的新结点s赋值给原队尾结点的后继
  Q->rear=s;    //* 把当前的s设置为队尾结点，rear指向s
  return 1;
}
//* 若队列不空,删除Q的队头元素,用e返回其值,并返回OK,否则返回ERROR
int DeQueue(LinkQueue *Q,QElemType *e)
{  QueuePtr p;
  if(Q->front==Q->rear)
    return 0;
  p=Q->front->next;    //* 将欲删除的队头结点暂存给p
  *e=p->data;    //* 将欲删除的队头结点的值赋值给e
  Q->front->next=p->next;
                                      //* 将原队头结点的后继p->next赋值给头结点后继
  if(Q->rear==p)    //* 若队头就是队尾，则删除后将rear指向头结点
    Q->rear=Q->front;
  free(p);
  return 1;
}
int main()
{
    int i,n;
    QElemType e;
    LinkQueue *Q=InitQueue();
    printf("Please input the count of Queue-elements:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("\nPlease input No.%d-number:",i+1);
        scanf("%d",&e);
        EnQueue(Q,e);
    }
    printf("\r\nNow Queue is:");
    for(i=0;i<n;i++)
    {
        DeQueue(Q,&e);
        printf("%d  ",e);
    }
    FreeQueue(Q);
    return 0;
}

/*
#include <stdio.h>
#include <stdlib.h>
#define  MAXSIZE   100 //*队列的最大长度
typedef int QElemType;
//* QElemType类型根据实际情况而定，这里假设为int

//* 循环队列的顺序存储结构
typedef struct
{
  QElemType data[MAXSIZE];
  int front;      //* 头指针
  int rear;    //* 尾指针，若队列不空，指向队列尾元素的下一个位置
}SqQueue;
//* 初始化一个空队列Q
SqQueue *InitQueue()
{
    SqQueue *Q=(SqQueue *)malloc(sizeof(SqQueue ));
    Q->front=0;
  Q->rear=0;
  return  Q;
}
//* 返回Q的元素个数，也就是队列的当前长度
int QueueLength(SqQueue Q)
{
  return  (Q.rear-Q.front+MAXSIZE)%MAXSIZE;
}
//* 若队列未满，则插入元素e为Q新的队尾元素
int EnQueue(SqQueue *Q,QElemType e)
{
  if ((Q->rear+1)%MAXSIZE == Q->front)//* 队列满的判断
    return 0;
  Q->data[Q->rear]=e;    //* 将元素e赋值给队尾
   //* rear指针向后移一位置，
        //* 若到最后则转到数组头部
  Q->rear=(Q->rear+1)%MAXSIZE;

  return  1;
}
//* 若队列不空，则删除Q中队头元素，用e返回其值
int DeQueue(SqQueue *Q,QElemType *e)
{
  if (Q->front == Q->rear)  //* 队列空的判断
    return 0;
  *e=Q->data[Q->front];  //* 将队头元素赋值给e
  //* front指针向后移一位置
       //* 若到最后则转到数组头部
  Q->front=(Q->front+1)%MAXSIZE;

  return  1;
}

int main()
{
    int i,n;
    QElemType e;
    SqQueue *Q=InitQueue();
    printf("Please input the count of Queue-elements:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("\nPlease input No.%d-number:",i+1);
        scanf("%d",&e);
        EnQueue(Q,e);
    }
    printf("\r\nNow Queue is:");
    for(i=0;i<n;i++)
    {
        DeQueue(Q,&e);
        printf("%d  ",e);
    }
    free(Q);
    return 0;
}
*/
