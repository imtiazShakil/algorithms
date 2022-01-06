#include <stdio.h>
#define SZ 5000001

int prime[350000];
bool num[SZ];
int fact[SZ];
int total[SZ];
bool deprime[SZ];

void seive()
{
    prime[0]=2;fact[2]=2;
    int i,pos=0,j;deprime[2]=1;
    for(i=4;i<SZ;i+=2) num[i]=true;
    for(i=3;i<SZ;i+=2)
    {
        if(!num[i])
        {
            prime[++pos]=i;
            deprime[i]=true;
            fact[i]=i;
            if(i<SZ/i)  for(j=i*i;j<SZ;j+=i) num[j]=true;
        }
    }

//    printf("tot %d %d\n",pos+1,prime[pos]);

    int div,k;
    for(i=0;i<=pos;i++)
    {
        k=prime[i];
        if(k<SZ/k)
        {
            for(j=k*k;j<SZ;j+=k)
            {
                div=j/k;
                if(div%k) fact[j]=fact[div]+fact[k];
                else fact[j]=fact[div];

                if(num[fact[j]]) deprime[j]=false;
                else deprime[j]=true;
            }
        }
    }

}
int main(void)
{
    seive();
    int val,i,count,a,b,ans;
    for(i=2,count=0;i<SZ;i++)
    {
        if(deprime[i]) count++;
        total[i]=count;
    }
//    while(scanf("%d",&val)==1)
//    {
//        printf("fact [ %d ] = %d     ",val,fact[val]);
//        if(deprime[val]) printf("deprime\n");
//        else printf("not deprime \n");
//    }

    while(scanf("%d",&a)==1 && a)
    {
        scanf("%d",&b);
        ans=total[b]-total[a-1];
        printf("%d\n",ans);
    }
}
