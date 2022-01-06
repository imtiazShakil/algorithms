#include <stdio.h>
#include <iostream>
#include <string.h>

int base_cas;
char str[1000];
int count;

int rec(int indx,int depth)
{
    str[depth]=indx+'0';
    puts(str);
    count++;
    for(int i=indx+1;i<=base_cas;i++)
    {
        rec(i,depth+1);
//        rec(i,depth);
    }

    str[depth]=0;
    return 1;
}
int main(void)
{
    while(scanf("%d",&base_cas)==1)
    {
        count=0;
        printf("0\n");
        for(int i=1;i<=base_cas;i++)
        {
            memset(str,0,sizeof str);
            rec(i,0);
        }
        printf("total combinations %d \n",count+1);
    }
    return 0;
}
