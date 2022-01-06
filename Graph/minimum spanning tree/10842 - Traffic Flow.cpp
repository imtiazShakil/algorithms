#include <stdio.h>
#include <stdlib.h>

#include <algorithm>
#include <vector>
#define SIZE 500
using namespace std;

int n,m;
int rank[SIZE];
int par[SIZE];

struct edge
{
    int u;
    int v;
    int cost;
};

vector<edge>pt;
vector<int>v;

bool com_p(edge  a, edge b)
{
    if(a.cost>b.cost) return true;

    return false;
}
void make_set(int x)
{
    par[x]=x;
    rank[x]=0;
    return ;
}
int find_set(int x)
{
    if(x!=par[x]) par[x]=find_set(par[x]);
    return par[x];
}
void link(int x,int y)
{
    if(rank[x]>rank[y]) par[y]=x;
    else par[x]=y;

    if(rank[x]==rank[y]) rank[y]++;
    return ;
}
void u_nion(int x,int y)
{
    link(find_set(x),find_set(y));
    return ;
}

void max_s_tree(void)
{
    int i;
    v.clear();
    for(i=0;i<n;i++) make_set(i);
    sort(pt.begin(),pt.end(),com_p);
//    for(i=0;i<pt.size();i++) printf("%d %d cost %d\n",pt[i].u,pt[i].v,pt[i].cost);
    for(i=0;i<pt.size();i++)
    {
        if(find_set(pt[i].u)!=find_set(pt[i].v))
        {
            u_nion(pt[i].u,pt[i].v);
            v.push_back(pt[i].cost);
        }
    }
}
int main(void)
{
    int loop,i,cas=0;
    scanf("%d",&loop);
    edge tmp;
    while(loop--)
    {
        scanf("%d %d",&n,&m);
        pt.clear();
        for(i=0;i<m;i++)
        {
            scanf("%d %d %d",&tmp.u,&tmp.v,&tmp.cost);
            pt.push_back(tmp);
        }
        max_s_tree();
        if(v.empty()) printf("Case #%d: %d\n",++cas,pt[0].cost);
        else printf("Case #%d: %d\n",++cas,v[(int)v.size() - 1]);
    }
}
