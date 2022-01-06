#include <stdio.h>
#define sz 200
bool num[sz];
int prime[100];
int store[100];
void seive(void)
{
    prime[0]=2;
    int i,j=0,k;
    for(i=3;i<sz;i+=2)
    {
        if(!num[i])
        {
            prime[++j]=i;
//            printf("prime[%d] = %d\n",j,prime[j]);
            if(i<sz/i)
            {
                for(k=i*i;k<sz;k+=i) num[k]=true;
            }
        }
    }
//    printf("total primes %d\n",j+1);
}

int main(void)
{
//    freopen("out.txt","w+",stdout);
    seive();
    int val,i,j,div,pos,var;

    while(scanf("%d",&val)==1 && val)
    {
        for(i=0,div=val,pos=0;prime[i]<=val;i++,div=val,pos++)
        {
            store[pos]=0;
            while(div)
            {
                var=div/prime[i];
                store[pos]+=var;
                div=var;
            }
//            printf("store[%d]= %d ___ %d\n",pos,store[pos],prime[i]);
        }
        printf("%3d! =",val);
        for(i=0;i<pos;i++)
        {
            if(i==15) printf("\n      ");
            printf("%3d",store[i]);
        }
        putchar('\n');
    }

}
