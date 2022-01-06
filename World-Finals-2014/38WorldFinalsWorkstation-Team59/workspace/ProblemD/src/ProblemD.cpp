//============================================================================
// Name        : ProblemD.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<stdio.h>
#include<string.h>
#include<string>
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<sstream>
#include<math.h>
#include<stdlib.h>
#include <assert.h>

#define SZ(a) (int)(a.size())
#define pb push_back
#define INF (1<<20)
#define MAX 10000100

using namespace std;

int col[300];
int dist[300];
int n;

vector<string>adj[300];
vector<int>sol[300];

int dfs(int now, int dest)
{
	if(now==dest) return dist[now]=0;
    col[now]=1;
	int ret = INF;

	int i, j;
	string str;
	int nxt, nret;
	for(i=0;i<SZ(adj[now]);i++)
	{
		str = adj[now][i];
		nret=0;
		for(j=0;j<SZ(str);j++)
		{
			    nxt = str[j]-'a';
				if(col[nxt]==1)
				{
					nret=INF;
					break;
				}
				if(col[nxt]==2)
				{
					nret=max(nret,dist[nxt]+1);
					continue;
				}
				nret = max(nret, dfs(nxt, dest)+1);

		}
		ret = min(ret, nret);
	}
	col[now]=2;
	dist[now]=ret;
	return ret;
}


int main()
{
	int i, j, k;
	scanf("%d", &n);

	for(i=0;i<n;i++)
		adj[i].clear();

	string str;

	for(i=0;i<n;i++)
	{
		int op;
		scanf("%d ", &op);
		for(j=0;j<op;j++)
		{
			cin>>str;
			adj[i].pb(str);
		}
	}

	for(i=0;i<n;i++)
		sol[i].clear();

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			memset(col, 0, sizeof col);
			int ans;
			if(i==j) ans = 0;
			else
				ans = dfs(i, j);
			sol[i].pb(ans);
		}
	}

	for(i=0;i<n;i++)
	{
		for(j=0;j<SZ(sol[i]);j++)
		{
			if(j!=0) printf(" ");
			if(sol[i][j]>=INF) printf("-1");
			else {
				printf("%d", sol[i][j]);
			//assert(sol[i][j]<=25);
			}
		}
		printf("\n");
	}
	printf("\n");

	return 0;
}
