#include <stdio.h>
#include <string.h>

char mat[27][27];
char rel[27][27][8][2];


int main(void)
{
    freopen("The Seasonal War.in","r",stdin);
    freopen("352 - The Seasonal War.out","w+",stdout);

    int square,up,down,left,right;
    while(scanf("%d",&square)==1)
    {


        int i,j;

        memset(mat,0,sizeof(mat));
        memset(rel,0,sizeof(rel));

        for(i=1;i<square + 1 ; i++)
            scanf("%s",mat[i]);

        for(i=1;i<square+1;i++)
            for(j=1;j<square + 1;j++)
                {
                    if(mat[i][j])
                    {
                        up=i-1;
                        down=i+1;
                        left=j-1;
                        right=j+1;

                        if(mat[i][j]==mat[up][j]) {rel[i][j][0][0]=up; rel[i][j][0][1]=j ;}
                        if(mat[i][j]==mat[down][j]) {rel[i][j][1][0]=down; rel[i][j][1][1]=j ;}
                        if(mat[i][j]==mat[i][left]) {rel[i][j][2][0]=i; rel[i][j][2][1]=left ;}
                        if(mat[i][j]==mat[i][right]) {rel[i][j][3][0]=i; rel[i][j][3][1]=right ;}
                        if(mat[i][j]==mat[up][right]) {rel[i][j][4][0]=up; rel[i][j][4][1]=right ;}
                        if(mat[i][j]==mat[up][left]) {rel[i][j][5][0]=up; rel[i][j][5][1]=left ;}
                        if(mat[i][j]==mat[down][right]) {rel[i][j][6][0]=down; rel[i][j][6][1]=right ;}
                        if(mat[i][j]==mat[down][left]) {rel[i][j][7][0]=down; rel[i][j][7][1]=left ;}

                    }
                }

        int k;
        for(i=1;i<square+1;i++)
            for(j=1;j<square + 1;j++)
                {
                    if(mat[i][j])
                    {
                        for(k=0;k<8;k++)
                        {

                        }

                    }
                }

    }
}
