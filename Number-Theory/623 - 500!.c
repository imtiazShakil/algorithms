#include <stdio.h>
#include <string.h>

char str[1020][3001];
char temp[3000];

void gen_fact()
{
    str[0][0]='1';
    str[1][0]='1';
    str[2][0]='2';
    int i,len,j,k,num,count,mod,pos;
    for(i=3;i<1005;i++)
    {
        len=strlen(str[i-1]);
        memset(temp,0,sizeof(temp[0]));
//        printf("temp %s len[prev] %d\n",temp,len);
        for(j=len-1,mod=0,pos=0;j>=0;j--)
        {
            count=(str[i-1][j] - '0')*i + mod;
            mod=count/10;
            count%=10;
            temp[pos++]=count + '0';
        }
        while(mod)
        {
            count=mod%10;
            temp[pos++]=count + '0';
            mod/=10;
        }

        for(j=0,k=pos-1;k>=0;k--,j++) str[i][j]=temp[k];
//        printf("%s\n",str[i]);

    }
}
int main(void)
{
    gen_fact();
    int val;
    while(scanf("%d",&val)==1)
    {
        printf("%d!\n",val);
        printf("%s\n",str[val]);
    }
}
