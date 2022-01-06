#include <stdio.h>
#include <string>
#include <vector>
#include <string.h>
#include <iostream>
#include <algorithm>
#define MAX 150

using namespace std;

int val[MAX];
int n,total;
int limit;
bool color[MAX];
char str[MAX];
bool flag;

vector<string>v;

bool com(string a,string b)
{
    if(a>b) return true;
    else  return false;
}
void BT(int depth)
{
    string tmp;
    char ans[10000];
    int i,len,sum;
    if(depth==limit)
    {
        for(i=0,sum=0;i<depth;i++)
        {
            sum+=val[str[i]-'0'-1];
        }
        if(sum==total)
        {
            flag=1;
            tmp.clear();
            for(i=0,sum=0;i<depth;i++)
            {
                if(i)
                {
                    sprintf(ans,"+%d",val[str[i]-'0'-1]);
                    tmp+=ans;
//                    printf("+%d",val[str[i]-'0'-1]);
                }
                else
                {
                    sprintf(ans,"%d",val[str[i]-'0'-1]);
//                    printf("%d",val[str[i]-'0'-1]);
                    tmp+=ans;
                }
            }
            if(v.empty()) v.push_back(tmp);
            else
            {
                bool mtch=0;
                for(i=0;i<v.size();i++)
                {
                    if(v[i]==tmp)
                    {
                        mtch=1;
                        break;
                    }
                }
                if(!mtch) v.push_back(tmp);
            }

//            puts("");
        }
//        printf("d %d * ",depth);
//        printf("%s\n",str);
        return ;
    }
    for(i=1;i<=n;i++)
    {
        if(!color[i])
        {
            if(depth>0)
            {
                if(i>(str[depth-1]-'0'))
                {
                    str[depth]=i+'0';
                    color[i]=true;
                    BT(depth+1);
                    color[i]=false;
                }
            }
            else
            {
                str[depth]=i+'0';
                color[i]=true;
                BT(depth+1);
                color[i]=false;
            }
        }
    }
}
int main(void)
{
    int max_n,i;
    while(scanf("%d %d",&total,&n)==2 && n)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d",&val[i]);
        }
        printf("Sums of %d:\n",total);
        v.clear();
        for(limit=1,flag=0;limit<=n;limit++)
        {
            memset(str,0,sizeof(str));
            BT(0);
        }
        if(v.empty()) {printf("NONE\n");continue;}
        sort(v.begin(),v.end(),com);
        for(i=0;i<v.size();i++) cout<<v[i]<<endl;
    }

//    while(scanf("%d %d",&n,&limit)==2 )
//    {
//
//        BT(0);
//    }
}
