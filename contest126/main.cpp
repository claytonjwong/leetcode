/*

    https://leetcode.com/contest/weekly-contest-126

    Rank	        Name	        Score	Finish Time 	Q1 (3)	    Q2 (5)	    Q3 (6)	    Q4 (9)
    1759 / 4564	    claytonjwong 	8	    0:42:27	        0:27:06	    0:42:27

    Q1: https://leetcode.com/problems/find-common-characters/
    A1: https://leetcode.com/problems/find-common-characters/discuss/247599/C%2B%2B-solution-with-explanation

    Q2: https://leetcode.com/problems/check-if-word-is-valid-after-substitutions/
    A2: https://leetcode.com/problems/check-if-word-is-valid-after-substitutions/discuss/247609/Concise-C%2B%2B

 */


#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>
#include <iomanip>


using namespace std;


class Solution
{
public:

    using VS = vector< string >;
    using VI = vector< int >;
    using VVI = vector< VI >;
    using Map = unordered_map< char, int >;

    VS commonChars( VS& A, VS res={} )
    {
        auto N{ A.size() };
        VVI alpha( N, VI( 123 ));
        for( size_t i{ 0 }; i < N; ++i )
        {
            Map counter;
            for( auto c: A[ i ])
                ++counter[ c ];
            for( auto j{ 97 }; j < 123; ++j )
                alpha[ i ][ j ] = counter[ j ];
        }
        for( char j{ 97 }; j < 123; ++j )
        {
            auto K{ 101 };
            for( auto i{ 0 }; i < N; ++i )
                K = min( K, alpha[ i ][ j ] );
            generate_n( back_inserter( res ), K, [=](){ return string( 1,j ); });
        }
        return res;
    }

};

int main()
{
    vector<string> input{ "cool","lock","cook" };
    Solution solution;
    auto res = solution.commonChars( input );
    for( auto& s: res )
        cout << s << endl;
    return 0;
}


/*
class Solution
{
public:
    bool isValid( string S )
    {
        while( ! S.empty() )
        {
            auto pos = S.find( "abc" );
            if( pos == string::npos )
                return false;
            S.erase( pos, 3 );
        }
        return true;
    }
};

int main()
{
    string str{ "cababc" };
    Solution solution;
    cout << boolalpha << solution.isValid( str ) << endl;

    return 0;
}
*/

/*
class Solution {
public:
    int mergeStones(vector<int>& A, int K, int cost=0 ) {
        try{
            while( A.size() > 1 )
            {
                if( A.size() < K )
                    throw out_of_range{ "cannot merge stones" };
                auto N{ A.size()+1 };
                vector<int> sums(N,0);
                for( auto i{ 1 }; i < N; ++i )
                    sums[ i ] = sums[ i-1 ] + A[ i-1 ];
                auto minIndex{ K }, minSum{ numeric_limits<int>::max() };
                for( auto i{ K }; i < N; ++i )
                {
                    auto sum = sums[ i ] - sums[ i-K ];
                    if( minSum > sum )
                        minSum = sum,
                        minIndex = i;
                }
                cost += minSum;
                vector<int> next;
                next.insert(next.end(), A.begin(),A.begin()+minIndex-K);
                next.push_back( minSum );
                next.insert(next.end(), A.begin()+minIndex, A.end());
                swap(A,next);
            }
        } catch( exception& ) {
            return -1;
        }
        return A.size() == 1 ? cost : -1 ;
    }

};

int main()
{
    vector<int> A{3,5,1,2,6};
    Solution solution;
    cout << solution.mergeStones(A,3) << endl;
    return 0;
}
*/
