//There are many O(Q  N  logN) solutions using segment trees or other data structures, but probably they will get time limit exceeded.
//
//We can solve each query independently. First, let's consider the following DP algorithm.
//
//dp[c] := the maximal value of a sequence whose last ball's color is c
//
//For each ball i, we want to update the array. Let the i-th ball's color be col[i], the i-th ball's value be val[i], and the maximal value of dp array other than dp[col[i]] be otherMAX. We can update the value of dp[col[i]] to dp[col[i]] + val[i] × a or otherMAX + val[i] × b. Here, we only need to know dp[col[i]] and otherMAX. If we remember the biggest two values of dp array in that time and their indexes in the array, otherMAX can be calculated using the biggest two values, which always include maximal values of dp array other than any particular color.
//
//Since the values of dp array don't decrease, we can update the biggest two values in O(1). Finally, the answer for the query is the maximal value of dp array.
//
//The complexity of the described algorithm is O(QN).
//#pragma warning (disable: 4786)

#include <sstream>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>
#include <list>
#include <string.h>
using namespace std;
#define print1(a)    cout<<a<<endl
#define print2(a,b) cout<<a<<" "<<b<<endl
#define print3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define oo          (1<<30)
#define PI          3.141592653589793
#define pi          (2*acos(0))
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
#define round(i,a)  i = ( a < 0 ) ? a - 0.5 : a + 0.5;
#define makeint(n,s)  istringstream(s)>>n
#define inpow(a,x,y) int i; a=x;fri(2,y)  a*=x
#define cntbit(mask) __builtin_popcount(mask)
#define debug_array(a,n) for(int i=0;i<n;i++) cerr<<a[i]<<" "; cerr<<endl;
#define debug_matrix(mat,row,col) for(int i=0;i<row;i++) {for(int j=0;j<col;j++) cerr<<mat[i][j]<<" ";cerr<<endl;}

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
#define lim 100010
#define inf 1000000000ll
LL n,q;
LL c[lim],v[lim];
LL a,b;
LL dp[lim];


int main()
{
   int i,j;
   while(cin>>n>>q)
   {
       for(i=1;i<=n;i++)
        cin>>v[i];
       for(i=1;i<=n;i++)
        cin>>c[i];

       for(i=1;i<=q;i++)
       {
           cin>>a>>b;
           for(j=1;j<=n;j++)
            dp[j]=-(inf*inf);
           LL max1=0,max2=0,col1=-1;
           for(j=1;j<=n;j++)
           {
               if(dp[c[j]]!=-(inf*inf)) dp[c[j]]=max(dp[c[j]],dp[c[j]]+a*v[j]);

               if(col1!=c[j]) dp[c[j]]=max(dp[c[j]],max1+b*v[j]);
               else dp[c[j]]=max(dp[c[j]],max2+b*v[j]);

               if(max1<dp[c[j]])
               {
                   if(col1!=c[j]) max2=max1; //2nd max should be different color
                   max1=dp[c[j]];
                   col1=c[j];
               }

               else if(max2<dp[c[j]]&&col1!=c[j]) //2nd max should be different color
                max2=dp[c[j]];
           }
           print1(max1);
       }
   }
   return 0;
}
