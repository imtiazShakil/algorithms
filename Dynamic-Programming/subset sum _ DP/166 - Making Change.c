#include <stdio.h>
#define SZ 20000
#define inf 1000000

int seller[SZ];
int buyer[SZ];

int main(void)
{
//    freopen("in_166.txt","r",stdin);
//    freopen("out_166.txt","w+",stdout);

    int i,j,given_cn[6],total_money,money,min;
    double mon;
    int cn[]={5,10,20,50,100,200};
    for(i=0;i<SZ;i+=5) buyer[i]=inf;
    buyer[0]=0;
    seller[0]=0;

    for(i=0;i<6;i++)
    {
        for(j=0;j<SZ;j+=5)
        {
            if(j+cn[i]<SZ) if( buyer[j]+1 < buyer[j+cn[i]] ) buyer[j+cn[i]]=buyer[j]+1;
        }
    }
//    for(i=0;i<SZ;i+=5) printf("buyer %d %d\n",i,buyer[i]);

    while(scanf("%d %d %d %d %d %d",&given_cn[0],&given_cn[1],&given_cn[2],&given_cn[3],&given_cn[4],&given_cn[5])==6 &&(given_cn[0] || given_cn[1] || given_cn[2] || given_cn[3] || given_cn[4] || given_cn[5] ) )
    {
        scanf("%lf",&mon);
        mon*=100;//printf("%lf\n",mon);

        money=mon+1e-5;

//        printf("money %d\n",money);

        for(i=0,total_money=0;i<6;i++)
        {
            total_money+= (cn[i]*given_cn[i]);
        }

        for(i=0;i<SZ;i+=5) seller[i]=inf;
        seller[0]=0;

        for(i=0;i<6;i++)
        {
            while(given_cn[i])
            {
                for(j=total_money;j>=0;j-=5)
                {
                    if(seller[j]==inf) continue;
                    if(j+cn[i]<SZ) if( seller[j] +1 < seller[j+cn[i]] )  seller[j+cn[i]]=seller[j] +1;
                }
                --given_cn[i];
            }
        }
//        for(i=0;i<=total_money;i+=5) printf("seller %d %d\n",i,seller[i]);
//        printf("total money %d\n",total_money);
        for(i=money,min=inf;i<=total_money;i+=5)
        {
            if(seller[i]==inf) continue;
            if(seller[i] + buyer[i-money] < min )
            {
                min=seller[i] + buyer[i-money];
//                printf("min %d seller[%d] = %d buyer[%d] = %d\n",min,i,seller[i],i-money,buyer[i-money]);
            }
        }
        printf("%3d\n",min);

    }

}
