#include <stdio.h>
#include <string.h>
#include <iostream>
#include <map>

#define MAX 1005
#define oo (1<<30)
#define print1(a) cout<<a<<endl
#define print2(a,b) cout<<a<<" "<<b<<endl
#define mem(a,b) memset(a,b,sizeof a)

using namespace std;

int n;
int dp[MAX][MAX];
int div[100];

int rec(int start,int end   )
{
    int &ret=dp[start][end];
    if(ret!=-1) return ret;

    int i,j;
    bool flag=0;
    for(i=0;i<n;i++)
    {
        if(div[i]>start && div[i] < end) {flag=1;break;}
    }
    if(!flag) {ret=0;return ret;}

    ret=oo;
    for(i=0;i<n;i++)
    {
        if(div[i]>start && div[i]<end)
        {
           ret=min(ret,rec(start,div[i]) + rec(div[i],end) + end-start );
        }
    }
    return ret;
}
int main(void)
{
    int i,j,l,ans;
    while(scanf("%d",&l)==1 && l)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++) scanf("%d",&div[i]);

        for(i=0;i<=l;i++)
            for(j=0;j<=l;j++) dp[i][j]=-1;

        ans=rec(0,l);
        printf("The minimum cutting is %d.\n",ans);
    }
    return 0;
}
