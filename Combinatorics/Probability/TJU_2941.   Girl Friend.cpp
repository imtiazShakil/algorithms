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
#define MAX 100005
#define SZ(x) (int)x.size()
#define paii pair<int,int>
#define oo (1<<25)
#define rep(x,n)        for(int x=0;x<(int)(n);x++)
#define Contains(X,item)        ((X).find(item) != (X).end())
#define popc(i) (__builtin_popcount(i))
#define fs      first
#define sc      second

///ll rrr[]={1,0,-1,0};ll ccc[]={0,1,0,-1}; //4 Direction
///int rrr[]={1,1,0,-1,-1,-1,0,1};int ccc[]={0,1,1,1,0,-1,-1,-1};//8 direction
///int rrr[]={2,1,-1,-2,-2,-1,1,2};int ccc[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
///int rrr[]={2,1,-1,-2,-1,1};int ccc[]={0,1,1,0,-1,-1}; //Hexagonal Direction
///ll month[]={31,28,31,30,31,30,31,31,30,31,30,31}; //month

using namespace std;

double dp[MAX];
int n;
double p[MAX],v[MAX];

///for expected value
///find all the outcomes & their probability
///here for each girl we selected comes 2 option whteher she makes bond or not

double rec(int girl)
{
    if(girl==n) return 0.0;

    double &ret=dp[girl];
    if(ret!=-1.) return ret;

    ret=0.;
    ///will I take make this date happen or not
    ret=max( rec(girl+1) , p[girl]*v[girl] + ( 1.0- p[girl] )*(rec(girl+1 ) ) );


    return ret;

}

int main(void)
{
    double ans;
    while(scanf("%d",&n)==1 && n)
    {
        for(int i=0;i<n;i++) {scanf("%lf %lf",&p[i],&v[i]);p[i]/=100.0;}
        for(int i=0;i<=n;i++) dp[i]=-1.0;
        ans=rec(0);
//        ans/=100.0;

        printf("%.2lf\n",ans);
    }
    return 0;
}

