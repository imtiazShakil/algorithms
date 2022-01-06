#include <stdio.h>
#include <iostream>
#include <string.h>
#include <map>

#define MAX 150
#define ll long long
#define oo (1<<30)
#define mem(a,b)  memset(a,b,sizeof a)

using namespace std;

int n,card[MAX];

ll dp[MAX][MAX];

ll rec(int i,int j)
{
    ll &ret=dp[i][j];
    if(i==j) {ret=0;return ret;}
    if(ret!=-1) return ret;

    ret=oo;

    for(int k=i;k<j;k++)
    {
        ret=min(ret,rec(i,k) + rec(k+1,j) + card[i-1]*card[k]*card[j] );
    }

    return ret;

}
int main(void)
{
    int i;
    ll ans;
    while(scanf("%d",&n)==1)
    {
        for(i=0;i<n;i++) scanf("%d",&card[i]);
        mem(dp,-1);
        ans=rec(1,n-1);

//        printf("%I64d\n",ans);
        cout<<ans<<endl;
    }

    return 0;
}
