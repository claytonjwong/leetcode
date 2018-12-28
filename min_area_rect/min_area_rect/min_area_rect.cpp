/*

939. Minimum Area Rectangle

Q: https://leetcode.com/problems/minimum-area-rectangle/
A: https://leetcode.com/problems/minimum-area-rectangle/discuss/194499/Straightforward-C%2B%2B

*/

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <limits>
#include <algorithm>
#include <ostream>
#include <numeric>
#include <deque>

using namespace std;

/*
#define X first
#define Y second
using Bucket = map< int, set<int> >;
class Solution {
public:
    int minAreaRect(vector<vector<int>>& points, Bucket m={}, int ans=numeric_limits<int>::max()) {

        for( const auto& point: points ){
            auto x = point[ 0 ], y = point[ 1 ];
            if( m.find( x ) == m.end() )
                m[ x ] = { y };
            else
                m[ x ].insert( y );
        }

        for( auto pre = m.cbegin();  pre != m.cend();  ++pre )
            for( auto cur = next(pre);  cur != m.cend();  ++cur )
                for( auto preY = cur->Y.cbegin();  preY != cur->Y.cend();  ++preY )
                    for( auto curY = next( preY );  curY != cur->Y.cend();  ++curY )
                        if( pre->Y.find( *preY ) != pre->Y.cend()  &&  pre->Y.find( *curY ) != pre->Y.cend() )
                            ans = min( ans, ( cur->X - pre->X )  *  ( *curY - *preY ) );

        return ans < numeric_limits<int>::max() ? ans : 0;
    }
};
*/

#define X first
#define Y second
using Bucket = map< int, set<int> >;
class Solution {
public:
    int minAreaRect( vector< vector<int> >& points, Bucket m={}, int ans=numeric_limits<int>::max() ) {

        for( const auto& p: points )
            if( m.find( p[0] ) == m.end() )
                m[ p[0] ] = { p[1] };
            else
                m[ p[0] ].insert( p[1] );

        for( auto pre = m.cbegin();  pre != m.cend();  ++pre )
            for( auto cur = next( pre );  cur != m.cend();  ++cur ){
                vector<int> common, delta;
                set_intersection( pre->Y.cbegin(), pre->Y.cend(), cur->Y.cbegin(), cur->Y.cend(), back_inserter( common ) );
                adjacent_difference( common.cbegin(), common.cend(), back_inserter( delta ) );
                ans = ( delta.size() < 2 ) ? ans : min( ans, (cur->X - pre->X) * *min_element( next(delta.cbegin()), delta.cend() ));
            }
        return ans < numeric_limits<int>::max() ? ans : 0;
    }
};

int main(int argc, const char * argv[]) {
    
    vector<vector<int>> points {
        {1,1},
        {1,2},
        {1,3},
        {3,1},
        {3,2},
        {3,3},
        {4,0},
        {5,1},
        {5,2},
        {5,5},
    };
    Solution s;
    cout << s.minAreaRect(points) << endl;
    
    return 0;
}
