#include <stdio.h>
#define SZ 1000005
//int prime[80000];
bool num[SZ];
bool digit_prime[SZ];
int total[SZ];
int sum_digit(int val)
{
    int count=0;
    while(val)
    {
        count+=val%10;
        val/=10;
    }

    return count;
}
void seive()
{
    //prime[0]=2;
    num[1]=true;digit_prime[2]=true;
    int i,j,k,check,count;for(i=4;i<=SZ;i+=2) num[i]=true;

    for(i=3,j=0,count=2,check=3;i<SZ;i+=2,count++,check+=2)
    {
        if(count==5) {count=0;}
        if(count==1) {check=sum_digit(i);}
        if(!num[i])
        {
//            prime[++j]=i;
            if(!num[check]) digit_prime[i] =true;
            if(i<SZ/i) for(k=i*i;k<SZ;k+=i) num[k]=true;
        }
//        printf("i=%d count %d check %d digit_prime %d\n",i,count,check,digit_prime[i]);
    }
}
int main(void)
{
    seive();
    int i,count=0,a,b,loop,ans;
    for(i=0;i<SZ;i++)
    {
        if(digit_prime[i]) count++;
        total[i]=count;

    }
//    printf("total[3] %d total[1] %d\n",total[3],total[1]);
    scanf("%d",&loop);
    while(loop--)
    {
        scanf("%d %d",&a,&b);
        ans=total[b]-total[a-1];

        printf("%d\n",ans);
    }
}
