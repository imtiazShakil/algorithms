#include "stdio.h"
#include "stdlib.h"

#include "iostream"
#include "queue"
#include "stack"

using namespace std;

// Complexity O(n)
int getLongestRangeWhereDifferenceBetweenMIN_MAXisSmallerthenQ( int Q , int arr[] ,int lenOfArr)
{
    deque< pair<int,int> >minQ; /// stores index,value , think of this as minimum priority queue ( ascending order )
    deque< pair<int,int> >maxQ; /// think of this as maximum priority queue ( descending order )

    int left,right; /// stores the actual left and right index
    int ans=0;      /// stores the actual length of the range

    int last=-1;
    for(int i=0;i<lenOfArr;i++)
    {
        /// arr[i] must be inserted at the back of both the deques

        while( !minQ.empty() )
        {
            if( abs( minQ.front().second - arr[i] ) >= Q ) {
                last=max(last,minQ.front().first);
                minQ.pop_front();
            }
            else break;
        }

        while( !maxQ.empty() )
        {
            if( abs( maxQ.front().second - arr[i] ) >= Q ) {
                last=max(last,maxQ.front().first);
                maxQ.pop_front();
            }
            else break;
        }

        while(!minQ.empty())
        {
            /// 1 2 6 7 <-- insert 4
            /// Result : 1 2 4 6 7
            /// but here {6,7} are useless as they will never be the minimum item of the deque
            /// as they don't have any effect so we remove them

            if( minQ.back().second >= arr[i] ) minQ.pop_back();
            else break;
        }

        /// same goes for maxQ
        while(!maxQ.empty())
        {
            if( maxQ.back().second <= arr[i] ) maxQ.pop_back();
            else break;
        }


        minQ.push_back( make_pair( i,arr[i] ) );
        maxQ.push_back( make_pair( i,arr[i] ) );

        if(ans< i-last)
        {
            ans=i-last;
            left=last+1;
            right=i;
        }
    }

    cout<<"Left "<<left<<" Right "<<right<<endl;
    return ans;
}

// Complexity O(n)
int leftMost[1000];
void getLeftMostIndexForEachItemOfTheArrayWhereItIsSmaller( int arr[] , int lenOfArr)
{
    stack< pair<int,int> > ST; /// stores indx,value

    for(int i=0;i<lenOfArr;i++)
    {
        leftMost[i]=i;
        while( !ST.empty() )
        {
            if( ST.top().second > arr[i] ) {
                    leftMost[i] = ST.top().first;
                    ST.pop();
            }
            else break;
        }
        ST.push( make_pair( i,arr[i] ) );
    }

    cout<<"Left most index for each item in array where current item is strictly smaller"<<endl;
    for(int i=0;i<lenOfArr;i++) cout<<leftMost[i]<<" ";
    puts("");
}

int main()
{
    int arr[]={ 2,5,6,3,5,4,3,10};
    int maxLen=getLongestRangeWhereDifferenceBetweenMIN_MAXisSmallerthenQ( 3 , arr , 8 );

    getLeftMostIndexForEachItemOfTheArrayWhereItIsSmaller(arr,8);

}
