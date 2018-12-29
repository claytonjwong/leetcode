#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <queue>
#include <numeric>
#include <algorithm>
#include <tuple>
#include <iterator>


using namespace std;

/*
class Solution
{
public:
    int repeatedNTimes( vector< int >& A, unordered_map< int, int > counter={} )
    {
        for( const auto x: A ) ++counter[ x ];
        for( const auto& p: counter ) if( p.second == A.size() / 2 ) return p.first;
    }
};
*/


class Solution
{
public:
    int repeatedNTimes( vector< int >& A, unordered_set< int > unique={} )
    {
        for( auto x: A ) if( ! unique.insert( x ).second ) return x;
    }
};


int main()
{

    Solution s;
    vector<int> A{ 1,2,3,3 };
    cout << s.repeatedNTimes( A ) << endl;

    A = { 2,1,2,5,3,2 };
    cout << s.repeatedNTimes( A ) << endl;

    A = { 5,1,5,2,5,3,5,4 };
    cout << s.repeatedNTimes( A ) << endl;


    return 0;
}


/*
using VI = vector< int >;
using Stack = VI;
class Solution
{
public:
    int maxWidthRamp( VI& A, Stack S={}, int index=0, int value=0, int ans=0 )
    {


        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> A{ 6,0,8,2,1,5 };
    cout << s.maxWidthRamp( A ) << endl;

    return 0;
}
*/
