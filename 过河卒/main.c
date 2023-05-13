int count=0;
int main()
{
    int x,y,dx,dy,mx,my;
    x=0;
    y=0;
    scanf("%d%d%d%d",&dx,&dy,&mx,&my);
    guo(x,y,dx,dy,mx,my);
    printf("%d",count);
    return 0;
}

void guo(int x,int y,int dx,int dy,int mx,int my)
{
    if(x==dx&&y==dy)
    {
        count++;
    }
    if(x>dx||y>dy)
    {
       return;
    }
    if((x==mx&&y==my)||(x==mx-2&&y==my-1)||(x==mx-1&&y==my-2)
       ||(x==mx+1&&y==my-2)||(x==mx+2&&y==my-1)||(x==mx+2&&y==my+1)
       ||(x==mx+1&&y==my+2)||(x==mx-1&&y==my+2)||(x==mx-2&&y==my+1))
    {
        return;
    }
    guo(x,y+1,dx,dy,mx,my);
    guo(x+1,y,dx,dy,mx,my);
}
