#include <stdio.h>
#define SZ 10000001


bool num[SZ];
void seive()
{
    int i,k;num[1]=true;
//    prime[0]=2;
    for(i=4;i<SZ;i+=2) num[i]=true;
    for(i=3;i<SZ;i+=2)
    {
        if(!num[i])
        {
//            prime[j++]=i;
            if(i<SZ/i) for(k=i*i;k<SZ;k+=i) num[k]=true;
        }
    }
//    printf("tot %d %d\n",j,prime[j-1]);

}
bool check2(int a,int b)
{
    if(!num[a] && !num[b]) return true;

    return false;
}
int main(void)
{
    seive();
    int n,a,b;
    while(scanf("%d",&n)==1)
    {
        if(n<8) {printf("Impossible.\n");continue;}
        if(n%2)
        {
            printf("2 3 ");
            n-=5;
            if(!num[n/2]) {printf("%d %d\n",n/2,n/2);continue;}
            else for(a=n/2-1,b=n/2+1; ;a--,b++)
            {
                if(check2(a,b)) {printf("%d %d\n",a,b);break;}
            }
            continue;
        }
        else
        {
            printf("2 2 ");
            n-=4;//printf("n = %d n/2 =%d %d \n",n,n/2,num[n/2]);
            if(!num[n/2]) {printf("%d %d\n",n/2,n/2);continue;}
            else for(a=n/2-1,b=n/2+1; ;a--,b++)
            {
                if(check2(a,b)) {printf("%d %d\n",a,b);break;}
            }
            continue;
        }
    }
}
