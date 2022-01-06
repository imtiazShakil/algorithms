#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <conio.h>
#define MAXSIEVE 100000000
#define MAXSIEVEHALF (MAXSIEVE/2)
#define MAXSQRT 5000
char a[MAXSIEVE/16+2];
#define isprime(n) (a[(n)>>4]&(1<<(((n)>>1)&7)))   /// Works when n is odd

int main()
{
    int i,j,k=0,l=0;
    memset(a,255,sizeof(a));
    a[0]=0xFE;
    for(i=1;i<MAXSQRT;i++)
    {
        if (a[i>>3]&(1<<(i&7)))
        {
            k++;
            for(j=2*i*(i+1);j<MAXSIEVEHALF;j+=i+i+1)
            {
                l++;
//                a[j>>3]&= ~(1<<(j&7));
                a[j>>3]=a[j>>3] & ~(1<<(j&7));
            }
        }
    }
    printf("k= %d l =%d \n",k,l);

    while(scanf("%d",&k)==1)
    {
        int val;
        val=isprime(k);
        printf("val %d , k= %d \n",val,k);
    }

}
