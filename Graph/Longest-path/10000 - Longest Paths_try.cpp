#include <stdio.h>
#include <stack>
#include <algorithm>
#include <map>
#include <set>

#define MAX 150
using namespace std;

int max_node,max_dist;

bool adj[MAX][MAX];
int dist[MAX];

//bool color[MAX];

//void dfs(int vertex)
//{
//    int node,i;
//    bool flag;
//    stack<int>S;
//    dist[vertex]=0;max_dist=0;
//    S.push(vertex);
//    color[vertex]=true;
//    while(!S.empty())
//    {
//        node=S.top();if(dist[node]>max_dist) max_dist=dist[node];
//        for(i=1;i<=max_node;i++)
//        {
//            flag=false;
//            if(adj[node][i])
//            {
//                if(dist[node]>=dist[i]) dist[i]=dist[node]+1;
//                if(dist[i]>max_dist) max_dist=dist[i];
//                if(!color[i])
//                {
//                    S.push(i);flag=true;color[i]=1;break;
//                }
//            }
//        }
//        if(!flag) {   S.pop();  }
//    }
//
//    return ;
//
//}
void dfs(int v)
{
    for(int i=0;i<MAX;i++)
    {
        if(adj[v][i])
        {
            if(dist[i]<dist[v]+1 )
            {
                dist[i]=dist[v]+1;
                max_dist=max(dist[i],max_dist);
                dfs(i);///I will check only those nodes<dfs> where i get a longer path
            }
            ///mustn't use dfs here because then I'll check other nodes where I don't get longest path
        }
    }
    return ;
}
int main(void)
{
    int u,v,start,i,j,cas=0;
    while(scanf("%d",&max_node)==1 && max_node)
    {
        scanf("%d",&start);

        for(i=0;i<MAX;i++) for(j=0;j<MAX;j++) adj[i][j]=0;
        for(i=0;i<MAX;i++) {dist[i]=0;color[i]=0;}//node[i]=0;}

//        node[0]=start;

        while(scanf("%d %d",&u,&v)==2 && (u || v))
        {
            adj[u][v]=1;
        }
        max_dist=0;
        dfs(start);///if start was not given then we would do toplogical sort & dfs the vertices in descending order

        if(max_dist)
        {
            for(i=0;i<MAX;i++)
            {
                if(dist[i]==max_dist) {printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n",++cas,start,max_dist,i);break;}
            }
        }
        else printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n",++cas,start,max_dist,start);
    }

    return 0;
}
