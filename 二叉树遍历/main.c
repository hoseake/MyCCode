#include <stdio.h>
#include <stdlib.h>
typedef struct BiTNode
{
    char data;
    struct BiTNode* lChild;
    struct BiTNode* rChild;
}BiTNode;
BiTNode* CreateTree();
void PreOrderTraverse(BiTNode*);//先序算法
void InorderTraverse(BiTNode*);//中序算法
void PostOrderTraverse(BiTNode*);//后序算法
void NumOfLeafNode(BiTNode*, int*);
int GetHight(BiTNode*);
BiTNode* CopyTree(BiTNode*);
void DestroyTree(BiTNode*);
int main()
{
    printf("请输入用于#号法创建树的字符串:\n");
    BiTNode* T;
    T=CreateTree();
    printf("\n先序遍历：\n");
    PreOrderTraverse(T);
    printf("\n中序遍历：\n");
    InorderTraverse(T);
    printf("\n后序遍历：\n");
    PostOrderTraverse(T);
    printf("\n");

    int n=0;
    NumOfLeafNode(T,&n);
    printf("该二叉树叶子结点数目为：%d\n", n);

    int h = GetHight(T);
    printf("该二叉树的高度为：%d\n", h);

    BiTNode* T1 = CopyTree(T);
    printf("中序遍历新拷贝的二叉树：\n");
    InorderTraverse(T1);
    printf("\n");

    printf("销毁二叉树T1：\n");
    DestroyTree(T);

    return 0;
}


void PreOrderTraverse(BiTNode* T)
{
    if(T==NULL)return;
    printf("%c",T->data);
    PreOrderTraverse(T->lChild);
    PreOrderTraverse(T->rChild);
}




void InorderTraverse(BiTNode* T)
{
    if(T==NULL)return;
    InorderTraverse(T->lChild);
    printf("%c",T->data);
    InorderTraverse(T->rChild);
}





void PostOrderTraverse(BiTNode* T)
{
    if(T==NULL)return;
    PostOrderTraverse(T->lChild);
    PostOrderTraverse(T->rChild);
    printf("%c",T->data);
}



//#号法先序创建树
BiTNode* CreateTree()
{
    char ch;
    scanf("%c", &ch);
    //递归结束条件
    if(ch == '#')return NULL;//#号数量表示线性维度
    BiTNode* root = (BiTNode*)malloc(sizeof(BiTNode));
    root->data = ch;
    root->lChild = CreateTree();
    root->rChild = CreateTree();
    return root;
}
//求二叉树的叶子节点数目
void NumOfLeafNode(BiTNode* T, int* n)
{
    if(T==NULL)return;
    NumOfLeafNode(T->lChild,n);
    NumOfLeafNode(T->rChild,n);
    if(T->lChild==NULL && T->rChild==NULL)(*n)++;

}
//求二叉树的高度
int GetHight(BiTNode* T)
{
    if(T==NULL)return 0;
    int h=0;
    int left=GetHight(T->lChild);
    int right=GetHight(T->rChild);
    h=left>right?left:right;
    return h+1;
}
//拷贝二叉树
BiTNode* CopyTree(BiTNode* T)
{
    if(T == NULL)return NULL;
    BiTNode* Tnew = (BiTNode*)malloc(sizeof(BiTNode));
    Tnew->data = T->data;
    Tnew->lChild = CopyTree(T->lChild);
    Tnew->rChild = CopyTree(T->rChild);
    return Tnew;
}
//销毁二叉树
void DestroyTree(BiTNode* T)
{
    if(T == NULL)return;
    //必须以后序遍历的方式进行销毁，因为要保证每棵子树的根结点最后被释放
    DestroyTree(T->lChild);
    DestroyTree(T->rChild);
    printf("当前释放结点值为：%c\n", T->data);
    free(T);
}
