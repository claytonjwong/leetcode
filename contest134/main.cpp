/*
 *
 * Rank	        Name	        Score	Finish Time 	Q1 (4)	 Q2 (5)	        Q3 (5)	    Q4 (8)
 * 1557 / 4136	claytonjwong 	5	    0:44:45 	        	 0:39:45  *1
 *
 */

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <cmath>
#include <limits>

using namespace std;

/*
class Solution {
public:
    using VI = vector< int >;
    using VVI = vector< VI >;
    using PII = pair< int, int >;
    struct Hash {
        size_t operator()( const PII& p ) const {
            return p.first * 51 + p.second;
        }
    };
    using Seen = unordered_set< PII, Hash >;
    VVI colorBorder( VVI& G, int r, int c, int next ){
        auto ans{ G };
        auto M = G.size(),
             N = G.back().size();
        VVI CC{ G };
        go( CC, M, N, r, c, G[ r ][ c ], next ); // fill in entire (C)onnected (C)omponent
        for( auto i{ 0 }; i < M; ++i )
            for( auto j{ 0 }; j < N; ++j )
                if( G[ i ][ j ] != CC[ i ][ j ] && isEdge( G, M, N, i, j ) ) // only update (G)raph with (C)onnected (C)omponent's edge
                    ans[ i ][ j ] = CC[ i ][ j ];
        return ans;
    }
private:
    const VVI dir{ VI{ -1,0 }, VI{ 0,1 }, VI{ 1,0 }, VI{ 0,-1 } };
    void go( VVI& G, int M, int N, int i, int j, int cur, int next, Seen&& seen={} ){
        if( i < 0 || j < 0 || M <= i || N <= j || G[ i ][ j ] != cur || ! seen.insert({ i,j }).second )
            return;
        G[ i ][ j ] = next;
        for( auto d: dir )
            go( G, M, N, i + d[0], j + d[1], cur, next, move( seen ) );
    }
    bool isMiddle( VVI& G, int M, int N, int i, int j ){
        if( i == 0 || j == 0 || i == M-1 || j == N-1 )
            return false;
        for( auto d: dir )
            if( G[ i ][ j ] != G[ i + d[0] ][ j + d[1] ] )
                return false;
        return true;
    }
    bool isEdge( VVI& G, int M, int N, int i, int j ){
        return ! isMiddle( G, M, N, i, j );
    }
};


int main() {
    Solution::VVI G = {
        {1,1,1},
        {1,1,1},
        {1,1,1},
    };
    auto ans = Solution().colorBorder( G, 1, 1, 2 );

    return 0;
}
*/

// wrong answer
/*
class Solution {
public:
    using VI = vector< int >;
    VI numMovesStones( int a, int b, int c ){
        if(( a > b && b > c ) || ( a == b-1 && b+1 == c ))
            return{ 0,0 };
        VI A{ a,b,c };
        auto mini{ 0 };
        if( is_sorted( A.begin(), A.end() ) ){
            mini = ( a == b-1 && b+1 == c )? 0
                    : ( a == b-1 && b+1 <  c )? 1
                  : ( a <  b-1 && b+1 == c )? 1
                    : 2;

        } else {
            sort( A.begin(), A.end() );
            mini = min( A[2] - A[1], A[1] - A[0]);
        }
        auto maxi = A[2] - A[0] - 2;
        return{ mini, maxi };
    }
};

int main(){
    auto ans = Solution().numMovesStones( 2,4,1 );
    return 0;
}
*/

namespace TopDown {
    class Solution {
    public:
        using VI = vector< int >;
        using PII = pair< int,int >;
        struct Hash {
            size_t operator()( const PII& p ) const {
                return p.first * 2001 + p.second;
            }
        };
        using Memo = unordered_map< PII, int, Hash >;
        int maxUncrossedLines( VI& A, VI& B ){
            return go( A, B );
        }
    private:
        int go( const VI& A, const VI& B, int i=0, int j=0, Memo&& memo={}, int ans=0 ){
            if( memo.find({ i,j }) != memo.end() )
                return memo[{ i,j }];
            auto M = A.size(),
                 N = B.size();
            if( i == M || j == N )
                return memo[{ i,j }] = 0;
            return memo[{ i,j }] = max({
                go( A, B, i+1, j+1, move( memo ) ) + ( A[ i ] == B[ j ] ),
                go( A, B, i+1, j  , move( memo ) ),
                go( A, B, i  , j+1, move( memo ) ),
            });
        }
    };
}
namespace BottomUp {
    class Solution {
    public:
        using VI = vector< int >;
        using VVI = vector< VI >;
        int maxUncrossedLines( VI& A, VI& B ){
            auto M = A.size(),
                 N = B.size();
            VVI dp( M+1, VI( N+1,0 ) );
            for( auto i{ 1 }; i <= M; ++i )
                for( auto j{ 1 }; j <= N; ++j )
                    dp[ i ][ j ] = max({
                        dp[ i-1 ][ j-1 ] + ( A[ i-1 ] == B[ j-1 ] ),
                        dp[ i-1 ][ j   ],
                        dp[ i   ][ j-1 ],
                    });
            return dp[ M ][ N ];
        }
    };
}

int main() {
    BottomUp::Solution::VI
        A{ 5,1,2,5,1,2,2,3,1,1,1,1,1,3,1 },
        B{ 2,5,1,3,4,5,5,2,2,4,5,2,2,3,1,4,5,3,2,4,5,2,4,4,2,2,2,1,3,1 };
    auto ans = BottomUp::Solution().maxUncrossedLines( A, B );
    cout << ans << endl;
    return 0;
}

