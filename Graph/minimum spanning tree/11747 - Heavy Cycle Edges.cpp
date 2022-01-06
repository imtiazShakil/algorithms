#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stdlib.h>

#define MAX 1100
using  namespace std;

int parent[MAX],n,m;
int rank[MAX];

struct edge
{
    int u;
    int v;
    int cost;
};
vector<edge>pt;
vector<int>weight;

bool com_cost(struct edge a,struct edge b)
{
//    printf("sorting %d<->%d & %d<->%d   ",a.u,a.v,b.u,b.v);
    if((b.cost-a.cost)>0) return 1;
    else return 0;

}

void make_set(int x)
{
    parent[x]=x;
    rank[x]=0;
    return ;
}
int find_set(int x)
{
    if(x!=parent[x]) parent[x]=find_set(parent[x]);

    return parent[x];
}
void link(int x,int y)
{
    if(rank[x]>rank[y]) parent[y]=x;
    else parent[x]=y;

    if(rank[x]==rank[y]) rank[y]++;

    return ;
}
void u_nion(int x,int y)
{
    link(find_set(x),find_set(y));
}

void mst(void)
{

    int i;
    sort(pt.begin(),pt.end(),com_cost);
//    for(int i=0;i<pt.size();i++) printf("path %d <-> %d  cost %d\n",pt[i].u,pt[i].v,pt[i].cost);

    for(i=0;i<n;i++) make_set(i);
    weight.clear();

    for(i=0;i<pt.size();i++)
    {
        if(find_set(pt[i].u)!=find_set(pt[i].v))
        {
            u_nion(pt[i].u,pt[i].v);
        }
        else weight.push_back(pt[i].cost);
    }

    sort(weight.begin(),weight.end());


}
int main(void)
{
    int i;
    edge tmp;
    while(scanf("%d %d",&n,&m)==2 && (n || m))
    {
        pt.clear();
        for(i=0;i<m;i++)
        {
            scanf("%d %d %d",&tmp.u,&tmp.v,&tmp.cost);
            pt.push_back(tmp);
        }

        mst();
        if(weight.empty()) {puts("forest");continue;}
        printf("%d",weight[0]);
        for(i=1;i<weight.size();i++) printf(" %d",weight[i]);
        putchar('\n');
    }
}
