#include <stdio.h>


#define infinite 2000000001
#define typ long long
typ store[5900];
typ check[5900][5];
short low[5900];
int main(void)
{
//    freopen("in.in","r",stdin);
//    freopen("out.out","w+",stdout);

    int i,j,k,start=0,end=0,item,index;
    typ min;
    store[0]=1;
    check[0][0]=2;check[0][1]=3;check[0][2]=5;check[0][3]=7;check[0][4]=2;low[0]=0;
    for(item=1;item<5843;item++)
    {
        for(i=start,min=infinite;i<=end;i++)
        {
            if(min==check[i][4])
            {
                low[i]++;
                if(low[i]>3) {start++;}
                else check[i][4]=check[i][low[i]];
            }
            if(min>check[i][4])
            {
                min=check[i][4];
                index=i;
            }

        }
        store[item]=min;
//        printf("store[%d] = %d \n",item,store[item]);
        end++;
        check[end][0]=min*2;check[end][1]=min*3;check[end][2]=min*5;check[end][3]=min*7;check[end][4]=check[end][0];low[end]=0;

        low[index]++;
        if(low[index]>3) {start++;}
        else check[index][4]=check[index][low[index]];

    }

    int val,num;
    while(scanf("%d",&val) && val)
    {
        num=val%10;
//        if(val>=10 && val<=20) {printf("The %dth humble number is %lld.\n",val,store[val-1]);continue;}
        if((val%100)/10==1) {printf("The %dth humble number is %lld.\n",val,store[val-1]);continue;}

        if(num==1) {printf("The %dst humble number is %lld.\n",val,store[val-1]);continue;}
        else if(num==2) {printf("The %dnd humble number is %lld.\n",val,store[val-1]);continue;}
        else if(num==3) {printf("The %drd humble number is %lld.\n",val,store[val-1]);continue;}
        else {printf("The %dth humble number is %lld.\n",val,store[val-1]);continue;}

//        printf("store[%d] = %lld \n",val,store[val-1]);
//        cout << "store " << val << " =   " << store[val-1] << endl ;
    }

}
