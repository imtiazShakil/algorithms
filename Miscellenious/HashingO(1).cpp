/// Author: Syed Shahriar Manjur (Dip)
/// Modified by Imtiaz Shakil Siddique

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

//no two level hash required for both method even for string related hash

//easy to code
//sometimes more time consuming even for less collision
struct Map
{
    static const int M = 1400007; //mod value
    long long v[M]; //the value
    int f[M]; //number of occurence
    void init()
    {
        memset(f,0,sizeof(f));
    }
    void insert(long long val)
    {
       int p = val%M;
       while(f[p] && v[p]!=val)  //check for collision
       {
            p++;if(p==M) p = 0;
       }
       f[p]++;v[p]=val;
    }
    int query(long long val)
    {
        int p = val%M;
        while(f[p] && v[p]!=val)
        {
            p++;if(p==M) p = 0;
        }
        if(v[p]==val) return f[p];
        return 0;
    }
}m;

//more safer
//keep the collided values like a queue
//less time consuming in case of less collision
struct HASH{
    static const int H = 1000003 , N = 1000008; //H=mod value //N>=H
    int head[H],next[N],sz; //sz=size of a queue  //head and next for maintaining the queue
    int val[H];
    long long q[N];
    void init(){
        memset(head,-1,sizeof(head));
        sz = 0;
    }
    void insert(const long long &u) {
        int v = u % H;
        for (int i = head[v]; i != -1; i = next[i]) { //check for exact same value
            if (q[i] == u) {
                val[i]++;
                return;
            }
        }

        //collision or no entry
        q[sz] = u;
        val[sz] = 1;
        next[sz] = head[v];
        head[v] = sz++;
    }
    int query(const long long &u) {
        int v = u % H;
        for (int i = head[v]; i != -1; i = next[i]) {
            if (q[i] == u) {
                return val[i];
            }
        }
        return 0;
    }
}H;


int main()
{
    //srand(time(NULL));
    //freopen("A.txt","r",stdin);
    //freopen("B.txt","w",stdout);
    return 0;
}
