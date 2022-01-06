#include <iostream>
#include <vector>
#include <algorithm>

#define all(x) (x).begin(),(x).end()
using   namespace std;


int main()
{
    int myints[] = {10,20,30,30,20,10,10,20};
    vector<int> v(myints,myints+8);

    sort(all(v));
    v.resize( unique(all(v)) -v.begin() );

    for(int i=0;i<(int)v.size();i++) cout<<v[i]<<endl;

    return 0;
}

/*

Output :
--------
10
20
30

*/
