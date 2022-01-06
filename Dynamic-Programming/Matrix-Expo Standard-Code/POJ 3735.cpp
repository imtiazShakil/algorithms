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

const int N = 110;
struct Matrix {
    int n , m;
    ll a[N][N];
    Matrix() {}
    Matrix(int _n,int _m):n(_n),m(_m){};
    void intput() {
        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%d",&a[i][j]);
    }
    Matrix operator + (const Matrix &b) {
        Matrix tmp = Matrix(n,m);
        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            tmp.a[i][j] = a[i][j] + b.a[i][j];
        return tmp;
    }
    Matrix operator - (const Matrix &b) {
        Matrix tmp = Matrix(n,m);
        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            tmp.a[i][j] = a[i][j] - b.a[i][j];
        return tmp;
    }
    Matrix operator * (const Matrix &b) {
        Matrix tmp = Matrix(n,b.m);
        for(int i=0;i<n;i++)
        for(int j=0;j<b.m;j++)
            tmp.a[i][j] = 0;
        for(int i=0;i<n;i++)
        for(int k=0;k<m;k++)
        if(a[i][k])
        for(int j=0;j<b.m;j++)
            tmp.a[i][j] += a[i][k]*b.a[k][j];
        return tmp;
    }
};

Matrix operator ^ (Matrix a , int p) {
    Matrix ret = Matrix(a.n,a.m);
    for(int i=0;i<a.n;i++)
    for(int j=0;j<a.m;j++)
        ret.a[i][j] = (i == j ? 1 : 0);
    while(p) {
        if(p%2) ret = ret * a;
        a = a * a;
        p /= 2;
    }
    return ret;
}
int main()
{
    ll ans[120];
    char arr[10] ;
    int n,m,k,a,b,cnst;
    while(~scanf("%d%d%d",&n,&m,&k) && n+m+k)
    {
        Matrix base=Matrix(n+1,n+1);
        memset(base.a,0,sizeof(base.a));

        cnst=0;
        for(int i=0;i<=n;i++) base.a[i][i]=1;
        for(int i=0;i<k;i++)
        {
            scanf("%s %d",arr,&a);
            if(arr[0]=='g') base.a[a][cnst]++;
            else if(arr[0]=='e') for(int i=0;i<=n;i++) base.a[a][i]=0;
            else {
                scanf("%d",&b);
                for(int i=0;i<=n;i++) swap(base.a[a][i] , base.a[b][i] );
            }
        }
        base=base^m;
        for(int i=1;i<=n;i++) ans[i]=base.a[i][cnst];

        printf("%I64d",ans[1]);
        for(int i=2;i<=n;i++) printf(" %I64d",ans[i]);puts("");
    }
    return 0;
}

