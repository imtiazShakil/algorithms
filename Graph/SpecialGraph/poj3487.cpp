#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <cctype>
#include <set>
#include <bitset>
#include <algorithm>
#include <list>
#include <vector>
#include <sstream>
#include <iostream>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> paii;
typedef pair< ll, ll > pall;


#define PI (2.0*acos(0))
#define ERR 1e-5
#define mem(a,b) memset(a,b,sizeof a)
#define pb push_back
#define popb pop_back
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define SZ(x) (int)x.size()
#define oo (1<<25)
#define FOREACH(it,x) for(__typeof((x).begin()) it=(x.begin()); it!=(x).end(); ++it)
#define Contains(X,item)        ((X).find(item) != (X).end())
#define popc(i) (__builtin_popcountll(i))
#define fs      first
#define sc      second
#define EQ(a,b)     (fabs(a-b)<ERR)
#define MAX 50500

template<class T1> void deb(T1 e){cout<<e<<endl;}
template<class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<" "<<e2<<endl;}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3){cout<<e1<<" "<<e2<<" "<<e3<<endl;}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<endl;}
template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<endl;}


template<class T> T Abs(T x) {return x > 0 ? x : -x;}
template<class T> inline T sqr(T x){return x*x;}
ll Pow(ll B,ll P){      ll R=1; while(P>0)      {if(P%2==1)     R=(R*B);P/=2;B=(B*B);}return R;}
int BigMod(ll B,ll P,ll M){     ll R=1; while(P>0)      {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return (int)R;} /// (B^P)%M

///int rrr[]={1,0,-1,0};int ccc[]={0,1,0,-1}; //4 Direction
///int rrr[]={1,1,0,-1,-1,-1,0,1};int ccc[]={0,1,1,1,0,-1,-1,-1};//8 direction
///int rrr[]={2,1,-1,-2,-2,-1,1,2};int ccc[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
///int rrr[]={2,1,-1,-2,-1,1};int ccc[]={0,1,1,0,-1,-1}; //Hexagonal Direction
///int month[]={31,28,31,30,31,30,31,31,30,31,30,31}; //month

struct edge{
   ll to,w,next;
};
edge arr[3*MAX];
int start[MAX];//from the reverse side
                // start[u] holds the index of the next edge index
int edgenumber;
void initialize()
{
    edgenumber=1;
    mem(start,0);
}
void addedge(int u,int v,int c)
{
    arr[edgenumber].to=v;
    arr[edgenumber].w=c;
    arr[edgenumber].next=start[u];
    start[u]=edgenumber++;
}

ll req[MAX];
ll totalFreq[MAX] , totalCost[MAX];

void calcDfs( int node , int par) /// calculates the cost for every subtree node
{

    ll to,c;
    totalCost[node]=0;
    totalFreq[node] = req[node];
    for(int i=start[node]; i!=0 ;i=arr[i].next )
    {
        to = arr[i].to;
        c = arr[i].w;
        if(to==par) continue;
        calcDfs(to,node);
        totalCost[node] += totalCost[to] + c*totalFreq[to];
        totalFreq[node] += totalFreq[to];
    }

//    deb("Calcnode",node,"par",par,totalCost[node],totalFreq[node]);
    return ;
}

ll mainCost[MAX] , mainFreq[MAX];
ll bestCost;
void calcDfs2( int node  , int par , ll c) /// calculates the totalCost where each node considered root
{
    ll temCost,temFreq;
    if(node!=par)
    {
        temCost = mainCost[par] - totalCost[node] - c*totalFreq[node] ;
        temFreq = mainFreq[par] - totalFreq[node];

        mainCost[node] = temCost + totalCost[node]  + c*temFreq;
        mainFreq[node] = totalFreq[node] + temFreq;
    }
    else mainCost[node] = totalCost[node] , mainFreq[node] = totalFreq[node];

    bestCost = min(bestCost,mainCost[node]);

    ll to,cc;
    for(int i=start[node];i!=0 ;i=arr[i].next)
    {
        to = arr[i].to;
        cc = arr[i].w;
        if(to==par) continue;
        calcDfs2(to,node,cc);
    }

//    deb("Calc**node",node,"par",par,mainCost[node],mainFreq[node]);
    return ;
}

int n;
int main(void)
{
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    int q,a,b,c;
    int cas,loop=0;
    scanf("%d",&cas);
    while(cas--)
    {
        scanf("%d",&n);
        initialize();
        for(int i=0;i<n-1;i++)
        {
            scanf("%d %d %d",&a,&b,&c);
            addedge(a,b,2*c);
            addedge(b,a,2*c);

            req[a]=0;
            req[b]=0;
        }

        scanf("%d",&q);
        for(int i=0;i<q;i++)
        {
            scanf("%d %d",&a,&c);
            req[a]=c;
        }

        bestCost = 12345678901234567LL;
        calcDfs(1,1);
        calcDfs2(1,1,0);
        bool flag=false;
        printf("%I64d\n",bestCost);
        for(int i=1;i<=n;i++) {
                if(mainCost[i]==bestCost) {
                    if(flag==true) printf(" ");
                    printf("%d",i);
                    flag=true;
                }
        }
        puts("");
    }
    return 0;
}
