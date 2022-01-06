#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#define MAX 50
using namespace std;


int num_b,dim,who,tot_mx;
int seqnce[MAX];
//int parent[MAX];
//int indx[MAX];

struct boxes
{
    vector<int>v_dim;
    int indx;
    int parent;
} ;

vector<boxes>v;

bool com(boxes a,boxes b)
{
    int i;
    for(i=0;i<dim;i++)
    {
        if(a.v_dim[i]!=b.v_dim[i]) if(b.v_dim[i]<a.v_dim[i]) return true;
    }
    return false;
}
bool check(boxes a ,boxes b)
{
    int i;
    for(i=0;i<dim;i++)
    {
        if(b.v_dim[i]>=a.v_dim[i]) return false;
    }

    return true;
}
void longest_increasing_subsequence(void)
{
    int i,j,tmp_par;
    bool flag;
    for(i=0;i<num_b;i++) seqnce[i]=1;

    int mx;
    who=0;
    v[0].parent= -1;
    for(i=1,tot_mx=1;i<num_b;i++)
    {
//        printf("i %d ",i);
        for(j=i-1,mx=1,flag=false;j>=0;j--)
        {
//            printf(" j =%d ",j);
            if(check(v[j],v[i]))
            {
//                puts("chk true");
                if(mx<=seqnce[j])
                {
                    mx=seqnce[j];
                    flag=true;
                    tmp_par=j;
                }
            }
        }
        if(flag)
        {
            seqnce[i]=mx+1;
            if(tot_mx<mx+1)
            {
                tot_mx=mx+1;
                who=i; ///who has the total maximum subsequence
            }
            v[i].parent=tmp_par;
//            cout<< "who  "<<who <<"  indx "<<i<<"  org indx "<<v[i].indx<<"  par "<<v[i].parent<<" max " <<seqnce[i]<<" total "<<tot_mx<<endl;
        }
//        puts("");
    }
    return ;

}
int main(void)
{
//    string tmp;
//    char str[100];
    int val;
    int i,j;
    boxes tmp;
    while(scanf("%d %d",&num_b,&dim)==2)
    {
//        tmp.clear();
        v.clear();
//        printf("v size %d",v.size());
        for(i=0;i<num_b;i++)
        {
            tmp.v_dim.clear();
            tmp.indx=i+1;
            tmp.parent=0;
            for(j=0;j<dim;j++)
            {
                scanf("%d",&val);
                tmp.v_dim.push_back(val);
//                sprintf(str,"%d",&val);
            }
            v.push_back(tmp);
        }
        for(i=0;i<num_b;i++)
        {
            sort(v[i].v_dim.begin(),v[i].v_dim.end());
        }
        sort(v.begin(),v.end(),com);


//        for(i=0;i<num_b;i++,puts(""))
//            for(j=0;j<dim;j++)
//            cout<<" "<< v[i].v_dim[j];

        longest_increasing_subsequence();
        printf("%d\n",tot_mx);
        int prnt=who;
        bool space=false;
        while(prnt!=-1)
        {
            if(space) printf(" %d",v[prnt].indx);
            else printf("%d",v[prnt].indx);

            prnt=v[prnt].parent;

            space=true;
        }
        puts("");
        for(i=0;i<num_b;i++)
        {
            v[i].parent=-1;
            v[i].indx=0;
        }
    }

    return 0;
}
