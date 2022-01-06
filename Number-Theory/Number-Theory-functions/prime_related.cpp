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
typedef vector<int> vi;
typedef pair<int,int> paii;

#define REP(i,n) for (i=0;i<n;i++)

#define PI (2*acos(0))
#define ERR 1e-5
#define mem(a,b) memset(a,b,sizeof a)
#define pb push_back
#define popb pop_back
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define SZ(x) (int)x.size()
#define oo (1<<25)
#define rep(x,n)        for(int x=0;x<(int)(n);x++)
#define FOREACH(it,x) for(__typeof((x).begin()) it=(x.begin()); it!=(x).end(); ++it)
#define Contains(X,item)        ((X).find(item) != (X).end())
#define popc(i) (__builtin_popcount(i))
#define fs      first
#define sc      second
#define EQ(a,b)     (fabs(a-b)<ERR)
#define MAX 60000

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

//#include <conio.h>
//#define wait getch()

///it will work for atmost 2^31 integer size
void seive();
void get_factors(int val);///Print all the prime factors of val & thier frequencies
void rec(int indx,int val);///(not for call _don't call it) used to calculate all possible divisors.
void get_divisor(int val);///(gets all the divisor of val in ascending order <super fast> )
int chk_prime(int val);///returns true if its a prime otherwise returns false
ll num_divisors(ll val);///returns total number of divisors

int prm[6100];
bool num[MAX];
vector<int>v;

struct data
{
    int prime,freq;
};
data factors[6100];

void seive()
{
    prm[0]=2;
    int pos=0;
    for(int i=3;i<MAX;i+=2)
    {
        if(num[i]==0)
        {
            prm[++pos]=i;
            if(i<MAX/i) for(int k=i*i;k<MAX;k+=i) num[k]=true;
        }
    }
    deb("total ",pos,"last one ",prm[pos]);
    return ;
}

void get_factors(int val)
{
    int sq=sqrt(val)+1;
    int indx=0;mem(factors,0);
    for(int i=0;sq>=prm[i];i++)
    {
        if(val%prm[i]==0)
        {
            factors[indx].prime=prm[i]; int cnt=0;
            while(val%prm[i]==0)
            {
                cnt++;val/=prm[i];
            }
            factors[indx++].freq=cnt;
            sq=sqrt(val) + 1;
        }
    }
    if(val>1) factors[indx].prime=val,factors[indx++].freq=1;

    for(int i=0; ;i++)
    {
        if(factors[i].prime==0) break;
        deb("prime",factors[i].prime,"frequency",factors[i].freq);
    }
    return ;
}

void rec(int indx,int val)
{
    if(factors[indx].prime==0) {v.pb(val);return ;}
    int tmp=val;
    for(int i=0;i<=factors[indx].freq;i++)
    {
        if(i) tmp*=factors[indx].prime;
        rec(indx+1,tmp);
    }
    return ;
}

void get_divisor(int val)
{
    get_factors(val);
    v.clear();
    rec(0,1);
    sort(all(v));
    printf("Divisors");
    for(int i=0;i<SZ(v);i++) cout<<" "<<v[i];
    puts("");
    return ;
}
int chk_prime(int val)
{
    if(val==2) return 1;
    if(val==1) return 0;
    if(val%2==0) return 0;
    int sq=sqrt(val) +1;
    for(int i=0;prm[i]<=sq;i++ )
    {
        if( val%prm[i]==0 ) return 0;
    }
    return 1;
}
ll num_divisors(ll val)
{
    if(val==1) return 1;
    int sq=sqrt(val)+1;
    ll sum=0;
    for(int i=0;sq>=prm[i];i++)
    {
        if(val%prm[i]==0)
        {
            int cnt=0;
            while(val%prm[i]==0)
            {
                cnt++;val/=prm[i];
            }
            if(sum==0) sum=cnt+1;
            else sum*=(cnt+1);
            sq=sqrt(val) + 1;
        }
    }
    if(val>1) sum= (sum==0)? 2 : (sum*2) ;

    return sum;
}

int main(void)
{
    seive();
//    get_factors(2592);
    get_divisor(1000000000);
}
