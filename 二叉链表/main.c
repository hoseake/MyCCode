#include <stdio.h>
#include <stdlib.h>
typedef int datatype;
typedef  struct  node
{
    datatype data;
    struct node *lchild,*rchild;
}JD;
JD *ctb()
{
    JD *s[7],*r;
    int i,j,k;
    for(i=0;i<7;i++)
    {
        s[i]=(JD *)malloc(sizeof(JD));
        s[i]->data='A'+i;
        s[i]->lchild=NULL;
        s[i]->rchild=NULL;
    }
    r=s[0];
    s[0]->lchild=s[1];
    s[1]->lchild=s[2];s[1]->rchild=s[3];
    s[3]->lchild=s[4];s[3]->rchild=s[5];
    s[4]->rchild=s[6];
    return r;
}
int main()
{

    printf("Hello world!\n");
    ctb();
    return 0;
}
