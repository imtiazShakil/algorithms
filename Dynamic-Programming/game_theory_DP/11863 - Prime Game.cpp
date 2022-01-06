#include <stdio.h>
#include <iostream>

#define SZ 100005

using namespace std;

bool num[SZ];
int dp[200][200];
int arr[200],n;

void seive(void)
{
    int i,j;
    num[0]=1;num[1]=1;
    for(i=4;i<SZ;i+=2) num[i]=1;
    for(i=3;i<SZ;i+=2)
    {
        if(!num[i])
        {
            if(i<SZ/i)  for(j=i*i;j<SZ;j+=i) num[j]=1;
        }
    }
//    for(i=0;i<100;i++) printf("%d val %d\n",i,num[i]);
    return;
}
bool is_prime(int val)
{
    if(val<0) return false;
    if(num[val]) return false;
    else return true;
}

int rec(int start,int stop)
{
//    printf("( %d , %d ) \n",start,stop);
    int &ret=dp[start][stop];
    if(start>stop) {ret=0;/*printf("( %d , %d ) val %d returned %d\n",start,stop,ret,!ret );*/return !ret;}
    if(ret!=-1) return !ret;
    int i,j,sum,k,l;
    ret=0;
    for(i=1;i+start<stop+2;i++)
    {
        for(sum=0,k=start  ;  k<start+i  ;  k++) sum+=arr[k];
        if(is_prime(sum)) ret+=rec(start+i,stop);
    }
    for(j=1;stop-j>start-2;j++)
    {

//        if( start>stop-j ) sum=arr[stop-j+1];
//        else for(sum=0,k=stop-j+1  ; k<n  ;  k++) sum+=arr[k];
        for(sum=0,k=stop-j+1,l=0 ; l<j ; k++ ,l++) sum+=arr[k];
        if(is_prime(sum))  ret+=rec(start,stop-j);
    }
//    printf("( %d , %d ) val %d returned %d\n",start,stop,ret,!ret );
    return !ret;

}
int main(void)
{
    seive();
//    cout<<is_prime(3)<<endl;
    int i,j,loop,cas=0,pass,ans;
    scanf("%d",&loop);
    bool flag;
    while(loop--)
    {
        scanf("%d %d",&n,&pass);
        for(i=0;i<200;i++) for(j=0;j<200;j++) dp[i][j]=-1;
        for(i=0,flag=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
            if(arr[i]==42) flag=1;
        }
        if(flag) {printf("Case %d: Soha\n",++cas);continue;}
        ans=rec(0,n-1);
        if(ans)  printf("Case %d: Tara\n",++cas);
        else printf("Case %d: Soha\n",++cas);
    }
    return 0;
}
