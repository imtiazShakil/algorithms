#define MAX 1000

int par[MAX];
int rank[MAX];

struct data
{
    int u,v,cost;
    data(int a, int b,int c)
    {
        u=a;v=b;cost=c;
    }
};
bool com(data a, data b)
{
    return a.cost<b.cost;
}
vector<data>path;

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
    if(rank[x]>rank[y])
        par[y]=x;
    else par[x]=y;

    if(rank[x]==rank[y])
        rank[y]++;
    return ;
}
void u_nion(int x,int y)
{
    link( find_set(x),find_set(y) );
    return ;
}

int mst(int n)
{
    for(int i=0;i<n;i++) make_set(i);
    sort(all(path),com);
    int edge=0,len=0;
    for(int i=0;i<SZ(path);i++)
    {
        if( find_set(path[i].u)!=find_set(path[i].v) )
        {
            u_nion(path[i].u,path[i].v);
            edge++;
            len+=path[i].cost;
        }
    }
    if(edge<n-1) return -1;
    else return len;
}
