#include <sstream>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>
#include <list>
#include <string.h>
using namespace std;
#define print1(a)    cout<<a<<endl
#define print2(a,b) cout<<a<<" "<<b<<endl
#define print3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define oo          (1<<30)
#define PI          3.141592653589793
#define pi          (2*acos(0))
#define ERR        1e-5
#define PRE        1e-8
#define SZ(s)      ((int)s.size())
#define LL          long long
#define ISS         istringstream
#define OSS         ostringstream
#define VS          vector<string>
#define VI          vector<int>
#define VD          vector<double>
#define VLL         vector<long long>
#define SII         set<int>::iterator
#define SI          set<int>
#define mem(a,b)    memset(a,b,sizeof(a))
#define fr(i,a,b)   for(i=a;i<=b;i++)
#define frn(i,a,b)  for(i=a;i>=b;i--)
#define fri(a,b)    for(i=a;i<=b;i++)
#define frin(a,b)   for(i=a;i>=b;i--)
#define frj(a,b)    for(j=a;j<=b;j++)
#define frjn(a,b)   for(j=a;j>=b;j--)
#define frk(a,b)    for(k=a;k<=b;k++)
#define frkn(a,b)   for(k=a;k>=b;k--)
#define frl(a,b)    for(l=a;l<=b;l++)
#define frln(a,b)   for(l=a;l>=b;l--)
#define EQ(a,b)     (fabs(a-b)<ERR)
#define all(a,b,c)  for(int I=0;I<b;I++)    a[I] = c
#define CROSS(a,b,c,d) ((b.x-a.x)*(d.y-c.y)-(d.x-c.x)*(b.y-a.y))
#define sqr(a)      ((a)*(a))
#define FORE(i,a)   for(typeof((a).begin())i=(a).begin();i!=(a).end();i++)
#define typing(j,b) typeof((b).begin()) j=(b).begin();
#define BE(a)       a.begin(),a.end()
#define rev(a)      reverse(BE(a));
#define sorta(a)    sort(BE(a))
#define pb          push_back
#define popb        pop_back
#define round(i,a)  i = ( a < 0 ) ? a - 0.5 : a + 0.5;
#define makeint(n,s)  istringstream(s)>>n
#define inpow(a,x,y) int i; a=x;fri(2,y)  a*=x
#define cntbit(mask) __builtin_popcount(mask)
#define mod         1000000007
#define MAXN 100100
#define LOGMAXN 21
int n,parent[MAXN][LOGMAXN],start[MAXN],finish[MAXN],T,step,m;//step=log(n) and T = time
VI adj[MAXN],adj2[MAXN];
bool cycle[MAXN],col[MAXN];
int cycleno[MAXN];
int cycleupto[MAXN];

int dfs(int u,int p)
{
    int i,v;
    col[u]=true;

    cycleno[u]=u;
    fr(i,0,SZ(adj[u])-1)
    {
        v=adj[u][i];
        if(v==p) continue;
        if(col[v])
        {
           if(cycleno[v]==v) cycleno[u]=v;
           continue;
        }

        int tem=dfs(v,u);
        if(tem!=v){ //a cycle but not a start of cycle
         cycleno[u]=tem;
         //printf("In cycle ");
         //print3(u,tem,cycleno[u]);
         if(tem==u) cycle[u]=true;
        }
    }

    return cycleno[u];
}

void dfs1(int u,int p)
{
    //print2(u,p);
    int i,v;

    col[u]=1;
    start[u]=T++;

    //print3(u,p,parent[7][0]);
    parent[u][0]=p;  //recursively defined
    for(i=1;i<=step;i++){
        parent[u][i]=parent[parent[u][i-1]][i-1];
        //print3(u,i,parent[u][i]);
        //print1(parent[7][0]);
    }

    fr(i,0,SZ(adj2[u])-1)
    {
        v=adj2[u][i];
        if(col[v]) continue;
        dfs1(v,u);
    }
    finish[u]=T++;
}

int dfs2(int u,int h)
{
    //print3(u,h,cycle[u]);
    int i,v;
    if(cycle[u])
      h++;
    cycleupto[u]=h;
    col[u]=true;
    //print1(parent[7][0]);
    fr(i,0,SZ(adj2[u])-1)
    {
        v=adj2[u][i];
        if(col[v]) continue;
        dfs2(v,h);
    }

    return 0;
}

bool IsAnchestor(int u,int v)
{
    if(start[u]<=start[v] && finish[u]>=finish[v]) return true;
    return false;
}

int lca_query(int u,int v)
{
    int w=-1,temp=u;
    if(IsAnchestor(u,v)) w=u;
    if(IsAnchestor(v,u)) w=v;

    if(w==-1)
    {
        for(int i=step;i>=0;i--){
            //print3(temp,i,parent[temp][i]);
            if(!IsAnchestor(parent[temp][i],v))
                temp=parent[temp][i];
        }
        w=parent[temp][0];
        //print3(temp,w,step);
    }
    return w;
}

long long bigmod(long long b,long long p,long long m)
{
    if(b==0) return 0;
    long long x,power;
    x=1;
    power=b%m;
    while(p)
    {
       if(p%2==1)
            x=(x*power)%m;
        power=(power*power)%m;
        p=p/2;
    }
    return x;
}


int main()
{
   //freopen("input.txt","r",stdin);
   //freopen("output1.txt","w",stdout);
   step=LOGMAXN-3;
   while(cin>>n>>m)
   {
      T=0;
      mem(cycle,false);
      int i,j;
      fr(i,1,n){
         adj[i].clear();
         adj2[i].clear();
      }
      int a,b;
      //print2(n,m);

      fr(i,1,m){
         cin>>a>>b;
         adj[a].pb(b);
         adj[b].pb(a);
        // print2(a,b);
      }

      dfs(1,0);
      mem(col,false);
      fr(i,1,n)
      fr(j,0,SZ(adj[i])-1)
      {
         int tem=adj[i][j];
         if(cycleno[tem]==cycleno[i]) continue;
         adj2[cycleno[i]].pb(cycleno[tem]);
         adj2[cycleno[tem]].pb(cycleno[i]);
      }

      dfs1(1,1);
      mem(col,false);

      dfs2(1,0);
      mem(col,false);
      //fr(i,1,n)
         //print2(i,cycleupto[i]);

      int k;
      cin>>k;
      //print1(k);
      fr(i,1,k)
      {
         cin>>a>>b;
         //print2(a,b);
         a=cycleno[a];
         b=cycleno[b];
         LL ans=cycleupto[a]+cycleupto[b];
         int q=lca_query(a,b);
         //print3(a,b,q);
         ans-=2*cycleupto[q];
         if(cycle[q])
          ans++;
         print1(bigmod(2LL,ans,mod));
      }
     // cout<<endl;
   }
   return 0;
}

/*
11 11
2 1
3 1
4 2
5 4
6 1
7 4
8 5
9 5
10 8
11 3
4 10
10
7 9
*/
