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
#define oo (1LL<<55)
#define FOREACH(it,x) for(__typeof((x).begin()) it=(x.begin()); it!=(x).end(); ++it)
#define Contains(X,item)        ((X).find(item) != (X).end())
#define popc(i) (__builtin_popcountll(i))
#define fs      first
#define sc      second
#define EQ(a,b)     (fabs(a-b)<ERR)
#define MAX 305
#define twoL(X) (((ll)(1))<<(X))

template<class T1> void deb(T1 e){cout<<e<<endl;}
template<class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<" "<<e2<<endl;}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3){cout<<e1<<" "<<e2<<" "<<e3<<endl;}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<endl;}
template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<endl;}


template<class T> T Abs(T x) {return x > 0 ? x : -x;}
template<class T> inline T sqr(T x){return x*x;}
ll Pow(ll B,ll P){      ll R=1; while(P>0)      {if(P%2==1)     R=(R*B);P/=2;B=(B*B);}return R;}
ll BigMod(ll B,ll P,ll M){     ll R=1; while(P>0)      {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

///int rrr[]={1,0,-1,0};int ccc[]={0,1,0,-1}; //4 Direction
///int rrr[]={1,1,0,-1,-1,-1,0,1};int ccc[]={0,1,1,1,0,-1,-1,-1};//8 direction
///int rrr[]={2,1,-1,-2,-2,-1,1,2};int ccc[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
///int rrr[]={2,1,-1,-2,-1,1};int ccc[]={0,1,1,0,-1,-1}; //Hexagonal Direction
///int month[]={31,28,31,30,31,30,31,31,30,31,30,31}; //month
int n,m,q;
//vector< pair<int,ll> >v[MAX];
ll dist[MAX][MAX];
ll mat[MAX][MAX];
int marked[MAX];

void floyd_warshall(int now)
{
    marked[now]=1;
    dist[now][now]=0;

    for(int i=0;i<n;i++)
    {
        if(!marked[i]) continue;

        dist[now][i]=min(dist[now][i],mat[now][i]);
        dist[i][now]=min(dist[i][now],mat[i][now]);
    }

    for(int k=0;k<n;k++)
    {
        if(!marked[k]) continue;
        for(int i=0;i<n;i++)
        {
            if(!marked[i]) continue;

            dist[i][now]=min(dist[i][now] , dist[i][k] + dist[k][now] );
        }
    }

    for(int k=0;k<n;k++)
    {
        if(!marked[k]) continue;
        for(int j=0;j<n;j++)
        {
            if(!marked[j]) continue;

            dist[now][j]=min(dist[now][j] , dist[now][k] + dist[k][j] );
        }
    }

    for(int i=0;i<n;i++)
    {
        if(!marked[i]) continue;
        for(int j=0;j<n;j++)
        {
            if(!marked[j]) continue;

            dist[i][j]=min( dist[i][j] , dist[i][now] + dist[now][j] );
        }
    }

    return ;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int a, b, c,typ,loop=0;
    ll d;
    while(scanf("%d %d %d",&n,&m,&q)==3 )
    {
        if(n==m && m==q && n==0) break;

        for(int i=0;i<=n;i++) for(int j=0;j<n;j++) mat[i][j]=oo;
        if(loop!=0) puts("");
        mem(marked,0);
        for(int i=0;i<m;i++)
        {
            scanf("%d %d %lld",&a,&b,&d);
            mat[a][b]=min(mat[a][b],d);
        }
        for(int i=0;i<=n;i++) for(int j=0;j<=n;j++) dist[i][j]=oo;

        printf("Case %d:\n",++loop);
        while(q--)
        {
            scanf("%d %d",&typ,&a);
            if(typ) scanf("%d",&b);

            if(typ==0) {
                if(marked[a]) printf("ERROR! At point %d\n",a);
                else floyd_warshall(a);
            }
            else {
                if( ( marked[a] + marked[b])<2 ) printf("ERROR! At path %d to %d\n",a,b);
                else if(dist[a][b]<oo) printf("%lld\n",dist[a][b]);
                else puts("No such path");
            }
        }

    }

    return 0;
}
