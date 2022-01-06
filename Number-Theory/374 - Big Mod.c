#include <stdio.h>
#include <math.h>

#define BIN_DIG 50

bool binary[BIN_DIG];
long long big_mod(int num,int power,int mod);

int main(void)
{
    //freopen("in.in","r",stdin);
    //freopen("out.out","w+",stdout);
    int b,p,n;
    long long ans;
    while(scanf("%d %d %d",&b,&p,&n)==3)
    {
        ans=big_mod(b,p,n);
        printf("%lld\n",ans);
    }
}

long long big_mod(int num,int power,int mod)
{
    //bool temp[BIN_DIG];
    int i=-1,len;
    long long val,new_pow;
    if(!power) i=0;
    while(power)
    {
        binary[++i]=power%2;
        power/=2;
    }
    len=i;
    //for(i=len;i>=0;i--)printf("%d",binary[i]);
    //putchar('\n');
    for(i=0,val=1,new_pow=num%mod;i<=len;i++)
    {
        if(binary[i]) val=(val*new_pow)%mod;
        /*
        {
            pow_of_2=pow(2,i);
            printf("2^%d  = %d\n",i,pow_of_2);
            new_pow=pow(num,pow_of_2);
            temp=(new_pow%mod);
            val*=temp;
            val=val%mod;
            printf("val %d\n",val);
        }
        */
        new_pow=(new_pow*new_pow)%mod;
    }
    return val;

}
