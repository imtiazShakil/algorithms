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
#define print3(a,b,c) cout<<a<<" "<<b<<" "<<endl
#define PI (2*acos(0))
#define ERR 1e-5
#define ll long long
#define VI vector<int>
#define mem(a,b) memset(a,b,sizeof a)
#define pb push_back
#define popb pop_back

#define MAX 40
#define oo (1<<25)

using namespace std;


int mat[MAX][MAX],max_nd;

void floyd_warshall(void)
{
    int i,j,k;
    for(k=0;k<=max_nd;k++)
        for(i=0;i<=max_nd;i++)
            for(j=0;j<=max_nd;j++)
            {
                if(mat[i][j] && mat[j][i] )
                {
                    mat[i][j]=-1;mat[j][i]=-1;
                }
                else if(mat[i][k]!=0 && mat[k][j]!=0)
                {
                    if(mat[i][k]==-1 || mat[k][j]==-1)
                    {
                        mat[i][j]=-1;//mat[j][i]=-1;
                    }
                    else if(mat[i][j]!=-1)
                    {
                        mat[i][j]+=mat[i][k] * mat[k][j];
                    }
                }
            }


    return ;
}
int main(void)
{
    int n,i,n1,n2,j,cas=0;
    while(scanf("%d",&n)==1)
    {
        mem(mat,0);
        max_nd=0;

        for(i=0;i<n;i++)
        {
            scanf("%d %d",&n1,&n2);
            max_nd=max(max_nd,n1);
            max_nd=max(max_nd,n2);

            mat[n1][n2]=1;
        }


        floyd_warshall();
        printf("matrix for city %d\n",cas++);
        for(i=0;i<=max_nd;i++,putchar('\n'))
            for(j=0;j<=max_nd;j++)
            {
                if(j) printf(" %d",mat[i][j]);
                else printf("%d",mat[i][j]);
            }

//        putchar('\n');
    }
    return 0;
}
