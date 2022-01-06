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
#define MAX 5005

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

ll dp[MAX][MAX]; /// DP[N][K] put k items from N items
ll mod = 1000000007LL;

unsigned int comb[MAX][MAX];

void nCrSecondMethod()
{
    comb[0][0]=1;
    for(int i=1;i<MAX;i++) {
        comb[i][0]=1;
        for(int j=1;j<=i;j++) comb[i][j]= ( comb[i-1][j-1] + comb[i-1][j] )%mod;
    }
    return ;
}

/// Current State(5,3) -> _ _ _ _ _ L  // L means Largest Item
/// You are trying to insert here ^

/// All the 5 items are sorted in ascending order i.e. the 5th item is the tallest one
/// You can insert the 5th item in current position so next state will be (4,2)
/// Or You can choose to insert any smaller item (total n-1 smaller items) so new state will be (4,3)


ll rec(int n,int k)
{
    if(n<0 ||k<0 ) return 0;
    if(n<k) return 0;
    if(n==0 && k==0) return 1;
    ll &ret=dp[n][k];
    if(ret!=-1) return ret;
    ret=0;
    ret = (ret +  rec(n-1,k-1)  + ((n-1)*rec(n-1,k) )%mod )%mod;
    return ret;
}

int main(void)
{
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    mem(dp,-1);
    nCrSecondMethod();
    ll ans;
    int n,l,r;
    while(scanf("%d %d %d",&n,&l,&r)==3)
    {
        if(n==0 && l==0 && r==0) break;
        ans =0;
        for(int i=1;i<=n;i++) /// putting the largest item in ith position
        {
            ans =  ( ans + ( ( ( rec(i-1,l-1)*rec(n-i,r-1) )%mod )*comb[n-1][i-1] )%mod  )%mod;
//            deb(i,ans);
        }
        printf("%lld\n",ans);
    }
    return 0;
}

