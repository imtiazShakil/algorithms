/*

A string is a finite sequence of symbols that are chosen from an alphabet.
In this problem you are given two non-empty strings A and B, both contain lower case English alphabets.
You have to find the number of times B occurs as a substring of A.

Input
Input starts with an integer T (≤ 5), denoting the number of test cases.

Each case starts with two lines. First line contains A and second line contains B. You can assume than 1 ≤ length(A), length(B) ≤ 106.

Output
For each case, print the case number and the number of times B occurs as a substring of A.

*/
#include <stdio.h>
#include <iostream>
#include <string.h>

#define MAX 1000500

using namespace std;

string S,T;
int F[MAX];
char arr[MAX];

void failure_func()
{
	F[0]=0;
	int pt=0,i=1;
	while(i<(int)T.size() )
	{
		if( T[i]==T[pt] ) {F[i]=pt+1;++pt;i++;}
		else if( pt>0 ) pt=F[pt-1];
		else {F[i]=0;i++;}
	}
    return ;
}

int kmp(void)
{
    failure_func();


    int i=0,pt=0,cnt=0;
    while( i<(int)S.size() )
    {
        if( S[i]==T[pt] )
        {
            i++;pt++;
            if( pt>=(int)T.size() ) { cnt++;pt=F[pt-1]; }
        }
        else if( pt>0 ) pt=F[pt-1];
        else i++;
    }
    return cnt;
}
int main(void)
{
	int cas,loop=0,ans;
	scanf("%d",&cas);
	while(cas--)
	{
		scanf("%s",arr);
		S.clear();S=(string)arr;

		scanf("%s",arr);
		T.clear();T=(string)arr;

        ans=kmp();
        printf("Case %d: %d\n",++loop,ans);
	}

	return 0;
}
