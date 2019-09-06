/*

https://leetcode.com/contest/weekly-contest-86

Weekly Contest 86
Aug 06, 2019 at 7:22 AM

Contest  	Duration	Score	Finish Time	    AC	    Ranking
86          1 h 30 m	8/22	0:59:45	        2/4	    643/2323

Q1: https://leetcode.com/problems/magic-squares-in-grid/
A1: https://leetcode.com/problems/magic-squares-in-grid/discuss/352614/C%2B%2B-Solution

Q2: https://leetcode.com/problems/keys-and-rooms/
A2: https://leetcode.com/problems/keys-and-rooms/discuss/352615/C%2B%2B-Solution

*/

#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_set>
#include <numeric>

using namespace std;

/*
class Solution {
public:
    using VI = vector< int >;
    using VVI = vector< VI >;
    int numMagicSquaresInside( VVI& G, int ans=0 ){
        auto M = static_cast< int >( G.size() ),
             N = static_cast< int >( G[0].size() );
        if( M < 3 || N < 3 )
            return 0;
        for( auto i{ 0 }; i+2 < M; ++i )
            for( auto j{ 0 }; j+2 < N; ++j )
                ans += magic( G, i, j );
        return ans;
    }
private:
    using Seen = unordered_set< int >;
    bool magic( VVI& G, int i, int j, int d1=0, int d2=0, VI r=VI(3), VI c=VI(3), int min_val=16, int max_val=-1, Seen seen={} ){
        for( auto u{ i }; u < i+3; ++u ){
            for( auto v{ j }; v < j+3; ++v ){
                auto x = G[u][v];
                d1 += ( u-i == v-j ) ? x : 0;
                d2 += ( u-i == 1 && v-j == 1 ) || ( u-i == 2 && v-j == 0 ) || ( u-i == 0 && v-j == 2 ) ) ? x : 0;
                r[u-i] += x;
                c[v-j] += x;
                if( x < 1 || x > 9 )
                    return false;
                seen.insert( G[u][v] );
            }
        }
        return c[0] == c[1] && c[1] == c[2] && r[0] == r[1] && r[1] == r[2] && d1 == d2 && seen.size() == 9;
    }
};

int main() {
    Solution solution;
    Solution::VVI G{ { 2,7,6 },
                     { 1,5,9 },
                     { 4,3,8 } };
//    Solution::VVI G{ { 4,3,8,4 },
//                     { 9,5,1,9 },
//                     { 2,7,6,2 } };
    auto ans = solution.numMagicSquaresInside( G );
    cout << ans << endl;
    return 0;
}
 */

/*
class Solution {
public:
    using VI = vector< int >;
    using VVI = vector< VI >;
    using Seen = unordered_set< int >;
    bool canVisitAllRooms( VVI& G, Seen seen={} ){
        auto N = static_cast< int >( G.size() );
        dfs( G, seen );
        return seen.size() == N;
    }
private:
    void dfs( VVI& G, Seen& seen, int i=0 ){
        if( ! seen.insert( i ).second )
            return;
        for( auto j: G[i] )
            dfs( G, seen, j );
    }
};

int main() {
    Solution solution;
    Solution::VVI G{ {1,3},{3,0,1},{2}, {0} };
    cout << solution.canVisitAllRooms( G ) << endl;
    return 0;
}
*/

// ran out of time
/*
class Solution {
public:
    using VI = vector< int >;
    VI splitIntoFibonacci( string S, VI f=VI(3) ){
        auto N = static_cast< int >( S.size()/3 );
        stringstream stream;
        for( auto i{ 1 }, f1{ 0 }; i <= N; ++i ){
            stream << S.substr( 0, i );
            stream >> f1;
            if( ! valid( S.substr( 0, i ), f1 ) )
                continue;
            for( auto j{ i+1 }, f2{ 0 }; j-i < N; ++j ){
                stream << S.substr( i, j-i );
                stream >> f2;
                if( ! valid( S.substr( i, j-i ), f2 ) )
                    continue;
                for( auto k{ j+1 }, f3{ 0 }; k-j < N; ++k ){
                    stream << S.substr( k, k-j );
                    stream >> f3;
                    if( ! valid( S.substr( j, k-j ), f3 ) )
                        continue;
                    if( f1 + f2 == f3 )
                        return{ f1, f2, f3 };
                }
            }
        }
        return {};
    }
private:
    bool valid( const string& S, int x ){
        stringstream stream;
        stream << x;
        return S == stream.str();
    }
};

int main() {
    Solution solution;
    string S{ "123456579" };
    auto ans = solution.splitIntoFibonacci( S );
    copy( ans.begin(), ans.end(), ostream_iterator< int >( cout, " " ) );
    return 0;
}
*/
