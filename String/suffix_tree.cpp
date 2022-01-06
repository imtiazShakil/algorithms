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
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define SZ(x) (int)x.size()
#define oo (1<<25)
#define FOREACH(it,x) for(__typeof((x).begin()) it=(x.begin()); it!=(x).end(); ++it)
#define popc(i) (__builtin_popcountll(i))
#define fs      first
#define sc      second
#define EQ(a,b)     (fabs(a-b)<ERR)
#define MAX 1000


template<class T1> void deb(T1 e){cout<<e<<endl;}
template<class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<" "<<e2<<endl;}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3){cout<<e1<<" "<<e2<<" "<<e3<<endl;}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<endl;}
template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<endl;}


struct data
{
    int next[258];
    string edge[258];
    data()
    {
        mem(next,-1);
    }
}stree[MAX];/// MAX defines total number of characters in a build string (Worst Case)

int COUNTER; /// Tracks the Current Total Node

int findNode(string &str , int &edgeId,int &cut1 , int &cut2)
{
/// parameters --> given suffix , EdgeId , character that need to be cut from oldEdge , characters that need to be cut from given suffix
/// Returns    --> The Parent Node ( in its EdgeId ) where  Child node has to be created
    int ptr=0,indx=0;

    int nd,i;
    while( true )
    {
        nd=str[indx];
        if( stree[ptr].next[ nd ]==-1 ) {  /// Current Character Not Found  means new Node has to be created
            edgeId=nd;
            cut1=0;
            cut2=indx; /// characters that need to be cut from suffix str
            return ptr;
        }
        string &tmp=stree[ptr].edge[ nd ];
        for(i=0 ; i<SZ(tmp) && indx<SZ(str); )
        {
            if( str[indx]==tmp[i]) i++,indx++;
            else break;
        }
        if(i==SZ(tmp)) ptr=stree[ptr].next[nd]; ///this ptr has been ended
        else {                                  ///this ptr hasn't been ended but the suffix string ended becuase of not matching
            edgeId=nd;
            cut1=i; /// character that need to be cut from current edge
            cut2=indx; /// characters that need to be cut from suffix str
            return ptr;
        }
    }
}

int dp[MAX];
int rec(int now) /// finds all the leaf nodes under this given node
{
    int &ret=dp[now];
    if(ret!=-1) return ret;
    ret=0;
    for(int i=0;i<257;i++) if(stree[now].next[i]!=-1) ret+=rec( stree[now].next[i] );
    if(ret==0) /// this must be a leaf node
        ret=1;

    return ret; ///this is not a leaf node ( ret holds number leaves inside it )
}

void buildSuffixTree(string &str) /// Build Complexity O(n^2)
{
    COUNTER=0;for(int i=0;i<MAX;i++) stree[i]=data();
    mem(dp,-1);
    int now,edgeId,cut1,cut2;
    string tmp=str+"$"; /// inserted a termination character ( $ ) /// Read the pdf files :)

    while(SZ(tmp)!=0) /// This loop will do for all the suffices of string str
    {
        now=findNode(tmp,edgeId,cut1,cut2);

        if(cut1==0) { ///completely new node
            stree[now].next[edgeId]=++COUNTER;
            stree[now].edge[edgeId]=tmp.substr(cut2);
        }
        else { /// must split the edge

            string oldString=stree[now].edge[ edgeId ];
            int oldNode=stree[now].next[ edgeId ];

            stree[now].next[edgeId]=++COUNTER; /// this is the intermediate new node
            stree[now].edge[ edgeId ]=  oldString.substr(0,cut1); /// parent node <now> links to this node

            int newNode=COUNTER;
            oldString.erase(0,cut1);
            stree[newNode].next[ oldString[0] ]=oldNode; /// The Old Original Edge Stripped off
            stree[newNode].edge[ oldString[0] ]=oldString;


            string newString=tmp;
            newString.erase(0,cut2);
            stree[newNode].next[ newString[0] ]=++COUNTER; /// This is the new Leaf Node
            stree[newNode].edge[ newString[0] ]=newString; /// with some of its Edge Stripped off

        }
        tmp.erase(0,1); /// first character of tmp has been erased to get the new suffix
    }
}


int patternFinding( string &str ) /// this function finds the total occurences of the pattern in the generated string
{                                   /// Finding Complexity O( length of pattern )
    int now=0,indx=0,indx2,nd;
    while(indx<SZ(str))
    {
        nd=stree[now].next[ str[indx] ];
        if(nd==-1) return 0;
        string &tmp=stree[now].edge[ str[indx] ];

        for(indx2=0;indx<SZ(str) && indx2<SZ(tmp);indx++,indx2++)
            if(str[indx]!=tmp[indx2]) break;

        if(indx2==SZ(tmp)) now=nd; /// Either this edge has been depleted so go to new node
        if(indx2<SZ(tmp) && indx<SZ(str) ) return 0;/// pattern doesn't exist

        if(indx==SZ(str)) return rec(nd); /// pattern completely found last known node is nd
    }

    return 0;
}

void traverse(int now) /// for Debuggind purpose traverse and print the whole suffix tree
{
    for(int i=0;i<256;i++)
    {
        if(stree[now].next[i]!=-1)
        {
            deb("from",now,"to",stree[now].next[i],"Edge",stree[now].edge[i]);
            traverse(stree[now].next[i]);
        }
    }
    return ;
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    string str,pat;
    while(cin>>str)
    {
        buildSuffixTree(str);
        traverse(0);

        puts("Number of Patterns ?");
        int q;scanf("%d",&q);
        while(q--) {
            cin>>pat;
            deb("Number of Occurences as substring --> ",patternFinding(pat) );
        }
    }
    return 0;
}
