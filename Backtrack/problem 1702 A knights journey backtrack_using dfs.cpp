#include <stdio.h>
#include <string>

using namespace std;

#define MAX 20
int n,m;
bool color[MAX][MAX];
char str[30][3];
int rrr[]={-1,1,-2,2,-2,2,-1,1};
int ccc[]={-2,-2,-1,-1,1,1,2,2};
bool sol;

void dfs(int x,int y,int depth)
{
    if(sol==true) return ;
    int i,p,q;

    color[x][y]=true;
    str[depth-1][0]=y+'A'-1;
    str[depth-1][1]=x+'0';
    if(depth==n*m)
    {
        for(i=0;i<depth;i++)
        {
            printf("%s",str[i]);
        }
        sol=true;
        puts("");
        return ;
    }
    for(i=0;i<8;i++)
    {
        p=x+rrr[i];
        q=y+ccc[i];
        if(p>=1 && q>=1 && p<=n && q<=m && !color[p][q])
        {
//            if(sol==true) return ;
            dfs(p,q,depth+1);
            color[p][q]=false;
            if(sol==true) return ;
        }
    }
    return;
}
int main(void)
{
    int loop,row,col,cas=0,i,j;
    scanf("%d",&loop);
    while(loop--)
    {
        scanf("%d %d",&n,&m);

        for(i=0;i<MAX;i++)
            for(j=0;j<MAX;j++) color[i][j]=0;

        sol=false;
        printf("Scenario #%d:\n",++cas);
        for(col=1;col<=m;col++)
            for(row=1;row<=n;row++)
            {
                if(sol) break;
                if(!color[row][col])
                {
//                    puts("dfs started");
                    dfs(row,col,1);
                }
            }
//        printf("sol %d\n",sol);
        if(!sol)printf("impossible\n\n");
        else printf("\n");
//        dfs(1,1,1);
    }
}
