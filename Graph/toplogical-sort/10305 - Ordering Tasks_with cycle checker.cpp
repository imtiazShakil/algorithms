#include <stdio.h>
#include <stack>
#include <algorithm>

#define MAX 200
#define index ind  ///uva doesn't support the name index <I got WA b.c.o.t.>
using namespace std;

int tim,n,m;

bool vertics[MAX];
int start_t[MAX];
int fin_t[MAX];
bool adj[MAX][MAX];
int index[MAX];

int com(const void *a ,const void *b)
{
    int *x=(int *)a;
    int *y=(int *)b;

    return *y-*x;
}
void dfs(int source)
{
//    if(vertics[source]) return ;
    stack<int>S;
    vertics[source]=true;
    tim++;///time has started <a new item found>
    S.push(source);
    start_t[source]=tim;
    int node,i;
    bool flag;
    while(!S.empty())
    {
        node=S.top();//printf("top %d\n",node);
        flag=false;
        for(i=1;i<=n;i++)
        {
            if(adj[node][i] && vertics[i] && fin_t[i]==0 )
            {
                printf("Whoa \aWe Got A \aCycle_*-^__*-^__*-^_toplogical sort out of the question :) :D\n\n");
                return ;
            }
            if(adj[node][i] && !vertics[i])
            {
                S.push(i);
                start_t[i]=++tim;//printf("start %d is %d\n",i,start_t[i]);
                vertics[i]=true;
                flag=true;
                break;
            }
        }
        if(!flag)
        {
            S.pop();
            fin_t[node]=++tim;
            index[tim]=node;
        }

    }

    return ;
}
int main(void)
{
    int i,val1,val2,j;
    while(scanf("%d %d",&n,&m)==2 && (n || m) )
    {
        for(i=1;i<=n;i++) for(j=1;j<=n;j++) adj[i][j]=0;
        for(i=1;i<=n;i++) {fin_t[i]=0;vertics[i]=0;index[i]=0;}
        tim=0;
        for(i=0;i<m;i++)
        {
            scanf("%d %d",&val1,&val2);
            adj[val1][val2]=true;
        }
        for(i=1;i<=n;i++)
        {
            if(!vertics[i]) dfs(i);
        }

//        for(i=1;i<=n;i++) printf("starting %d in %d  finishing  in %d\n",i,start_t[i],fin_t[i]);

        qsort( &fin_t[1],n,sizeof(int),com);

//        for(i=1;i<=n;i++) printf("finishing of %d is %d\n",index[fin_t[i]],fin_t[i]);

        printf("%d",index[fin_t[1]]);
        for(i=2;i<=n;i++) printf(" %d",index[fin_t[i]]);
        putchar('\n');
    }
}
