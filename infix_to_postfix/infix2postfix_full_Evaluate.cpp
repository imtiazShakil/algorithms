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
vector< pair< char , string> >instrn;
int ending[1000],order[300];

///  ------------------------
///  |ZOJ Problem Set - 1246|
///  ------------------------


string rec(int start,int end)
{
    if(start>end) return "";
    string ret="",tmp,mult;
    for(int i=start;i<=end; )
    {
        if(ending[i]!=-1)
        {
            mult=instrn[i].sc;
            if(SZ(mult)) mult=mult+"*";
            tmp=rec(i+1,ending[i]-1);
            if(SZ(tmp) && SZ(ret)  ) ret=ret+"+"+mult+"("+tmp+")";
            else if(SZ(tmp) && SZ(ret)==0  ) ret=mult+"("+tmp+")";

            i=ending[i]+1;
        }
        else {
            tmp=instrn[i].sc;
            if(SZ(ret)) ret=ret+"+"+tmp;
            else ret=tmp;
            i++;
        }
    }
    return ret;
}
string preprocess()
{

//    for(int i=0;i<SZ(instrn);i++) cout<<instrn[i].fs<<" "<<instrn[i].sc<<" ";puts("");
    stack< int >S;
    mem(ending,-1);
    for(int i=0;i<SZ(instrn);i++)
    {
        if(instrn[i].fs=='O') continue;
        else if(instrn[i].fs=='E') {
            ending[ S.top() ]=i;
            S.pop();
        }
        else S.push(i);
    }
//    for(int i=0;i<SZ(instrn);i++) if(ending[i]!=-1) cout<<"start "<<i<<" end "<<ending[i]<<endl;

//    puts("Final Equation");
//    deb(rec(0,SZ(instrn)-1));

    string res=rec(0,SZ(instrn)-1);
    return res;
}
vector<string> infix_to_postfix(string &str)
{
    vector<string>inp;
    string val;
    for(int i=0;i<SZ(str);i++)
    {
        if(  isdigit(str[i]) )
        {
            val="";
            int j;
            for( j=i; j<SZ(str) ;j++ )
            {
                if( !isdigit(str[j]) ) break;
                val=val+str[j];
            }
            i=j-1;
            inp.pb(val);
        }
        else {
            string tt="";tt.pb(str[i]);
            inp.pb(tt);
        }
    }

    stack<string>S;
    vector<string>res;

    string tmp;
    for(int i=0;i<SZ(inp);i++)
    {
        if( isalpha(inp[i][0]) ) res.pb(inp[i]);
        else if( isdigit(inp[i][0]) ) res.pb(inp[i]);
        else {
            if(inp[i][0]=='(') S.push(inp[i]);
            else if( S.empty() ) S.push(inp[i]);
            else if(inp[i][0]==')')
            {
                tmp=S.top();
                while(tmp[0]!='(') {
                    res.pb( S.top() );
                    S.pop();
                    tmp=S.top();
                }
                S.pop();
            }
            else {
                while(true)
                {
                    if(S.empty()) break;
                    tmp=S.top();
                    if( order[tmp[0]] >= order[inp[i][0]] ) {
                        res.pb(S.top());
                        S.pop();
                        if(S.empty()) break;
                        tmp=S.top();
                    }
                    else break;
                }
                S.push( inp[i] );
            }
        }
    }
    while(!S.empty()) {res.pb(S.top()); S.pop();}
    return res;
}

struct data
{
    vector< pair< int ,int > >term;
    int con;

    data( vector< pair< int ,int > >a , int b)
    {
        term=a;con=b;
    }
    data()
    {
        term.clear();con=0;
    }
};

void print(data a)
{
    for(int i=0;i<SZ(a.term);i++) deb("coeff",a.term[i].fs ," n^",a.term[i].sc);
    deb("constant",a.con);
}
data multiply( data a, data b )
{

    data ret,tmp,c;
    if(SZ(a.term)==0) {
        tmp=a;
        a=b;
        b=tmp;
    }

    for(int i=0;i<SZ( a.term );i++) {
        for(int j=0;j<SZ( b.term );j++)
        {
            ret.term.pb( mp( a.term[i].fs * b.term[j].fs , a.term[i].sc+b.term[j].sc) );
        }
        ret.term.pb( mp( a.term[i].fs*b.con , a.term[i].sc  )  );
    }

    for(int j=0;j<SZ(b.term);j++)
    {
        ret.term.pb(  mp( b.term[j].fs*a.con , b.term[j].sc ) );
    }
    ret.con=a.con*b.con;

    map<int,int>M;
    for(int i=0;i<SZ(ret.term);i++) M[ ret.term[i].sc ]+=ret.term[i].fs;
    ret.term.clear();

    FOREACH(it,M)
    {
        if(it->sc==0 || it->fs==0) continue;
        ret.term.pb( mp(it->sc , it->fs) );
    }

    return ret;
}

data add( data a, data b)
{
    map<int,int>M; ///power ,coeff
    data ret;

    for(int i=0;i<SZ(a.term);i++) M[ a.term[i].sc ]+= a.term[i].fs;
    for(int i=0;i<SZ(b.term);i++) M[ b.term[i].sc ]+= b.term[i].fs;

    FOREACH(it,M)
    {
        if(it->sc==0 || it->fs==0) continue;
        ret.term.pb( mp( it->sc , it->fs ) );
    }
    ret.con=a.con+b.con;
    return ret;
}

data evaluate(vector<string>&inp)
{
    int val;
    stringstream ss;
    data a,b,tmp;
    stack<data>S;
    for(int i=0;i<SZ(inp);i++)
    {
        if(inp[i][0]=='+')
        {
            a=S.top();S.pop();
            b=S.top();S.pop();
            tmp=add(a,b);
            S.push(tmp);
        }
        else if(inp[i][0]=='*')
        {
            a=S.top();S.pop();
            b=S.top();S.pop();
            tmp=multiply(a,b);
            S.push(tmp);
        }
        else if( isdigit(inp[i][0]) )
        {
            ss.clear();
            ss<<inp[i];
            ss>>val;
            tmp.term.clear();
            tmp.con=val;

            S.push( tmp  );
        }
        else {

            tmp.term.clear();
            tmp.term.pb(mp(1,1));
            tmp.con=0;
            S.push(tmp);
        }
    }

    return S.top();
}

bool com(paii a, paii b)
{
    return a.sc>b.sc;
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    order['+']=1;
    order['*']=2;

    vector<string>inp;
    stringstream ss;
    int cas,loop=0,cnt;
    scanf("%d",&cas);getchar();
    string str,tmp;
    char prv;
    while(cas--)
    {
        instrn.clear();cnt=0;
        while( getline(cin,str) )
        {
            if(SZ(str)==0) continue;
            else break;
        }
        ss.clear();ss<<str;

        while(ss>>tmp)
        {
            if(tmp=="BEGIN") cnt++ , instrn.pb( mp( 'B',"" )  );
            else if(tmp=="END") --cnt , instrn.pb( mp('E',"")  );
            else if( tmp!="LOOP" && tmp!="OP" ) instrn.pb(  mp(  prv,tmp ) );

            if(tmp=="LOOP") prv='L',cnt++;
            if(tmp=="OP") prv='O';
        }

        while(cnt)
        {
            getline(cin,str);
            ss.clear();ss<<str;

            while(ss>>tmp)
            {
                if(tmp=="END") --cnt , instrn.pb( mp('E',"")  );
                else if( tmp!="LOOP" && tmp!="OP" ) instrn.pb(  mp(  prv,tmp ) );

                if(tmp=="LOOP") prv='L',cnt++;
                if(tmp=="OP") prv='O';
            }
        }

        str=preprocess();
        inp.clear();inp=infix_to_postfix(str);

        data ans=evaluate(inp);
        sort(all(ans.term),com);

        printf("Program #%d\n",++loop);
        printf("Runtime = ");

        paii gg;int fff=0,aaa=0;
        for(int i=0;i<SZ(ans.term);i++)
        {
            gg=ans.term[i];
            if(gg.fs==0 || gg.sc==0) continue;

            if(fff) printf("+");
            if( gg.fs>1 ) printf("%d*n",gg.fs);
            else printf("n");
            if(gg.sc>1) printf("^%d",gg.sc);
            fff=1;
            aaa=1;
        }
        if(fff && ans.con) aaa=1,printf("+%d",ans.con);
        else if(fff==0 && ans.con) aaa=1,printf("%d",ans.con);
        if(!aaa) printf("0");
        puts("\n");
    }

    return 0;
}
