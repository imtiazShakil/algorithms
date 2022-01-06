#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <ctype.h>

#define MAX 50
using namespace std;

int com(const void *a,const void *b)
{
    char *x=(char *)a;
    char *y=(char *)b;

    return *x-*y;
}

//int com2(const void *a,const void *b)
//{
//    char *x=(char *)a;
//    char *y=(char *)b;
//
//    return strcmp(x,y);
//}

//int fact(int num)
//{
//    int result=1,i;
//    for(i=2;i<=num;i++) result*=i;
//    return result;
//}

char txt[MAX];
char sol[MAX];
bool color[20];

//struct
//{
//    char string[MAX];
//    bool flag;
//}all_sol[3628800];
//
//int index;

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
//        index=0;

        memset(sol,0,sizeof sol);
        memset(color,true,sizeof color);
//        memset(all_sol,0,sizeof (all_sol));

        scanf("%s",txt);
        len=strlen(txt);
//        for(i=0;i<len;i++) srt[i]=str[i];
//
//        qsort(srt,len,sizeof(int),com);
//
//        for(i=0;i<len;i++) str[i]=srt[i];
        qsort(txt,len,sizeof(char),com);
        //puts(str);

        //for(int i=0;i<4;i++) printf("%d",str[i]);
        BT(0,len);
        putchar('\n');
//        int fct=fact(len);

//        for(i=0;i<fct;i++) printf("%s\n",all_sol[i].string);
//        puts("_________sorted__________");
//        for(i=0;i<fct;i++)
//        {
//            if(!strcmp(all_sol[i].string,all_sol[i+1].string)) ;
//            else printf("%s\n",all_sol[i]);
//
//        }
//        puts("_________sorted__________");
//        putchar('\n');
//        qsort(all_sol,fct,sizeof (char) * MAX,com2);
//        for(i=0;i<fct;i++)
//        {
//            if(!strcmp(all_sol[i],all_sol[i+1])) ;
//            else printf("%s\n",all_sol[i]);
//        }

    }
}





