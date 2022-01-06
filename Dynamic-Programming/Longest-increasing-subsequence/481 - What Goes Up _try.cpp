#include <stdio.h>
#include <stack>
#include <queue>
#include <iostream>
#include <vector>
using namespace std;

//struct num
//{
//    int par;
//    int lis_val;
//    int val;
//} ;

//vector<num>v;
vector<int>v;
vector<int>lis;

void find_lis(vector<int> &a, vector<int> &b)
{
	vector<int> p(a.size());
	int u, v;

	if (a.empty()) return;

	b.push_back(0);

	for (size_t i = 1; i < a.size(); i++)
        {
                // If next element a[i] is greater than last element of current longest subsequence a[b.back()], just push it at back of "b" and continue
		if (a[b.back()] < a[i])
                {
			p[i] = b.back();
			b.push_back(i);
			continue;
		}

                // Binary search to find the smallest element referenced by b which is just bigger than a[i]
                // Note : Binary search is performed on b (and not a). Size of b is always <=k and hence contributes O(log k) to complexity.
		for (u = 0, v = b.size()-1; u < v;)
                {
			int c = (u + v) / 2;
			if (a[b[c]] < a[i]) u=c+1; else v=c;
		}

                // Update b if new value is smaller then previously referenced value
		if (a[i] < a[b[u]])
                {
			if (u > 0) p[i] = b[u-1];
			b[u] = i;
		}
	}

	for (u = b.size(), v = b.back(); u--; v = p[v]) b[u] = v;
}

int main(void)
{
//    freopen("in_481.txt","r",stdin);
    int n,i,j,max,ans,total_max=1,mom,top;

    v.clear();
    lis.clear();

    while(scanf("%d",&n)==1)
    {
        v.push_back(n);
    }
    find_lis(v,lis);
    printf("%d\n-\n",(int)lis.size());
    for(i=0;i<(int)lis.size();i++)
    {
        printf("%d\n",v[lis[i]]);
    }
    return 0;


}

