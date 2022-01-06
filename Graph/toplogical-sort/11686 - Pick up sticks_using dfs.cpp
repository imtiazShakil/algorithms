#include <stdio.h>
#include <stack>
#include <algorithm>
#include <vector>

#define MAX 1000100

using namespace std;

//int initial_t[MAX],final_t[MAX];
int tim,n,m;
bool invalid;

vector<int>V[MAX];

//struct path
//{
//    int u;
//    int v;
//}edges[MAX];

//bool color[MAX];
struct vrtc
{
    int indx;
//    int initial_t;
    int final_t;
    bool color;
}nodes[MAX];


int com(const void *a,const void *b)
{
    struct vrtc *x=(struct vrtc *)a;
    struct vrtc *y=(struct vrtc *)b;

    return y->final_t-x->final_t;

}
void dfs(int u)
{
    if(nodes[u].color) return ;
    int i,vertice;
    bool flag;
//    struct vrtc vertice;
//    int vertice;
    nodes[u].color=true;
    /*nodes[u].initial_t=*/++tim;
    stack<int>S;
    S.push(u);//printf("pushed %d\n",u);
    while(!S.empty())
    {
        vertice=S.top();
//        for(i=0,flag=0;i<m;i++)
//        {
//            if(edges[i].u==vertice) {if(nodes[edges[i].v].final_t==0 && nodes[edges[i].v].color) {/*printf("veritce %d -> %d initial %d final %d\n",vertice,edges[i].v,nodes[edges[i].v].initial_t,nodes[edges[i].v].final_t);*/invalid=true;return ;}}
//            if(edges[i].u==vertice && !nodes[edges[i].v].color)
//            {
//                //printf("node %d initial %d\n",edges[i].v,nodes[edges[i].v].initial_t);
//                S.push(edges[i].v);//printf("pushed %d\n",edges[i].v);
//                nodes[edges[i].v].initial_t=++tim;
//                nodes[edges[i].v].color=true;
//                flag=true;
//                break;
//            }
//        }
        for(i=0,flag=0;i<V[vertice].size();i++)
        {
            if(nodes[V[vertice][i]].final_t==0 && nodes[V[vertice][i]].color) {invalid=true;return ;}
            if(!nodes[V[vertice][i]].color)
            {
                S.push(V[vertice][i]);
                ++tim;
                nodes[V[vertice][i]].color=true;
                flag=true;
                break;
            }
        }
        if(!flag)
        {
            S.pop();//printf("popped %d\n",vertice);
            nodes[vertice].final_t=++tim;
        }
    }
    return  ;

}
int main(void)
{
    int i,u,v;
//    for(i=1;i<MAX;i++) nodes[i].indx=i;
    while(scanf("%d %d",&n,&m)==2 && (n || m))
    {
        for(i=1;i<=n;i++) {nodes[i].color=false;/*nodes[i].initial_t=0;*/nodes[i].final_t=0;V[i].clear();nodes[i].indx=i;}
//        for(i=0;i<m;i++) {edges[i].u=0;edges[i].v=0;}

        for(i=0;i<m;i++)
        {
            scanf("%d %d",&u,&v);
            V[u].push_back(v);
        }
        tim=0;
        for(i=1,invalid=false;i<=n;i++)
        {
            dfs(i);
            if(invalid)
            {
                break;
            }
        }
        if(invalid) {printf("IMPOSSIBLE\n");continue;}
//        sort(&nodes[1],&nodes[n],com);
        qsort(&nodes[1],n,sizeof (vrtc),com);
        for(i=1;i<=n;i++)
        {
            printf("%d\n",nodes[i].indx);
        }

    }
//    printf("\a\a\a");
    return 0;
}
