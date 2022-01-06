#include <stdio.h>
#include <algorithm>
#include <math.h>
#define dbl double
#define PRECS 0.00001
#define typ long long
using namespace std;

struct point
{
    typ x;
    typ y;
} val[1500],pivot,stack[1500];

typ cross(point vct1,point vct2)
{
    typ temp=vct1.x * vct2.y - vct1.y * vct2.x;
    return temp;
}
dbl len(point a,point b)
{
    dbl temp;
    temp=sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
    return temp;
}
point MV(point a,point b)
{
    point temp;
    temp.x=b.x-a.x;
    temp.y=b.y-a.y;

    return temp;
}
int com(const void *a ,const void *b)
{
    point *x=(point *)a;
    point *y=(point *)b;
    dbl c,dist1,dist2;
    point vct1=MV(pivot,*x);point vct2=MV(pivot,*y);

    c=cross(vct1,vct2);
    if(c>0.0) return -1;
    else if(c<0.0) return 1;
    else
    {
        dist1=len(pivot,*x);
        dist2=len(pivot,*y);
        if(dist1>dist2) return 1;
        else return -1;
    }
    return 0;
}
int main(void)
{
    //freopen("in.in","r",stdin);
    int n,i,low,top,j=1,loop;
    dbl ans,ribn,c;
    point temp,vct1,vct2;
//    bool flag=0;
    scanf("%d",&loop);
    while(loop--)
    {
        scanf("%lf %d",&ribn,&n);
        for(i=0;i<n;i++) scanf("%lld %lld",&val[i].x,&val[i].y);


        pivot=val[0];
        for(i=1,low=0;i<n;i++)
        {
            if(pivot.y>val[i].y) {pivot=val[i];low=i;continue ;}
            if(pivot.y<val[i].y) continue;
            if(pivot.y==val[i].y) if(pivot.x>val[i].x) {pivot=val[i];low=i;}
        }

        val[low]=val[0];val[0]=pivot;

        qsort(val,n,sizeof (point),com);
//        puts("****sorted******");for(i=0;i<n;i++) printf("%d %d\n",val[i].x,val[i].y);
        stack[0]=pivot;
        stack[1]=val[1];
        for(i=2,top=1;i<n;)
        {
            if(top<=0)
            {
                stack[++top]=val[i];i++;continue;
            }
            vct1=MV(stack[top-1],stack[top]);
            vct2=MV(stack[top],val[i]);

            c=cross(vct1,vct2);
            if(c>0){stack[++top]=val[i];i++;continue;}
            else  {top--;continue;}

        }

        stack[++top]=stack[0];

//        puts("____stack____");
//        for(i=0;i<=top;i++) printf("%d %d\n",stack[i].x,stack[i].y);


        for(i=0,ans=0.0;i<top;i++) ans += len(stack[i],stack[i+1]);

        if(ans-ribn>PRECS) printf("%.5lf\n",ans);
        else printf("%.5lf\n",ribn);

    }
}
