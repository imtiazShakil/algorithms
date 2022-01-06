#include <stdio.h>
#include <math.h>
#include <algorithm>
#define typ long long
using namespace std;

typ divisor[1000];

int com(const void *a,const void *b)
{
    typ *x=(typ *)a;
    typ *y=(typ *)b;

    return *x-*y;
}

typ lcm_find(typ a,typ b)
{
    typ smal=a,larg=b,temp,ans,prod=a*b;

    if(smal>larg) {smal^=larg^=smal^=larg;}
    while(larg%smal)
    {
        temp=larg%smal;
        larg=smal;
        smal=temp;
    }
    ans=prod/smal;

    return ans;
}
int main(void)
{
    int ans,rt;
    int pos,i,count,j;
    typ val;
    divisor[0]=1;
    while(scanf("%lld",&val)==1 && val)
    {
        if(val==1) {printf("1 1\n");continue;}
        pos=1,count=2;
        rt=sqrt(val)+1;
        for(i=2;i<rt;i++)
        {
            if(!(val%i))
            {
                divisor[pos++]=i;
                if(val/i != i ) divisor[pos++]=val/i;
            }
        }
        divisor[pos]=val;//printf("pos %d\n",pos);
        qsort(&divisor[1],pos-1,sizeof(divisor[0]),com);
//        for(i=0;i<=pos;i++) printf("%lld ",divisor[i]);
//        putchar('\n');
        if(pos==1) {printf("%lld 2\n",val);continue;}
        for(i=1;i<pos;i++)
        {
            for(j=pos;j>i;j--)
            {
                if(divisor[i]*divisor[j]<val) break;

                if(lcm_find(divisor[i],divisor[j])== val) count++;//printf("pair %lld %lld count %d\n",divisor[i],divisor[j],count);}

            }
        }
//        printf("count %d\n",count);
        printf("%lld %d\n",val,count);
    }
}
