#include <sstream>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <string.h>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>
#include <list>
using namespace std;
#define print1(a)    cout<<a<<endl
#define print2(a,b) cout<<a<<" "<<b<<endl
#define print3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define oo          (1<<30)
#define PI          3.141592653589793
#define pi          (2.0*acos(0.0))
#define ERR         1e-5
#define PRE         1e-8
#define SZ(s)       (int)s.size()
#define LL           long long
#define ISS         istringstream
#define OSS        ostringstream
#define VS          vector<string>
#define VI          vector<int>
#define VD          vector<double>
#define VLL         vector<long long>
#define SII         set<int>::iterator
#define SI          set<int>
#define mem(a,b)    memset(a,b,sizeof(a))
#define fr(i,a,b)   for(i=a;i<=b;i++)
#define frn(i,a,b)  for(i=a;i>=b;i--)
#define fri(a,b)    for(i=a;i<=b;i++)
#define frin(a,b)   for(i=a;i>=b;i--)
#define frj(a,b)    for(j=a;j<=b;j++)
#define frjn(a,b)   for(j=a;j>=b;j--)
#define frk(a,b)    for(k=a;k<=b;k++)
#define frkn(a,b)   for(k=a;k>=b;k--)
#define frl(a,b)    for(l=a;l<=b;l++)
#define frln(a,b)   for(l=a;l>=b;l--)
#define EQ(a,b)     (fabs(a-b)<ERR)
#define all(a,b,c)  for(int I=0;I<b;I++)    a[I] = c
#define CROSS(a,b,c,d) ((b.x-a.x)*(d.y-c.y)-(d.x-c.x)*(b.y-a.y))
#define sqr(a)      ((a)*(a))
#define FORE(i,a)   for(typeof((a).begin())i=(a).begin();i!=(a).end();i++)
#define typing(j,b) typeof((b).begin()) j=(b).begin();
#define BE(a)       a.begin(),a.end()
#define rev(a)      reverse(BE(a));
#define sorta(a)    sort(BE(a))
#define pb          push_back
#define popb        pop_back
#define round(i,a)  i = ( a < 0 ) ? a - 0.5 : a + 0.5;
#define makeint(n,s)  istringstream(s)>>n
#define inpow(a,x,y) int i; a=x;fri(2,y)  a*=x
#define csprnt printf("Case %d: ", ++cas);
using namespace std;

template<class T1> void debug(T1 e){cout<<e<<endl;}
template<class T1,class T2> void debug(T1 e1,T2 e2){cout<<e1<<"\t"<<e2<<endl;}
template<class T1,class T2,class T3> void debug(T1 e1,T2 e2,T3 e3){cout<<e1<<"\t"<<e2<<"\t"<<e3<<endl;}
template<class T1,class T2,class T3,class T4> void debug(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<"\t"<<e2<<"\t"<<e3<<"\t"<<e4<<endl;}
template<class T> string toString(T n){ostringstream oss;oss<<n;oss.flush();return oss.str();}
int toInt(string s){int r=0;istringstream sin(s);sin>>r;return r;}
bool isVowel(char ch){ch=tolower(ch);if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')return true;return false;}
bool isUpper(char c){return c>='A' && c<='Z';}
bool isLower(char c){return c>='a' && c<='z';}
//*************************************************My Code Starts Here*********************************************************************************
bool quadraticequation(double a,double b,double c,double &x1,double &x2);
//all angles in radian
//normally avoid asin
//vector3d or point3d
//atan2(y,x)
#define vectorVar3d double //change should be done here for different datatype
struct vector3d{
   vectorVar3d x,y,z;
   vector3d(vectorVar3d  x1=0,vectorVar3d  y1=0,vectorVar3d  z1=0)  {  x=x1; y=y1; z=z1;  }
   int scan() { return scanf("%lf %lf %lf",&x,&y,&z); }
   int scanint()
   {
       return scanf("%d %d %d",&x,&y,&z);
   }

   int scanLL()
   {
       return scanf("%lld %lld %lld",&x,&y,&z);
   }

   vector3d negate()
   {
       vector3d ret(-x,-y,-z);
       return ret;
   }

   vectorVar3d  length()
   {
       return sqrt(x*x+y*y+z*z);
   }

   vectorVar3d sqrLength()
   {
       return x*x+y*y+z*z;
   }

   vectorVar3d  length(vector3d b)  //length from a to b
   {
       vector3d tem(x-b.x,y-b.y,z-b.z);
       return tem.length();
   }

   vector3d add(vector3d b)
   {
       vector3d ret(x+b.x,y+b.y,z+b.z);
       return ret;
   }

   vector3d substract(vector3d b)
   {
       vector3d ret(x-b.x,y-b.y,z-b.z);
       return ret;
   }

   vectorVar3d dot(vector3d b)
   {
       return x*b.x+y*b.y+z*b.z;
   }

   vector3d cross(vector3d b)
   {
       vector3d ret(y*b.z-z*b.y,z*b.x-x*b.z,x*b.y-y*b.x);
       return ret;
   }

   vector3d lengthTransform(vectorVar3d  l)  //for unit vector l=1
   {
       vectorVar3d  len=length();
       vector3d ret(x*l/len,y*l/len,z*l/len);
       return ret;
   }

   vectorVar3d angle(vector3d b)  //(0 to +pi)
   {
       vectorVar3d  ret=dot(b)/(length()*b.length());
       if(ret<-1) ret=-1;
       if(ret>1) ret=1;
       return acos(ret);
   }

   //vectorVar3d angleWithSign(vector3d b) //(-pi to +pi)  (a to b)
   //{
       //if(cross(b)>0) return angle(b);
     //  return -angle(b);
   //}
   //vector3d rotation(vectorVar3d  theta)  //under construction
   //{

   //}
};

//Vector or point2d
#define vectorVar double  //change should be done here for different datatype
struct Vector{
   vectorVar  x,y;
   Vector(vectorVar  x1=0,vectorVar  y1=0) { x=x1; y=y1;}

   int scan() { return scanf("%lf %lf",&x,&y); }
   int scanint() { return scanf("%d %d",&x,&y); }
   int scanLL() { return scanf("%lld %lld",&x,&y); }
   void print() { print2(x,y); }

   Vector negate() { return Vector(-x,-y);}
   vectorVar length() { return sqrt(x*x+y*y);}
   vectorVar sqrLength() { return x*x+y*y; }
   vectorVar length(Vector b)  //from a to b and vice versa
   {
       Vector tem(x-b.x,y-b.y);
       return tem.length();
   }
   vectorVar angle()  //(-pi to +pi)  (for all angles)
   {
       vectorVar  ret=atan2(y,x);
       return ret;
   }
   vectorVar angle(Vector b)  //(0 to +pi)
   {
       vectorVar  ret=dot(b)/(length()*b.length());
       if(ret<-1) ret=-1;
       if(ret>1) ret=1;
       return acos(ret);
   }
   vectorVar angleWithSign(Vector b) //(-pi to +pi)  (a to b)
   {
       if(cross(b)>0) return angle(b);
       return -angle(b);
   }
   Vector add(Vector b) { return Vector(x+b.x,y+b.y); }
   Vector substract(Vector b) { return Vector(x-b.x,y-b.y); }
   vectorVar dot(Vector b) { return x*b.x+y*b.y; }
   //negative means b is clockwise to main vector
   vectorVar  cross(Vector b) { return x*b.y-b.x*y; }
   //a is fixed
   vectorVar cross(Vector a,Vector b) //now to b
   {
       Vector now;
       now=substract(a);
       b=b.substract(a);
       return now.cross(b);
   }
   //for unit vector l=1
   Vector lengthTransform(vectorVar l) { vectorVar  len=length(); return  Vector(x*l/len,y*l/len); }
   Vector rotation(vectorVar theta) { return Vector(x*cos(theta)-y*sin(theta),x*sin(theta)+y*cos(theta)); }

   Vector shortestPoint(Vector b)  //make point a vector //distance from point to line
   {
       vectorVar len=dot(b)/length();
       Vector ret=lengthTransform(len);
       if(ret.x>max(0.0,x)||ret.x<min(0.0,x))
       {
           ret.x=0;
           ret.y=0;
           if(b.length()<length(b))  return ret;
           ret.x=x;
           ret.y=y;
           return ret;
       }
       if(ret.y>max(0.0,y)||ret.y<min(0.0,y))
       {
           ret.x=0;
           ret.y=0;
           if(b.length()<length(b))  return ret;
           ret.x=x;
           ret.y=y;
           return ret;
       }
       return ret;
   }

   vectorVar shortestDist(Vector b)  //make point a vector //distance from point to line
   {
       vectorVar len=dot(b)/length();
       Vector ret=lengthTransform(len);
       if(ret.x>max(0.0,x)||ret.x<min(0.0,x))
            return min(b.length(),length(b));

       if(ret.y>max(0.0,y)||ret.y<min(0.0,y))
           return min(b.length(),length(b));
       ret=ret.substract(b);
       return ret.length();
   }
};
typedef Vector Point;
Vector operator + (Vector a, Vector b) { return Vector(a.x+b.x, a.y+b.y); }
Vector operator - (Vector a, Vector b) { return Vector(a.x-b.x, a.y-b.y); }
Vector operator * (Vector a, double p) { return Vector(a.x*p, a.y*p); }
Vector operator / (Vector a, double p) { return Vector(a.x/p, a.y/p); }
//this are used for set compare
int dcmp(double x){ //precise up to ERR
	if(fabs(x)<ERR)return 0;else return x<0?-1:1;
}
bool operator<( const Point& A,const Point& B ){return dcmp(A.x-B.x)<0||(dcmp(A.x-B.x)==0&&dcmp(A.y-B.y)<0);}
bool operator==(const Point&a,const Point&b){return dcmp(a.x-b.x)==0&&dcmp(a.y-b.y)==0;}
bool operator!=(const Point&a,const Point&b){return a==b?false:true;}

//line or segment2d
struct line{
     Vector p,q;
     line(Vector p1=0,Vector q1=0) { p=p1; q=q1; }
     void print()
     {
         printf("%.10lf %.10lf %.10lf %.10lf\n",p.x,p.y,q.x,q.y);
     }
     //ax+by+c=0;
     void equation(vectorVar &a,vectorVar &b,vectorVar &c)
     {
         a=p.y-q.y;
         b=q.x-p.x;
         c=-(a*p.x+b*p.y);
     }
     //y=m*x+c (p.x!=q.x)
     void equation(vectorVar &m,vectorVar &c)
     {
         vectorVar a=p.x-q.x;
         vectorVar b=p.y-q.y;
         m=b/a;
         c=(a*p.y-b*p.x)/a;
     }

     //some test still remaining
     //this line to l
     vectorVar interiorangle(line l)
     {
         vectorVar a1,b1,c1,a2,b2,c2;
         equation(a1,b1,c1);
         l.equation(a2,b2,c2);
         vectorVar x,y;
         y=-a2*b1+a1*b2;
         x=a1*a2+b1*b2;
         //print2(x,y);
         vectorVar ret=atan2(y,x);
         if(ret<-pi/2) ret=ret+pi;
         else if(ret>pi/2) ret=ret-pi;
         if(ret>pi/2) ret=pi/2;
         else if(ret<-pi/2) ret=-pi/2;
         return ret;
     }

     //some test still remaining
     //this line to l
     vectorVar exteriorangle(line l)
     {
         double ret=interiorangle(l);
         if(ret>0) ret=pi-ret;
         else ret=-pi-ret;
         if(ret>pi) ret=pi;
         else if(ret<-pi) ret=-pi;
         return ret;
     }
     //qpp1 angle (p is in the middle)
     vectorVar angle(Vector p1)
     {
         p1=p1.substract(p);
         Vector q1=q.substract(p);
         return q1.angle(p1);
     }
     //qpp1 angle (p is in the middle)  (from q to p1)
     vectorVar angleWithSign(Vector p1)
     {
         p1=p1.substract(p);
         Vector q1=q.substract(p);
         return q1.angleWithSign(p1);
     }

     //a point inside a line segment
     bool inside(Vector p1)
     {
         if(p1.x>max(p.x,q.x)||p1.x<min(p.x,q.x)) return false;
         if(p1.y>max(p.y,q.y)||p1.y<min(p.y,q.y)) return false;
         return true;
     }
     vectorVar length() { Vector q1=q.substract(p); return q1.length(); }
     vectorVar sqrLength() { Vector q1=q.substract(p); return q1.sqrLength(); }
     //if p.x!=q.x
     vectorVar gety(double x)
     {
         Vector ret(q.x-p.x,q.y-p.y);
         x-=p.x;
         double m=1.0*ret.y/(1.0*ret.x);
         double y=m*x;
         y+=p.y;
         return y;
     }
     //if p.y!=q.y
     double getx(double y)
     {
         if(EQ(p.x,q.x)) return p.x;
         Vector ret(q.x-p.x,q.y-p.y);
         y-=p.y;
         double m=1.0*ret.y/(1.0*ret.x);
         double x=y/m;
         x+=p.x;
         return x;
     }

     Vector shortestPointOfSegment(Vector p1)
     {
         p1=p1.substract(p);
         Vector q1=q.substract(p);
         Vector ret=q1.shortestPoint(p1);
         ret=ret.add(p);
         return ret;
     }
     //point to segment
     vectorVar shortestDistOfSegment(Vector p1) { p1=p1.substract(p); Vector q1=q.substract(p);  return q1.shortestDist(p1); }
     //segment to segment
     vectorVar shortestDistOfSegment(line l)
     {
         vectorVar ret=shortestDistOfSegment(l.p);
         ret=min(ret,shortestDistOfSegment(l.q));
         ret=min(ret,l.shortestDistOfSegment(p));
         ret=min(ret,l.shortestDistOfSegment(q));
         return ret;
     }
     //keeping p fixed
     line lengthTransform(vectorVar l)
     {
         Vector q1=q.substract(p);
         q1=q1.lengthTransform(l);
         q1=q1.add(p);
         return line(p,q1);
     }
     //keeping p fixed
     line rotation(vectorVar theta)
     {
         Vector q1=q.substract(p);
         q1=q1.rotation(theta);
         q1=q1.add(p);
         return line(p,q1);
     }
     //only shift in c in y=mx+c
     line shift(vectorVar cshift)
     {
         Vector tem(0,cshift);
         double theta=q.substract(p).angle();
         if(fabs(theta)>pi/2.0) theta+=pi;
         else if(EQ(theta,-pi/2.0)) theta+=pi; //-pi/2 to pi/2 range(-pi/2 exclusive)
         tem=tem.rotation(theta);
         return line(tem.add(p),tem.add(q));
     }
     //slope should not be the same
     Vector lineIntersectingPoint(line l)
     {
         vectorVar a1,b1,c1,a2,b2,c2;
         equation(a1,b1,c1);
         l.equation(a2,b2,c2);
         Vector ret;
         ret.x=(b1*c2-b2*c1)/(a1*b2-a2*b1);
         ret.y=(c1*a2-c2*a1)/(a1*b2-a2*b1);
         return ret;
     }
     //if line segment intersect with each other
     //for double
     //risky to use this in case of double(special attention to error)
     bool intersects(line l)
     {
         vectorVar a1,b1,c1,a2,b2,c2;
         equation(a1,b1,c1);
         l.equation(a2,b2,c2);
         if(EQ(a1*b2,a2*b1)) return false;
         Vector ret=lineIntersectingPoint(l);
         if(ret.x>max(p.x,q.x)+ERR||ret.x<min(p.x,q.x)-ERR) return false;
         if(ret.x>max(l.p.x,l.q.x)+ERR||ret.x<min(l.p.x,l.q.x)-ERR) return false;
         if(ret.y>max(p.y,q.y)+ERR||ret.y<min(p.y,q.y)-ERR) return false;
         if(ret.y>max(l.p.y,l.q.y)+ERR||ret.y<min(l.p.y,l.q.y)-ERR) return false;
         return true;
     }

     //determines which side of line the point is in
     vectorVar sideOfLine(Point p)
     {
         vectorVar a,b,c;
         equation(a,b,c);
         return a*p.x+b*p.y+c;
     }
};

struct triangle
{
    Point a,b,c;
    triangle(Vector a1=0,Vector b1=0, Vector c1=0) { a=a1; b=b1; c=c1; }
    //a is fixed
    //.5 should be omitted in case of integer counting
    vectorVar areaWithoutSign() { Vector p=b.substract(a); Vector q=c.substract(a); return fabs(.5*p.cross(q)); }
    //a is fixed
    //.5 should be omitted in case of integer counting
    vectorVar areaWithSign() { Vector p=b.substract(a); Vector q=c.substract(a); return .5*p.cross(q); }
};

struct circle{
   Point c;//center
   vectorVar r;
   circle(vectorVar x=0,vectorVar y=0, vectorVar r1=0) { c.x=x; c.y=y; r=r1; }
   double area() { return pi*r*r; }
   bool inside(Vector p) { p=p.substract(c); return (!(p.sqrLength()>r*r)); }
   //change for integer
   bool onBoundary(Vector p) { p=p.substract(c); return EQ(p.sqrLength(),r*r); }
   double areaOfArc(double theta) { return (r*r*theta)/2.0; }
   //from p to q
   //area inside circle only
   double areaOfArc(Vector p,Vector q) { p=p.substract(c); q=q.substract(c); return areaOfArc(p.angleWithSign(q)); }
   //point should be on boundary
   double areaOfArcExceptTriangle(Vector p,Vector q) { double sub=triangle(c,p,q).areaWithSign(); return areaOfArc(p,q)-sub; }
   //returns the point on boundary with given angle
   Point point(double a){return Point(c.x+cos(a)*r,c.y+sin(a)*r);}
   //of linesegment
   //if it is tangent it will return twice
   vector<Vector> intersects(line l)
   {
       int i;
       l.p=l.p.substract(c);
       l.q=l.q.substract(c);
       Vector p,q;
       vector<Vector>ret;
       //vertical line
       if(EQ(l.p.x,l.q.x))
       {
           p.x=l.p.x;
           q.x=l.q.x;
           if(!quadraticequation(1,0,p.x*p.x-r*r,p.y,q.y)) return ret;
           if(l.inside(p)) ret.pb(p);
           if(l.inside(q)) ret.pb(q);
           fr(i,0,SZ(ret)-1)
            ret[i]=ret[i].add(c);
           return ret;
       }
       vectorVar m,cc;
       l.equation(m,cc);
       if(!quadraticequation(1+m*m,2*m*cc,cc*cc-r*r,p.x,q.x)) return ret;
       p.y=m*p.x+cc;
       q.y=m*q.x+cc;
       if(l.inside(p)) ret.pb(p);
       if(l.inside(q)) ret.pb(q);
       fr(i,0,SZ(ret)-1)
            ret[i]=ret[i].add(c);
       return ret;
   }

   //1 based
   //polygon should be simple
   //logn
   double intersectingArea(Vector poly[],int n)
   {
       int i;
       double area=0;
       for(i=1;i<=n;i++)
       {
           int j=i+1;
           if(j>n) j=1;
           vector<Vector> ret=intersects(line(poly[i],poly[j]));
           if(inside(poly[i]) && inside(poly[j])) //both inside
                area+=triangle(c,poly[i],poly[j]).areaWithSign();
           else if(!ret.size()) //both outside without intersection
             area+=areaOfArc(poly[i],poly[j]);
           else if(ret.size()==1) //exactly 1 point is inside
           {
               if(inside(poly[i])) area+=areaOfArc(ret[0],poly[j])+triangle(c,poly[i],ret[0]).areaWithSign();
               else area+=areaOfArc(poly[i],ret[0])+triangle(c,ret[0],poly[j]).areaWithSign();
           }
           else //both are outside with intersection
           {
                if(poly[i].length(ret[0])>poly[i].length(ret[1])) swap(ret[0],ret[1]);
                area+=areaOfArc(poly[i],ret[0])+triangle(c,ret[0],ret[1]).areaWithSign()+areaOfArc(ret[1],poly[j]);

           }
       }
       return fabs(area);
   }

   int circleIntersectingPoint(circle cir,Point &p1,Point &p2)
   {
        double d=c.length(cir.c); //distance of two center
        if(dcmp(d)==0) //same center
        {
            if(dcmp(r-cir.r)==0) return 3; //same circle(infinite intersection point)
            return 0; //totally inside
	    }
	    //different center
        if(dcmp(r+cir.r-d)<0) return -1; //strictly outside
        if(dcmp(fabs(r-cir.r)-d)>0) return 0; //strictly inside
        double a=fabs(cir.c.substract(c).angle());
        double da=acos((r*r+d*d-cir.r*cir.r)/(2*r*d));
        p1=point(a-da);p2=point(a+da);
        if(p1==p2) return 1; //touch in one point
        return 2;
   }

   //tested by LJ 1118
   double circleIntersectingArea(circle cir)
   {
        double d = c.length(cir.c);
        double r1=r;
        double r2=cir.r;
        if (r1 + r2 <d) return 0; //outside
        if (d >fabs (r1 - r2)+PRE) //partially inside
        {
             double x = (d * d + r1 * r1 - r2 * r2) / (2 * d);
             double t1 = acos (x / r1);
             double t2 = acos ((d - x) / r2);
             return r1 * r1 * t1 + r2 * r2 * t2 - d * r1 * sin (t1);
        }
         //totally inside
        double rr = min (r1, r2);
        return pi * rr * rr;
    }
};

//1 based
//should be clockwise or anticlockwise
//works in simple polygon
vectorVar areaOfPolygon(Vector poly[],int n)
{
    int i;
    double area=0;
    for(i=2;i<n;i++)
    {
        triangle tem(poly[1],poly[i],poly[i+1]);
        area+=tem.areaWithSign();
    }
    return fabs(area);
}

//1 based
//should be clockwise or anticlockwise
//clipping polygon should be strictly convex(no 180 degree angles) and target polygon should be simple
//twice memory is needed in worst case
//complexity 2*n*m
vectorVar areaOfClippingPolygon(Vector clipPoly[],int n,Vector targetPoly[],int m)
{
    int i,j;
    Vector temtar[2*m+4];
    int temm;
    double chck=clipPoly[2].cross(clipPoly[1],clipPoly[3]);
    for(i=1;i<=n;i++)
    {
        int next=i+1;
        if(next>n) next=1;
        temm=0;
        //clipping done with infinte line
        for(j=1;j<=m;j++)
        {
            int nextj=j+1;
            if(nextj>m) nextj=1;
            if(clipPoly[next].cross(clipPoly[i],targetPoly[j])*chck>-PRE)
            {
                if(clipPoly[next].cross(clipPoly[i],targetPoly[nextj])*chck>-PRE) //both are inside
                    temtar[++temm]=targetPoly[nextj];
                else temtar[++temm]=line(clipPoly[i],clipPoly[next]).lineIntersectingPoint(line(targetPoly[j],targetPoly[nextj])); //inside to outside
            }

            else if(clipPoly[next].cross(clipPoly[i],targetPoly[nextj])*chck>-PRE) //outside to inside
            {
                temtar[++temm]=line(clipPoly[i],clipPoly[next]).lineIntersectingPoint(line(targetPoly[j],targetPoly[nextj]));
                temtar[++temm]=targetPoly[nextj];
            }
        }

        m=temm;
        for(j=1;j<=m;j++)
            targetPoly[j]=temtar[j];
    }

    return areaOfPolygon(targetPoly,m);
}

//1 based
//polygon should be disjoint and strictly convex
//should be given in clockwise or anticlockwise
//complexity m+n
vectorVar shortestDistBetweenPolygon(Vector P[],int n,Vector Q[],int m)
{
    if(P[2].cross(P[1],P[3])>0) //anticlockwise
        reverse(P+1,P+n+1);
    if(Q[2].cross(Q[1],Q[3])>0) //anticlockwise
        reverse(Q+1,Q+m+1);
    int inP=1;
    double mi=P[1].y;
    int i,j;
    for(i=2;i<=n;i++)
    if(P[i].y<mi)
    {
        mi=P[i].y;
        inP=i;
    }

    int inQ=1;
    double ma=Q[1].y;
    for(i=2;i<=m;i++)
    if(Q[i].y>ma)
    {
        ma=Q[i].y;
        inQ=i;
    }

    i=inQ;
    j=inP;
    int cntP=1;
    int cntQ=1;
    double ans=P[inP].length(Q[inQ]);
    while(cntP<n||cntQ<m)
    {
        if(i>n) i=1;
        if(j>m) j=1;
        int nexti=i+1;
        int nextj=j+1;
        if(nexti>n) nexti=1;
        if(nextj>m) nextj=1;
        vectorVar chck=P[nexti].substract(P[i]).angle();
        chck-=Q[nextj].substract(Q[j]).angle();
        if(chck<0) chck+=2.0*pi;
        if(fabs(chck)<ERR&&cntP<n&&cntQ<m) //segment to segment
        {
            ans=min(ans,line(P[nexti],P[i]).shortestDistOfSegment(line(Q[nextj],Q[j])));
            i++;
            j++;
            cntP++;
            cntQ++;
        }

        else if(chck<pi&&cntQ<m) //Q is near
        {
            ans=min(ans,line(Q[nextj],Q[j]).shortestDistOfSegment(P[i]));
            j++;
            cntQ++;
        }

        else if(chck>pi&&cntP<n) //P is near
        {
            ans=min(ans,line(P[nexti],P[i]).shortestDistOfSegment(Q[j]));
            i++;
            cntP++;
        }

        else if(cntQ<m) //only Q left
        {
            ans=min(ans,line(Q[nextj],Q[j]).shortestDistOfSegment(P[i]));
            j++;
            cntQ++;
        }

        else //only P left
        {
            ans=min(ans,line(P[nexti],P[i]).shortestDistOfSegment(Q[j]));
            i++;
            cntP++;
        }
    }
    return ans;
}

//a*x^2+b*x+c=0
bool quadraticequation(vectorVar a,vectorVar b,vectorVar c,double &x1,double &x2)
{
    vectorVar d=b*b-a*c*4;
    if(d<0) return false;
    d=sqrt(d);
    x1=(-b+d)/(2*a);
    x2=(-b-d)/(2*a);
    return true;
}

bool mult(Point sp,Point ep,Point op)
{
	return (sp.x-op.x)*(ep.y-op.y)>=(ep.x-op.x)*(sp.y-op.y);
}

bool operator < (const Point& l,const Point& r)
{
	return l.y<r.y||(l.y==r.y&&l.x<r.x);
}

int graham(Point pnt[],int n,Point res[])
{
	int i,len,k=0,top=1;
	sort(pnt,pnt+n);
	if(n==0) return 0; res[0]=pnt[0];
	if(n==1) return 1; res[1]=pnt[1];
	if(n==2) return 2; res[2]=pnt[2];
	for(i=2;i<n;i++)
	{
		while(top&&mult(pnt[i],res[top],res[top-1]))
			top--;
		res[++top]=pnt[i];
	}
	len=top; res[++top]=pnt[n-2];
	for(i=n-3;i>=0;i--)
	{
		while(top!=len&&mult(pnt[i],res[top],res[top-1]))
			top--;
		res[++top]=pnt[i];
	}
	return top;
}
//works for simple polygon (both convex and concave)
//returns true if it on the boundary or vertex
//1 based
bool pointInPoly(int n, Vector arr[], Vector P)  //nodes should be given in clockwise or anti-clockwise order
{
  int i, j;
  bool c=false;
  vectorVar xx=P.x;
  vectorVar yy=P.y;
  for (i = 1, j = n; i <= n; j = i++) {
      if ( ((arr[i].y>yy) != (arr[j].y>yy)) && //here all corner(vertex) case are handled
	 (xx < (arr[j].x-arr[i].x) * (yy-arr[i].y) / (arr[j].y-arr[i].y) + arr[i].x) )
       c = !c;
  }
  return c;
}

struct bspNode{
   line l;
   int left,right; //left for negative and right for positive
};
//1 based
//indBSP should be made 0
bspNode mainBSPNode[10000];
int indBSP;

//Binary Space Partitioning
void bsp(line arr[],int par,bool left,int n)
{
    int now=rand()%n+1;
    //left or right child
    int temInd=(++indBSP);
    if(left) mainBSPNode[par].left=temInd;
    else mainBSPNode[par].right=temInd;

    //partioning the space into left and right parts
    line lft[n+2],right[n+2];
    int inl=0,inr=0;
    for(int i=1;i<=n;i++)
    if(i!=now)
    {
        if(arr[now].sideOfLine(arr[i].p)<0)
        {
            if(arr[now].sideOfLine(arr[i].q)<0) //both are left
                lft[++inl]=arr[i];
            else //left to right
            {
                Point intersectingPoint=arr[now].lineIntersectingPoint(arr[i]);
                lft[++inl]=line(arr[i].p,intersectingPoint);
                right[++inr]=line(intersectingPoint,arr[i].q);
            }
        }

        else if(arr[now].sideOfLine(arr[i].q)<0) //right to left
        {
            Point intersectingPoint=arr[now].lineIntersectingPoint(arr[i]);
            lft[++inl]=line(arr[i].q,intersectingPoint);
            right[++inr]=line(intersectingPoint,arr[i].p);
        }

        else right[++inr]=arr[i]; //both right
    }

    mainBSPNode[temInd].l=arr[now];
    mainBSPNode[temInd].left=0;
    mainBSPNode[temInd].right=0;
    if(inl) bsp(lft,temInd,true,inl);
    if(inr) bsp(right,temInd,false,inr);
}

int main()
{
    line arr[200];
    int n;
    while(cin>>n)
    {
        for(int i=1;i<=n;i++) {
            arr[i].p.scan();
            arr[i].q.scan();
        }
        indBSP=0;
        bsp(arr,0,false,n);
        for(int i=1;i<=indBSP;i++)
        {
            print2("Now in index",i);
            mainBSPNode[i].l.print();
            print2("Left Child is ",mainBSPNode[i].left);
            print2("Right Child is ",mainBSPNode[i].right);
        }
    }
    return 0;
}
