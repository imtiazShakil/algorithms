#include <stdio.h>
#include <math.h>

//#define SZ 10000001
//short divisor[SZ];
//
//void gen_div(void)
//{
//    int i=2,val,j;
//    for(i=2;i<SZ;i++)
//    {
//        divisor[i]=2;
//        for(j=2,val=sqrt(i)+1;j<val;j++)
//        {
//            if(i%j) continue;
//            else
//            {
//                if(i/j==j) divisor[i]++;
//                else divisor[i]+=2;
//
//            }
//        }
////        printf("divisor[%d] = %d\n",i,divisor[i]);
//    }
//    return ;
//}

int get_div(int num)
{
    if(num==1) return 1;
    int val=sqrt(num)+1;
    int ans=2,i;
    for(i=2;i<val;i++)
    {
        if(num%i) continue;
        else
        {
            if(num/i==i) ans++;
            else ans+=2;
        }
    }
    return ans;
}
int main(void)
{
    int ul,ll,loop,i,max,val,j;
    scanf("%d",&loop);
    while(loop--)
    {
        scanf("%d %d",&ll,&ul);
        for(i=ll,max=0;i<=ul;i++)
        {
            j=get_div(i);
            if(max<j) {max=j;val=i;}
        }

        printf("Between %d and %d, %d has a maximum of %d divisors.\n",ll,ul,val,max);
    }
}
