#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;
vector<int>v;
vector<int>v_sz;
int main(void)
{
    int val,i,max,j,max_total,cas=0;
    bool flag=false,edit,line=false;
    v.clear();v_sz.clear();
    while(scanf("%d",&val))
    {
        if(flag && val== -1) break;
        flag=false;
        if(val==-1)
        {
            flag=true;
            for(i=1,max_total=1;i<v.size();i++)
            {
                for(j=i-1,max=1,edit=false;j>=0;j--)
                {
                    if(v[i]<v[j])
                    {
                        edit=true;
                        if(max<v_sz[j]) max=v_sz[j];
                    }
                }
                if(edit)
                {
                    v_sz[i]=max+1;
                    if(max+1>max_total) max_total=max+1;
                }
            }
            if(line) printf("\nTest #%d:\n",++cas);
            else printf("Test #%d:\n",++cas);
            printf("  maximum possible interceptions: %d\n",max_total);

            line=true;

            v.clear();
            v_sz.clear();
            continue;
        }
        else
        {
            v.push_back(val);
            v_sz.push_back(1);
        }

    }
    return 0;
}
