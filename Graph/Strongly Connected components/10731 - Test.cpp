#include <stdio.h>
#include <stack>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <string.h>
#define MAX 400
#define index ind

using namespace std;

int initial_t[MAX],tim=0,n;
int final_t[MAX],index[MAX];
bool adj[MAX][MAX],time_counter;
bool color[MAX];
bool exist[MAX];
vector<string>VC;

int com(const void *a,const void *b)
{
    int *x=(int *)a,*y=(int *)b;
    return *y-*x;
}

void dfs(int vertex)
{
    string str;
    str.clear();

    if(!exist[vertex]) return;
    if(color[vertex]) return;
    int i,j,node;
    bool flag;
    stack<int>S;
    color[vertex]=true;
    S.push(vertex);//printf("pushed (new) before stack %c\n",vertex+'A');
    if(time_counter) initial_t[vertex]=++tim;
    while(!S.empty())
    {
        node=S.top();
        for(i=0,flag=0;i<=n;i++)
        {
            if(adj[node][i] && !color[i])
            {
                S.push(i);color[i]=true;//printf("pushed %c\n",i+'A');
                if( time_counter )initial_t[i]=++tim;
                flag=true;
                break;
            }
        }
        if(!flag)
        {
            if( time_counter ) final_t[node]=++tim;
            S.pop();//printf("popped %c\n",node+'A');
//            V[group].push_back(node);
//            str[group]+=node+'A';
            if(!time_counter) str+=node+'A';
        }

    }
    //cout<<"group "<<str<<endl;
    if(!time_counter) VC.push_back(str);
    //group++;

    return ;
}
void transpose(void)
{
    bool done[MAX][MAX];
    int i,j,tmp;
    for(i=0;i<=n;i++) for(j=0;j<=n;j++) done[i][j]=0;

    for(i=0;i<=n;i++)
        for(j=0;j<=n;j++)
        {
            if(exist[i])
            {
            //adj[i][j]^=adj[j][i]^=adj[i][j]^=adj[j][i];
                if(adj[i][j] && !done[i][j] && !done[j][i])
                {

                    tmp=adj[i][j];
                    adj[i][j]=adj[j][i];
                    adj[j][i]=tmp;
    //                printf("adjacency[ %c ] [ %c ] = %d\n",i+'A',j+'A',adj[i][j]);
    //                printf("adjacency[ %c ] [ %c ] = %d\n",j+'A',i+'A',adj[j][i]);
                    done[i][j]=1;
                    done[j][i]=1;
                }
            }
        }

//    for(i=0;i<=n;i++,putchar('\n')) for(j=0;j<=n;j++) printf("adjacency[ %c ] [ %c ] = %d\n",i+'A',j+'A',adj[i][j]);
}
int main(void)
{
    //freopen("out_10731.txt","w+",stdout);

    int ques,i,node,link,j,source;
    char q1[2],q2[2],q3[2],q4[2],q5[2],q6[2];
    bool for_empty_line=0;
    while(scanf("%d",&ques)==1 && ques)
    {
        VC.clear();
        tim=0;
        for(i=0;i<MAX;i++) for(j=0;j<MAX;j++) adj[i][j]=0;
        for(i=0;i<MAX;i++) {color[i]=0;initial_t[i]=0;final_t[i]=0;exist[i]=0;index[i]=0;}

        for(i=0,n=0;i<ques;i++)
        {
            scanf("%s %s %s %s %s %s",q1,q2,q3,q4,q5,q6);
            link=q6[0]-'A';if(n<link) n=link;
            exist[link]=1;
            if(link!=q1[0]-'A') adj[link][q1[0]-'A']=1;exist[q1[0]-'A']=1;if(n<q1[0]-'A') n=q1[0]-'A';
            if(link!=q2[0]-'A') adj[link][q2[0]-'A']=1;exist[q2[0]-'A']=1;if(n<q2[0]-'A') n=q2[0]-'A';
            if(link!=q3[0]-'A') adj[link][q3[0]-'A']=1;exist[q3[0]-'A']=1;if(n<q3[0]-'A') n=q3[0]-'A';
            if(link!=q4[0]-'A') adj[link][q4[0]-'A']=1;exist[q4[0]-'A']=1;if(n<q4[0]-'A') n=q4[0]-'A';
            if(link!=q5[0]-'A') adj[link][q5[0]-'A']=1;exist[q5[0]-'A']=1;if(n<q5[0]-'A') n=q5[0]-'A';
        }
//        for(i=0;i<=n;i++,putchar('\n')) for(j=0;j<=n;j++) printf("adjacency[ %c ] [ %c ] = %d\n",i+'A',j+'A',adj[i][j]);
        //printf("n=%d %c\n",n,n+'A');
        time_counter=1;
        for(i=0;i<=n;i++)
        {
            dfs(i);
        }
//        for(i=0;i<=n;i++) if(exist[i]) printf("cord %c inital %d end %d\n",i+'A',initial_t[i],final_t[i]);

        transpose();

        for(i=0;i<MAX;i++) color[i]=0;
        for(i=0;i<=n;i++) if(exist[i]) index[final_t[i]]=i;
        qsort(final_t,n+1,sizeof(int),com);
        time_counter=0;//group=0;
//        for(i=0;i<=n;i++) printf("final %d index %c\n",final_t[i],index[final_t[i]]+'A');
        for(i=0;i<=n;i++)
        {
            source=index[final_t[i]];
            dfs(source);
        }

        for(i=0;i<VC.size();i++) sort(VC[i].begin(),VC[i].end());
        sort(VC.begin(),VC.end());
//        printf("went here\n");
//        printf("size %d\n",(int)VC.size());
        if( for_empty_line ) printf("\n");
        for(i=0;i<VC.size();i++)
        {
            for(j=0;j<VC[i].size();j++)
            {
                if(j) /*cout<<" "<<VC[i][j]<<endl;//*/printf(" %c",VC[i][j]);
                else /*cout<<VC[i][j]<<endl; //*/printf("%c",VC[i][j]);
            }
//            cout<<VC[i]<<endl;
//            printf("went here\n");
//            for(j=0;j<VC[i].size();j++)
//            {
//
//                if(j) /*cout<<" "<<VC[i][j]<<endl;//*/printf(" %c",VC[i][j]);
//                else /*cout<<VC[i][j]<<endl; //*/printf("%c",VC[i][j]);
//            }
            putchar('\n');
        }


        for_empty_line=1;
    }
}
