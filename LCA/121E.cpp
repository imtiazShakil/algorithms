//#pragma warning (disable: 4786)

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
#define ERR         1e-5
#define PRE         1e-8
#define SZ(s)       ((int)s.size())
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
#define REP(i,n)    for(i=0;i<n;i++)
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
#define debug_array(a,n) for(int i=0;i<n;i++) cerr<<a[i]<<" "; cerr<<endl;
#define debug_matrix(mat,row,col) for(int i=0;i<row;i++) {for(int j=0;j<col;j++) cerr<<mat[i][j]<<" ";cerr<<endl;}

template<class T1> void debug(T1 e){cout<<e<<endl;}
template<class T1,class T2> void debug(T1 e1,T2 e2){cout<<e1<<"\t"<<e2<<endl;}
template<class T1,class T2,class T3> void debug(T1 e1,T2 e2,T3 e3){cout<<e1<<"\t"<<e2<<"\t"<<e3<<endl;}
template<class T1,class T2,class T3,class T4> void debug(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<"\t"<<e2<<"\t"<<e3<<"\t"<<e4<<endl;}
template<class T1,class T2,class T3,class T4,class T5> void debug(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5){cout<<e1<<"\t"<<e2<<"\t"<<e3<<"\t"<<e4<<"\t"<<e5<<endl;}
template<class T1,class T2,class T3,class T4,class T5,class T6> void debug(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6){cout<<e1<<"\t"<<e2<<"\t"<<e3<<"\t"<<e4<<"\t"<<e5<<"\t"<<e6<<endl;}
template<class T> void debug(vector< vector<T> > e,int row,int col){int i,j;REP(i,row) {REP(j,col) cout<<e[i][j]<<" ";cout<<endl;} cout<<endl;}
template<class T> void debug(vector< basic_string<T> > e,int row,int col){int i,j;REP(i,row) {REP(j,col) cout<<e[i][j];cout<<endl;} cout<<endl;}
template<class T> void debug(T e[110][110],int row,int col){int i,j;REP(i,row) {REP(j,col) cout<<e[i][j]<<" ";cout<<endl;}}
template<class T> string toString(T n){ostringstream oss;oss<<n;oss.flush();return oss.str();}
int toInt(string s){int r=0;istringstream sin(s);sin>>r;return r;}
bool isVowel(char ch){ch=tolower(ch);if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')return true;return false;}
bool isUpper(char c){return c>='A' && c<='Z';}
bool isLower(char c){return c>='a' && c<='z';}
//*************************************************My Code Starts Here*********************************************************************************
#define lim 100010
#define step 18
struct edge{
   int node;
   int in;
};
vector<edge>adj[lim];
int n;
//for LCA
int col[lim],parent[lim][step+2],start[lim],finish[lim],T;// T = time

void dfs(int u,int p)
{
    int i,v;

    col[u]=1;
    start[u]=T++;

    parent[u][0]=p;  //recursively defined
    for(i=1;i<=step;i++)
        parent[u][i]=parent[parent[u][i-1]][i-1];


    fr(i,0,SZ(adj[u])-1)
    {
        v=adj[u][i].node;
        if(col[v]) continue;
        dfs(v,u);
    }
    finish[u]=T++;
}

bool IsAnchestor(int u,int v) //Is u ancestor of v including himself
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
        for(int i=step;i>=0;i--)
            if(!IsAnchestor(parent[temp][i],v))
                temp=parent[temp][i];
        w=parent[temp][0];
    }
    return w;
}
int up[lim],stop[lim];
int ans[lim];

int dfsquery(int node,int par)
{
    //print3(node,up[node],stop[node]);
    int i;
    for(i=0;i<SZ(adj[node]);i++)
    {
        edge tem=adj[node][i];
        if(tem.node==par) continue;
        int dif=dfsquery(tem.node,node);
        up[node]+=dif;
        ans[tem.in]=dif;
    }
    return up[node]-stop[node];
}


int main()
{
    while(cin>>n)
    {
       int i,j,a,b,c;
       edge tem;
       for(i=1;i<n;i++)
       {
           cin>>a>>b;
           tem.in=i;
           tem.node=b;
           adj[a].pb(tem);
           tem.node=a;
           adj[b].pb(tem);
       }
       dfs(1,1);

       int k;
       cin>>k;
       for(i=1;i<=k;i++)
       {
           cin>>a>>b;
           c=lca_query(a,b);
           up[a]++;
           up[b]++;
           stop[c]+=2;
           //print3(a,b,c);
       }
       dfsquery(1,0);
       printf("%d",ans[1]);
       for(i=2;i<n;i++)
        printf(" %d",ans[i]);
       cout<<endl;
    }
    return 0;
}
