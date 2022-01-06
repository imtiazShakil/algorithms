#include <stdio.h>
#define SZ 10000001

//int prime[670000];
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
bool check(int odd,int even)
{
    if(even%2) {odd^=even^=odd^=even;}
    if(num[odd-2]) return false;

    return true;
}
bool check2(int a,int b)
{
    if(!num[a] && !num[b]) return true;

    return false;
}
int main(void)
{
    seive();
    int n;bool flag,flag2;
    int p,q,a,b,store;
    while(scanf("%d",&n)==1)
    {
        if(n<8) {printf("Impossible.\n");continue;}
        if(n%2)
        {
            for(p=n/2,q=n-p,flag=0;p>1 && q>1;p++,q--)
            {
                if(check(p,q)) {flag=1;break;}
            }
            if(flag)
            {

                if(p%2) {printf("2 %d ",p-2);a=q;}
                else {printf("2 %d ",q-2);a=p;}

                if(!num[a/2]) printf("%d %d\n",a/2,a/2);
                else for(p=a/2-1,q=a/2+1; ;p--,q++)
                {
                    if(check2(p,q)) {printf("%d %d\n",p,q);break;}
                }

                continue;
            }
            else  {printf("Impossible.\n");continue;}


        }
        else
        {
            p=n/2;q=p;store=p;
            if(p%2)
            {
                if(check(p,q)) {printf("2 2 %d %d\n",p-2,q-2);continue;}
                p--;q++;
                if(q<3 || p<3) {printf("Impossible.\n");continue;}
                flag=1;
                if(!num[p/2]) printf("%d %d ",p/2,p/2);
                else
                for(a=p/2-1,b=p/2 +1,flag=0; a>1 && b>1 ;a--,b++)
                {
                    if(check2(a,b)) {printf("%d %d ",a,b);flag=1;break;}
                }
                if(flag==0) {printf("Impossible.\n");continue;}


                flag=1;
                if(!num[q/2]) printf("%d %d ",q/2,q/2);
                else for(a=q/2-1,b=q/2 +1,flag=0; a>1 && b>1 ;a--,b++)
                {
                    if(check2(a,b)) {printf("%d %d\n",a,b);flag=1;break;}
                }
                if(flag==0) {printf("Impossible.\n");continue;}

            }
            else
            {
                if(!num[p/2]) {printf("%d %d %d %d\n",p/2,p/2,p/2,p/2);continue;}
                flag=1;
                for(p=store/2-1,q=store/2 +1,flag=0;p>1 && q>1 ;p--,q++)
                {
                    if(check2(p,q)) {printf("%d %d %d %d\n",p,p,q,q);flag=1;break;}
                }
                if(flag==0) {printf("Impossible.\n");continue;}


            }
        }
    }
}
