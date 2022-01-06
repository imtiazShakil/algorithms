#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long long LL;
typedef pair<int,int> paii;


#define fs first
#define sc second
#define pb push_back
#define oo (1<<29)
#define FOREACH(it,x) for(__typeof((x).begin()) it=(x.begin()); it!=(x).end() ; ++it)
#define mem(a,b) memset(a,b,sizeof a)
#define SZ(x) (int)x.size()
#define fr(i,a,b) for(i=a;i<=b;i++)
#define round(i,a) i = (a<0) ? a -.5 : a + .5 ;
#define makeFast __std::ios_base::sync_with_stdio (false); cin.tie(0);
#define mp make_pair

#define MAX 2002

int PR,PC,MR,MC;
ll rBase[MAX] , cBase[MAX];
char pat[MAX][MAX];
char grid[MAX][MAX];

ll hashPat[MAX][MAX] , hashGrid[MAX][MAX];

void preProcess()
{
    rBase[0]=1;
    cBase[0]=1;
    for(int i=1;i<MAX;i++) rBase[i] = rBase[i-1]*(10000007LL);
    for(int i=1;i<MAX;i++) cBase[i] = cBase[i-1]*(10000009LL);
    return ;
}

void processPat()
{
    for(int i=1;i<=PR;i++)
        for(int j=1;j<=PC;j++) hashPat[i][j] = (pat[i][j]-'X')*rBase[i]*cBase[j];


    for(int i=1;i<=PR;i++)
        for(int j=1;j<=PC;j++) hashPat[i][j] += hashPat[i][j-1] + hashPat[i-1][j] -hashPat[i-1][j-1];
//    for(int i=1;i<=PR;i++) for(int j=1;j<=PC;j++) hashPat[i][j]+= hashPat[i][j-1];
//    for(int j=1;j<=PC;j++) for(int i=1;i<=PR;i++) hashPat[i][j]+= hashPat[i-1][j];

    return ;
}

void processGrid()
{
    for(int i=1;i<=MR;i++)
        for(int j=1;j<=MC;j++) hashGrid[i][j] = (grid[i][j]-'X')*rBase[i]*cBase[j];

    for(int i=1;i<=MR;i++)
        for(int j=1;j<=MC;j++) hashGrid[i][j] += hashGrid[i][j-1] + hashGrid[i-1][j] - hashGrid[i-1][j-1];
//    for(int i=1;i<=MR;i++) for(int j=1;j<=MC;j++) hashGrid[i][j]+= hashGrid[i][j-1];
//    for(int j=1;j<=MC;j++) for(int i=1;i<=MR;i++) hashGrid[i][j]+= hashGrid[i-1][j];

    return ;
}

int calc()
{
//    ll nowHash;
    int ret=0;
    for(int i=1;i<=MR-PR+1;i++)
        for(int j=1;j<=MC-PC+1;j++) {
//            nowHash = hashGrid[i+PR-1][j+PC-1] - hashGrid[i-1][j+PC-1] - hashGrid[i+PR-1][j-1] + hashGrid[i-1][j-1] ;
            if( hashPat[PR][PC]*rBase[i-1]*cBase[j-1] == hashGrid[i+PR-1][j+PC-1] - hashGrid[i-1][j+PC-1] - hashGrid[i+PR-1][j-1] + hashGrid[i-1][j-1] ) ret++;
        }
    return ret;
}



int main()
{
//    freopen("in.txt","r",stdin);

    preProcess();
    while(scanf(" %d %d %d %d ",&PR,&PC,&MR,&MC)==4)
    {
//        for(int i=1;i<=PR;i++ , getchar())  for(int j=1;j<=PC;j++) pat[i][j] = getchar();//scanf("%s",pat[i]+1);
//        for(int i=1;i<=MR;i++,getchar())  for(int j=1;j<=MC;j++) grid[i][j] = getchar();//scanf("%s",grid[i]+1);

        for(int i=1;i<=PR;i++)  scanf("%s",&pat[i][1]);
        for(int i=1;i<=MR;i++)  scanf("%s",&grid[i][1]);


        processPat();processGrid();
        printf("%d\n",calc());

    }
    return 0;
}

