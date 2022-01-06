#include <stdio.h>
#include <string.h>

int num[30],sol[30];
bool color[500];
int stop;

void BT(int depth)
{
    int i;
    if(depth==6)
    {
        printf("%d",sol[0]);
        for(i=1;i<6;i++) {printf(" %d",sol[i]);}
        putchar('\n');
        //memset(color,true,sizeof color);
        return ;
    }
    for(i=0;i<stop;i++)
    {
        if(color[num[i]])
        {
            if(depth) if(num[i]<sol[depth-1]) continue;
            sol[depth]=num[i]; color[num[i]]=false;
            BT(depth+1);
            color[num[i]]=true;
        }
    }
}

int main(void)
{
    //freopen("out.txt","w+",stdout);

    bool flag=0;
    int k,i;
    while(scanf("%d",&k)==1 && k)
    {
        memset(color,true,sizeof color);
        if(flag) putchar('\n');
        for(i=0;i<k;i++) scanf("%d",&num[i]);
        stop=k;
        BT(0);
        flag=1;
    }
}
