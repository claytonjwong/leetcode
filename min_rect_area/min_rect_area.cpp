#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

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


int main() {

    vector<vector<int>> points{
        {0,4},
        {1,0},
        {1,3},
        {2,0},
        {2,1},
        {2,4},
        {3,4},
        {4,0},
        {4,2},
        {4,3}
    };
    Solution s;
    cout << s.minAreaRect( points ) << endl;


    return 0;
}