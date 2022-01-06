#include <sstream>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <complex>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>
#include <list>
#include <string.h>
#include <assert.h>
#include <time.h>

using namespace std;

#define SZ(x) ((int)x.size())
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define mem(name,val) memset(name,(val),sizeof(name));
#define EPS 10e-9
#define ll long long
#define ull long long unsigned
#define SF scanf
#define PF printf
#define psb(b) push_back((b))
#define ppb() pop_back()
#define oo 0x3f3f3f3f
#define mp make_pair
#define fs first
#define sc second
#define rep(var,s,n,it) for(var=(s);var<(n);(var)+=it)
#define rev(var,s,n,it) for(var=(n-1);var>(s-1);(var)-=it)
#define Read freopen("in.txt","r",stdin)
#define Write freopen("out.txt","w",stdout)
#define __ std::ios_base::sync_with_stdio (false)

///V*E^2 Complexity
///Base doesn't matter

const int MAXN = 350;///total nodes
const int MAXM = 120200;///total edges

int edges;
///edge info
int last[MAXN];
int prev[MAXM],head[MAXM];
int Cap[MAXM];
int Cost[MAXM];

int Flow[MAXN];
int edgeNo[MAXN];
int dist[MAXN];
int par[MAXN];
bool visited[MAXN];

void init(int N)
{
    memset(last,-1,sizeof(int)*N);
    edges=0;
}

void addEdge(int u,int v,int cap,int cost)
{
    head[edges]=v;
    prev[edges]=last[u];
    Cap[edges]=cap;
    Cost[edges]=cost;
    last[u]=edges++;

    head[edges]=u;
    prev[edges]=last[v];
    Cap[edges]=0;
    Cost[edges]=-cost;
    last[v]=edges++;
}

queue<int> Q;
pair<int,int> SPFA(int S,int E,int N)
{
    int totFlow=0,totCost=0;
    while(!Q.empty()) Q.pop();
    int u,v,cap,cost;
    while(true)
    {
        Flow[S]=oo;
        memset(dist,oo,sizeof(int)*N);
        dist[S]=0;
        memset(visited,false,sizeof(bool)*N);
        visited[S]=1;
        Q.push(S);
        while(!Q.empty())
        {
            u=Q.front();Q.pop();
            visited[u]=false;
            for(int e=last[u];e>=0;e=prev[e])
            {
                v=head[e];
                cap=Cap[e];
                cost=Cost[e];
                if(cap&&dist[v]>dist[u]+cost)
                {
                    dist[v]=dist[u]+cost;
                    Flow[v]=min(Flow[u],cap);
                    edgeNo[v]=e;
                    par[v]=u;
                    if(!visited[v])
                    {
                        visited[v]=true;
                        Q.push(v);
                    }
                }
            }
        }
        if(dist[E]==oo) break;
        totCost+=dist[E]*Flow[E];
        totFlow+=Flow[E];
        for(int i=E;i!=S;i=par[i])
        {
            Cap[edgeNo[i]]-=Flow[E];
            Cap[edgeNo[i]^1]+=Flow[E];
        }
    }
    return mp(totFlow,totCost);
}

int main()
{
    return 0;
}














