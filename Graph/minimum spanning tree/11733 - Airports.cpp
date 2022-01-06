#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>
#include <stdlib.h>
using namespace std;

#define MAX 10100

int parnt[MAX],n,m;
int rank[MAX],total_cost;
int cost_order[MAX],pos;
//vector<int>V[MAX];

struct edge
{
    int u;
    int v;
    int cost;
    bool color;
}path[100100];

void make_set(int x)
{
    parnt[x]=x;
    rank[x]=0;
    return ;
}
int find_set(int x)
{
    if(x!=parnt[x]) parnt[x]=find_set(parnt[x]);

    return parnt[x];
}
void link(int x,int y)
{
    if(rank[x]>rank[y]) parnt[y]=x;
    else parnt[x]=y;

    if(rank[x]==rank[y]) rank[y]++;
}
void u_nion(int x,int y)
{
    link(find_set(x),find_set(y));
}

int com(const void *a,const void *b)
{
    struct edge *x=(struct edge *)a;
    struct edge *y=(struct edge *)b;

    return x->cost-y->cost;
}
void mst(void)
{
    int i;
    qsort(path,m,sizeof(edge),com);
//    for(i=0;i<m;i++) printf("edges %d %d cost %d\n",path[i].u,path[i].v,path[i].cost);
    for(i=1;i<=n;i++) make_set(i);
    for(i=0;i<m;i++)
    {
        if(find_set(path[i].u)!=find_set(path[i].v))
        {
            u_nion(path[i].u,path[i].v);
            path[i].color=1;
            total_cost+=path[i].cost;
            cost_order[pos++]=path[i].cost;
        }
    }

    return ;
}
int minimum_pl(void)
{
    int i,node;
    set<int>S;
    for(i=1;i<=n;i++)
    {
        node=find_set(i);
        S.insert(node);
    }
//    printf("minimum plane %d\n",S.size());
    return S.size();
}
int main(void)
{
    int loop,cas=0,i,cost_plane,min_plane,max_plane,val,j,count,check;
    scanf("%d",&loop);
    while(loop--)
    {
        scanf("%d %d %d",&n,&m,&cost_plane);

        for(i=0;i<m;i++) {path[i].color=0;cost_order[i]=0;}
        for(i=0;i<m;i++) scanf("%d %d %d",&path[i].u,&path[i].v,&path[i].cost);

        total_cost=0;pos=0;
        mst();

//        for(i=0;i<m;i++) printf("edges %d %d cost %d CHOSEN  %d\n",path[i].u,path[i].v,path[i].cost,path[i].color);
//        for(i=0;i<pos;i++) printf("cost %d\n",cost_order[i]);
        min_plane=minimum_pl();

        total_cost=total_cost+(min_plane*cost_plane);//printf("total cost %d\n",total_cost);
//        for(max_plane=n,i=-1,val=0;max_plane>=min_plane;max_plane--,i++)
//        {
//            if(i>=0) val+=cost_order[i];
//            if( max_plane*cost_plane + val <= total_cost) {total_cost=max_plane*cost_plane + val;count=max_plane;}
//        }
        for(max_plane=n,i=-1,val=0,count=min_plane;max_plane>=min_plane;max_plane--,i++)
        {
            if(i>=0) val+=cost_order[i];
            check=max_plane*cost_plane + val;
            if(check<total_cost) {total_cost=check;count=max_plane;}
            else if(check==total_cost && max_plane>count) {count=max_plane;}
        }
        printf("Case #%d: %d %d\n",++cas,total_cost,count);
    }
}
