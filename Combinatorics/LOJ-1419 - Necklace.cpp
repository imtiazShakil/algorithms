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
#define SZ(s)      (int)s.size()
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
#define mod         1000000007

long long bigmod(long long b,long long p,long long m)
{
    if(b==0) return 0;
    long long x,power;
    x=1;
    power=b%m;
    while(p)
    {
       if(p%2==1)
            x=(x*power)%m;
        power=(power*power)%m;
        p=p/2;
    }
    return x;
}
LL n,k;
int col[1100],rot[1100];

void dfs(LL node,LL t)
{
    if(col[node]) return;
    col[node]=true;
    dfs((node+t+n)%n,t);
}


int main()
{
    int t,cas=0;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        printf("Case %d: ",++cas);
        LL ans=0;
        LL i,j;
        fr(i,0,n-1)
        {
            int chc=__gcd(i,n);
            if(i&&chc!=i)
            {
                ans=(ans+(2*bigmod(k,rot[chc],mod))%mod)%mod;
                continue;
            }
            mem(col,0);
            LL num=0;
            fr(j,0,n-1)
            if(!col[j])
            {
                dfs(j,i);
                num++;
            }
            rot[i]=num;
            ans=(ans+(2*bigmod(k,num,mod))%mod)%mod;
        }
        ans=(ans*bigmod(2*n,mod-2,mod))%mod;
        print1(ans);
    }
    return 0;
}
