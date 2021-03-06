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
#define oo (1<<28)
#define FOREACH(it,x) for(__typeof((x).begin()) it=(x.begin()); it!=(x).end(); ++it)
#define Contains(X,item)        ((X).find(item) != (X).end())
#define popc(i) (__builtin_popcountll(i))
#define fs      first
#define sc      second
#define EQ(a,b)     (fabs(a-b)<ERR)
#define MAX 100000

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

template<class T> void read(T &x)
{
    char ch;
    while ((ch=getchar()) && !isdigit(ch));x=ch-'0';
    while ((ch=getchar()) && isdigit(ch)) x=x*10+ch-'0';
}
int n,m;
int grid[4005][4005] , cost[4005][4005] , dp[4005][805];

void rec( int  lft , int rght , int group , int optL , int optR)
{
    if(lft>rght) return ;
    if(lft==rght)
    {
        for(int i=optL;i<=min(optR,rght-1) ;i++)
            dp[lft][group] = min(dp[lft][group], dp[i][group-1] + cost[i+1][lft] );
        return;
    }
    int mid= (lft+rght)/2 , bestCandi=0;

    for(int i=optL;i<=min(optR,rght-1) ;i++) {
        if( dp[mid][group] > dp[i][group-1] + cost[i+1][mid] )
            dp[mid][group] = dp[i][group-1] + cost[i+1][mid] , bestCandi=i;
    }
    rec(lft,mid-1,group,optL,bestCandi);
    rec(mid+1,rght,group,bestCandi,optR);
    return ;
}

int main(void)
{
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    read(n);read(m);
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) read(grid[i][j]);
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) grid[i][j] += grid[i-1][j] + grid[i][j-1] - grid[i-1][j-1];
    for(int i=1;i<=n;i++) for(int j=i;j<=n;j++) cost[i][j] = (grid[j][j] - grid[j][i-1] - grid[i-1][j] + grid[i-1][i-1] ) /2;

    for(int i=0;i<n+5;i++) for(int j=0;j<=m+5;j++) dp[i][j]=oo;
    dp[0][0]=0;
    for(int i=1;i<=m;i++) rec(1,n,i,0,n-1);
    printf("%d\n",dp[n][m]);

    return 0;
}
