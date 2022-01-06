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

/// coded by Imtiaz Shakil Siddique
#define MAX 10000

vector<int>adj[MAX];
int tim[MAX],low[MAX];
vector< pair<int,int> > bridges;
int TIMER;
bool isArticulationPoint[MAX];


void find_bridge( int  now, int par ) /// initially par should be -1
{
    tim[now]=low[now] = ++TIMER;
    int to;
    for(int i=0;i< adj[now].size() ; i++ )
    {
        to = adj[now][i];
        if(to==par) continue;
        if( tim[to]==0 ) /// to is yet not visited
        {
            find_bridge(to,now);
            low[now] = min( low[now] , low[to] ); /// updating low[now] from child low[to] [ to is direct child of now ]
            if( tim[now] < low[to] ) { /// because to can't move upward before now and now itself
                bridges.push_back(  make_pair( now,to ) );
            }
        }
        else if( tim[to] < tim[now] ) low[now] = min(low[now],tim[to]); /// this is a back_edge thus low[now] updated from tim[to]
    }
    return ;
}

void find_articulation_point(int now , int par ) /// initially par should be -1
{
    tim[now]=low[now] = ++TIMER;
    int to, subtree=0;
    for(int i=0;i< adj[now].size() ; i++ )
    {
        to = adj[now][i];
        if(to==par) continue;
        subtree++;
        if( tim[to]==0 ) /// to is yet not visited
        {
            find_articulation_point(to,now);
            low[now] = min( low[now] , low[to] ); /// updating low[now] from child low[to] [ to is direct child of now ]

            if( tim[now] <= low[to] && par!=-1 ) { /// because to can't move upward before now
                                                   /// now is not the root
                isArticulationPoint[now] = true;
            }
        }
        else if( tim[to] < tim[now] ) low[now] = min(low[now],tim[to]); /// this is a back_edge thus low[now] updated from tim[to]
    }
    if( par==-1 && subtree>1 ) isArticulationPoint[now]=true; /// now is the root where it has more then one children
    return ;
}

int initBridge(int totalNodes) {  /// assuming nodes are zero(0) based
                            /// this method should be called to calculate bridges
                            /// in case of multiple edges between two nodes this bridge finding method will FAIL
    memset( tim,0,sizeof(tim) );
    memset( low,0,sizeof(low) );
    TIMER=0;
    bridges.clear();
    for(int i=0;i<totalNodes;i++) if( tim[i]==0 ) find_bridge(i,-1);
}

int initArticulation(int totalNodes) {  /// assuming nodes are zero(0) based
                            /// this method should be called to calculate bridges
                            /// in case of multiple edges between two nodes this articulation finding method will WORK :) !!!
    memset( tim,0,sizeof(tim) );
    memset( low,0,sizeof(low) );
    memset( isArticulationPoint,0,sizeof(isArticulationPoint) );
    TIMER=0;
    for(int i=0;i<totalNodes;i++) if( tim[i]==0 ) find_articulation_point(i,-1);
}


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);

    return  0;
}


