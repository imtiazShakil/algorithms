#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

vector<int>prices;

int main(void)
{
        prices.push_back(39);
        prices.push_back(88);
        prices.push_back(67);
        prices.push_back(5);
        prices.push_back(69);
        prices.push_back(87);
        prices.push_back(82);
        prices.push_back(64);
        prices.push_back(58);
        prices.push_back(61);


        vector<int>ans;
	    vector<int>lis,ways_of_lis;

	    int i,j,temp,longest_seq=0,tot_ways;

	    for(i=0;i<prices.size();i++) {lis.push_back(0);ways_of_lis.push_back(0);}

	    for(i=0;i<prices.size();i++)
	    {
	        for(j=i-1,temp=0;j>=0;j--)  if(prices[j]<prices[i]) temp=max(temp,lis[j]);
	        lis[i]=temp+1;
	        for(j=i-1;j>=0;j--)
	        {
	            if(lis[j]==temp) if(prices[j]<prices[i]) ways_of_lis[i]+=ways_of_lis[j];
	        }
	        if(ways_of_lis[i]==0) ways_of_lis[i]=1;
	        longest_seq=max(longest_seq,lis[i]);
	    }
//        for(i=0;i<prices.size();i++) cout<<"val "<<prices[i]<<"  lis  "<<lis[i]<<endl;
	    for(i=0,tot_ways=0;i<prices.size();i++)
	    {
	        if(longest_seq==lis[i])
	        {
	            tot_ways+=ways_of_lis[i];
	        }
	    }
	    ans.push_back(longest_seq);
	    ans.push_back(tot_ways);

        cout<<"longest sequence  "<<ans[0]<<" total ways  "<<ans[1]<<endl;

        return 0;

}
