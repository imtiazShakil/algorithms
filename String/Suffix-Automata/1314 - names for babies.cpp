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
#define MAX 10020
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

struct state{
    int len,link;
    map<char,int>next;
    state(){
        len=0;link=-1;
        next.clear();
    }
};

state st[2*MAX];

int sz,last;
void sa_init()
{
    sz=0;last=0;
    st[0]=state();
    sz++;
}

void sa_extend(char ch)
{
    int cur=sz++;
    st[cur]=state();
    st[cur].len=st[last].len+1;
    int p;
    for(p=last ;p!=-1 && st[p].next.count(ch)==0 ; p=st[p].link )  st[p].next[ch]=cur;
    if(p==-1) st[cur].link=0;
    else {
        int q=st[p].next[ch];
        if(st[q].len==st[p].len+1) st[cur].link=q;
        else {
            int clone=sz++;
            st[clone].len=st[p].len+1;
            st[clone].next=st[q].next;
            st[clone].link=st[q].link;
            for(;p!=-1 && st[p].next[ch]==q ;p=st[p].link) st[p].next[ch]=clone;

            st[q].link=clone;
            st[cur].link=clone;
        }
    }
    last=cur;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    char arr[MAX];
    int mn,mx,len,mn_len,mx_len;
    int cas,loop=0,ans;
    scanf("%d",&cas);
    while(cas--)
    {
        scanf("%s",arr);
        scanf("%d %d",&mn,&mx);
        sa_init();
        len=strlen(arr);
        for(int i=0;i<len;i++) sa_extend(arr[i]);
        ans=0;
        for(int i=1;i<sz;i++)
        {
//            deb("len",st[i].len,"node",i,"link",st[i].link);
            mn_len=st[st[i].link].len+1;
            mx_len=st[i].len;

            mn_len=max(mn,mn_len);
            mx_len=min(mx,mx_len);
            if(mx_len-mn_len+1>0) ans+=mx_len-mn_len+1;
        }
        printf("Case %d: %d\n",++loop,ans);
    }

    return 0;
}

