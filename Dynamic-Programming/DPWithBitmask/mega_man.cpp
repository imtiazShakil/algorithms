#include <stdio.h>
//#include <vector>
//#include <string>
#include <string.h>
#define mask_size 100000
#define MAX 50
//using namespace std;
#define ll long long

char mat[MAX][MAX];
char rob_gun[MAX];
ll dp[mask_size];
int robot;

//bool chk(int num)
//{
//    int i;
//    for(i=0;i<robot;i++)
//    {
//        if((num & (1<<i))==0) return false;
//    }
//    return true;
//}

long long rec(int mask)
{
    int i,j;
    bool flag ;
    ll &ret=dp[mask];
    if(ret!=-1) return ret  ;
    if(__builtin_popcount(mask)==robot) {ret=1;return ret;}
    ret=0;
    for(i=0;i<robot;i++)
    {
        if((mask &(1<<i))==0)
        {
            if( rob_gun[i]=='1' ) ret+=rec(mask|(1<<i));
            else
            {
                for(j=0,flag=false;j<robot;j++)
                {
                    if(mask&(1<<j))
                    {
                        if(mat[j][i]=='1') {flag=true;break;}
                    }
                }
                if(flag) ret+=rec(mask|(1<<i));
            }
        }
    }
    return ret;
}


int main(void)
{
    int loop,i,j,cas=0;
    scanf("%d",&loop);
    long long val;
    while(loop--)
    {
        scanf("%d",&robot);
        scanf("%s",rob_gun);
        for(i=0;i<robot;i++)
        {
            scanf("%s",mat[i]);
        }
        for(i=0;i<mask_size;i++) dp[i]=-1;
        val=rec(0);
//        printf("val %d\n",val);
        printf("Case %d: %lld\n",++cas,val);
    }
    return 0;
}

