#include <stdio.h>
#include <queue>
#include <vector>

#define MAX 300
using namespace std;
bool color[MAX],chromtic_val[MAX],check,bi_color;
int n;
vector<int>V[MAX];

void bfs(int vertex)
{
    int node,i;
    if(check)
    {
        if(color[vertex]) return ;
        queue<int>Q;
        Q.push(vertex);
        while(!Q.empty())
        {
            node=Q.front();Q.pop();
            color[node]=true;
            for(i=0;i<V[node].size();i++)
            {
                if( chromtic_val[node]==chromtic_val[V[node][i]] ) { bi_color=0;return ; }
                if(!color[V[node][i]])  Q.push(V[node][i]);
            }
        }
        return ;
    }
    else
    {
        if(color[vertex]) return ;
    //    color[vertex]=true;
        queue<int>Q;
        Q.push(vertex);
        while(!Q.empty())
        {
            node=Q.front();Q.pop();
            color[node]=true;
            for(i=0;i<V[node].size();i++)
            {
                if(!color[V[node][i]])
                {
                    chromtic_val[V[node][i]] = !chromtic_val[node];
                    Q.push(V[node][i]);
                }
            }
        }
        return ;
    }
}
int main(void)
{
    int m,i,u,v;
    while(scanf("%d",&n)==1 && n)
    {
        for(i=0;i<n;i++) {V[i].clear();color[i]=0;chromtic_val[i]=0;}
        scanf("%d",&m);
        for(i=0;i<m;i++)
        {
            scanf("%d %d",&u,&v);
            V[u].push_back(v);
            V[v].push_back(u);
        }
        for(i=0,check=0;i<n;i++) bfs(i);
//        for(i=0;i<n;i++) printf("chromatic val of node %d -> %c\n",i,chromtic_val[i]+'A');
        check=true;
        for(i=0;i<n;i++) color[i]=0;
        for(i=0,bi_color=1;i<n;i++)
        {
            bfs(i);
            if(!bi_color) break;
        }
        if(bi_color) printf("BICOLORABLE.\n");
        else printf("NOT BICOLORABLE.\n");
    }
}
