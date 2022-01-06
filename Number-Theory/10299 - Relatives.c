#include <stdio.h>
#include <math.h>
#define SIZE 1000000

bool num[SIZE];
int prime[80000];
int prm[80000];
void prm_gen(void)
{
    int i,j=1,k;
    prime[0]=2;num[1]=true;
    for(i=4;i<SIZE;i+=2) num[i]=true;
    for(i=3;i<SIZE;i+=2)
    {
        if(!num[i])
        {
            prime[j++]=i;
            if(i<SIZE/i) for(k=i*i;k<SIZE;k+=i) num[k]=true;
        }
    }
//    printf("Total %d %d\n",j,prime[j-1]);
}

bool check_prime(int val)
{
    if(val<SIZE) {if(num[val]) return false;else return true;}
    int i,rt=sqrt(val);
    for(i=0;prime[i]<rt;i++)
    {
        if(val%prime[i]) continue;
        else return false;
    }
    return true;
}

int main(void)
{
    prm_gen();
    int ques,i,val,pos,rt;
    long long ans;
    bool flag;
    while(scanf("%d",&ques)==1 && ques)
    {
        if(ques==1) {printf("0\n");continue;}
        if(check_prime(ques)) {printf("%d\n",ques-1);continue;}
//        printf("not prime\n");
        rt=sqrt(ques)+1;
//        for(i=0,pos=0,val=ques;val!=1;i++)
        for(i=0,pos=0,val=ques;prime[i]<rt;i++)
        {
            flag=false;
            while(!(val%prime[i]))
            {
//                printf("val %d\n",val);
                val/=prime[i];
                flag=true;
            }
            if(flag) {prm[pos++]=prime[i];rt=sqrt(val)+1;}
//            if(check_prime(val)) {prm[pos++]=val;break;}

        }
        if(val>1) prm[pos++]=val;
        ans=ques;
//        for(i=0;i<pos;i++) printf("%d ",prm[i]);
//        putchar('\n');
        for(i=0;i<pos;i++) {ans*=(prm[i]-1);}
        for(i=0;i<pos;i++) ans/=prm[i];
        printf("%lld\n",ans);

    }
}
