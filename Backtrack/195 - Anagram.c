#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <ctype.h>

#define MAX 100
using namespace std;

int com(const void *a,const void *b)
{
    char *x=(char *)a;
    char *y=(char *)b;

    char ch=toupper(*x),ch2=toupper(*y);
    if(ch!=ch2) return ch-ch2;

    return *x-*y;
}



char txt[MAX];
char sol[MAX];
bool color[MAX];



void BT(int depth,int stop)
{
    int i;
    if(depth==stop)
    {
        printf("%s\n",sol);
        return ;
    }
    for(i=0;i<stop;i++)
    {
        //if(i-1>-1) if(txt[i]==txt[i-1]) continue;
        if(color[i])
        {
            if(i-1>-1) if(color[i-1]) if(txt[i]==txt[i-1]) continue;
            sol[depth]=txt[i]; color[i]=false;
            BT(depth+1,stop);
            color[i]=true;
        }


    }

    return ;
}
int main(void)
{
    int loop,len,i;
    scanf("%d",&loop);
    while(loop--)
    {


        memset(sol,0,sizeof sol);
        memset(color,true,sizeof color);


        scanf("%s",txt);
        len=strlen(txt);

        qsort(txt,len,sizeof(char),com);

        //printf("sorted %s\n",txt);

        BT(0,len);
        //putchar('\n');


    }
}


