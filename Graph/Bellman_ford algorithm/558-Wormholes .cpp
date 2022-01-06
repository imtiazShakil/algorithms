#include <stdio.h>


int n,m;
int info[3000][3];
struct node
{
    int dist;
    ///int predecessor;
}vertice[2000];

bool bellman_ford(int source)
{
    int i,j,weight,u,v;
    for(i=0;i<n;i++) vertice[i].dist=-1ul/2;

    vertice[source].dist=0;

    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
        {
            u=info[j][0];
            v=info[j][1];
            weight=info[j][2];
            if(vertice[u].dist + weight < vertice[v].dist)
            {
                vertice[v].dist=vertice[u].dist + weight;
            }
        }

//    for(i=0;i<n;i++) printf("vertice %d dist %d\n",i,vertice[i].dist );
    for(j=0;j<m;j++)
    {
        u=info[j][0];
        v=info[j][1];
        weight=info[j][2];
        if(vertice[u].dist + weight < vertice[v].dist)
        {
            return true;
        }
    }

    return false;
}

int main(void)
{
    int cases,i,j;
    scanf("%d",&cases);
    while(cases--)
    {
        scanf("%d %d",&n,&m);
        for(i=0;i<m;i++) scanf("%d %d %d",&info[i][0], &info[i][1], &info[i][2]);

        if(bellman_ford(0)) printf("possible\n");  ///negative cycle is possible
        else printf("not possible\n");


    }

}

