#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    using VI = vector< int >;
    using VVI = vector< VI >;
    using Seen = set< int >;
    VI eventualSafeNodes( VVI& G, Seen all={}, Seen cycle={}, VI ans={}, Seen visited={} ){
        const int N = static_cast< int >( G.size() );
        for( auto i{ 0 }; i < N; ++i )
            dfs( G, i, visited, cycle );
        generate_n( inserter( all, all.begin() ), N, [ i=0 ]() mutable { return i++; });
        set_difference(all.begin(), all.end(), cycle.begin(), cycle.end(), back_inserter( ans ) );
        return ans;
    }
private:
    bool dfs( VVI& G, int i, Seen& visited, Seen& cycle, Seen&& visiting={}, bool ok=true ){
        if( visited.find( i ) != visited.end() )
            return cycle.find( i ) == cycle.end();
        if( ! visiting.insert( i ).second ){
            cycle.insert( i );
            return false;
        }
        for( auto adj: G[ i ] )
            ok &= dfs( G, adj, visited, cycle, move( visiting ) );
        visiting.erase( i );
        visited.insert( i );
        if( ! ok )
            cycle.insert( i );
        return ok;
    }
};

int main() {
    Solution::VVI G{{1,2},{2,3},{5},{0},{5},{},{}};
    auto ans = Solution().eventualSafeNodes( G );
    copy( ans.begin(), ans.end(), ostream_iterator< int >( cout, " " ) );
    return 0;
}