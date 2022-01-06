#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <iostream>
#include <queue>

using namespace std;

#define inf 10000000
int adj[110][110],nodes;
bool color[110];

struct data_q
{
    int address;
    int dist;

    bool operator<(const data_q & x)const
	{
		return dist>x.dist;                    ///for minimum_priority queue
	}

};

struct
{
    int dist;
    ///int parent;
}vertices[110];


void relax(int u,int v,int weight)
{
    if(vertices[u].dist + weight < vertices[v].dist)
    {
        vertices[v].dist=vertices[u].dist + weight;
        ///vertices[v].parent = u;
    }
}

void dijkstra(int source)
{
    int i,u,v,last_node;

    struct data_q temp;

    priority_queue<data_q>Q;

    for(i=1;i<=nodes;i++) {vertices[i].dist=inf; /*vertice[i].parent=NILL */}   ///initialization starts here
    vertices[source].dist=0;
    for(i=1;i<=nodes;i++) color[i]=0;           ///end initialization

    //for(i=1;i<=nodes;i++)                            ///inserted everything in queue
    //{
        temp.address=source;
        temp.dist=vertices[source].dist;
        Q.push(temp);
    //}                                                ///ends here

    while(!Q.empty())
    {
        temp=Q.top();
        Q.pop();
        u=temp.address;
        if(color[u]==false)
        {
            color[u]=true;
            last_node=u;
//            printf("u-> %d color %d \n",u,color[u]);
            /// if(vertices[u].dist==inf) then all remaining vertices are inaccessible from source  so we should break here

            for(v=1;v<=nodes;v++)
            {
                if(adj[u][v]>=0 )
                {
                    relax(u,v,adj[u][v]);  ///if(adj[u][v]==-1 there is no path)
//                    if(color[v]==false)
                    //{
                        temp.address=v;
                        temp.dist=vertices[v].dist;
                        Q.push(temp);
                    //}
                }
            }
        }
    }
//    printf("last node %d is %d\n",last_node,vertices[last_node].dist);
    printf("%d\n",vertices[last_node].dist);

}
int main(void)
{
    int i,j,val;
    char str[100];
    while(scanf("%d",&nodes)==1)
    {
        for(i=1;i<=nodes;i++) adj[i][i]=0;
        for(i=2;i<=nodes;i++)
            for(j=1;j<i;j++)
            {
                scanf("%s",str);
                if(!strcmp(str,"x"))
                {
                    adj[i][j]=-1;adj[j][i]=-1;continue;
                }
                val=atoi(str);
                adj[i][j]=val;adj[j][i]=val;
            }

//        for(i=1;i<=nodes;i++,putchar('\n')) for(j=1;j<=nodes;j++) printf("%d ",adj[i][j]);
        dijkstra(1);

//        for(i=1;i<=nodes;i++) printf("vertices %d  dist-> %d\n",i,vertices[i].dist);
    }

}
