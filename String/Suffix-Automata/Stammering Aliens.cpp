/*
Given an integer m, and a string s, representing the message, your task is to find the longest substring of s that appears at least m times.
For example, in the message baaaababababbababbab, the length-5 word babab is contained 3 times, namely at positions 5, 7
and 12 (where indices start at zero). No substring appearing 3 or more times is longer (see the first example from the sample input).
 On the other hand, no substring appears 11 times or more (see example 2).

In case there are several solutions, the substring with the rightmost occurrence is preferred (see example 3).
Input :
The input contains several test cases. Each test case consists of a line with an integer m (m >= 1),
the minimum number of repetitions, followed by a line containing a string s of length between m and 40 000, inclusive.
All characters in s are lowercase characters from "a" to "z". The last test case is denoted by m = 0 and must not be processed.
Output :

Print one line of output for each test case. If there is no solution, output none;
otherwise, print two integers in a line, separated by a space. The first integer denotes the maximum length of a substring appearing at least m times;
the second integer gives the rightmost starting position of this substring.

Sample Input
3
baaaababababbababbab
11
baaaababababbababbab
3
cccccc
0
Sample Output
5 12
none
4 2
*/

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
#define MAX 40200
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
    int len,link,right,cnt;
    map<char,int>next;
    state() {
        next.clear();
        cnt=0;
        right=-1;
    }
}st[2*MAX] ,*top[2*MAX];

int sz,last;
void sa_init()
{
    sz=last=0;
    st[0]=state();
    st[0].len=0;
    st[0].link=-1;

    sz++;
}

void extend_automata(char ch , int right_index)
{
    int cur=sz++,p;
    st[cur]=state();
    st[cur].len=st[last].len+1;
    st[cur].right=right_index;

    for(p=last;p!=-1 && st[p].next.count(ch)==0 ;p=st[p].link) st[p].next[ch]=cur;
    if(p==-1) st[cur].link=0;
    else {
        int q=st[p].next[ch];
        if(st[q].len==st[p].len+1) st[cur].link=q;
        else {
            int clone=sz++;
            st[clone]=state();
            st[clone].len=st[p].len+1;
            st[clone].link=st[q].link;
            st[clone].next=st[q].next;
            st[clone].right=st[q].right;

            for( ; p!=-1 && st[p].next[ch]==q; p=st[p].link) st[p].next[ch]=clone;
            st[q].link=st[cur].link=clone;
        }
    }
    last=cur;
}

int c[2*MAX];
char arr[MAX];

paii calc(int threshold)
{
    memset(c, 0, sizeof c);
    int tot_len=strlen(arr);

    for(int i=0;i<sz;i++) c[st[i].len]++;
    for(int i=1;i<=tot_len;i++) c[i]+=c[i-1];
    for(int i=0;i<sz;i++) top[--c[st[i].len]] = &st[i];

    int p=0,cur=0;
    while(cur<tot_len)
    {
        p=st[p].next[arr[cur]];
        st[p].cnt=1;
        cur++;
    }
    for(int i=sz-1;i>=0;i--)
    {
        state *p= top[i];

        if(p->link==-1) continue;
        st[p->link].cnt+= p->cnt;
        st[p->link].right=max(st[p->link].right , p->right);
    }


    int len=-1,right_most=-1;
    for(int i=1;i<sz;i++)
    {
        if(st[i].cnt>=threshold)
        {
            if(len<st[i].len) {
                len=st[i].len;
                right_most=st[i].right-len+1;
            } else if(len==st[i].len) {
                right_most= max( right_most, st[i].right-len+1);
            }
        }
    }
    return mp(len,right_most);
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    paii ans;

    int rept,l;
    while(scanf("%d",&rept)==1 && rept)
    {
        scanf("%s",arr); l=strlen(arr);
        sa_init();
        for(int i=0;i<l;i++) extend_automata(arr[i],i);
        ans=calc(rept);
        if(ans.fs==-1) puts("none");
        else printf("%d %d\n",ans.fs,ans.sc);
    }

    return 0;
}
