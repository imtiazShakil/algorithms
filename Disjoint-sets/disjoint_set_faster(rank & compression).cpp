#include <stdio.h>
#define max_vertice 100

int parent[max_vertice];
int rank[max_vertice];

int find_set(int vertice)
{
    if(vertice!=parent[vertice])
        parent[vertice]=find_set(parent[vertice]);

    return parent[vertice];
}

void link(int u,int v)
{
    if(rank[u]>rank[v]) parent[v]=u;
    else parent[u]=v;

    if(rank[u]==rank[v])
        rank[v]++;

    return ;
}
void make_set(int vertice)
{
    rank[vertice]=0;
    parent[vertice]=vertice;

    return ;
}

void u_nion(int u,int v)
{
    link(find_set(u),find_set(v));
}

int main(void)
{

}
