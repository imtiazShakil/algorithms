#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<string>
#include<sstream>
#include<ctype.h>
#include<vector>
#include<map>
#include<queue>
#include<math.h>
#include<algorithm>
#include<set>

#define pb push_back
#define PI acos(-1.0)
#define SZ(a) (int)a.size()
#define csprnt printf("Case %d:\n", cas++);
#define EPS 1e-9
#define MAX 100010
#define ll long long
#define INF (1<<30)
#define pii pair<int, int>
#define MP make_pair
#define MOD 20090717
int xx[] = {1,1,0,-1,-1,-1,0,1}, yy[] = {0,1,1,1,0,-1,-1,-1}; //eight direction

using namespace std;

struct tt
{
	int par, child[26];
	int str;
};

tt T[110];
char words[12][15];
int dp[110][26][(1<<10)+5];
int sz;
int m, val;

void init(int lim)
{
	for(int i=0;i<=lim;i++)
	{
		T[i].par=0;
		memset(T[i].child, 0, sizeof T[i].child);
		T[i].str=0;
	}
	sz=1;
	return;
}

void build(int n)
{
	int i, j, last, len;
	char ch;
	for(i=0;i<n;i++)
	{
		last=0;
		len = strlen(words[i]);
		for(j=0;j<len;j++)
		{
			ch = words[i][j] - 'a';
			if(T[last].child[ch]==0)
				T[last].child[ch]=sz++;
			last = T[last].child[ch];
		}
		T[last].str |= (1<<i);
	}

	queue<int>Q;
	for(i=0;i<26;i++)
	{
		if(T[0].child[i])
		{
			Q.push(T[0].child[i]);
			T[T[0].child[i]].par = 0;
		}
	}
	int u, v, k;
	while(!Q.empty())
	{
		u = Q.front(); Q.pop();
		for(i=0;i<26;i++)
		{
			if(T[u].child[i])
			{
				v = T[u].child[i];
				k = T[u].par;
				while(k>0 && T[k].child[i]==0)
					k = T[k].par;
				T[v].par = T[k].child[i];
				T[v].str |= T[T[k].child[i]].str;
				Q.push(v);
			}
			else
                T[u].child[i] = T[T[u].par].child[i];
		}
	}
	T[0].str = 0;
	return;
}

int rec(int node, int cur, int mask)
{
    if(cur==m)
    {
        int popc = __builtin_popcount(mask);
        if(popc>=val) return 1;
        return 0;
    }
    int &ret = dp[node][cur][mask];
    if(ret!=-1) return ret;
    ret=0;
    int i, now;
    for(i=0;i<26;i++)
    {
        now = T[node].child[i];
        ret = (ret + rec(now, cur+1, mask|(T[now].str)))%MOD;
    }
    return ret;
}

int main()
{
    int n, cas=1;
	sz=1;
	while(scanf("%d%d%d", &m, &n, &val)==3)
	{
	    if(!n && !m && !val) break;
		init(sz);
		int i, j;

		for(i=0;i<n;i++)
			scanf(" %s", &words[i]);

		build(n);

		memset(dp, -1, sizeof dp);
		int ans = rec(0, 0, 0);
		cout<<ans<<endl;
	}
    return 0;
}

