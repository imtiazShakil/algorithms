#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
using namespace std;

struct Point{
    double x,y;
    Point(double x=0,double y=0):x(x),y(y){}
};
typedef Point Vector;
Vector operator + (Vector A,Vector B){return Vector(A.x+B.x,A.y+B.y);}
Vector operator - (Vector A,Vector B){return Vector(A.x-B.x,A.y-B.y);}
Vector operator * (Vector A,double p){return Vector(A.x*p,A.y*p);}
Vector operator / (Vector A,double p){return Vector(A.x/p,A.y/p);}
bool operator <(const Point& a, const Point& b)
{
    return a.x<b.x||(a.x==b.x&&a.y<b.y);
}
const double eps=1e-10;
int dcmp(double x)
{
    if(fabs(x)<eps)return 0;else return x<0?-1:1;
}
bool operator==(const Point& a,const Point &b)
{
    return dcmp(a.x-b.x)==0&&dcmp(a.y-b.y)==0;
}
double Dot(Vector A, Vector B){return A.x*B.x+A.y*B.y;}
double Length(Vector A){return sqrt(Dot(A,A));}
double Angle(Vector A,Vector B){return acos(Dot(A,B)/Length(A)/Length(B));}
double Cross(Vector A,Vector B){return A.x*B.y-A.y*B.x;}
double Area2(Point A,Point B,Point C){return Cross(B-A,C-A);}
Vector Rotate(Vector A,double rad)
{
    return Vector(A.x*cos(rad)-A.y*sin(rad),A.x*sin(rad)+A.y*cos(rad));
}
Vector Normal(Vector A)
{
    double L=Length(A);
    return Vector(-A.y/L,A.x/L);
}


Point GetLineIntersection(Point P,Vector v,Point Q,Vector w)
{
    Vector u=P-Q;
    double t=Cross(w,u)/Cross(v,w);
    return P+v*t;
}
double DistanceToLine(Point P,Point A,Point B)
{
    Vector v1=B-A,v2=P-A;
    return fabs(Cross(v1,v2)/Length(v1));
}
double DistanceToSegment(Point P,Point A,Point B)
{
    if(A==B)return Length(P-A);
    Vector v1=B-A,v2=P-A,v3=P-B;
    if(dcmp(Dot(v1,v2))<0)return Length(v2);
    else if(dcmp(Dot(v1,v3))>0)return Length(v3);
    else return fabs(Cross(v1,v2)/Length(v1));
}
Point GetLineProjection(Point P,Point A,Point B)
{
    Vector v=B-A;
    return A+v*(Dot(v,P-A)/Dot(v,v));
}
bool SegmentProperIntersection(Point a1,Point a2,Point b1,Point b2)
{
    double c1=Cross(a2-a1,b1-a1),c2=Cross(a2-a1,b2-a1),c3=Cross(b2-b1,a1-b1),c4=Cross(b2-b1,a2-b1);
    return dcmp(c1)*dcmp(c2)<0&&dcmp(c3)*dcmp(c4)<0;
}
bool OnSegment(Point p,Point a1,Point a2)
{
    return dcmp(Cross(a1-p,a2-p))==0&&dcmp(Dot(a1-p,a2-p))<0;
}


double ConvexPolygonArea(Point* p,int n)
{
    double area=0;
    for(int i=1;i<n-1;i++)
        area+=Cross(p[i]-p[0],p[i+1]-p[0]);
    return area/2;
}


const int maxn=1e2+10;
int ConvexHull(Point *p,Point *ch,int n)
{
    sort(p,p+n);
    int i,m=0,k;
    for(i=0;i<n;i++)
    {
        while(m>1&&Cross(ch[m-1]-ch[m-2],p[i]-ch[m-2])<=0)m--;
        ch[m++]=p[i];
    }
    k=m;
    for(i=n-2;i>=0;i--)
    {
        while(m>k&&Cross(ch[m-1]-ch[m-2],p[i]-ch[m-2])<=0)m--;
        ch[m++]=p[i];
    }
    if(n>1)m--;
    return m;
}

//if(ConvexHullIntersection(ch1,t1,ch2,t2)&&ConvexHullIntersection(ch2,t2,ch1,t1))printf("YES\n");else printf("NO\n");
bool ConvexHullIntersection(Point *ch1,int t1,Point *ch2,int t2)
{
    double angle[maxn],x;
    int i,j,k,m;
    if(t1==1)return true;
    if(t1==2)
    {
        for(i=0;i<t2;i++)
        {
            k=dcmp(Cross(ch1[1]-ch1[0],ch2[i]-ch1[0]));
            if(k==0&&Dot(ch1[1]-ch1[0],ch2[i]-ch1[0])>0)
            {
                if(Length(ch2[i]-ch1[0])<Length(ch1[1]-ch1[0]))break;
            }
        }
        if(i<t2)return false;
        if(t2==2&&SegmentProperIntersection(ch1[0],ch1[1],ch2[0],ch2[1]))return false;
        return true;
    }

    angle[0]=0;
    for(i=2;i<t1;i++)
    angle[i-1]=Angle(ch1[1]-ch1[0],ch1[i]-ch1[0]);
    for(i=0;i<t2;i++)
    {
        j=dcmp(Cross(ch1[1]-ch1[0],ch2[i]-ch1[0]));
        if(j<0||(j==0&&Dot(ch1[1]-ch1[0],ch2[i]-ch1[0])<0))continue;
        j=dcmp(Cross(ch1[t1-1]-ch1[0],ch2[i]-ch1[0]));
        if(j>0||(j==0&&Dot(ch1[t1-1]-ch1[0],ch2[i]-ch1[0])<0))continue;
        x=Angle(ch1[1]-ch1[0],ch2[i]-ch1[0]);
        m=lower_bound(angle,angle+t1-1,x)-angle;
        if(m==0)j=0;
        else j=m-1;
        k=dcmp(Cross(ch1[j+1]-ch2[i],ch1[j+2]-ch2[i]));
        if(k>=0)break;
    }
    if(i<t2)return false;
    return true;
}

Point p1[maxn],ch1[maxn],p2[maxn],ch2[maxn];
int n,m,t1,t2;
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(n==0&&m==0)break;
        int i,j,k;
        for(i=0;i<n;i++)
            scanf("%lf%lf",&p1[i].x,&p1[i].y);
        for(i=0;i<m;i++)
            scanf("%lf%lf",&p2[i].x,&p2[i].y);
        t1=ConvexHull(p1,ch1,n);
        t2=ConvexHull(p2,ch2,m);
        if(ConvexHullIntersection(ch1,t1,ch2,t2)&&ConvexHullIntersection(ch2,t2,ch1,t1))printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}

/*
4 1
0 0 2 0 2 2 0 2
0 3
*/

