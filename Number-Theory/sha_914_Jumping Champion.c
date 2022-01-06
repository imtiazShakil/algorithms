#include <stdio.h>
#define sz  1000007
bool num[sz];
int prime[80000];
int freq[80000];
int digit[120];
void seive(void)
{
    prime[0]=2;
    freq[0]=0;
    int i,j=0,k,max=0,diff;
    for(i=3;i<sz;i+=2)
    {
        if(!num[i])
        {
            prime[++j]=i;
            diff=prime[j]-prime[j-1];
            freq[j]=diff;
//            if(diff>max) {max=diff;printf("max %d\n",max);}
            if(i<sz/i) for(k=i*i;k<sz;k+=i) num[k]=true;
        }
    }
//    printf("total prime %d  %d\n",j+1,prime[j]);

}
int main(void)
{
    seive();
    int low,high,mid,loop,ul,ll,index_ll,index_ul,max;
    scanf("%d",&loop);
    while(loop--)
    {
        scanf("%d %d",&ll,&ul);
        low=0;high=78498;mid=(low+high)/2;

        while(prime[mid]!=ll && high>low)
        {
            if(prime[mid]>ll)
            {
                high=mid-1;
                mid=(low+high)/2;
            }
            else
            {
                low=mid+1;
                mid=(low+high)/2;
            }
        }

        index_ll=mid;
        if(prime[index_ll]<ll) index_ll++;
//        printf("lower limit prime[%d] = %d\n",index_ll,prime[index_ll]);

        low=0;high=78498;mid=(low+high)/2;
        while(prime[mid]!=ul && high>low)
        {
            if(prime[mid]>ul)
            {
                high=mid-1;
                mid=(low+high)/2;
            }
            else
            {
                low=mid+1;
                mid=(low+high)/2;
            }
        }
        index_ul=mid;
        if(prime[index_ul] > ul) index_ul--;
//        printf("upper limit prime[%d] = %d\n",index_ul,prime[index_ul]);

        if(index_ll==index_ul)  {printf("No jumping champion\n");continue;}

        int i,ans;
        bool flag,flag2;
        for(i=0;i<120;i++) digit[i]=0;
        for(i=index_ll+1,max=0;i<=index_ul;i++)
        {
            digit[freq[i]]++;
            if(max<digit[freq[i]]) max=digit[freq[i]];
        }
        for(i=1,flag=0,flag2=0;i<120;i++)
        {
            if(max==digit[i] && flag==0)
            {
                ans=i;
                flag=1;
            }
            else if(max==digit[i] && flag)
            {
                flag2=1;
            }
        }
        if(flag2) {printf("No jumping champion\n");continue;}
        else printf("The jumping champion is %d\n",ans);

    }

}
