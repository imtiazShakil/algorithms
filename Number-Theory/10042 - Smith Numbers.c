#include <stdio.h>
#include <math.h>

#define SZ 1000001

int prime[80000];
bool num[SZ];


void seive(void)
{
    int i,j=0,k;
    prime[0]=2;num[1]=true;
    for(i=4;i<SZ;i+=2) num[i]=true;
    for(i=3;i<SZ;i+=2)
    {
        if(!num[i]) prime[++j]=i;
        if(i<SZ/i) for(k=i*i;k<SZ;k+=i) num[k]=true;
    }
//    printf("total [%d] = %d\n",j+1,prime[j]);
}
int sum_digit(int num)
{
    int sum=0,mod;
    while(num)
    {
        sum+= num%10;
        num/=10;
    }
    return sum;
}
bool check_prime(int val)
{
    if(val<SZ) if(!num[val]) return true;
    int j,rt=sqrt(val)+1;
    for(j=0;prime[j]<rt;j++)
        if(val%prime[j]==0) return false;

    return true;
}
int main(void)
{
    seive();
    int loop,inp,i,j,rt,val,val2,ans,div;
    bool flag;
    scanf("%d",&loop);
    while(loop--)
    {
        scanf("%d",&inp);
        for(i=inp+1; ;i++)
        {
            rt=sqrt(i)+1;
//            printf("opreating %d root %d\n",i,rt);
            if(check_prime(i)) continue;


            for(j=0,val=0,div=i;div!=1;)
            {

//                printf("prime [%d] = %d\n",j,prime[j]);
                if(div%prime[j]) {j++;continue;}
                else
                {
//                  printf("prime [%d] = %d\n",j,prime[j]);
                    val+=sum_digit(prime[j]);
                    div/=prime[j];
//                    printf("prime[%d] = %d  div %d\n",j,prime[j],div);
                    if(check_prime(div))
                    {
//                        printf("wnt here\n");
                        val+=sum_digit(div);
                        break;
                    }
                }
            }

//            printf("val %d\n",val);
            val2=sum_digit(i);
//            printf("val2 %d\n",val2);
            if(val==val2)
            {
                ans=i;break;
            }
            else continue;
        }
        printf("%d\n",ans);
    }
}
