/*
 * https://leetcode.com/contest/weekly-contest-146 (virtual)
 *
 * Rank         Name	        Score   Finish Time     Q1 (3)	        Q2 (6)	    Q3 (7)  	Q4 (7)
 * 1678 / 3887  claytonjwong 	3       0:30:48         0:30:48  *1
 *
 * Q1: https://leetcode.com/problems/number-of-equivalent-domino-pairs/
 * A1: https://leetcode.com/problems/number-of-equivalent-domino-pairs/discuss/340778/C%2B%2B-solution
 *
 * Q2: https://leetcode.com/problems/shortest-path-with-alternating-colors/
 * A2: https://leetcode.com/problems/shortest-path-with-alternating-colors/discuss/340773/C%2B%2B-solution
 *
 */

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <cmath>
#include <queue>

using namespace std;

/*
class Solution {
public:
    using VI = vector< int >;
    using VVI = vector< VI >;
    struct Hash {
        size_t operator()( const VI& x ) const {
            return 10 * x[ 0 ] + x[ 1 ];
        }
    };
    using Count = unordered_map< VI,int,Hash >;
    int numEquivDominoPairs( VVI& D, Count cnt={}, int ans=0 ){
        for( auto i{ 0 }; i < D.size(); ++i ){
            auto dom = D[ i ]; // i-th (dom)ino
            sort( dom.begin(), dom.end() ); // if needed, "flip" domino for unique count such that lhs < rhs (i.e. [2,1] -> [1,2], since [2,1] == [1,2] )
            ++cnt[ dom ];
        }
        for( auto& pair: cnt ){
            auto n = pair.second;
            ans += n * ( n-1 ) / 2;
        }
        return ans;
    }
};
*/

class Solution {
public:
    using VI = vector< int >;
    using VVI = vector< VI >;
    using Count = unordered_map< int,int >;
    static constexpr int INF = 10;
    int numEquivDominoPairs( VVI& D, Count cnt={}, int ans=0 ){
        for( auto i{ 0 }; i < D.size(); ++i ){
            auto dom = D[ i ]; // i-th (dom)ino
            sort( dom.begin(), dom.end() ); // if needed, "flip" domino for unique count such that lhs < rhs (i.e. [2,1] -> [1,2], since [2,1] == [1,2] )
            auto key = dom[ 0 ] * INF + dom[ 1 ];
            ans += cnt[ key ]++;
        }
        return ans;
    }
};

int main() {

    Solution::VVI D{ {1,2},{1,2},{1,1},{1,2},{2,2} };
    auto ans = Solution().numEquivDominoPairs( D );
    cout << ans << endl;
    return 0;
}

/*
class Solution {
public:
    using VI = vector< int >;
    using VVI = vector< VI >;
    using Graph = unordered_map< int,unordered_set< int > >;
    using Node = pair< int,bool >; // id, color
    static constexpr int INF = static_cast< int >( 1e5 );
    struct Hash {
        size_t operator()( const Node& node ) const {
            return ( 10 * node.first ) + node.second;
        }
    };
    using Seen = unordered_set< Node, Hash >;
    using Queue = queue< Node >;
    VI shortestAlternatingPaths( int N, VVI& A, VVI& B ){
        VI D( N, INF );
        D[ 0 ] = 0;
        Graph red = gen( A ),
              blue = gen( B );
        Queue q({ { 0, true }, { 0, false } });
        Seen seen{ { 0, true }, { 0, false } };
        for( auto depth{ 1 }; ! q.empty(); ++depth ){
            auto M = q.size();
            while( M-- ){
                auto node = q.front(); q.pop();
                auto u = node.first;
                auto color = ! node.second; // next color must be opposite of current color
                auto adj = color ? red : blue;
                for( auto v: adj[ u ] ){
                    if( D[ v ] > depth )
                        D[ v ] = depth;
                    if( seen.insert({ v, color }).second )
                        q.push({ v, color });
                }
            }
        }
        transform( D.begin(), D.end(), D.begin(), [&]( auto x ){ return x == INF ? -1 : x; });
        return D;
    }
private:
    Graph gen( const VVI& E, Graph G={} ){
        for( auto& edge: E ){
            auto[ u,v ] = tie( edge[ 0 ], edge[ 1 ] );
            G[ u ].insert( v );
        }
        return G;
    }
};



int main() {
    Solution solution;
    Solution::VVI red{{2,2},{0,4},{4,2},{4,3},{2,4},{0,0},{0,1},{2,3},{1,3}}, blue{{0,4},{1,0},{1,4},{0,0},{4,0}};
    auto ans = solution.shortestAlternatingPaths( 5, red, blue );
    copy( ans.begin(), ans.end(), ostream_iterator< int >( cout, " " ) );
    return 0;
}
*/
