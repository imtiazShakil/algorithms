#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <sstream>

using namespace std;

typedef long long ll;

#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))

#define MAXN 100009

int N;
int RA[MAXN], SA[MAXN], rSA[MAXN], tmpRA[MAXN], tmpSA[MAXN];
int cnt[MAXN];
char str[MAXN];
int phi[MAXN], lcp[MAXN];

void buildLCP(){
	/* Chinese Shitty LCP + Buggy
	int L=0;
	phi[SA[0]] = -1;
	for(int i=1;i<N;i++) phi[SA[i]] = SA[i-1];
	for(int i=0;i<N;i++){
		if(phi[i]==-1){ lcp[rSA[i]]=0; continue; }
		while(str[i+L]==str[phi[i]+L]) L++;
		lcp[rSA[i]] = L;
		if(L) L--;
	}
	*/
	int mx_mtch=0,SApos,j;
    for(int i=0;i<N;i++)
    {

        SApos=rSA[i];
        if(SApos==0) continue;
        if(mx_mtch>0) mx_mtch--;

        j=SA[SApos-1];

        while( (i+mx_mtch)<N && (j+mx_mtch)<N && str[i+mx_mtch]==str[j+mx_mtch]  )
            mx_mtch++;

        lcp[SApos]=mx_mtch;
    }
    lcp[0]=0;

}
void csort(int k){
	int cub = max(N, 128);
	FILL(cnt, 0);
	for(int i=0;i<N;i++) cnt[i+k<N?RA[i+k]:0]++;
	REP(i,1,cub) cnt[i] += cnt[i-1];
	for(int i=cub-1;i>=1;i--) cnt[i] = cnt[i-1];
	cnt[0] = 0;
	for(int i=0;i<N;i++) tmpSA[ cnt[SA[i]+k<N?RA[SA[i]+k]:0]++ ] = SA[i];
	for(int i=0;i<N;i++) SA[i] = tmpSA[i];
}
void buildSA(){
	REP(i,0,N){
		RA[i] = str[i];
		SA[i] = i;
	}
	int k = 1;
	while(k<N){
		csort(k); csort(0);
		int r = 0;
		tmpRA[SA[0]] = 0;
		REP(i,1,N){
			if(RA[SA[i]]!=RA[SA[i-1]] || RA[SA[i]+k]!=RA[SA[i-1]+k]) r++;
			tmpRA[SA[i]] = r;
		}
		REP(i,0,N) RA[i] = tmpRA[i];
		if(RA[SA[N-1]]==N-1) break;
		k <<= 1;
	}
	REP(i,0,N) rSA[SA[i]] = i;
}

void printSA()
{
    for(int i=0;i<N;i++) printf("%d ",SA[i]);
    puts("");
    for(int i=1;i<N;i++) printf("%d ",lcp[i]);
    puts("");
    return ;
}

int main(){

    freopen("cas.txt","r",stdin);
    freopen("outChinese.txt","w",stdout);

	int cs;
    scanf("%d",&cs);
	REP(csn,1,cs+1){
        scanf("%s",str);
		N = strlen(str);
		str[N++] = '$';
		buildSA();
		buildLCP();

        printSA();


	}

	return 0;
}
