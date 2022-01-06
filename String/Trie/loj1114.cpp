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
#define popc(i) (__builtin_popcount(i))
#define fs      first
#define sc      second
#define EQ(a,b)     (fabs(a-b)<ERR)
#define MAX 148000

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

struct data
{
    int edges[52];
    int complete;
    data ()
    {
        complete=0;
        mem(edges ,-1);
    }
};
int counter,loop;
data trie[MAX];
char text[110];

int get_char_val(char ch)
{
    if(ch>='A' && ch<='Z') return ch-'A';
    return ch-'a'+26;
}
void trie_insert(int node,int indx)
{
    if(text[indx]=='\0')
    {
        trie[node].complete++;
        return ;
    }
    int now=get_char_val(text[indx]);

    if(trie[node].edges[now]==-1) trie[node].edges[now]=++counter;///child created

    trie_insert(trie[node].edges[now],indx+1);

    return ;
}

int _word_count(int node,int indx)
{
    if(text[indx]=='\0') return trie[node].complete;
    int now=get_char_val(text[indx]);

    if(trie[node].edges[now]==-1) return 0;
    return _word_count( trie[node].edges[now] , indx+1 );
}

int main(void)
{
    char arr[10010];string tmp;
    int cas,n,ans,sntnce,len;
    scanf("%d",&cas);loop=1;
    while(cas--)
    {
        scanf("%d",&n);counter=0;
        for(int i=0;i<n;i++) {
            scanf(" %s",text);
            len=strlen(text);
            if(len>2) sort(&text[1],&text[1]+(len-2));

            trie_insert(0,0);
        }


        printf("Case %d:\n",loop++);
        scanf("%d ",&sntnce);
        while(sntnce--)
        {
            ans=1;
            gets(arr);
            stringstream ss(arr);

            while(ss>>text)
            {
                len=strlen(text);
                if(len>2) sort(&text[1],&text[1]+(len-2) );
                ans*=_word_count(0,0);
                if(ans==0) break;
            }
            printf("%d\n",ans);
        }
        for(int i=0;i<=counter;i++) trie[i]=data();
    }
    return 0;
}
