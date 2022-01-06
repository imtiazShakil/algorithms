/// Syed Shahriar Manjur (Dip)
//#pragma warning (disable: 4786)

#include <sstream>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <complex>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>
#include <list>
#include <string.h>
#include <assert.h>
#include  <time.h>
using namespace std;
#define print1(a)    cout<<a<<endl
#define print2(a,b) cout<<a<<" "<<b<<endl
#define print3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define oo          (1<<30)
#define PI          3.141592653589793
#define pi          (2.0*acos(0.0))
#define ERR         1e-5
#define PRE         1e-8
#define SZ(s)       ((int)s.size())
#define LL          long long
#define ISS         istringstream
#define OSS         ostringstream
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
#define REP(i,n)    for(i=0;i<n;i++)
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
#define mp          make_pair
#define round(i,a)  i = ( a < 0 ) ? a - 0.5 : a + 0.5;
#define makeint(n,s)  istringstream(s)>>n
#define inpow(a,x,y) int i; a=x;fri(2,y)  a*=x
#define cntbit(mask) __builtin_popcountll(mask)
//0 based print
#define debug_array(a,n) for(int i=0;i<n;i++) cerr<<a[i]<<" "; cerr<<endl;
#define debug_matrix(mat,row,col) for(int i=0;i<row;i++) {for(int j=0;j<col;j++) cerr<<mat[i][j]<<" ";cerr<<endl;}

#define csprnt printf("Case %d: ", ++cas);
#define mod         1000000007
#define eulerconstant 0.5772156649

template<class T1> void debug(T1 e){cout<<e<<endl;}
template<class T1,class T2> void debug(T1 e1,T2 e2){cout<<e1<<"\t"<<e2<<endl;}
template<class T1,class T2,class T3> void debug(T1 e1,T2 e2,T3 e3){cout<<e1<<"\t"<<e2<<"\t"<<e3<<endl;}
template<class T1,class T2,class T3,class T4> void debug(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<"\t"<<e2<<"\t"<<e3<<"\t"<<e4<<endl;}
template<class T1,class T2,class T3,class T4,class T5> void debug(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5){cout<<e1<<"\t"<<e2<<"\t"<<e3<<"\t"<<e4<<"\t"<<e5<<endl;}
template<class T1,class T2,class T3,class T4,class T5,class T6> void debug(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6){cout<<e1<<"\t"<<e2<<"\t"<<e3<<"\t"<<e4<<"\t"<<e5<<"\t"<<e6<<endl;}
template<class T> void debug(vector< vector<T> > e,int row,int col){int i,j;REP(i,row) {REP(j,col) cout<<e[i][j]<<" ";cout<<endl;} cout<<endl;}
template<class T> void debug(vector< basic_string<T> > e,int row,int col){int i,j;REP(i,row) {REP(j,col) cout<<e[i][j];cout<<endl;} cout<<endl;}
template<class T> void debug(T e[110][110],int row,int col){int i,j;REP(i,row) {REP(j,col) cout<<e[i][j]<<" ";cout<<endl;}}
template<class T> string toString(T n){ostringstream oss;oss<<n;oss.flush();return oss.str();}
int toInt(string s){int r=0;istringstream sin(s);sin>>r;return r;}
bool isVowel(char ch){ch=tolower(ch);if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')return true;return false;}
bool isUpper(char c){return c>='A' && c<='Z';}
bool isLower(char c){return c>='a' && c<='z';}
//*************************************************My Code Starts Here*********************************************************************************
//Andrei Lopatin
//UVA 10746
//return minimum cost (multiply -1 in each entry for maximum cost)
//1 based (0 is used for algorithm)
//Complexity O(n^2*m) or O(n^3)
#define INF 2000000000
#define rows 110
#define clms 110
double arr[rows][clms]; //main matrix
double  u[rows], v[clms]; //used for labeling
int p[clms] , way[clms]; //p = match , way = the augmenting path

//n = number of rows
//m = number of columns
//n<=m
double hungarian(int n,int m) {

    mem(p,0);
    mem(u,0);
    mem(v,0);
    for ( int i = 1 ; i <= n ; ++ i ) {
        p [ 0 ] = i ;
        int j0 = 0 ;
        vector < double > minv ( m + 1 , INF ) ;
        vector < bool > used ( m + 1 , false ) ;
        do { //works like bfs
            used [ j0 ] = true ;
            int i0 = p [ j0 ] ,   j1 ;
            double delta = INF;
            for ( int j = 1 ; j <= m ; ++ j )
                if ( ! used [ j ] ) {
                    double cur = arr [ i0 ] [ j ] - u [ i0 ] - v [ j ] ;
				if ( cur < minv [ j ] )
					minv [ j ] = cur,  way [ j ] = j0 ;
				if ( minv [ j ] < delta )
					delta = minv [ j ] ,  j1 = j ;
                }

            //matrix doesn't change here
            for ( int j = 0 ; j <= m ; ++ j )
                if ( used [ j ] )
                    u [ p [ j ] ] += delta,  v [ j ] -= delta ;
                else
                    minv [ j ] -= delta ;
            j0 = j1 ;
            } while ( p [ j0 ] != 0 ) ;
        do {
                int j1 = way [ j0 ] ;
                p [ j0 ] = p [ j1 ] ;
                j0 = j1 ;
            } while ( j0 ) ;

    }

    return -v[0]; //minimum cost is stored here
}


int main()
{
    //srand(time(NULL));
    //freopen("A.txt","r",stdin);
    //freopen("B.txt","w",stdout);
    int n,m;
    while(cin>>n>>m && (n||m))
    {
        int i,j;
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
                scanf("%lf",&arr[i][j]);

        double ans = hungarian(n,m)/n;
        printf("%.2lf\n",ans+(1e-3));
    }
    return 0;
}
/*
3 4
10.0 23.0 30.0 40.0
5.0 20.0 10.0 60.0
18.0 20.0 20.0 30.0
0 0

Answer = 13.33
*/
