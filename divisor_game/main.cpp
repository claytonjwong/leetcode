/*
 *
 * Q: https://leetcode.com/problems/divisor-game/
 *
 * A: https://leetcode.com/problems/divisor-game/discuss/292472/C%2B%2B-solutions%3A-TopDown-and-BottomUp
 *
 */

#include <iostream>
#include <unordered_map>
#include <vector>
#include <cassert>

using namespace std;

namespace TopDown {
    class Solution {
    public:
        bool divisorGame( int N ){
            return go( N );
        }
    private:
        using Memo = unordered_map< int, bool >;
        bool go( int N, Memo&& memo={}, int turn=0 ){
            if( memo.find( N ) != memo.end() )
                return memo[ N ];
            if( N == 1 )
                return memo[ N ] = turn == 1; // alice wins if there are no moves left and it is bob's turn
            for( int i=1; i*i <= N; ++i )
                if( N % i == 0 && go( N-i, move( memo ), turn^1 ) )
                    return memo[ N ] = true;
            return memo[ N ] = false;
        }
    };
}
namespace BottomUp {
    class Solution {
    public:
        using Collection = bitset< 1001 >;
        bool divisorGame( int N, Collection dp={} ){
            dp[ 0 ] = true;
            for( auto i{ 1 }; i <= N; ++i )
                for( auto j{ 1 }; j*j <= i; ++j )
                    if( i % j == 0 && ! dp[ i-j ] ){
                        dp[ i ] = true;
                        break;
                    }
            return dp[ N ];
        }
    };
}

int main() {
    using Solution = BottomUp::Solution;
    Solution solution;
    for( auto i{ 1 }; i <= 1000; ++i )
        if( i % 2 == 0 )
            assert( solution.divisorGame( i ) == true );
        else
            assert( solution.divisorGame( i ) == false );
    return 0;
}
