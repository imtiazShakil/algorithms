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
#define LL           long long
#define ISS         istringstream
#define OSS        ostringstream
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
#define lim          1005
//no problem in multiple edge
int tim[lim],low[lim];// low means the last dependent node (tim should be memset)
bool flag[lim];// should be memset, flag true means articulation point
int timer;//timer=0 initially should be made
VI adj[lim];

void dfs(int u,int par)// par=-1 dhore call dite hobe(root ar parent nai)
{
    tim[u] = low[u] = ++timer;
    int subtree = 0;
    for(int i = 0 ; i<SZ(adj[u]) ; i++)
    {
        int v = adj[u][i];
        if(v==par) continue; //parent check is needed
        if(!tim[v])
        {
            subtree++;
            dfs(v,u);
            low[u] = min(low[u],low[v]);
            if(low[v]>=tim[u] && par!=-1) flag[u] = true; //attention greater equals for bridge and articulation point
        }
        else //determining back edge
        {
            low[u] = min(low[u],tim[v]);
        }
    }

    if(par==-1 && subtree>1) flag[u] = true; //for root
    return;
}

//sometimes change needed here
void articulationPoint(int n)
{
    mem(tim,0);
    mem(flag,0);
    timer=0;
    for(int i=1;i<=n;i++)
    if(!tim[i])
        dfs(i,-1);
}


int main()
{
   return 0;
}
