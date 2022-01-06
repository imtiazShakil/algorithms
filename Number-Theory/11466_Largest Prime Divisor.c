#include <stdio.h>
#include <math.h>
//#include <stdlib.h>
//#include <iostream.h>
//using namespace std;
#define SIZE 10000001

bool num[SIZE];
int prime[700000];

void seive()
{
    prime[0]=2;
    int i,j=0,k;
//    for(i=4;i<SIZE;i+=2) num[i]=true;
    for(i=3;i<SIZE;i+=2)
    {
        if(!num[i])
        {
            prime[++j]=i;
            if(i<SIZE/i) for(k=i*i;k<SIZE;k+=i) num[k]=true;
        }
    }
//    printf("prime %d = %d \n",j+1,prime[j]);
}

int main(void)
{
    seive();
    long long val,rt,i,ans,max;
    bool flag,flag2;
    while(scanf("%lld",&val)==1 && val)
//    while(cin >> val && val)
    {
        if(val<0) val= -1*val;
        flag=0;flag2=0;max=0;
        rt=sqrt(val) +1;
        for(i=0;prime[i]<rt;i++)
        {
            if(val%prime[i]) continue;
            else
            {
//                if(flag) flag2=1;
                if(max) flag2=1;
                max=prime[i];flag=1;

                while((val%prime[i])==0)
                {
                    val/=prime[i];
                }
                rt=sqrt(val)+1;
            }
        }
        if(val>1)
        {
            if(val>max) max=val;
            if(max) flag2=1;
        }

        if(!flag) {printf("-1\n");continue;}
        if(!flag2) {printf("-1\n");continue;}
//        cout << max << endl;
        printf("%lld\n",max);
    }
}
