/*
 * Rank	Name	Score	        Finish Time 	Q1 (3)	    Q2 (3)	    Q3 (5)	    Q4 (7)
 * 530 / 1634	claytonjwong 	11	            0:06:24	    0:15:52	    0:55:46
 *
 * Q1:
 * A1:
 *
 * Q2:
 * A2:
 *
 * Q3: https://leetcode.com/problems/connecting-cities-with-minimum-cost/
 * A3:
 *
 * Q4: https://leetcode.com/problems/parallel-courses/
 * A4: https://leetcode.com/problems/parallel-courses/discuss/344888/C%2B%2B-Solution
 *
 */

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <queue>

using namespace std;

/*
class Solution {
public:
    using VI = vector< int >;
    using Counter = unordered_map< int,int >;
    int largestUniqueNumber( VI& A, Counter cnt={}, int ans=-1 ){
        for( auto num: A )
            ++cnt[ num ];
        for( auto num: A ){
            if( ans < num && cnt[ num ] == 1 )
                ans = num;
        }
        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> A = {9,9,8,8};
    auto ans = solution.largestUniqueNumber(A);
    cout << ans << endl;
    return 0;
}
*/

/*
class Solution {
public:
    bool isArmstrong(int N) {
        auto x{ N }, y{ 0 };
        for( auto exp = log10( N ); 0 < N; N /= 10 ){
            y += pow( N % 10, exp );
        }
        return x == y;
    }
private:
    int log10( int N ){
        if( N == 0 )
            return 0;
        return 1 + log10( N / 10 );
    }
};

int main() {
    Solution solution;
    cout << solution.isArmstrong( 153 ) << endl;
    cout << solution.isArmstrong( 123 ) << endl;
    return 0;
}
*/

/*
class Solution {
public:
    struct Edge {
        int u{ 0 }, v{ 0 }, w{ 0 };
        bool operator==( const Edge& rhs ) const {
            return u == rhs.u && v == rhs.v && w == rhs.w;
        }
    };
    struct Cmp {
        bool operator()( const Edge& lhs, const Edge& rhs ) const {
            return lhs.w > rhs.w;
        }
    };
    struct Hash {
        size_t operator()( const Edge& edge ) const {
            return 10001 * edge.u + edge.v;
        }
    };
    using Queue = priority_queue< Edge, vector< Edge >, Cmp >;
    using Parent = unordered_map< int,int >;
    using Tree = unordered_set< Edge,Hash >;
    int minimumCost(int N, vector<vector<int>>& G, Queue q={}, Parent p={}, Tree mst={} ) {
        for( auto i{ 1 }; i <=N; ++i )
            p[ i ] = i;
        for( auto edge: G ){
            auto[ u,v,w ] = tie( edge[ 0 ], edge[ 1 ], edge[ 2 ] );
            q.push({ u,v,w });
        }
        while( ! q.empty() ){
            auto edge = q.top(); q.pop();
            auto[ u,v,w ] = tie( edge.u, edge.v, edge.w );
            if( Union( p, u, v ) ){
                mst.insert({ u,v,w });
            }
        }
        if( mst.size() < N-1 )
            return -1;
        auto ans{ 0 };
        for( auto edge: mst )
            ans += edge.w;
        return ans;
    }
private:
    bool Union( Parent& p, int a, int b ){
        a = Find( p, a );
        b = Find( p, b );
        if( a == b )
            return false;
        p[ a ] = b; // arbitrary choice
        return true;
    }
    int Find( Parent& p, int x ){
        if( p[ x ] == x )
            return x;
        return p[ x ] = Find( p, p[ x ] );
    }
};

int main() {
    Solution solution;
    vector<vector<int>> G = {{1,2,3},{3,4,4}};
    auto ans = solution.minimumCost(4, G);
    cout << ans << endl;
    return 0;
}
*/


class Solution {
public:
    using Graph = unordered_map< int, unordered_set< int > >;
    using Queue = queue< int >;
    using Seen = unordered_set< int >;
    using InDegree = unordered_map< int,int >;
    int minimumSemesters(int N, vector<vector<int>>& E, Graph G={}, InDegree D={}, Queue q={}, Seen seen={}, int depth=0 ) {
        for( auto& edge: E ){
            auto[ u,v ] = tie( edge[ 0 ], edge[ 1 ] );
            G[ u ].insert( v );
            ++D[ v ];
        }
        for( auto& pair: G ){
            auto u = pair.first;
            if( D[ u ] == 0 ){
                q.push( u );
                seen.insert( u );
            }
        }
        for(; ! q.empty(); ++depth ){
            auto K = q.size();
            while( K-- ){
                auto cur = q.front(); q.pop();
                for( auto adj: G[ cur ] )
                    if( --D[ adj ] == 0 && seen.insert( adj ).second )
                        q.push( adj );
            }
        }
        return( seen.size() == N )? depth : -1;
    }
};

int main() {
    auto N{ 3 };
    vector<vector<int>> G = {{1,3},{2,3}};
    Solution solution;
    auto ans = solution.minimumSemesters(N, G);
    cout << ans << endl;
    return 0;
}
