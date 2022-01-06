
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

#include <string.h>
#include <stdio.h>

using namespace std;
#define print1(a) cout<<a<<endl
#define pb        push_back
#define mem(a,b)       memset(a,b,sizeof(a))
#define BE(a)     a.begin(),a.end()
#define sorta(a)  sort(BE(a))
#define SZ(a)     (int)a.size()
#define inf       1000000000
#define lim 1001000
#define range RNG

int n,k;

struct range{
	int a;
	int b;
	int in;
	range(int aa=0,int bb=0,int inin=0)
	{
		a=aa;
		b=bb;
		in=inin;
	}
};
int heap[4*lim];

bool comp1(range p,range q)
{
	if(p.b==q.b) return p.a<q.a;
	return p.b>q.b;
}

bool comp2(range p,range q)
{
	if(p.a==q.a) return p.b>q.b;
	return p.a<q.a;
}

void update(int in,int st,int end,int x,int val)
{
	if(st>end) return;
	if(x>end) return;
	if(x<st) return;
	if(st==end && st==x)
	{
		heap[in]=val;
		return;
	}

	int mid=(st+end)/2;
	update(2*in,st,mid,x,val);
	update(2*in+1,mid+1,end,x,val);
	heap[in]=max(heap[2*in],heap[2*in+1]);
	return;
}

int query(int in,int st,int end,int x,int y)
{
	if(x>y) return 0;
	if(st>y) return 0;
	if(end<x) return 0;
	if(st>=x && end<=y)
		return heap[in];
	int mid=(st+end)/2;
	return max(query(2*in,st,mid,x,y),query(2*in+1,mid+1,end,x,y));
}

int giveans(int lft,int rght)
{
	int ret=0;
	while(lft<=rght)
	{
		int newlft=query(1,1,n,1,lft)+1;
		if(newlft<=lft) return inf;
		lft=newlft;
		ret++;
	}
	return ret;
}


void printans(int var)
{
	if(var>=inf) print1("impossible");
	else print1(var);
	return;
}

int main() {
	while(cin>>n>>k)
	{
		mem(heap,0);
		int ai,bi;
		vector<range> candi1,candi2;
		int i;
		for(i=1;i<=k;i++)
		{
			scanf("%d %d",&ai,&bi);
		    if(ai<=bi)
		    	update(1,1,n,ai,bi);
		    if(ai>bi)
		    {
		    	candi1.pb(range(ai,bi,i));
		    	candi2.pb(range(ai,bi,i));
		    }
		}
        sort(BE(candi1),comp1);
        sort(BE(candi2),comp2);
        int ans=giveans(1,n);
        if(SZ(candi1)==0)
        {
        	printans(ans);
        	continue;
        }

        if(candi1[0].b==n || candi2[0].a==1)
        {
        	print1(1);
        	continue;
        }

        if(candi1[0].in==candi2[0].in)
        {
        	ans=min(ans,giveans(candi1[0].b+1,candi2[0].a-1) + 1);
        	printans(ans);
        	continue;
//        	print1(giveans(candi1[0].b+1,candi2[0].a-1));
        }


        ans=min(ans,giveans(candi1[0].b+1,candi1[0].a-1) + 1);
        ans=min(ans,giveans(candi2[0].b+1,candi2[0].a-1) + 1);
        ans=min(ans,giveans(candi1[0].b+1,candi2[0].a-1) + 2);
        printans(ans);
	}
	return 0;
}
