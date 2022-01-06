#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>
#define MAX 550
#define PRECS 0.00001
using namespace std;


int par[MAX],sat,n;
int rank[MAX];

struct point
{
    int indx;
    int x;
    int y;
}pt[MAX];

struct edge
{
    int u;
    int v;
    double dst;
};
vector<struct edge>path;
vector<struct edge>new_path;

bool com_dist2(edge a,edge b)
{
    if((a.dst-b.dst)>PRECS) return 1;
    return 0;
}

bool com_dist(edge a,edge b)
{
    if((b.dst-a.dst)>PRECS) return 1;
    return 0;
}
double dist(struct point a,struct point b)
{
    double ans= sqrt(pow(a.x-b.x,2) + pow(a.y-b.y,2));
    return ans;
}
void make_set(int x)
{
    rank[x]=0;
    par[x]=x;

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
}
void u_nion(int x,int y)
{
    link(find_set(x),find_set(y));
    return ;
}

void new_mst(void)
{
    int i,count=0;
    new_path.clear();
    for(i=0;i<n;i++) make_set(i);
    for(i=0;i<path.size() && count<n-sat;i++)
    {
        if( find_set(path[i].u)!= find_set(path[i].v))
        {
            u_nion(path[i].u,path[i].v);
            new_path.push_back(path[i]);
            count++;
        }
    }
}
int main(void)
{
    int loop,i,j;
    scanf("%d",&loop);
    while(loop--)
    {
        scanf("%d %d",&sat,&n);
        for(i=0;i<n;i++)
        {
            pt[i].indx=i;
            scanf("%d %d",&pt[i].x,&pt[i].y);
        }


        struct edge tmp;
        path.clear();
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
            {
                if(i!=j)
                {
                    tmp.u=pt[i].indx;
                    tmp.v=pt[j].indx;
                    tmp.dst=dist(pt[i],pt[j]);

                    path.push_back(tmp);
                }
            }

//        for(i=0;i<path.size();i++) printf("%d %d %lf\n",path[i].u,path[i].v,path[i].dst);
        sort(path.begin(),path.end(),com_dist);
//        for(i=0;i<path.size();i++) printf("%d %d %lf\n",path[i].u,path[i].v,path[i].dst);
        new_mst();
//        for(i=0;i<new_path.size();i++) printf("%d %d %lf\n",new_path[i].u,new_path[i].v,new_path[i].dst);

        sort(new_path.begin(),new_path.end(),com_dist2);
//        for(i=0;i<new_path.size();i++) printf("%d %d %lf\n",new_path[i].u,new_path[i].v,new_path[i].dst);
        if(new_path.empty()) printf("0.00\n");
        else printf("%.2lf\n",new_path[0].dst);
//        printf("%.2lf\n",new_path[0].dst);
    }
}
