#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <ctype.h>
using namespace std;

int cost[30];
bool possibile[300];

int main(void)
{
    possibile[0]=1;
    char str[1000];
    char tmp[1000];
    cost[0]=0;
    int loop,i,j,len,pos,arr_sz,sum;
    scanf("%d ",&loop);
    while(loop--)
    {
        gets(str);//puts(str);
        len=strlen(str);
        memset(tmp,0,sizeof(tmp));
        for(i=0,sum=0,arr_sz=0,pos=0;i<len;i++)
        {

            if(isspace(str[i]))
            {
                cost[arr_sz++]=atoi(tmp);
                sum+=cost[arr_sz-1];
                memset(tmp,0,sizeof(tmp));
                pos=0;
            }
            else
            {
                tmp[pos++]=str[i];
            }

            if(i+1==len)
            {
//                int num=atoi(tmp);
//                printf("num %d\n",num);
                cost[arr_sz++]=atoi(tmp);
                sum+=cost[arr_sz-1];
                memset(tmp,0,sizeof(tmp));
                pos=0;
            }
        }
//        printf("total %d\n",sum);
        if(sum%2)
        {
            puts("NO");
            continue;
        }
        for(i=1;i<250;i++) possibile[i]=0;

        ///susdet sum starts here
        for(i=0;i<arr_sz;i++)
        {
            for(j=sum;j>=0;j--)
            {
                if(possibile[j])
                {
                    possibile[j+cost[i]]=1;
                }
            }
        }
//        printf("sum %d possibility %d\n",sum,possibile[sum/2]);
        if(possibile[sum/2]) puts("YES");
        else puts("NO");
//        printf("loop %d\n",loop+1);
    }
}
