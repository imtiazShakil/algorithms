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
#define print3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define PI (2*acos(0))
#define ERR 1e-5
#define ll long long
#define VI vector<int>
#define mem(a,b) memset(a,b,sizeof a)
#define pb push_back
#define popb pop_back
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define MAX 100005
#define SZ(x) (int)x.size()
#define paii pair<int,int>
#define oo (1<<25)
#define rep(x,n)        for(int x=0;x<(int)(n);x++)
#define Contains(X,item)        ((X).find(item) != (X).end())
#define popc(i) (__builtin_popcount(i))
#define fs      first
#define sc      second

///ll rrr[]={1,0,-1,0};ll ccc[]={0,1,0,-1}; //4 Direction
///int rrr[]={1,1,0,-1,-1,-1,0,1};int ccc[]={0,1,1,1,0,-1,-1,-1};//8 direction
///int rrr[]={2,1,-1,-2,-2,-1,1,2};int ccc[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
///int rrr[]={2,1,-1,-2,-1,1};int ccc[]={0,1,1,0,-1,-1}; //Hexagonal Direction
///ll month[]={31,28,31,30,31,30,31,31,30,31,30,31}; //month

using namespace std;
///finds the sum of an array in logn time
///update & change the array

int arr[MAX];
int s_tree[4*MAX];///max node capacity reduce to 3*MAX if mem short

int segment_tree(int node,int i,int j)
{
    if(i==j) return s_tree[node]=arr[i];

    s_tree[node]=segment_tree(node*2,i,(i+j)/2 ) + segment_tree(node*2 + 1, (i+j)/2 + 1,j) ;
    return s_tree[node];
}
int query(int node,int lft,int rght,int i,int j)
{
    if(i>rght || j<lft) return 0; /// lft & rght are outside the range< i , j>

    if( lft>=i && rght<=j ) return s_tree[node]; /// lft & rght is inside <i ,j>

    int mx=query(node*2 , lft, (lft+rght)/2 , i,j );
    mx=mx+query(node*2 + 1, (lft+rght)/2 + 1,rght, i, j);
    return mx;
}

int update(int node,int lft,int rght,int indx)
{
    if(lft==rght && lft== indx) return s_tree[node]=arr[indx];

    int mid=(lft+rght)/2;
    if(indx>mid) update(node*2 + 1, mid+1 ,rght,indx);
    else update(node*2 , lft ,mid , indx);

    s_tree[node]=s_tree[node*2] + s_tree[node*2 + 1];
    return s_tree[node];
}

int main(void)
{
    int loop,itm,n,m,x,y,sum;
    scanf("%d",&loop);
    char str[100];

    while(loop--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++) scanf("%d",&arr[i]);
        segment_tree(1,0,n-1);

        scanf("%d",&m);
        while(m--)
        {
            scanf("%s %d %d",str,&x,&y);
            if(!strcmp(str,"Inquire"))
            {
                 sum=query(1,0,n-1,x-1,y-1);
                 print1(sum);
            }
            else if(!strcmp(str,"Add"))
            {
                arr[x-1]+=y;
                update(1,0,n-1,x-1);

            }
            else if(!strcmp(str,"Delete"))
            {
                arr[x-1]-=y;
                if( arr[x-1] <0) arr[x-1]=0;
                update(1,0,n-1,x-1);
            }
        }
    }
    return 0;
}

