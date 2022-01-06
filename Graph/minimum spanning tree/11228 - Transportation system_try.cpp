
#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
#define MAX 1500
#define PRECS 0.01
using namespace std;

int par[MAX];
int rank[MAX];
int n,m,r;
double road_dst,rail_dst;
int new_par[MAX];
int new_rank[MAX];

struct edge
{
    int u;
    int v;
    double dst;
};

struct point
{
    int x;
    int y;
    int indx;
}pt[MAX] ;

vector<struct edge>pth;
double dist(struct point a,struct point b)
{
    double ans= sqrt(pow(a.x-b.x,2) + pow(a.y-b.y,2));
    return ans;
}
int com_pt(const void *a,const void *b)
{
    struct point *x=(struct point *)a;
    struct point *y=(struct point *)b;

    struct point zero;
    zero.x=0;zero.y=0;
    double len1=dist(zero,*x);
    double len2=dist(zero,*y);

    if((len1-len2)>=PRECS) return 1;

    return 0;
}
bool com_dist(edge a,edge b)
{
    if((b.dst-a.dst)>PRECS) return 1;
    return 0;
}

void make_set(int x,bool road_or_state)
{
    if(road_or_state)
    {
        par[x]=x;
        rank[x]=0;
        return ;
    }
    else
    {
        new_par[x]=x;
        new_rank[x]=0;

        return ;
    }
}
int find_set(int x,bool road_or_state)
{
    if(road_or_state)
    {
        if(x!=par[x]) par[x]=find_set(par[x],1);

        return par[x];
    }
    else
    {
        if(x!=new_par[x]) new_par[x]=find_set(new_par[x],0);

        return new_par[x];
    }
}
void link(int x,int y,bool road_or_state)
{
    if(road_or_state)
    {
        if(rank[x]>rank[y]) par[y]=x;
        else par[x]=y;

        if(rank[x]==rank[y]) rank[y]++;
        return ;
    }
    else
    {
        if(new_rank[x]>new_rank[y]) new_par[y]=x;
        else new_par[x]=y;

        if(new_rank[x]==new_rank[y]) new_rank[y]++;
        return ;
    }
}
void u_nion(int x,int y,bool road_or_state)
{
    if(road_or_state)
    {
        link(find_set(x,1),find_set(y,1),1);
        return ;
    }
    else
    {
        link(find_set(x,0),find_set(y,0),0);
        return ;
    }
}
void mst(void)
{
    int i;
    road_dst=0;rail_dst=0;

    sort(pth.begin(),pth.end(),com_dist);

//    for(i=0;i<pth.size();i++) printf("bet %d %d cost %lf\n",pth[i].u,pth[i].v,pth[i].dst);

    for(i=0;i<n;i++) {make_set(i,1);make_set(i,0);}
    for(i=0;i<pth.size();i++)
    {
        if(find_set(pth[i].u,1)!=find_set(pth[i].v,1))
        {
            u_nion(pth[i].u,pth[i].v,1);
            if((pth[i].dst-r)>=PRECS)
            {
                rail_dst+=pth[i].dst;
//                printf("no %d rail %lf\n",i,rail_dst);
            }
            else
            {
                u_nion(pth[i].u,pth[i].v,0);
                road_dst+=pth[i].dst;
//                printf("no %d road %lf\n",i,road_dst);
            }
        }
    }
}
int main(void)
{
//    freopen("in_11228.txt","r",stdin);
    int loop,i,cas=0,state,j;
    scanf("%d",&loop);

    while(loop--)
    {
        scanf("%d %d",&n,&r);
        for(i=0;i<n;i++)
        {
            pt[i].indx=i;
            scanf("%d %d",&pt[i].x,&pt[i].y);
        }
        qsort(pt,n,sizeof(struct point),com_pt);

//        for(i=0;i<n;i++) printf("indx %d x->%d y->%d\n",pt[i].indx,pt[i].x,pt[i].y);
        pth.clear();
        struct edge tmp;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(i!=j)
                {
                    tmp.u=pt[i].indx;
                    tmp.v=pt[j].indx;
                    tmp.dst=dist(pt[i],pt[j]);
                    pth.push_back(tmp);
                }
            }
        }
        mst();
//        printf("road %lf rail %lf\n",road_dst,rail_dst);
        bool color[MAX];
        for(i=0;i<n;i++) color[i]=0;
        for(i=0,state=0;i<n;i++)
        {
            if(!color[find_set(i,0)])
            {
                state++;
                color[find_set(i,0)]=1;
            }
        }
        printf("Case #%d: %d %d %d\n",++cas,state,(int)floor(road_dst+0.5),(int)floor(rail_dst+0.5));
    }
}
