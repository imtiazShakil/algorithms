#include <stdio.h>
#include <string.h>

char str[1000];
char tmp[1000];
int store[400][10];

void gen(void)
{
//    store[0][1]=1;
    str[0]='1';
    store[1][1]=1;
    int i,j,k,len,count,rem;
    for(i=2;i<400;i++)
    {
        len=strlen(str);
        memset(tmp,0,sizeof(char));

        for(j=0,rem=0,k=0;j<len;j++)
        {
            count=(str[j]-'0')*i + rem;
            rem=count/10;
            count%=10;
            store[i][count]++;
            tmp[k++]=count + '0';
        }
        while(rem)
        {
            count=rem%10;
            store[i][count]++;
            rem/=10;
            tmp[k++]=count + '0';

        }
        strcpy(str,tmp);
//        printf("%s\n",str);
    }
}
int main(void)
{
    gen();
    int fact;
    while(scanf("%d",&fact)==1 && fact)
    {
        printf("%d! --\n",fact);
        printf("   (0)%5d    (1)%5d    (2)%5d    (3)%5d    (4)%5d\n",store[fact][0],store[fact][1],store[fact][2],store[fact][3],store[fact][4] );
        printf("   (5)%5d    (6)%5d    (7)%5d    (8)%5d    (9)%5d\n",store[fact][5],store[fact][6],store[fact][7],store[fact][8],store[fact][9] ) ;
    }
}
