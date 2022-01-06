#include <stdio.h>
#include <math.h>
#define SIZE 50001

int prime[6000];
int divisor[6000];
int unmatched[50005];
int tot_f[50005];

bool num[SIZE];

void prm_gen(void)
{
    prime[0]=2;num[1]=true;
    int i,j=0,k;
    for(i=4;i<SIZE;i+=2) num[i]=true;
    for(i=3;i<SIZE;i+=2)
    {
        if(!num[i])
        {
            prime[++j]=i;
            if(i<SIZE/i) for(k=i*i;k<SIZE;k+=i) num[k]=true;
        }
    }
//    printf("total %d %d\n",j+1,prime[j]);
}


void eul_phi(void)
{
    long long ans;
    int i,j,k,rt,val,pos;
    for(i=2;i<SIZE;i++)
    {
        if(!num[i]) {tot_f[i]=i-1;continue;}
        rt=sqrt(i) + 1;
        for(j=0,val=i,pos=0;prime[j]<rt;j++)
        {
            if(!(val%prime[j]))
            {
                divisor[pos++]=prime[j];//printf("%d ",prime[j]);
                while(!(val%prime[j]))   {val/=prime[j];}
                rt=sqrt(val) + 1;
            }
        }
        if(val>1) divisor[pos++]=val;
        ans=i;
        for(k=0;k<pos;k++) ans*=(divisor[k]-1);
        for(k=0;k<pos;k++) ans/=divisor[k];
        tot_f[i]=ans;
//        printf("for %d tot_fi %d\n",i,tot_f[i]);
    }
}
void match_maker(void)
{
    unmatched[1]=1;
    int i;
    for(i=2;i<SIZE;i++)
    {
        unmatched[i]=unmatched[i-1] + tot_f[i]*2;
    }
}
int main(void)
{
    prm_gen();
    eul_phi();
    match_maker();
    int ques;
    while(scanf("%d",&ques)==1 && ques)
    {
        printf("%d\n",unmatched[ques]);
    }

}
