#include <stdio.h>
#include <algorithm>
#define MAX 200
using namespace std;

int set[MAX];
bool color [MAX];
int sol[MAX];

//int com(const void *a,const void *b)
//{
//    int *x=(int *)a;
//    int *y=(int *)b;
//
//    return *x-*y;
//}

void BT(int depth,int stop)
{
    int i;
    if(depth==6)
    {
        /* for(i=0;i<6;i++) */ printf("%d %d %d %d %d %d\n",sol[0],sol[1],sol[2],sol[3],sol[4],sol[5]);
        return ;
    }
    for(i=0;i<stop;i++)
    {
        if (depth>0) if(color[i] && sol[depth-1]>set[i]) continue;

        if(color[i])
        {
            sol[depth]=set[i];color[i]=false;
            BT(depth+1,stop);
            color[i]=true;

        }
    }
}
int main(void)
{
    int k,i,j;
    bool flag=0;
    while(scanf("%d",&k)==1  && k)
    {
        if(flag) putchar('\n');
        memset(color,true,sizeof color);

        for(i=0;i<k;i++) scanf("%d",&set[i]);
        //qsort(set,k,sizeof (int),com);
        flag=1;
        BT(0,k);

//        for(i=0;i<k;i++) printf("%d\n",set[i]);

    }
}
