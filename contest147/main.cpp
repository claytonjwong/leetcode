/*
 * Rank	        Name	        Score	Finish Time 	Q1 (2)	        Q2 (5)	        Q3 (7)  	Q4 (7)
 * 2085 / 4906	claytonjwong 	7	    1:06:44	        0:07:12  *2	    0:41:44  *3
 *
 *
 */

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <iterator>
#include <algorithm>

using namespace std;

/*
class Solution {
public:
    using Memo = unordered_map< int,int >;
    int tribonacci( int n, Memo&& M={} ){
        if( M.find( n ) != M.end() )
            return M[ n ];
        if( n == 0 )
            return M[ n ] = 0;
        if( n < 3 )
            return M[ n ] = 1;
        return M[ n ] = tribonacci( n-3, move( M ) ) + tribonacci( n-2, move( M ) ) + tribonacci( n-1, move( M ) );
    }
};
*/


class Solution {
public:
    string alphabetBoardPath( string target, int r=0, int c=0, string ans={} ){
        for( auto ch: target ){
            auto next_r = ( ch - 'a' ) / 5,
                 next_c = ( ch - 'a' ) % 5;
            for( auto found{ false }; ! found; ){
                if     ( r > next_r ) --r, ans.push_back( 'U' );
                else if( c < next_c ) ++c, ans.push_back( 'R' );
                else if( c > next_c ) --c, ans.push_back( 'L' );
                else if( r < next_r ) ++r, ans.push_back( 'D' );
                else
                    found = true, ans.push_back( '!' );
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;
    auto ans = solution.alphabetBoardPath( "zb" );
    cout << ans << endl;
    return 0;
}

/*
class Solution {
public:
    int largest1BorderedSquare( vector<vector<int>>& G, int ans=0 ){
        for( auto i{ 0 }; i < G.size(); ++i ){
            for( auto j{ 0 }; j < G[ 0 ].size(); ++j ){
                for( auto k{ 0 }; k < min( G.size(), G[ 0 ].size() ); ++k ){
                    auto d{ i }, r{ j }, u{ i+k }, l{ j+k };
                    for(; d < min( G.size(), G[ 0 ].size() ) && r < min( G.size(), G[ 0 ].size() ) && 0 <= u && 0 <= l && d <= u && r <= l && G[ d ][ j ] && G[ i ][ r ] && G[ u ][ j ] && G[ i ][ l ]; ){
                        ++d, ++r, --u, --l;
                    }
                    if( ans < (k+1)*(k+1) && d > u && r > l )
                        ans = (k+1)*(k+1);
                }
            }
        }
        return ans;
    }
};

int main(){
    vector<vector<int>> G{{0,0,0,1}};
    auto ans = Solution().largest1BorderedSquare( G );
    cout << ans << endl;
    return 0;
}
*/
