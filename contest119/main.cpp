/*

https://leetcode.com/contest/weekly-contest-119

Rank	        Name	        Score	Finish Time 	Q1 (3)	        Q2 (4)  	Q3 (6)	Q4 (8)
1712 / 3334	    claytonjwong 	7	    1:06:20	        0:33:06  *2	    0:56:20


Q1: https://leetcode.com/problems/k-closest-points-to-origin
A1: https://leetcode.com/problems/k-closest-points-to-origin/discuss/217964/Concise-C%2B%2B

Q2: https://leetcode.com/problems/largest-perimeter-triangle/
A2: https://leetcode.com/problems/largest-perimeter-triangle/discuss/217961/Concise-C%2B%2B


*/


#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>
#include <limits>
#include <cmath>


using namespace std;


class Solution
{
public:

    using Point = vector< int >;
    using Points = vector< Point >;

    Points kClosest( Points& P, int K )
    {
        auto distance = []( auto a, auto b ){ return sqrt( a*a + b*b ); };
        partial_sort( P.begin(), P.begin() + K, P.end(),
            [&]( const Point& p, const Point& q ){ return distance( p[0], p[1] ) < distance( q[0], q[1] ); });
        return { P.cbegin(), P.cbegin() + K };
    }

};

//class Solution
//{
//public:
//
//    using Point = vector< int >;
//    using Points = vector< Point >;
//
//    Points kClosest( Points& P, int K )
//    {
//        partial_sort( P.begin(), P.begin() + K, P.end(),
//            [&]( const auto& p, const auto& q ){ return sqrt( p[0]*p[0] + p[1]*p[1] ) < sqrt( q[0]*q[0] + q[1]*q[1] ); });
//        return { P.cbegin(), P.cbegin() + K };
//    }
//
//};


int main()
{

    Solution s;
    Solution::Points points{ {3,3}, {5,-1}, {-2,4} };
    auto result = s.kClosest( points, 2 );

    return 0;
}


/*
using Collection = vector< int >;

class Solution
{
public:

    int largestPerimeter( Collection& A )
    {
        sort( A.begin(), A.end() );
        for( int N = int( A.size() ); N - 3 >= 0; --N )
            if( A[ N-3 ] + A[ N-2 ] > A[ N-1 ])
                return( A[ N-3 ] + A[ N-2 ] + A[ N-1 ] );
        return 0;
    }

};

int main()
{
    Collection A{ 3,6,2,3 };
    Solution s;
    cout << s.largestPerimeter( A ) << endl;
    return 0;
}
*/
