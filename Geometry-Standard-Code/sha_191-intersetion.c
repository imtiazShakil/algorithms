#include <stdio.h>
typedef struct
{
    int x;
    int y;
} vector;


vector MV(int x1,int y1,int x2,int y2)
{
    vector temp;
    temp.x=x2-x1;
    temp.y=y2-y1;

    return temp;
}

int min(int x1,int x2)
{
    if(x1<x2) return x1;
    else return x2;
}

int max(int x1,int x2)
{
    if(x1>x2) return x1;
    else return x2;
}

bool  on_line(vector start,vector end,vector betn)
{
    if((min(start.x,end.x)<=betn.x && betn.x<=max(start.x,end.x)) && (min(start.y,end.y)<=betn.y && betn.y<=max(start.y,end.y)) )  return true;
    else return false;
}

int cross(vector a,vector b)
{
   return (a.x * b.y - a.y * b.x);
}

bool intersect(vector a,vector b,vector c,vector d)
{
    int d1,d2,d3,d4;
    vector p1_p2=MV(a.x,a.y,b.x,b.y);
    vector p3_p4=MV(c.x,c.y,d.x,d.y);

    d1=cross(p1_p2,MV(a.x,a.y,c.x,c.y)); //p1_p2 * p1_p3
    d2=cross(p1_p2,MV(a.x,a.y,d.x,d.y)) ; //p1_p2*p1_p4
    d3=cross(p3_p4,MV(c.x,c.y,a.x,a.y)) ; //p3_p4 * p3_p1
    d4=cross(p3_p4,MV(c.x,c.y,b.x,b.y)); //p3_p4 * p3_p2

    if(d1*d2<0 && d3*d4<0) return true;
    if(!d1 && on_line(a,b,c)) return true;
    if(!d2 && on_line(a,b,d)) return true;
    if(!d3 && on_line(c,d,a)) return true;
    if(!d4 && on_line(c,d,b)) return true;

    return false;
}

int main(void)
{
    int loop,i;
    vector a,b,c,d,line_st,line_end;    /// 4 sides of a rectangle
    int x[2],y[2];
    //int check[][4]={0,1,1,0,0,0,1,1};
    //x[0] =x_rec_lef
    //x[1] =x_rec_right
    //y[0] =y_rec_top
    //y[1] =y_rec_botm
    scanf("%d",&loop);
    while(loop)
    {
        scanf("%d %d %d %d %d %d %d %d",&line_st.x,&line_st.y,&line_end.x,&line_end.y,&x[0],&y[0],&x[1],&y[1]);

        //int mini=min(x[0],x[1]) , maxi=max(x[0],x[1]);
        //if(x[0]>x[1])
        //{
         //   x[0]^=x[1]^=x[0]^=x[1];
        //    y[0]^=y[1]^=y[0]^=y[1];
        //}
        a.x=d.x=min(x[0],x[1]);
        b.x=c.x=max(x[0],x[1]);
        a.y=b.y=max(y[0],y[1]);
        c.y=d.y=min(y[0],y[1]);

        //printf("min x=%d max x=%d\n",mini,maxi);
        //if(x[0]<x[1]) { mini=y[0];maxi=y[1];}
        //else  { mini=y[1];maxi=y[0];}
        //b.y=a.y=mini;
        //c.y=d.y=maxi;
        //printf("min y=%d max y=%d\n",mini,maxi);
        //printf("%d %d  ---  %d %d\n%d %d  ---  %d %d\n",a.x,a.y,b.x,b.y,d.x,d.y,c.x,c.y);

        if(intersect(line_st,line_end,a,b)) { printf("T\n"); --loop; continue;}
        if(intersect(line_st,line_end,b,c)) { printf("T\n"); --loop; continue;}
        if(intersect(line_st,line_end,c,d)) { printf("T\n"); --loop; continue;}
        if(intersect(line_st,line_end,d,a)) { printf("T\n"); --loop; continue;}

        if(min(x[0],x[1])<=line_st.x && line_st.x <=max(x[0],x[1]) && min(y[0],y[1])<=line_st.y && line_st.y <=max(y[0],y[1]))  { printf("T\n");--loop; continue;}

        printf("F\n");
        --loop;
    }
}

