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

ll nCrFirstMethod(int n, int r)
{
    if(n<r) return 0;
    ll sum1,sum2,m,val;
    sum1=sum2=1;
    m=max(r,n-r);
    for(int i=m+1,k=1;i<=n;i++,k++)
    {
        sum1*=i;
        sum2*=k;
        val=__gcd(sum1,sum2);
        sum1/=val;
        sum2/=val;
    }
    return sum1;
}

unsigned int comb[100][100];

void nCrSecondMethod()
{
    comb[0][0]=1;
    for(int i=1;i<100;i++) {
        comb[i][0]=1;
        for(int j=1;j<=i;j++) comb[i][j]=comb[i-1][j-1] + comb[i-1][j];
    }
    return ;
}

int main()
{

}
