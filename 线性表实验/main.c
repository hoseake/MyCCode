#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
#define NULL 0
typedef int ElemType;

typedef struct
{
    ElemType data[MAXSIZE];
    int length;
} SeqList;

SeqList  *init_SeqList()
{
    SeqList *L=(SeqList *)malloc(sizeof(SeqList));
    L->length=0;
    return L;
}
//void OtherList();
SeqList *MergeList();
int main()
{
    int n;
    SeqList *L;
    SeqList *Lb;
    SeqList *Lc;
//    Lp=init_SeqList( );
    SeqList Ls;
    Ls.length=0;
    L=&Ls;
    ElemType x;
    int Location;
    int s;
    printf("\n\n\t|********顺序表基本操作***************|\n");
    printf("\t|*********1.按位置查找****************|\n");
    printf("\t|*********2.按值查找******************|\n");
    printf("\t|*********3.插入**********************|\n");
    printf("\t|*********4.删除**********************|\n");
    printf("\t|*********5.输出**********************|\n");
    printf("\t|*********6.输入新线性表并合并********|\n");
    printf("\t|*********0.退出**********************|\n");
    printf("******要满足其他功能，先要执行3号功能输入数据******\n");
    while(1)
    {
        printf("请输入想要操作功能的序号：");
        scanf("%d",&s);
        switch(s)
        {
        case 1:
            printf("请输入要查找数据的下标：");
            scanf("%d",&Location);
            if(LocateByEdress(L,Location))
            {
                ElemType d=LocateByEdress(L,Location);
                printf("查找到的数据为：%d\n",d);
            }
            else
                printf("位置下标有误！\n");
            break;
        case 2:
            printf("请输入要查找的值：");
            scanf("%d",&x);
            ElemType i=LocateByData(L,x);
            if(LocateByData(L,x)==-1)
                printf("查无此数据！");
            else
                printf("要查找的值下标为：%d\n",i);
            break;
        case 3:
            printf("请输入要插入的值(尾插法)：");
            scanf("%d",&x);
            if(InsertList(L,L->length,x))
                printf("插入成功！\n");
            break;
        case 4:
            printf("请输入要删除数据的下标：");
            scanf("%d",&Location);
            if(DeleteList(L,Location))
                printf("删除成功！\n");

            break;
        case 5:
            PutList(L);
            break;
        case 6:
            Lb=init_SeqList();
            Lc=init_SeqList();
            if(Lb)
                printf("新线性表已创建！\n");
            printf("请输入需合并的有序表长度：");
            scanf("%d",&n);
            printf("数据元素值:");
            for(i=0; i<n; i++)
            {
                scanf("%d",&x);
                InsertList(Lb,Lb->length,x);
            }
            Lc=MergeList(L,Lb);
            printf("合并成功 !\n");
            PutList(Lc);
            //printf("请输入新线性表元素：");
            //scanf("%d",&x);
            //InsertList(Lb,Lb->length,x);
            //PutList(OtherList(x));
            break;
        case 0:
            if(L!=NULL)
                free(L);
            if(Lb!=NULL)
                free(Lb);
            if(Lc!=NULL)
                free(Lc);
            system("cls");
            exit(0);
            break;
        }
    }

}
int LocateByData(SeqList  *L, ElemType x)
{
    int i;
    for(i=0; i<L->length; i++)
        if(L->data[i]==x)
            return i;
    return -1;
}
ElemType LocateByEdress(SeqList  *L,int Edress)
{
    if(Edress<0||Edress>=L->length)
    {
        return 0;
    }
    return L->data[Edress];
}
int InsertList(SeqList  *L,int i, ElemType x)
{
    int k;
    if (L->length==MAXSIZE)
    {
        printf("线性表超出最大范围！\n");
        return 0;
    }
    if (i<0 || i>L->length)
    {
        printf("插入位置有误！\n");
        return 0;
    }
    for(k=L->length-1; k>=i; k--)
        L->data[k+1]=L->data[k];
    L->data[i]=x;
    L->length++;
    return 1;
}
int DeleteList(SeqList  *L,int i)
{
    int  k;
    if(i<0 || i>=L->length)
    {
        printf ("删除位置有误！\n");
        return 0;
    }
    if(L->length==0)
    {
        printf("线性表为空！\n");
        return 0;
    }

    for(k=i+1; k<=L->length-1; k++)
        L->data[k-1]=L->data[k];
    L->length--;
    return 1;
}
void PutList(SeqList *L)
{
    printf("线性表内容为：");
    for(int i = 0; i < L->length; i++)
    {
        printf("%d ",L->data[i]);
    }
    printf("\n");
}
//void OtherList(ElemType x)
//{
//    SeqList *Lb;
//    Lb=init_SeqList();
//    if(Lb)printf("新线性表已创建！\n");
//    InsertList(Lb,Lb->length,x);
//}
SeqList *MergeList(SeqList *La, SeqList *Lb)
{
    int i=0,j=0,k=0;
    SeqList *Lc;
    Lc=init_SeqList();
    while(i<La->length&&j<Lb->length)
    {
        if (La->data[i]<=Lb->data[j])
        {
            InsertList(Lc,k, La->data[i]);
            i++,k++;
        }
        else
        {
            InsertList(Lc,k, Lb->data[j]);
            j++,k++;
        }
    }
    while(i<La->length)
    {
        InsertList(Lc,k,La->data[i]);
        i++,k++;
    }
    while(j<Lb->length)
    {
        InsertList(Lc,k,Lb->data[j]);
        j++,k++;
    }

    return Lc;
}
