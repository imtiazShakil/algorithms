
#include <stdio.h>
#include <string.h>
#define SIZE 100
bool relation[SIZE][SIZE];
bool colour[SIZE];
short max[SIZE][1];
short quee[SIZE];
short distance[SIZE][SIZE];

void bfs(int size,int source);
int isempty(short arr[]);

int main(void)
{
    int val,i=1,len;
    while(scanf("%d",&val)==1)
    {

        if(!val) {i++;}
        else if(val<0)
        {
            len=i;
            bfs(len,1);
            for(i=1;i<8;i++) printf("=> %d  ",distance[1][i]);
            putchar('\n');

            memset(relation,false,sizeof(relation));
            memset(colour,false,sizeof(colour));
            memset(max,0,sizeof(max));
            memset(distance,0,sizeof(distance));
            i=1;


        }
        else
        {
            relation[i][val]=1;
            if(max[i][0]<val) max[i][0]=val;
        }

    }



}


void bfs(int size,int source)
{
        int i,j,vertex=source,front,rear;
        for(j=1;j<SIZE;j++)
            for(i=1;i<SIZE;i++) distance[j][i]=200;

        front=rear=0;
        colour[vertex]=true;

        quee[rear++]=vertex;

        distance[vertex][vertex]=0;

        while(front<rear)
        {
            i=quee[front];
            for(j=0;j<=max[i][0];j++)
                if(relation[i][j] && !colour[j])
                {
                    distance[vertex][j]=distance[vertex][i]+1;
                    colour[j]=true;
                    quee[rear++]=j;
                }
            quee[front++]=0;

        }
}


