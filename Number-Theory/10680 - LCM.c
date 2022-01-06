#include <stdio.h>
#define sz 1000001
#define LARGE 100000
#define type long long
type lcm[sz];
bool num[sz];
bool flag2[sz];
type store[sz];
//int prime[80000];
void prime_gen(void)
{
//    prime[0]=2;
    int i,k;
    for(i=4;i<sz;i+=2) num[i]=true;
    for(i=4;i<sz;i*=2) {flag2[i]=true;store[i]=2;}
    for(i=3;i<sz;i+=2)
    {
        if(!num[i])
        {
//            prime[++j]=i;
            if(i<sz/i)
            {
                for(k=i*i;k<sz;k+=i) num[k]=true;
                for(k=i*i;;k*=i) {flag2[k]=true;store[k]=i;/*printf("i= %d k=%d\n",i,k);*/if(k>sz/i) break;}
            }
        }
    }
}
//int lcm_find(int a,int b)
//{
//    int smal=a,big=b,temp,prod=a*b,ans;
//    if(big<smal) {smal^=big^=smal^=big;}
//
//    while(big%smal)
//    {
//        temp=big%smal;
//        big=smal;
//        smal=temp;
//    }
//    ans=prod/smal;
//
//    return ans;
//
//}
void lcm_gen(void)
{
    type ans,i;
    lcm[1]=1;lcm[2]=2;
    for(i=3;i<sz;i++)
    {
        if(num[i] && flag2[i]) {ans=lcm[i-1]*store[i];}
        else if(!num[i]) {ans=lcm[i-1]*i;}
//        ans=lcm_find(i,lcm[i-1]);
        while(!(ans%10))
        {
            ans/=10;
        }
        ans%=LARGE;
        lcm[i]=ans;
//        printf("lcm[%d] = %d \n",i,ans);
    }
}
int main(void)
{
//    freopen("in.txt","r",stdin);
    prime_gen();
    lcm_gen();
    int val;
    type temp;
    while(scanf("%d",&val) && val)
    {
        temp=lcm[val];
//        printf("origin %d   ",temp);
        while(temp/10)
        {
            temp%=10;
        }
        printf("%d\n",temp);
    }
}
