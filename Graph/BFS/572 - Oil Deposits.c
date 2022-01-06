#include <string.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
using namespace std;

#define MAX 102
void bfs(int x_cor,int y_cor);

char str[MAX][MAX];
bool colour[MAX][MAX];


int main(void)
{
    int m,n,i,j,oil;

    while(scanf("%d %d",&m,&n)==2 && m && n)
    {
        memset(colour,false,sizeof(bool));
        memset(str,0,sizeof(char));

        for(i=0;i<m;i++) scanf("%s",str[i]);

        for(i=0;i<m;i++)
            for(j=0;j<n;j++)
                if(str[i][j]=='@') colour[i][j]=true;


        for(i=0,oil=0;i<m;i++)
            for(j=0;j<n;j++)
            {
                if(colour[i][j])
                {
                    bfs(i,j);
                    ++oil;
                }

            }

        printf("%d\n",oil);
    }

    return 0;
}

void bfs(int x_cor,int y_cor)
{
    int rrr[]={-1,-1,-1,0,1,1,1,0};
    int ccc[]={-1,0,1,1,1,0,-1,-1};

    int row,col,i,p,q;
    queue<int>Q;

    Q.push(x_cor);
    Q.push(y_cor);
    colour[x_cor][y_cor]=false;

    while(!Q.empty())
    {
        row=Q.front();
        Q.pop();
        col=Q.front();
        Q.pop();
        for(i=0;i<8;i++)
        {
            p=row+rrr[i];
            q=col+ccc[i];
            if(row>-1 && row<=MAX && col>-1 && col<=MAX && colour[p][q])
            {
                Q.push(p);
                Q.push(q);
                colour[p][q]=false;
            }
        }
    }

}

