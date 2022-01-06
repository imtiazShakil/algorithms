#include <stdio.h>
#include <string.h>

#define SIZE 900000000

bool num[SIZE];
int max;
void ugly(void)
{
    int i,count=1,count2=0,j,store;
//    memset(num,0,sizeof(bool));
    num[1]=true;
    /*
    for(i=1;i<7;i++) num[i]=true;
    num[8]=true;
    num[9]=true;
    num[10]=true;
    num[12]=true;
    num[15]=true;
    */
    bool flag1=1,flag2=1,flag3=1;
    for(i=1;count2<15;i++)
    {
//        if (i>(SIZE/5)) break;
        if(num[i] )
        {
            count2++;
//            if(num[2*i]==0) {count++;printf("num %d true %d count %d\n",2*i,num[2*i],count);}
//            if(num[3*i]==0) {count++;printf("num %d true %d count %d\n",3*i,num[3*i],count);}
//            if(num[5*i]==0) {count++;printf("num %d true %d count %d\n",5*i,num[5*i],count);}
            if(flag2)
            {
                if(i<(SIZE/3)) num[3*i]=true;
                else flag2=0;
            }
            if(flag3)
            {
                if(i<(SIZE/5)) num[5*i]=true;
                else flag3=0;
            }
            if(flag1)
            {
                if(i<(SIZE/2)) num[2*i]=true;
                else flag2=0;
            }
            printf("num %d true %d count2 %d\n",i,num[i],count2);

        }
    }

}


int main(void)
{
    ugly();
    long long  i;
    int c=0;




//    printf("The 1500'th ugly number is %lld.\n",i-1);
}
