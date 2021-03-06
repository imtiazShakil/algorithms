#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <list>
#include <set>
#include <cmath>
#include <cstring>

#include <stdio.h>
#include <string.h>
#include <sstream>
#include <stdlib.h>
#include <vector>
#include <iomanip>
#include <ctime>

using namespace std;

//Type Definition
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi>vvi;
typedef vector<string> vs;
typedef map<string,int> msi;
typedef map<int,int>mii;

#define INF (1<<28)
#define SIZE 110
#define ERR 1e-9
#define PI 3.141592653589793

#define REP(i,n) for (i=0;i<n;i++)
#define FOR(i,p,k) for (i=p; i<k;i++)
#define FOREACH(it,x) for(__typeof((x).begin()) it=(x.begin()); it!=(x).end(); ++it)

#define Sort(x) sort(x.begin(),x.end())
#define Reverse(x) reverse(x.begin(),x.end())
#define MP(a,b) make_pair(a,b)
#define Clear(x,with) memset(x,with,sizeof(x))
#define SZ(x) (int)x.size()
#define pb push_back
#define popcount(i) __builtin_popcount(i)
#define gcd(a,b)    __gcd(a,b)
#define lcm(a,b) ((a)*((b)/gcd(a,b)))
#define two(X) (1<<(X))
#define twoL(X) (((ll)(1))<<(X))
#define setBit(mask,i) (mask|two(i))
#define contain(S,X) (((S)&two(X))!=0)
#define X first
#define Y second
#define CS c_str()
#define EQ(a,b) (fabs(a-b)<ERR)

//For debugging
template<class T1> void debug(T1 e){cout<<e<<endl;}
template<class T1,class T2> void debug(T1 e1,T2 e2){cout<<e1<<"\t"<<e2<<endl;}
template<class T1,class T2,class T3> void debug(T1 e1,T2 e2,T3 e3){cout<<e1<<"\t"<<e2<<"\t"<<e3<<endl;}
template<class T1,class T2,class T3,class T4> void debug(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<"\t"<<e2<<"\t"<<e3<<"\t"<<e4<<endl;}
template<class T1,class T2,class T3,class T4,class T5> void debug(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5){cout<<e1<<"\t"<<e2<<"\t"<<e3<<"\t"<<e4<<"\t"<<e5<<endl;}
template<class T1,class T2,class T3,class T4,class T5,class T6> void debug(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6){cout<<e1<<"\t"<<e2<<"\t"<<e3<<"\t"<<e4<<"\t"<<e5<<"\t"<<e6<<endl;}
template<class T> void debug(vector< vector<T> > e,int row,int col){int i,j;REP(i,row) {REP(j,col) cout<<e[i][j]<<" ";cout<<endl;} cout<<endl;}
template<class T> void debug(vector< basic_string<T> > e,int row,int col){int i,j;REP(i,row) {REP(j,col) cout<<e[i][j];cout<<endl;} cout<<endl;}
template<class T> void debug(T e[SIZE][SIZE],int row,int col){int i,j;REP(i,row) {REP(j,col) cout<<e[i][j]<<" ";cout<<endl;}}

//Important Functions
template<class T> void setmax(T &a, T b) { if(a < b) a = b; }
template<class T> void setmin(T &a, T b) { if(b < a) a = b; }
template<class T> T Abs(T x) {return x > 0 ? x : -x;}
template<class T> inline T sqr(T x){return x*x;}
template<class T> inline T Mod(T n,T m) {return (n%m+m)%m;} //For Positive Negative No.
template<class T> string toString(T n){ostringstream oss;oss<<n;oss.flush();return oss.str();}
int toInt(string s){int r=0;istringstream sin(s);sin>>r;return r;}
bool isVowel(char ch){ch=tolower(ch);if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')return true;return false;}
bool isUpper(char c){return c>='A' && c<='Z';}
bool isLower(char c){return c>='a' && c<='z';}
ll Pow(ll B,ll P){	ll R=1;	while(P>0)	{if(P%2==1)	R=(R*B);P/=2;B=(B*B);}return R;}
int BigMod(ll B,ll P,ll M){	ll R=1;	while(P>0)	{if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;}	return (int)R;}
void binprint(ll mask,ll n){ll i;string s="";do{s+=(mask%2+'0');mask/=2;}while(mask);Reverse(s);s=string(max(n-SZ(s),0LL),'0')+s;for(i=SZ(s)-n;i<SZ(s);i++) printf("%c",s[i]);printf("\n");}
void ASCII_Chart(){int i,j,k;printf("ASCII Chart:(30-129)\n");FOR(i,30,50){REP(j,5){k=i+j*20;printf("%3d---> '%c'   ",k,k);}printf("\n");}}


//int month[]={-1,31,28,31,30,31,30,31,31,30,31,30,31};  //Not Leap Year
//string monthName[]={"","January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
//string dayName[]={"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={-1,-1,+0,+1,+1,+0};int dy[]={-1,+1,+2,+1,-1,-2}; //Hexagonal Direction

//#include<conio.h> //for using getch();

//struct pq{ int cost,node; pq(int _cost=0,int _node=0){cost=_cost;node=_node;}bool operator<(const pq &b)const {return cost>b.cost;}}; // Min Priority Queue
//bool comp(pq a,pq b){ return a.cost < b.cost;} //Asc Sort by cost

struct matrix
{
    int row,col;
    int mat[2][2];

    matrix(int _row=0,int _col=0)
    {
        row=_row;col=_col;
        for(int i=0;i<row;i++) for(int j=0;j<col;j++) mat[i][j]=0;
    }
    matrix operator*(const matrix &B)const
    {
        int i,j,k;
        matrix temp(row,B.col);

        REP(i,row) REP(j,B.col) REP(k,col)
            temp.mat[i][j]=(temp.mat[i][j]+mat[i][k]*B.mat[k][j]);
        return temp;
    }
    matrix operator+(const matrix &B)const
    {
        int i,j;
        matrix temp(row,col);

        REP(i,row) REP(j,col)
            temp.mat[i][j]=mat[i][j]+B.mat[i][j];
        return temp;
    }
    void print(int row,int col)
    {
        int i,j;
        REP(i,row) {REP(j,col) cout<<mat[i][j]<<" ";  cout<<endl;}
    }
};

matrix PowerMat(matrix A,int P)     //Compute A^steps
{
    int i;
    matrix R(A.row,A.col);

    REP(i,R.row) R.mat[i][i]=1;

    while(P)
    {
        if(P&1)
            R=(R*A);
        P>>=1;
        A=(A*A);
    }
    return R;
}

//Matrix Power Efficiently Calculate using pre process
// M[0]=M^1, M[1]=M^2, M[2]=M^4, M[3]=M^8, M[4]=M^16, M[5]=M^32,.....

matrix M[50];

matrix PowerMatPre(matrix &A, int steps)
{
    int i;
    matrix ans(A.row,A.col);

    REP(i,ans.row) ans.mat[i][i]=1;

    for(i=30;i>=0;i--)
    {
        if(two(i)<=steps)
        {
            ans=(ans*M[i]);
            steps-=two(i);
        }
    }
    return ans;
}

int main()
{
    int row,col,i,j,N;

    matrix A(4,4),B(4,4),C(4,4);

    cin>>row>>col;

    REP(i,row) REP(j,col) scanf("%d",&A.mat[i][j]);
    cin>>N;
    C=PowerMat(A,N);
    C.print(row,col);

    return 0;
}

/*
Input:

->Addition:

3 3

1 2 3
4 5 6
7 8 9

2 9 8
0 -1 8
4 6 7

Output:

3 11 11
4 4 4
11 14 16

->Multiplication
2 2

3 2
5 6

2 6
8 7

Output:
22 32
58 72

->PowerMat
//Obviously row and col are same
4 4
0 1 1 0
1 0 0 1
1 0 0 1
0 1 1 0
4
Output:
8 0 0 8
0 8 8 0
0 8 8 0
8 0 0 8

*/
