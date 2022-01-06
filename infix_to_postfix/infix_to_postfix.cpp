#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <cctype>
#include <set>
#include <bitset>
#include <algorithm>
#include <list>
#include <vector>
#include <sstream>
#include <iostream>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> paii;
typedef pair< ll, ll > pall;


#define PI (2.0*acos(0))
#define ERR 1e-5
#define mem(a,b) memset(a,b,sizeof a)
#define pb push_back
#define popb pop_back
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define SZ(x) (int)x.size()
#define oo (1<<25)
#define FOREACH(it,x) for(__typeof((x).begin()) it=(x.begin()); it!=(x).end(); ++it)
#define Contains(X,item)        ((X).find(item) != (X).end())
#define popc(i) (__builtin_popcountll(i))
#define fs      first
#define sc      second
#define EQ(a,b)     (fabs(a-b)<ERR)
#define MAX 100050
#define twoL(X) (((ll)(1))<<(X))

template<class T1> void deb(T1 e){cout<<e<<endl;}
template<class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<" "<<e2<<endl;}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3){cout<<e1<<" "<<e2<<" "<<e3<<endl;}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<endl;}
template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<endl;}


template<class T> T Abs(T x) {return x > 0 ? x : -x;}
template<class T> inline T sqr(T x){return x*x;}
ll Pow(ll B,ll P){      ll R=1; while(P>0)      {if(P%2==1)     R=(R*B);P/=2;B=(B*B);}return R;}
ll BigMod(ll B,ll P,ll M){     ll R=1; while(P>0)      {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

///int rrr[]={1,0,-1,0};int ccc[]={0,1,0,-1}; //4 Direction
///int rrr[]={1,1,0,-1,-1,-1,0,1};int ccc[]={0,1,1,1,0,-1,-1,-1};//8 direction
///int rrr[]={2,1,-1,-2,-2,-1,1,2};int ccc[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
///int rrr[]={2,1,-1,-2,-1,1};int ccc[]={0,1,1,0,-1,-1}; //Hexagonal Direction
///int month[]={31,28,31,30,31,30,31,31,30,31,30,31}; //month

///  ----------------
///  | LightOJ 1309 |
///  ----------------

struct data {
    int coeff,val;
    data(int a, int b) ///3*x + 7,--> 3 coeff , 7 value
    {
        coeff=a;val=b;
    }
    data() {}
};

vector<string> infix_to_postfix(string &str , int order[] )
{
    vector<string>inp;

    string val;
    for(int i=0;i<SZ(str); i++)
    {
        if( isdigit(str[i]) )
        {
            val="";
            int j;
            for( j=i;j<SZ(str);j++)
            {
                if(!isdigit(str[j])) break;
                val=val+ str[j];
            }
            i=j-1;
            inp.pb(val);
        }
        else  { // variable is considered one character
            string tt="";tt.pb(str[i]);
            inp.pb( tt );
        }
    }

    stack<string>S;
    vector<string>res;

    string tmp;
    for(int i=0;i<SZ(inp);i++)
    {
        if(isalpha( inp[i][0] ) ) res.pb( inp[i] );///variable
        else if(isdigit( inp[i][0] ) ) res.pb( inp[i] ); ///number
        else { ///operator
            if(inp[i][0]=='(') S.push(inp[i]);
            else if(S.empty()) S.push( inp[i] );
            else if(inp[i][0]==')')
            {
                tmp=S.top();
                while(tmp[0]!='(') {
                    res.pb(S.top());
                    S.pop();
                    tmp=S.top();
                }
                S.pop(); /// ( is removed
                /// ) is not inserted into stack
            }
            else {
                while(true)
                {
                    if(S.empty()) break;
                    tmp=S.top();

                    if(  order[tmp[0]] >= order[ inp[i][0] ] ) { ///pop untill the top of the stack has a lower precedence
                        res.pb( S.top() );
                        S.pop();
                        if(S.empty()) break;
                        tmp=S.top();
                    }
                    else break;
                }
                S.push(inp[i]);
            }
        }
    }
    while(!S.empty()) {res.pb(S.top());S.pop();}
    return res;
}

int get_val(string str) {int val;stringstream ss;ss<<str;ss>>val;return val;}
data check_val(vector<string> &inp )
{
    data a,b;
    stack<data>S;
    for(int i=0;i<SZ(inp);i++)
    {
        if( isalpha( inp[i][0] ) ) S.push( data(1,0) );
        else if(isdigit(inp[i][0])) S.push( data(0, get_val(inp[i]) ) );
        else {
            b=S.top();S.pop();
            a=S.top();S.pop();

            if(inp[i][0]=='+')
                S.push( data( a.coeff+b.coeff , a.val+b.val ) );
            else if(inp[i][0]=='-')
                S.push( data( a.coeff-b.coeff , a.val-b.val ) );
            else {
                if(a.coeff==0) ///number
                    S.push( data( b.coeff*a.val , b.val*a.val) );
                else S.push( data( a.coeff*b.val , a.val*b.val) );
            }
        }
    }
    return S.top();
}
void init(int order[])
{
    mem(order,0);
    order['+']=1;
    order['-']=1;
    order['*']=2;
}
ll labs(ll vv)
{
    if(vv<0) return -1*vv;
    return vv;
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int order[400] , val[400];
    init(order);

    vector<string>s1,s2;
    data left,right;

    int x,ans;
    int flag;
    string tmp1,tmp2;
    char arr[700];
    int cas,loop=0,ok;
    scanf("%d",&cas);
    while(cas--)
    {
        scanf("%s",arr);
        tmp1="";tmp2="";flag=0;
        for(int i=0;arr[i]!='\0';i++)
        {
            if(arr[i]=='=') {flag=1;continue;}
            if(!flag) tmp1.pb(arr[i]);
            else tmp2.pb(arr[i]);
        }

        s1=infix_to_postfix(tmp1,order);
        s2=infix_to_postfix(tmp2,order);

        left=check_val(s1);
        right=check_val(s2);


        ans=0;
        x=0;
        x=left.coeff-right.coeff;
        ans=right.val-left.val;

        printf("Case %d: ",++loop);
        if(x==0 && ans) puts("no solution");
        else if(x==0 && ans==0) puts("infinitely many solutions");
        else {
            ll a=x;
            ll b=ans;
            ll g=__gcd(a,b);
            a/=g;
            b/=g;
            if(a==1) printf("%lld\n",b);
            else {
                if(a<0 || b<0 ) printf("-");
                a=labs(a);
                b=labs(b);
                printf("%lld/%lld\n",b,a);
            }
        }
    }

    return 0;
}



