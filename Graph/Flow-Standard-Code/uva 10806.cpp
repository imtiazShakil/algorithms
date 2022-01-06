#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<string>
#include<sstream>
#include<ctype.h>
#include<vector>
#include<map>
#include<queue>
#include<math.h>
#include<algorithm>
#include<set>

#define pb push_back
#define PI acos(-1.0)
#define SZ(a) (int)a.size()
#define csprnt printf("Case %d: ", cas++);
#define EPS 1e-9
#define MAX 100010
#define ll long long
#define INF (1<<30)
#define pii pair<int, int>
#define MP make_pair
int xx[] = {1,1,0,-1,-1,-1,0,1}, yy[] = {0,1,1,1,0,-1,-1,-1}; //eight direction

using namespace std;

int par[205], source, sink, flow, dist[205], edge_no;

struct node{
    int u, v, cap, revind, cost;
    node(int c=0, int a=0, int b=0, int d=0, int _cost=0)
    {
        u=c, v=a, cap=b, revind=d, cost=_cost;
    }
};
node edge[10010];

struct pq{
    int cost, node;
    pq(int x=0, int y=0) { node=x, cost=y;}
    bool operator<(const pq &b)const
    {return (cost>b.cost);}};

vector<int>adj[205];

void addedge(int u, int v, int c, int w)
{
    edge[edge_no] = node(u, v, c, edge_no+1, w);
        adj[u].pb(edge_no);
        edge[edge_no+1] = node(v, u, 0, edge_no, -w);
        adj[v].pb(edge_no+1);
        edge_no+=2;
        return;
}

bool aug_path()
{
    int i, now, nxt, nc, xc, ed, cap;
    priority_queue<pq>Q;
    Q.push(pq(source, 0));
    for(i=source;i<=sink;i++) dist[i]=INF;
    memset(par, -1, sizeof par);
    dist[source] = 0;
    while(!Q.empty())
    {
        now = Q.top().node, nc = Q.top().cost; Q.pop();
        for(i=0;i<SZ(adj[now]);i++)
        {
                ed = adj[now][i];
                        nxt = edge[ed].v, xc = edge[ed].cost, cap = edge[ed].cap;
            if((dist[nxt] > (xc+dist[now])) && (cap>0))
            {
                dist[nxt] = dist[now]+xc;
                par[nxt] = ed;
                Q.push(pq(nxt, dist[now]+xc));
            }
        }
    }
    if(dist[sink]!=INF) return true;
    return false;
}

void path_upd(int v)
{
    node now = edge[par[v]];
    flow = min(flow, now.cap);
    if(now.u!=source) path_upd(now.u);
        edge[par[v]].cap-=flow;
    edge[now.revind].cap+=flow;
    return;
}

int maxflow()
{
        int ret=0, cnt=0;
        while(aug_path())
        {
                flow=INF;
                path_upd(sink);
                ret+=dist[sink];
                cnt++;
        }
        if(cnt<2) return -1;
        return ret;
}

int main()
{
    int n;
    while(scanf("%d", &n)==1)
    {
        if(n==0) break;
        edge_no=0;
                int i, j, m, u, v, w;
                source=0, sink=n+1;
                for(i=source;i<=sink;i++) adj[i].clear();
                scanf("%d", &m);
                for(i=0;i<m;i++)
                {
                        scanf("%d%d%d", &u, &v, &w);
                        addedge(u, v, 1, w);
                        addedge(v, u, 1, w);
                }
                addedge(source, 1, 2, 0);
                addedge(n, sink, 2, 0);
                int ans = maxflow();
                if(ans==-1) printf("Back to jail\n");
                else printf("%d\n", ans);
    }
    return 0;
}
