
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
#define popc(i) (__builtin_popcount(i))
#define fs      first
#define sc      second
#define EQ(a,b)     (fabs(a-b)<ERR)
#define MAX 100050
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


int len=2;
ll mod;
struct mat
{
    ll p[2][2];
    mat() {
        for(int i=0;i<len;i++) for(int j=0;j<len;j++) p[i][j]=0;
    }
};
mat base,identity,AK;

mat mat_mul(mat a,mat b)
{
    mat tmp;
    for(int i=0;i<len;i++)
    {
        for(int j=0;j<len;j++)
        {
            tmp.p[i][j]=0;
            for(int k=0;k<len;k++)
            {
                tmp.p[i][j]=  (tmp.p[i][j] + (a.p[i][k] * b.p[k][j] )%mod)%mod ;
            }
        }
    }
    return tmp;
}
mat mat_add(mat a,mat b)
{
    mat tmp;
    for(int i=0;i<len;i++) for(int j=0;j<len;j++) {tmp.p[i][j]=a.p[i][j] + b.p[i][j] ; tmp.p[i][j]%=mod;}
    return tmp;
}
mat mat_pow(mat a, ll P)
{
    int i;
    mat r;

    for(i=0;i<len;i++) for(int j=0;j<len;j++) r.p[i][j]=0;
    for(i=0;i<len;i++) r.p[i][i]=1;

    while(P)
    {
        if(P&1) r=mat_mul(r,a);
        P>>=1;
        a=mat_mul(a,a);

    }
    return r;
}

void print( mat a)
{
    for(int i=0;i<len;i++,puts("")) for(int j=0;j<len;j++) printf("%lld ",a.p[i][j]);
    puts("");
}

mat function(int n )
{
    if(n==1) return AK;

    mat tmp=  function(n/2);
    mat tmp2 = mat_mul( mat_pow(AK,n/2) , tmp);
    mat tmp3=mat_add( tmp , tmp2 );

    if(n%2) tmp3=mat_add(tmp3 , mat_pow(AK,n) );

    return tmp3;
}

int main()
{
    identity=mat();identity.p[0][0]=1;identity.p[1][1]=1;

    mat tmp;
    ll k ,b,n;
    while(scanf("%I64d %I64d %I64d %I64d",&k,&b,&n,&mod)==4)
    {
        base=mat();
        base.p[0][1]=base.p[1][0]=base.p[1][1]=1;

        AK=mat_pow(base,k);

        tmp=function(n-1);
        tmp=mat_add( identity , tmp );
        tmp=mat_mul( mat_pow(base,b) , tmp );

        printf("%I64d\n",tmp.p[0][1]);


    }
    return 0;
}
