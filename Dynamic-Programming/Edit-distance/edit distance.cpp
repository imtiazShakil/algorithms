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


#define print1(a) cout<<a<<endl
#define print2(a,b) cout<<a<<" "<<b<<endl
#define print3(a,b,c) cout<<a<<" "<<b<<" "<<endl
#define PI (2*acos(0))
#define ERR 1e-5
#define ll long long
#define VI vector<int>
#define mem(a,b) memset(a,b,sizeof a)
#define pb push_back
#define popb pop_back
#define all(x) (x.begin(),x.end())
#define mp make_pair
#define MAX 60
#define SZ(x) (int)x.size()
#define paii pair<int,int>

#define oo (1<<25)
//ll rrr[]={1,0,-1,0};ll ccc[]={0,1,0,-1}; //4 Direction
//int rrr[]={1,1,0,-1,-1,-1,0,1};int ccc[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int rrr[]={2,1,-1,-2,-2,-1,1,2};int ccc[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int rrr[]={2,1,-1,-2,-1,1};int ccc[]={0,1,1,0,-1,-1}; //Hexagonal Direction
//ll month[]={31,28,31,30,31,30,31,31,30,31,30,31}; //month

using namespace std;

int dp[MAX][MAX];
string str, txt;

int rec(int i,int j)
{

    if(i==SZ(str) && j==SZ(txt)) return 0;

    int &ret=dp[i][j];
    if(ret!=-1) return ret;
    ret=oo;
    if(i<SZ(str) && j<SZ(txt))
    {
        if( str[i]==txt[j])
        {
            ret=min(ret,rec(i+1,j+1));
        }
        else
        {
            ret=min(ret,rec(i+1,j+1) + 1);///replace
            ret=min(ret,rec(i,j+1) + 1);///add 2 str
            ret=min(ret,rec(i+1,j) + 1);///del frm str
        }
    }
    else
    {
        if(j<SZ(txt)) ret=min(ret,rec(i,j+1) + 1);
        if(i<SZ(str) ) ret=min(ret,rec(i+1,j) + 1);
    }
    return ret;
}

int main(void)
{
    ///str can be modified ,added,deleted
    ///but txt can't be changed

    while(cin>>str>>txt)
    {
        mem(dp,-1);
        int ans=rec(0,0);
        cout<<ans<<endl;
    }


    return 0;
}

