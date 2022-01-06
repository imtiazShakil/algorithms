#include <stdio.h>
#include <string.h>

#define MAX 100

int parent[MAX];
int rank[MAX];
bool color[MAX];

void make_set(int vertice)
{
    rank[vertice]=0;
    parent[vertice]=vertice;
    return ;
}

int find_set(int vertice)
{
    if(parent[vertice]!=vertice)
        parent[vertice]=find_set(parent[vertice]);

    return parent[vertice];
}

void link(int u,int v)
{
    if(rank[u]>rank[v])
        parent[v]=u;
    else parent[u]=v;

    if(rank[u]==rank[v])  rank[v]++;

    return ;
}

void u_nion(int u,int v)
{
    link(find_set(u),find_set(v));

    return ;
}

int main(void)
{
    //freopen("out_459.txt","w+",stdout);
    //freopen("in_459.txt","r",stdin);

    int loop,max,i,highest_rank,root;
    char str[10],ch2,ch1,ch3;
    bool flag=false;
    scanf("%d",&loop);
    //printf("A %d\n",'A');
    while(loop--)
    {
        scanf(" %c",&ch1);

        //printf("%s\n",str);
        max=ch1-'A';
        //printf("max %d\n",max);
        //for(i=0;i<=max;i++) connection[i]=0;
        for(i=0;i<=max;i++) make_set(i);
        //scanf("%c",&ch3);
        int c=0;
        while(gets(str))
        {
            if(strlen(str)==0 && c!=0 ) break;

            if(strlen(str)) u_nion(str[0]-'A',str[1]-'A');
            c++;
        }
        for(i=0;i<=max;i++) color[i]=0;
        for(i=0,highest_rank=0;i<=max;i++)
        {
            root=find_set(i);//printf("i=%c root %c\n",i+'A',root+'A');
            if(!color[root]) {highest_rank++;color[root]=true;}
//            if(connection[root]>highest_rank) highest_rank=connection[root];
        }
        if (flag) printf("\n%d\n",highest_rank);
        else printf("%d\n",highest_rank);

        flag=true;

    }


    return 0;
}

