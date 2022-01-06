#include <stdio.h>
#include <iostream>
using namespace std;

#define sz 10002
int store[sz];
void gen(void)
{
    store[0]=1;
    store[1]=1;
//    long long val=1;
    long long  i,count,next,rem,val=1;
    for(i=2;i<sz;i++)
    {
        val*=i;
        val%=100000000;
        while((val%10)==0)
        {
            val/=10;
        }
        count=val%10;
        store[i]=count;


    }
}
int main(void)
{
    gen();
    int fact;
    while(scanf("%d",&fact)==1)
    {
        printf("%5d -> %d\n",fact,store[fact]);
    }
}
