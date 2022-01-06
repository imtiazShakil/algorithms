#include <stdio.h>
#define SZ 1000001

int prime[80000];
bool num[SZ];

void seive()
{
    prime[0]=2;
    int i,pos=0,j;num[1]=true;
    for(i=4;i<SZ;i+=2) num[i]=true;
    for(i=3;i<SZ;i+=2)
    {
        if(!num[i])
        {
            prime[++pos]=i;
            if(i<SZ/i) for(j=i*i;j<SZ;j+=i) num[j]=true;
        }
    }
//    printf("tot %d %d\n",pos+1,prime[pos]);

}
int main(void)
{
    seive();
    int val,count,i,n;
    while(scanf("%d",&val)==1 && val)
    {
        n=val;
        count=0;
        if(!num[val]) {printf("%d : 1\n",val);continue;}

        for(i=0;val!=1;i++)
        {
            if(val%prime[i]) continue;
            else
            {
                count++;
                val/=prime[i];
//                printf("prime[%d]= %d \n",i,prime[i]);

                if(!num[val])
                {
//                    printf("val %d\n",val);
                    if(prime[i]!=val) count++;
                    break;
                }
                while(val%prime[i]==0)
                {
                    val/=prime[i];
                }
            }
        }
        printf("%d : %d\n",n,count);


    }
}
