/*
 *
 * https://leetcode.com/contest/weekly-contest-143/ranking
 *
 * Rank	            Name	        Score	Finish Time 	Q1 (4)	    Q2 (4)	        Q3 (6)  	Q4 (6)
 * 2686 / 4271	    claytonjwong 	4	    1:05:36		                1:00:36  *1
 *
 * Q1: https://leetcode.com/problems/distribute-candies-to-people/
 * A1: https://leetcode.com/problems/distribute-candies-to-people/discuss/323409/C%2B%2B-Solution
 *
 * Q2: https://leetcode.com/problems/path-in-zigzag-labelled-binary-tree/
 * A2: https://leetcode.com/problems/path-in-zigzag-labelled-binary-tree/discuss/323290/C%2B%2B-Solution
 *
 */

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <queue>

using namespace std;

/*
using VI = vector< int >;
class Solution {
public:
    VI pathInZigZagTree( int N, VI A={1}, VI ans={} ){
        for( auto d{ 1 };; ++d ){
            auto K{ 1<<d };
            if( K > N )
                break;
            VI row( K );
            if( d % 2 == 0 )
                generate( row.begin(), row.end(), [ i=K ]() mutable { return i++; });
            else
                generate( row.rbegin(), row.rend(), [ i=K ]() mutable { return i++; });
            copy_n( row.begin(), K, back_inserter( A ) );
        }
        auto it = find( A.begin(), A.end(), N );
        for( auto i = distance( A.begin(), it ); 0 < i; i = ( i-1 ) / 2 )
            ans.push_back( A[ i ] );
        ans.push_back( 1 ); // root
        return{ ans.rbegin(), ans.rend() };
    }
};

int main() {
    Solution solution;
    auto ans = solution.pathInZigZagTree( 16 );
    copy( ans.begin(), ans.end(), ostream_iterator< int >( cout, " " ) ); cout << endl;

    return 0;
}
*/


class Solution {
public:
    using VI = vector< int >;
    VI distributeCandies( int N, int K ){
        VI A( K, 0 );
        for( auto cnt{ 0 }; 0 < N; ){
            for( auto i{ 0 }; i < K; ++i ){
                auto take = min( ++cnt, N );
                A[ i ] += take;
                N -= take;
            }
        }
        return A;
    }
};

int main() {
    Solution solution;
    auto ans = solution.distributeCandies( 60, 4 );
    copy( ans.begin(), ans.end(), ostream_iterator< int >( cout, "  " ) );

    return 0;
}


