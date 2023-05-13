#include<stdio.h>
#include<stdlib.h>
struct node
{
    int value;
     struct node*d;
};
int main()
{
    struct node a,b;
    a.value=123;
    b.value=321;
    a.d=&b;
    a.d->value=177;
    printf("a.value=%d\n",a.value);
    printf("b.value=%d\n",b.value);
    return 0;
}
