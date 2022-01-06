
#include <stdio.h>
#include <math.h>
#define size 1000010
bool num[size];
int sol[size];
int total[size];
int prime[80000];

void seive(void)
{
    prime[0]=2;
    sol[2]=1;

    int i,j,pos=0,k;
    for(i=3;i<size;i+=2)
    {
        if(!num[i])
        {
            prime[++pos]=i;
            sol[i]=1;

            if(i<size/i) {j=i*i;for(;j<size;j+=i) num[j]=true;}

        }
    }
    int val;
    for(i=0;i<pos;i++)
    {
        if(prime[i]<size/prime[i])
        {
            for(j=prime[i]*prime[i];j<size;j+=prime[i])
            {
                val=j/prime[i];
                sol[j]=1+sol[val];
            }
        }
    }
//    printf("total primes %d\n",pos+1);
}
int main(void)
{
    seive();
    int i,k,j,val;
    for(i=2;i<size;i++)
    {
        total[i]=total[i-1]+sol[i];
    }
    while(scanf("%d",&val)==1)
    {
        printf("%d\n",total[val]);
    }
}
