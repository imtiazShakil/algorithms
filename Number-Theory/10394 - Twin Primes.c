#include <stdio.h>
#define SIZE 19000000

bool num[SIZE];
int prev;
int pair[104000][2];

void seive()
{
    prev=2;
    int i,j,pos=1;
    for(i=3;i<SIZE;i+=2)
    {
        if(!num[i])
        {
            if((i-prev)==2) {pair[pos][0]=prev;pair[pos][1]=i;pos++;}
            prev=i;
            if(i<SIZE/i) for(j=i*i;j<SIZE;j+=i) num[j]=true;
        }
    }
//    printf("total pair %d pair %d %d \n",pos-1,pair[pos-1][0],pair[pos-1][1]);
}
int main(void)
{
    seive();
    int pos;
    while(scanf("%d",&pos)==1)
    {
        printf("(%d, %d)\n",pair[pos][0],pair[pos][1]);
    }
}
