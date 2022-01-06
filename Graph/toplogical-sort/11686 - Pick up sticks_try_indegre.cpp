#include <stdio.h>
#include <queue>
#include <vector>
#include <map>
#define MAX 1000100
using namespace std;

vector<int>V[MAX];
vector<int>result;
map<int,int>M;
int indeg[MAX],n;
//bool exist[MAX];

void toplogical_sort(void)
{
    queue<int>Q;
    int i,node;
    result.clear();
    for(i=1;i<=n;i++)
    {
        if(!indeg[i]) {Q.push(i);result.push_back(i);}
    }
    while(!Q.empty())
    {
        node=Q.front();Q.pop();
        for(i=0;i<V[node].size();i++)
        {
            indeg[V[node][i]]--;
            if(indeg[V[node][i]]==0) {Q.push(V[node][i]);result.push_back(V[node][i]);}
        }
    }
    return ;
}
int main(void)
{
    int m,i,u,v,j;
    while(scanf("%d %d",&n,&m)==2 && (n||m))
    {
        for(i=1;i<=n;i++) {V[i].clear();indeg[i]=0;}
        for(i=0;i<m;i++)
        {
            scanf("%d %d",&u,&v);
            V[u].push_back(v);
        }
        for(i=1;i<=n;i++)
        {
            M.clear();
            for(j=0;j<V[i].size();j++)
            {
                    M[V[i][j]]=i;
            }
            V[i].clear();
            for(map<int,int>::iterator I=M.begin();I!=M.end();I++)
            {
                indeg[I->first]++;
                V[I->second].push_back(I->first);
            }
        }
//        for(i=1;i<=n;i++) for(j=0;j<V[i].size();j++) printf("V[%d] = ->%d\n",i,V[i][j]);
//        for(i=1;i<=n;i++) printf("indeg [ %d ] => %d\n",i,indeg[i]);
        toplogical_sort();
//        for(i=1;i<=n;i++) printf("indeg [ %d ] => %d\n",i,indeg[i]);
        for(i=1,j=0;i<=n;i++)
        {
            if(indeg[i]) {j=1;break;}
        }
        if(j) printf("IMPOSSIBLE\n");
        else
        {
            for(i=0;i<result.size();i++) printf("%d\n",result[i]);
        }
    }

}
