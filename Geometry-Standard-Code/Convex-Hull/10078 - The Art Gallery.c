#include <stdio.h>
#include <algorithm>
#include <math.h>
#define MAX 60
using namespace std;

struct point
{
    int x;
    int y;
}coordinates[MAX],stack[MAX];

point pivot;

point MV(point a,point b)   //vector in the direction ab
{
    point temp;
    temp.x=b.x-a.x;
    temp.y=b.y-a.y;

    return temp;
}
int com(const void *a,const void *b)
{
    struct point *x=(struct point *)a;
    struct point *y=(struct point *)b;

    if(x->y!=y->y) return x->y - y->y;
    else return x->x - y->x;
}

//int dot(point a,point b)
//{
//    int temp=a.x * b.x + a.y * b.y;
//    return temp;
//}

int cross(point vct1,point vct2)
{
    int temp=vct1.x * vct2.y - vct1.y * vct2.x ;

    return temp;
}
int com2(const void *x,const void *y)
{
    struct point *a=(struct point *)x;
    struct point *b=(struct point *)y;

    point vect1=MV(pivot,*a);
    point vect2=MV(pivot,*b);

    int c;
    c=cross(vect1,vect2);

    if(c>0) return -1;
    if(c<0) return 1;
    if(c==0)
    {
        double dist1=sqrt(pow(pivot.x-a->x,2) + pow(pivot.y-a->y,2));  //distance pivot 2 a
        double dist2=sqrt(pow(pivot.x-b->x,2) + pow(pivot.y-b->y,2));   //distance pivot 2 b

        if(dist1 > dist2) return -1; //dont swap
        else return 1;
    }
}

int main(void)
{
    int n,i,top,c,j;
    point vct1,vct2;
    while(scanf("%d",&n)==1 && n)
    {
//        for(i=0;i<MAX;i++) {coordinates[i].x=0;coordinates[i].y=0;stack[i].x=0;stack[i].y=0;}
        for(i=0;i<n;i++) scanf("%d %d",&coordinates[i].x,&coordinates[i].y);
        qsort(coordinates,n,sizeof(point),com);
//        printf("sorted\n\n");
//        for(i=0;i<n;i++) printf("%d %d\n",coordinates[i].x,coordinates[i].y);

        pivot=coordinates[0];
        qsort(&coordinates[1],n-1,sizeof(point),com2);

//        printf("sorted with respect to pivot\n\n");
//        for(i=0;i<n;i++) printf("%d %d\n",coordinates[i].x,coordinates[i].y);

        stack[0]=coordinates[0];
        stack[1]=coordinates[1];
        stack[2]=coordinates[2];

        top=2;
        bool flag;
        for(i=3,flag=1;i<n;)
        {
            vct1=MV(stack[top-1],stack[top]);
            vct2=MV(stack[top],coordinates[i]);

            c=cross(vct1,vct2);
            if(c<0) {top--;flag=0;break;}
            else {++top;stack[top]=coordinates[i];i++;}

//            printf("___>>>>stack<<<<<___\n\n");
//            for(j=0;j<=top;j++) printf("%d %d\n",stack[j].x,stack[j].y);
        }

        if(flag) printf("No\n");
        else printf("Yes\n");
    }
}
