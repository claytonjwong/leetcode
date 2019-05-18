/*
 * https://leetcode.com/contest/weekly-contest-136
 * 9/23	1:11:24	2/4	765/3320
 */

#include <iostream>
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
    enum class Dir { N, S, E, W };
    using Position = pair< int,int >;
    bool isRobotBounded( string A, Dir dir=Dir::N, Position pos={ 0,0 }, Position target={ 0,0 } ){
        for( auto i{ 0 }; i < 1e6; ++i ){
            for( auto& cmd: A ){
                if( cmd == 'G' )
                    step( dir, pos );
                else
                    turn( dir, cmd );
            }
            if( pos == target )
                return true;
        }
        return false;
    }

private:
    void step( const Dir& dir, Position& pos ){
        switch( dir ){
            case Dir::N: ++pos.first; break;
            case Dir::S: --pos.first; break;
            case Dir::E: ++pos.second; break;
            case Dir::W: --pos.second; break;
        }
    }
    void turn( Dir& dir, const char cmd ){
        if( cmd == 'L' ){
            dir = dir == Dir::N? Dir::W
                : dir == Dir::S? Dir::E
                : dir == Dir::E? Dir::N
                : dir == Dir::W? Dir::S
                : Dir::S;
        } else {
            dir = dir == Dir::N? Dir::E
                : dir == Dir::S? Dir::W
                : dir == Dir::E? Dir::S
                : dir == Dir::W? Dir::N
                : Dir::N;
        }
    }
};

int main() {
    Solution solution;
    auto ans = solution.isRobotBounded( "GL" );
    cout << ans << endl;
    return 0;
}
*/

/*
class Solution {
public:
    using VI = vector< int >;
    using VVI = vector< VI >;
    using Graph = unordered_map< int, unordered_set< int > >;
    using Unique = unordered_set< int >;
    using Queue = queue< int >;
    VI gardenNoAdj( int N, VVI& paths, Graph G={}, Queue q={}, Unique seen={}, VI ans={} ){
        for( auto& path: paths ){
            auto u = path[ 0 ],
                 v = path[ 1 ];
            G[ u ].insert( v );
            G[ v ].insert( u );
        }
        VI color( N+1, 0 );
        for( int i{ 1 }; i <= N; ++i ){
            if( seen.insert( i ).second )
                q.push( i );
            while( ! q.empty() ){
                auto cur = q.front(); q.pop();
                Unique candidates{{ 1,2,3,4 }};
                for( auto adj: G[ cur ] ){
                    if( 0 < color[ adj ] )
                        candidates.erase( color[ adj ] );
                    if( seen.insert( adj ).second )
                        q.push( adj );
                }
                color[ cur ] = *candidates.begin();
            }
        }

        for( auto i{ 1 }; i <= N; ++i )
            ans.push_back( color[ i ] );
        return ans;
    }
};

int main() {
    auto N{ 4 };
    Solution::VVI paths = {
        { 1,2 },
        { 2,3 },
        { 4,3 },
        { 1,3 },
        { 1,4 },
        { 2,4 },
    };
    Solution solution;
    auto ans = solution.gardenNoAdj( N, paths );
    copy( ans.begin(), ans.end(), ostream_iterator< int >( cout, "," ) );
    return 0;
}
*/

class Solution {
public:
    using VI = vector< int >;
    int maxSumAfterPartitioning( VI& A, int K ){

    }
};

int main() {
    return 0;
}
