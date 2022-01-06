#include <stdio.h>
#include <string.h>

#include <iostream>

#define oo (1<<25)
#define mem(a,b) memset(a,b,sizeof a)

using namespace std;

int stick[25],n,mid;
int dp[(1<<21)];


int rec(int mask,int sum,int turn)
{
    int &ret=dp[mask];
    if(turn==4 && __builtin_popcount(mask)==n ) {ret=1;return ret;}
    if(ret!=-1) return ret;

    ret=0;
    for(int i=0;i<n;i++)
    {
        if((mask&(1<<i))==0)
        {
            if(sum+stick[i]<mid)
            {
                ret+=rec(mask|(1<<i),sum+stick[i],turn);
            }
            else if(sum+stick[i]==mid)
            {
                ret+=rec(mask|(1<<i),0,turn+1);
            }
        }
        if(ret) return ret;
    }
    return ret;
}
int main(void)
{
    int loop,i,sum,ans;
    bool flag;
    scanf("%d",&loop);
    while(loop--)
    {
        scanf("%d",&n);
        for(i=0,sum=0;i<n;i++) {scanf("%d",&stick[i]);sum+=stick[i] ;}
        if(sum%4) {printf("no\n");continue;}
        mid=sum/4;
        for(i=0,flag=0;i<n;i++)
        {
            if(stick[i]>mid) {flag=1;break;}
        }
        if(flag) {printf("no\n");continue;}

        mem(dp,-1);
        ans=rec(0,0,0);

        if(ans) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
