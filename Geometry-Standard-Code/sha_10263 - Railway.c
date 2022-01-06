#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PRECS 0.0000001
#define MAX 100
#define typ double
struct point
{
    typ x,y;
}corners[MAX];
struct
{
    double x,y;
}new_vct,intersect;

point MV(point a,point b)
{
    point temp;
    temp.y=b.y - a.y;
    temp.x=b.x - a.x;

    return temp;
}
typ dot(point vct1,point vct2)
{
    typ temp=vct1.x * vct2.x + vct1.y * vct2.y;
    return temp;
}
typ cross(point vct1,point vct2)
{
    typ temp=vct1.x*vct2.y - vct1.y*vct2.x;
    return temp;
}
double length(point a,point b)
{
    double temp=sqrt(pow(a.x-b.x,2) + pow(a.y-b.y,2));
    return temp;
}
int main(void)
{
//    freopen("in.in","r",stdin);
//    freopen("out.out","w",stdout);

    point m,vct1,vct2,vct3,vct4;
    typ c1,c2,c_cros;
    int n,i;
    double dist,d1,len,width,unit;
    bool flag;
    while(scanf("%lf %lf",&m.x,&m.y)==2)
    {
        scanf("%d",&n);
        n=2*n +2;
        n/=2;

        for(i=0;i<n;i++) scanf("%lf %lf",&corners[i].x,&corners[i].y);

        for(i=0,flag=0;i<n-1;i++,flag=0)
        {
            vct1=MV(corners[i],corners[i+1]);
            vct2=MV(corners[i],m);
            c1=dot(vct1,vct2);
            vct3=MV(corners[i+1],corners[i]);
            vct4=MV(corners[i+1],m);
            c2=dot(vct3,vct4);


            if((c1>0 && c2>0) || (c1==0.0 || c2==0.0))
            {
                c_cros=fabs(cross(vct1,vct2));//printf("cross %lf  ",c_cros);   //a cross b = ab *sin(ang)
                len=length(corners[i],corners[i+1]);// printf("len %lf\n",len);//dist of a
                d1=c_cros/len;//printf("1st d1 %lf\n",d1);
                if(i==0) {dist=d1;flag=1;}
                else if((dist-d1) >PRECS) {dist=d1;flag=1;}
            }
            else if(c1>0 && c2<0)  //point is closer to c2
            {
                d1=length(corners[i+1],m);//printf("2nd d1 %lf\n",d1);
                if(i==0) {dist=d1;flag=1;}
                else if((dist-d1) >PRECS) {dist=d1;flag=1;}
            }
            else if(c1<0 && c2>0)  //point is closer to c1
            {
                d1=length(corners[i],m);//printf("3rd d1 %lf\n",d1);
                if(i==0) {dist=d1;flag=1;}
                else if((dist-d1) >PRECS) {dist=d1;flag=1;}
            }
            if(flag)  //if flag==1 then find the intersecting points
            {
                if(c1<0 && c2>0) {intersect.x = corners[i].x ;intersect.y = corners[i].y;}
                else if(c1>0 && c2<0) {intersect.x = corners[i+1].x ;intersect.y = corners[i+1].y;}
                else if((c1>=0 && c2>=0))
                {
                    width=c1/len;
                    unit=width/len;
                    new_vct.x=unit*vct1.x;new_vct.y=unit*vct1.y;
                    intersect.y=corners[i].y + new_vct.y;
                    intersect.x=corners[i].x + new_vct.x;
                }
                //printf("distance %lf || x %lf y %lf\n",dist,intersect.x,intersect.y);
            }
        }
        printf("%.4lf\n%.4lf\n",intersect.x,intersect.y);
    }
    return 0;
}
