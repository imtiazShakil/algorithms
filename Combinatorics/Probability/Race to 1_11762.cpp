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


#define print1(a) cout<<a<<endl
#define print2(a,b) cout<<a<<" "<<b<<endl
#define print3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define PI (2*acos(0))
#define ERR 1e-5
#define ll long long
#define VI vector<int>
#define mem(a,b) memset(a,b,sizeof a)
#define pb push_back
#define popb pop_back
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define MAX 1000005
#define SZ(x) (int)x.size()
#define paii pair<int,int>
#define oo (1<<25)
#define rep(x,n)        for(x=0;x<(int)(n);x++)
#define Contains(X,item)        ((X).find(item) != (X).end())
#define fs      first
#define sc      second

///ll rrr[]={1,0,-1,0};ll ccc[]={0,1,0,-1}; //4 Direction
///int rrr[]={1,1,0,-1,-1,-1,0,1};int ccc[]={0,1,1,1,0,-1,-1,-1};//8 direction
///int rrr[]={2,1,-1,-2,-2,-1,1,2};int ccc[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
///int rrr[]={2,1,-1,-2,-1,1};int ccc[]={0,1,1,0,-1,-1}; //Hexagonal Direction
///ll month[]={31,28,31,30,31,30,31,31,30,31,30,31}; //month

using namespace std;

///expected number of moves
///here first of all you need to find all the possible outcomes and their probability
//
//getting head in a toss<expected number of moves>
//E(H) = P(H) + P(T) * (1+E(H))
//
///for this problem
///E(13) = (1/6)*(1+E(13/13) ) + (5/6)*(1+E(13))



double dp[MAX];
int prime[79000];
bool num[MAX];

void seive()
{
    int j,k=0;
    prime[0]=2;
    for(int i=3;i<MAX;i+=2)
    {
        if(!num[i])
        {
            prime[++k]=i;
            if(i<MAX/i) for(int p=i*i;p<MAX;p+=i) num[p]=1;
        }
    }
//    print2(k,prime[k]);
}

double rec(int n)
{
    if(n==1) return 0.0;
    double &ret=dp[n];
    if(ret!=-1.0) return ret;
    int i;
    ret=0.0;
    double cut=0.0,div;
    for( i=0;prime[i]<=n;i++)
    {
        if(n%prime[i]==0) ret+=(1.0+ rec( n/prime[i] ) );
        else {cut+=1.0;ret+=1.0;}
    }
    div=(double)i;
    div-=cut;
    ret=ret/div;
    return ret;


}
int main(void)
{
    seive();
    for(int i=0;i<MAX;i++) dp[i]=-1.0;
    int cas,val;
    double ans;
    scanf("%d",&cas);
    for(int i=1;i<=cas;i++)
    {
        scanf("%d",&val);
        ans=rec(val);
        printf("Case %d: %.10lf\n",i,ans);
//        print1(ans);
    }
    return 0;
}

