#include <stdio.h>

int len=0;
int vertices[1000];
//int head[1000];
int rep[1000];
int tail[1000];
int size[1000];
int next[1000];

void make_set(int v)
{
    vertices[len]=v;
    //head[v]=len;
    tail[v]=v;
    next[v]=0;
    rep[v]=v;
    size[rep[v]]=1;
    len++;
    return ;
}

int  find_set(int v)
{
    return rep[v];
}

void u_nion(int u,int v)
{
    int node=tail[u];
    next[node]=rep[v];

    size[rep[u]]=size[rep[u]] + size[rep[v]];
    int ptr=rep[u];
    while(ptr)
    {
        tail[ptr]=tail[v];
        ptr=next[ptr];
    }

    ptr=rep[v];
    while(ptr)
    {
        rep[ptr]=rep[u];
        ptr=next[ptr];
    }
    return ;
}
int main(void)
{
    int v;

    puts("enter 1 for make set");
    puts("enter 2 to find");
    puts("enter 3 to union");

    while(scanf("%d",&v)==1 && v)
    {
        int num,u,vt;


        if(v==1)
        {
            puts("enter input");
            scanf("%d",&num);
            make_set(num);
        }
        if(v==2)
        {
            scanf("%d",&num);
            printf("representor of %d is %d\n",num,find_set(num));
        }
        if(v==3)
        {
            puts("give 2 inputs");
            scanf("%d %d",&u,&vt);
            u_nion(u,vt);
            int ptr=rep[u];
            while(ptr)
            {
                printf("set element %d\n",ptr);
                ptr=next[ptr];
            }
        }
        puts("give ur choice");
    }
}
