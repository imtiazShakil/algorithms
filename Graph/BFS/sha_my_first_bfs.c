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

        if(!val) {i++;} //printf("for %d  max =%d\n",i,max[i][0]);
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
            //printf("for %d = %d  true= %d \n",i,val,relation[i][val]);
        }

    }


    //printf("Length %d\n",len-1);


}


void bfs(int size,int source)
{
        int i=1,j,p=-1,vertex=source,k,t;
        for(j=1;j<SIZE;j++)
            for(k=1;k<SIZE;k++) distance[j][k]=200;

        k=-1,t=0;
        colour[vertex]=true;
        //printf("colour[%d] = true\n",vertex);
        quee[++p]=vertex;
        //printf("quee[%d] = %d\n",p,quee[p]);
        distance[vertex][vertex]=0;
        //printf("distance[%d][%d] = %d\n",vertex,vertex,distance[vertex][vertex]);
        while(isempty(quee))
        {
            i=quee[t++];
            //printf("quee[%d] = %d\n",t-1,i);

            for(j=0;j<=max[i][0];j++)
                if(relation[i][j] && !colour[j])
                {
                    distance[vertex][j]=distance[vertex][i]+1;
                    //printf("distance[%d][%d] = distance[%d][%d] +1 =%d\n",vertex,j,vertex,i,distance[vertex][j]);
                    colour[j]=true;
                    //printf("colour[%d] = true\n",j);
                    quee[++p]=j;
                    //printf("quee[%d] =%d\n",p,j);

                }
            quee[++k]=0;
            //printf("quee[%d] = %d\n",k,quee[k]);
        }


        //for(j=1;j<=max[i][0];) ;
    //}

}

int isempty(short arr[])
{
    int i;
    for(i=0;i<SIZE;i++) if(arr[i]) return 1;
    return 0;
}
