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

#define REP(i,n) for (i=0;i<n;i++)
#define FOR(i,p,k) for (i=p; i<k;i++)
#define REV(i,n) for (i=n;i>=0;i--)
#define Reverse(x) reverse(x.begin(),x.end())

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


string cut_leading_zero(string a)
{
    string s;
    int i;
    if(a[0]!='0')   return a;
    REP(i,SZ(a)-1)  if(a[i]!='0')   break;
    FOR(i,i,SZ(a))  s+=a[i];
    return s;
}

string Division(string a,int k)
{
    int i,sum=0;
    string ans="0";

    REP(i,SZ(a))
    {
        sum=(sum*10+(a[i]-'0'));
        ans+=(sum/k)+'0';
        sum=sum%k;
    }
    ans=cut_leading_zero(ans);
    return ans;
}


ll mod=1000000007LL;
const int N = 3;
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
            tmp.a[i][j] = ( tmp.a[i][j] + a[i][k]*b.a[k][j] )%mod;
        return tmp;
    }
    void print() {
        for(int i=0;i<n;i++,puts("")) for(int j=0;j<m;j++) printf(" %d",a[i][j]);
    }
    void init() {
        memset (a, 0, sizeof (a));
    }
};

Matrix operator ^ (Matrix a , string p) {
    Matrix ret = Matrix(a.n,a.m);
    for(int i=0;i<a.n;i++)
    for(int j=0;j<a.m;j++)
        ret.a[i][j] = (i == j ? 1 : 0);

    while(p!="0") {
        if( ( p[SZ(p)-1]-'0')%2 ) p[SZ(p)-1]--, ret = ret * a;
        a = a * a;
        p = Division(p,2);
    }
    return ret;
}
ll get_int( string s)
{
    stringstream ss;
    ss<<s;
    ll var;ss>>var;
    return var;
}
int get_indx(string s)
{
    if(s.substr(0,2)=="C1") return 0;
    return 1;
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);

    int len=3;
    string str;
    ll p;char tt[200];
    ll v,ans;char arr[100],arr2[100],arr3[100];
    int cas,loop=0;
    ll a,b,q;
    scanf("%d",&cas);
    while(cas--)
    {
        scanf("%I64d",&v);
        Matrix base=Matrix(3,3);
        base.init();
        for(int i=0;i<len;i++) base.a[i][i]=1;

        while(scanf("%s",arr)==1)
        {
            if(!strcmp(arr,"END")) break;
            scanf("%s %s",arr2,arr3);

            if(!strcmp(arr,"SET"))
            {
                a=get_indx(arr2);
                if( arr3[0]=='C')
                {
                    b=get_indx(arr3);
                    for(int i=0;i<3;i++) base.a[a][i]=base.a[b][i];
                }
                else {
                    b=get_int(arr3);
                    base.a[a][0]=0; base.a[a][1]=0; base.a[a][2]=b;
                }
            }
            else if(!strcmp(arr,"ADD"))
            {
                a=get_indx(arr2);
                if( arr3[0]=='C')
                {
                    b=get_indx(arr3);
                    for(int i=0;i<3;i++) base.a[a][i]+=base.a[b][i];
                }
                else {
                    b=get_int(arr3);
                    base.a[a][2]+=b;
                }
            }
            else {
                a=get_indx(arr2);
                b=get_int(arr3);
                for(int i=0;i<3;i++) base.a[a][i]*=b;
            }
            for(int i=0;i<3;i++) for(int j=0;j<3;j++) base.a[i][j]%=mod;
        }
        Matrix tmp=Matrix(3,3);
        printf("Case %d:\n",++loop);
        scanf("%I64d",&q);
        while(q--)
        {
            scanf("%s",tt);
            str=tt;

            tmp=base^str;
            ans= ( (tmp.a[1][0]*v)%mod + tmp.a[1][2] ) %mod;
            printf("%I64d\n",ans);
        }
    }
    return 0;
}

