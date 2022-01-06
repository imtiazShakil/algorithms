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
#define MAX 11000
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

int n,m;
vector<int>v[MAX],v_new[MAX];
paii edges[2*MAX];
stack<paii>S;

int tim[MAX],low[MAX],color_id[MAX], TME,found;

int check_bicolor(int now, int col)
{
    color_id[now]=col;
    int ret=1;found++;
    for(int i=0;i<SZ(v_new[now]);i++)
    {
        int to=v_new[now][i];
        if(color_id[to]==-1)
        {
            ret&=check_bicolor(to,!col);
        } else if(color_id[to]==col) ret=0;
    }
    return ret;
}
void check_bcc(int a, int b)
{
    int indx=0,x,y;
    while(!S.empty())
    {
        x=S.top().fs,y=S.top().sc;S.pop();
        edges[indx++]=mp(x,y);

        if(x==a && y==b ) break;
        if(x==b && y==a) break;
    }
    if(indx<=1) return ;
    for(int i=0;i<indx;i++)
    {
        v_new[edges[i].fs].pb(edges[i].sc);
        v_new[edges[i].sc].pb(edges[i].fs);
    }
    return ;
}
int getArtiPoint(int now, int par)
{
    tim[now]=low[now]=++TME;
    for(int i=0;i<SZ(v[now]);i++)
    {
        int to=v[now][i];
        if(to==par) continue;


        if(tim[to]==0)
        {
            S.push(mp(now,to));
            low[now]=min(low[now],getArtiPoint(to,now));
            if(tim[now]<=low[to]) check_bcc(now,to);

        }else if(tim[to]<tim[now]) /// this has to be a backedge
        {                           ///connecting an ancestor
            S.push(mp(now,to));
            low[now]=min(low[now],tim[to]); ///if it wasn't an ancestor then no need to push him in stack
        }

    }
    return low[now];
}

int main()
{
    int cas,loop=0,a,b,ans;
    scanf("%d",&cas);
    while(cas--)
    {
        mem(tim,0);mem(low,0);mem(color_id,-1);
        scanf("%d %d",&n,&m);
        for(int i=0;i<n;i++) v[i].clear(), v_new[i].clear();
        while(!S.empty()) S.pop();

        for(int i=0;i<m;i++)
        {
            scanf("%d %d",&a,&b);
            v[a].pb(b);v[b].pb(a);
        }

        for(int i=0;i<n;i++)
            if(tim[i]==0) getArtiPoint(i,-1);


        ans=0;
        for(int i=0;i<n;i++)
        {
            if(color_id[i]==-1) {
                found=0;
                if(!check_bicolor(i,0)) ans+=found;
            }
        }
        printf("Case %d: %d\n",++loop,ans);
    }

    return 0;
}

