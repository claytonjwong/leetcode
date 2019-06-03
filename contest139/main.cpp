/*
 * https://leetcode.com/contest/weekly-contest-139
 *
 * Duration	   Score	Finish Time	    AC	    Ranking
 * 1 h 30 m	   10/24	1:12:07	        2/4	    842/3201
 *
 * Q1: https://leetcode.com/problems/greatest-common-divisor-of-strings/
 * A1: https://leetcode.com/problems/greatest-common-divisor-of-strings/discuss/304453/C%2B%2B-Solution
 *
 * Q2: https://leetcode.com/problems/flip-columns-for-maximum-number-of-equal-rows/
 * A2: https://leetcode.com/problems/flip-columns-for-maximum-number-of-equal-rows/discuss/304448/C%2B%2B-Solution
 *
 */

#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>
#include <limits>
#include <iterator>
#include <cmath>

using namespace std;

/*
class Solution {
public:
    string gcdOfStrings( string a, string b ){
        return a.size() > b.size()? go( a, b, b.size() )
                                  : go( b, a, a.size() );
    }
private:
    string go( const string& a, const string& b, int i ){
        if( i == 0 )
            return {};
        string target = b.substr( 0, i );
        if( divides( a, target ) && divides( b, target ) )
            return target;
        return go( a, b, i-1 );
    }
    bool divides( const string& a, const string& b ){
        if( b.empty() )
            return true;
        auto i{ 0 };
        for( size_t pos{ 0 }; i < a.size(); i += b.size() ){
            pos = a.find( b, i );
            if( pos == string::npos )
                break;
        }
        return i == a.size();
    }
};

int main() {
    Solution solution;
    cout << solution.gcdOfStrings( "ABABAB", "AB" ) << endl;
    return 0;
}
*/

/*
class Solution {
public:
    using VI = vector< int >;
    using VVI = vector< VI >;
    int maxEqualRowsAfterFlips( VVI& M, int ans=1 ){
        auto N = M.size();
        for( auto i{ 0 }; i+1 < N; ++i )
            for( auto j{ i+1 }, k{ 1 }; j < N; ++j ) // the first row is equal to itself, this is counted as k=1
                if( M[ i ] == M[ j ] || M[ i ] == flip( M[ j ] ) )
                    ans = max( ans, ++k );
        return ans;
    }
private:
    VI flip( VI A ){
        transform( A.begin(), A.end(), A.begin(), []( auto& x ){ return x^1; });
        return A;
    }
};
*/

class Solution {
public:
    using VI = vector< int >;
    using VVI = vector< VI >;
    int maxEqualRowsAfterFlips( VVI& M, int ans=1 ){
        for( auto i{ M.begin() }; next( i ) != M.end(); ++i ){
            auto same{ 1 }; // the first row is always equal to itself
            for( auto j{ i+1 }; j != M.end(); ++j )
                if( *i == *j || *i == flip( *j ) )
                    ans = max( ans, ++same );
        }
        return ans;
    }
private:
    VI flip( VI A ){
        transform( A.begin(), A.end(), A.begin(), []( auto& x ){ return x^1; });
        return A;
    }
};

int main(){
    Solution solution;
    Solution::VVI M = {
        { 0,0,0 },
        { 0,0,1 },
        { 1,1,0 },
    };
    cout << solution.maxEqualRowsAfterFlips( M ) << endl;
    return 0;
}


/*
class Solution {
public:
    using VI = vector< int >;
    VI addNegabinary( VI& a, VI& b ){
        auto sum = value( a ) + value( b );

    }
private:
    int value( const VI& A ){
        if( A.empty() )
            return 0;
        auto sum = ( A.back() == 0 )? 0 : 1;
        for( auto it=A.rbegin()+1; it != A.rend(); ++it ){
            if( *it == 0 )
                continue;
            auto N = distance( it, A.rbegin() );
            sum += pow( -2, N );
        }
        return sum;
    }
};
*/
