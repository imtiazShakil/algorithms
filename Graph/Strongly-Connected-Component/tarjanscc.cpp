#include <sstream>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>
#include <list>
#include <stack>
#include <string.h>
using namespace std;
#define pb push_back
#define SZ(s)      ((int)s.size())
#define mem(a,b)    memset(a,b,sizeof(a))
#define EQ(a,b)     (fabs(a-b)<ERR)
#define FORE(i,a)   for(typeof((a).begin())i=(a).begin();i!=(a).end();i++)
#define lim          1005 //number of nodes
//No problem in multiple edges and self loop
//0 based
vector<int> adj[lim];//only adj should be cleared
int col[lim],low[lim],tim[lim],timer;
int group_id[lim];
int components;//components=number of components group_id = which node belongs to which node
stack<int>S;

void scc(int u)
{
    int i,v,tem;
    col[u]=1;
    low[u]=tim[u]=timer++;
    S.push(u);
    for(i=0;i<=SZ(adj[u])-1;i++)
    {
        v=adj[u][i];
        if(col[v]==1)
            low[u]=min(low[u],tim[v]);
        else if(col[v]==0)
        {
            scc(v);
            low[u]=min(low[u],low[v]);
        }
    }

    //SCC checking...
    if(low[u]==tim[u])
    {
        do
        {
            tem=S.top();S.pop();
            group_id[tem]=components;
            col[tem]=2; //Completed...
        }while(tem!=u);
        components++;
    }
}

int TarjanSCC(int n) //some change may be required here
{
    int i;
    timer=components=0;
    mem(col,0);
    while(!S.empty()) S.pop();
    for(i=0;i<=n-1;i++) if(col[i]==0) scc(i);
    return components;
}

vector<int> nadj[lim];//new adjcency list after SCC(DAG)
void MakeNewDAG_Graph(int n)
{
    int i,j,u,v;

    for(i=0;i<=components-1;i++) nadj[i].clear();

    for(i=0;i<=n-1;i++)
    {
        for(j=0;j<=SZ(adj[i])-1;j++)
        {
            u=group_id[i];
            v=group_id[adj[i][j]];
            if(u!=v)
                nadj[u].pb(v);
        }
    }
}

void add(int ina,int inb)
{
    adj[ina].pb(inb);
}


int main()
{
    //freopen("A.in","r",stdin);
    //freopen("A.out","w",stdout);
    int i,j,t,cas=0,u,v,ans,n,m;

    while(scanf("%d %d",&n,&m)==2)
    {
        for(i=0;i<=n-1;i++) adj[i].clear();
        for(i=1;i<=m;i++)
        {
            scanf("%d %d",&u,&v);
            adj[u].pb(v);
        }
        TarjanSCC(n);
        printf("Total Groups: %d\n",components);
        MakeNewDAG_Graph(n);
        printf("NewGraphLinkUsingSCC: this graph is directed acyclic graph:\n");
    //this link between groups no.....
        for(i=0;i<=components-1;i++)
        {
            for(j=0;j<=SZ(nadj[i])-1;j++)
            {
                u=i;
                v=nadj[i][j];
                cout<<u<<" "<<v<<endl;
            }
        }
    }
    return 0;
}
/*
Input:
8 14
0 1
1 2
1 5
1 4
2 6
2 3
3 2
3 7
4 5
5 6
7 6
7 3
6 5
4 0
Output:
Total Groups: 3
NewGraphLinkUsingSCC: this graph is directed acyclic graph:
1 0
1 0
2 1
2 0
2 0


Another Input:
6 6
0 1
1 2
2 1
3 4
4 5
5 4
Total Groups: 4
NewGraphLinkUsingSCC: this graph is directed acyclic graph:
1       0
3       2

*/
