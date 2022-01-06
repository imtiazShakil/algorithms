#include <stdio.h>
#include <queue>
#define MAX 200
using namespace std;


int dist[MAX][MAX];
bool color[MAX][MAX];
char mat[MAX][MAX];
int r,c;
void bfs(int x_cor,int y_cor,char ch)
{
    int i,j,p,q,row,col;
    if(ch=='Z')
    {
        int rrr[]={-1,-2,-2,-1,1,2,2,1};
        int ccc[]={-2,-1,1,2,2,1,-1,-2};
        color[x_cor][y_cor]=true;

        for(i=0;i<8;i++)
        {
            p=x_cor+rrr[i];
            q=y_cor+ccc[i];
            if(p>=0 && p<r && q>=0 && q<c) color[p][q]=true;
        }
        return ;
    }
    if(ch=='K')
    {
        int rrr[]={-1,-1,-1,0,1,1,1,0};
        int ccc[]={-1,0,1,1,1,0,-1,-1};
        queue<int>Q;
        color[x_cor][y_cor]=true;
        dist[x_cor][y_cor]=0;
        Q.push(x_cor);Q.push(y_cor);
        while(!Q.empty())
        {
            row=Q.front();Q.pop();
            col=Q.front();Q.pop();
            for(i=0;i<8;i++)
            {
                p=row+rrr[i];
                q=col+ccc[i];
                if(p>=0 && p<r && q>=0 && q<c && !color[p][q])
                {
                    dist[p][q]=dist[row][col]+1;
                    color[p][q]=true;
                    Q.push(p);
                    Q.push(q);
                }
            }
        }
        return ;
    }
}
int main(void)
{
    int loop,i,j, start[2] ,end[2];
    scanf("%d",&loop);
    while(loop--)
    {
        scanf("%d %d",&r,&c);
        for(i=0;i<r;i++) scanf("%s",mat[i]);

        for(i=0;i<r;i++) for(j=0;j<c;j++) {color[i][j]=0;dist[i][j]=0;}

        for(i=0;i<r;i++)
            for(j=0;j<c;j++)
                {
                    if(mat[i][j]=='A') {start[0]=i;start[1]=j; continue;}
                    if(mat[i][j]=='B') {end[0]=i;end[1]=j; continue;}

                    if(mat[i][j]=='Z') bfs(i,j,'Z');
                }

        color[end[0]][end[1]]=0;
        bfs(start[0],start[1],'K');

        if(dist[end[0]][end[1]]) printf("Minimal possible length of a trip is %d\n",dist[end[0]][end[1]]);
        else printf("King Peter, you can't go now!\n");
    }
}
