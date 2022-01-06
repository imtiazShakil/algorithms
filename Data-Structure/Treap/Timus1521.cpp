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
#define popb pop_back
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define SZ(x) (int)x.size()
#define oo (1<<25)
#define FOREACH(it,x) for(__typeof((x).begin()) it=(x.begin()); it!=(x).end(); ++it)
#define Contains(X,item)        ((X).find(item) != (X).end())
#define popc(i) (__builtin_popcountll(i))
#define fs      first
#define sc      second
#define EQ(a,b)     (fabs(a-b)<ERR)
#define MAX 100050
#define twoL(X) (((ll)(1))<<(X))

template<class T1> void deb(T1 e){cout<<e<<endl;}
template<class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<" "<<e2<<endl;}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3){cout<<e1<<" "<<e2<<" "<<e3<<endl;}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<endl;}
template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<endl;}


template<class T> T Abs(T x) {return x > 0 ? x : -x;}
template<class T> inline T sqr(T x){return x*x;}
ll Pow(ll B,ll P){      ll R=1; while(P>0)      {if(P%2==1)     R=(R*B);P/=2;B=(B*B);}return R;}
ll BigMod(ll B,ll P,ll M){     ll R=1; while(P>0)      {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M


typedef struct item * pitem;
struct item {
	int prior, value, cnt;

	pitem l, r;
	item (int prior, int value) : prior(prior), value(value), l(NULL), r(NULL) , cnt(0)
	{
	}
};

int cnt (pitem it) {
	return it ? it->cnt : 0;
}

void upd_cnt (pitem it) {
	if (it)
		it->cnt = cnt(it->l) + cnt(it->r) + 1;
}

void push_up(pitem it)
{
    upd_cnt(it);
}


void merge (pitem & t, pitem l, pitem r) {

	if (!l || !r)
		t = l ? l : r;
	else if (l->prior > r->prior)
		merge (l->r, l->r, r),  t = l;
	else
		merge (r->l, l, r->l),  t = r;

	push_up(t);
}

void split (pitem t, pitem & l, pitem & r, int key, int add = 0) {
    /// start from root t
    /// splits the tree in two parts and stores left tree in l and right in r
    /// split is done according to the key value provided
    /// for every node x in left subtree its key_xi is strictly less then key
    /// for every node x in right subtree its key_xi is greater then or equal to key

	if (!t)
		return void( l = r = 0 );

	int cur_key = add + cnt(t->l);
	if (key <= cur_key)
		split (t->l, l, t->l, key, add),  r = t;
	else
		split (t->r, t->r, r, key, add + 1 + cnt(t->l)),  l = t;

	push_up(t);
}
int findValue(pitem t,int key, int add=0 )
{
    if(!t) return -1;
    int cur_key = add + cnt(t->l);
    if(key==cur_key) return t->value;

    if(key<cur_key) return findValue(t->l,key,add);
    else return findValue(t->r,key,add+1+cnt(t->l) );
}


void output (pitem t) {
    /// prints the array

	if (!t)  return;
	output (t->l);
	printf ("%d ", t->value);
	output (t->r);
}

void insert(int indx,int val, pitem &root)
{
    /// indx is zero based
    /// if indx is greater than array size then item will be inserted in the last+1 index
    /// if indx is negative then item will be inserted in the zeroth index

    int prior= rand()%(1000000007) + 1;
    pitem pit = new item( prior , val );

    pitem leftTree=NULL,rightTree=NULL;
    split(root,leftTree,rightTree,indx,0);

    merge(leftTree,leftTree,pit);
    merge(root,leftTree,rightTree);
    return ;
}

void remove(int left, int right , pitem &root )
{
    pitem leftTree=NULL,middleTree=NULL,rightTree=NULL;

    split(root,leftTree,middleTree, left , 0 );

    split(middleTree,middleTree , rightTree , right-left+1,0  );

    merge(root,leftTree,rightTree);
    return ;
}


int main()
{
    pitem root=NULL;
    int n,k,indx;
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++) insert(i,i+1,root);
    --k;indx=0;
    while(n)
    {
        indx+=k; indx%=n;
        if(n>1) printf("%d ",findValue(root,indx));
        else printf("%d",findValue(root,indx));
        remove(indx,indx,root);
        --n;
    }
    puts("");
    return 0;
}
