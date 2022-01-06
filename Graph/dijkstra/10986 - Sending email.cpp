#include <stdio.h>
#include <stdlib.h>

#include <vector>
#include <queue>
#include <algorithm>

#define oo -1u/2
#define SIZE 20005
using namespace std;

bool color[SIZE];
int n,dist[SIZE];

struct vertice
{
    int node;
    int dist;

    bool operator<(const vertice & x)const
    {
        return dist>x.dist;
    }
} ;

struct edge
{
    int v;
    int weight;
} ;

vector<edge>pt[SIZE];

bool relax(int u,int v,int w)
{
    if(dist[v]>dist[u] + w)  {dist[v]=dist[u] + w;return true;}
    return false;
}
void dijkstra(int source)
{
    priority_queue<vertice>Q;

    int i,u;

    for(i=0;i<n;i++) color[i]=0;
    for(i=0;i<n;i++) dist[i]=oo;

    dist[source]=0;
    struct vertice tmp;

    tmp.node=source;
    tmp.dist=0;
    Q.push(tmp);




    while(!Q.empty())
    {
        tmp=Q.top();Q.pop();
        if(color[tmp.node]) continue;
        else
        {
            color[tmp.node]=true;
            u=tmp.node;
            for(i=0;i<pt[u].size();i++)
            {
                  if(relax(u,pt[u][i].v,pt[u][i].weight))
                  {
                        tmp.node=pt[u][i].v;
                        tmp.dist=dist[pt[u][i].v];
                        Q.push(tmp);
                  }

            }
        }
    }

}
int main(void)
{
    int loop,m,s,t,i,j,u,v,w,cas=0;
    struct edge tmp;
    scanf("%d",&loop);
    while(loop--)
    {

        scanf("%d %d %d %d",&n,&m,&s,&t);
        for(i=0;i<n;i++) pt[i].clear();
        for(i=0;i<m;i++)
        {
            scanf("%d %d %d",&u,&v,&w);
            tmp.v=v;
            tmp.weight=w;
            pt[u].push_back(tmp);

            tmp.v=u;
            pt[v].push_back(tmp);

        }
        dijkstra(s);
        if(dist[t]==oo) printf("Case #%d: unreachable\n",++cas);
        else printf("Case #%d: %d\n",++cas,dist[t]);
    }
}
