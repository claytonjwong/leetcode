/*

    https://leetcode.com/contest/weekly-contest-126

    Rank	        Name	        Score	Finish Time 	Q1 (3)	    Q2 (5)	    Q3 (6)	    Q4 (9)
    1759 / 4564	    claytonjwong 	8	    0:42:27	        0:27:06	    0:42:27

    Q1: https://leetcode.com/problems/find-common-characters/
    A1: https://leetcode.com/problems/find-common-characters/discuss/248417/Concise-C%2B%2B

    Q2: https://leetcode.com/problems/check-if-word-is-valid-after-substitutions/
    A2: https://leetcode.com/problems/check-if-word-is-valid-after-substitutions/discuss/247609/Concise-C%2B%2B

    Q3: https://leetcode.com/problems/max-consecutive-ones-iii/
    A3: https://leetcode.com/problems/max-consecutive-ones-iii/discuss/248529/Concise-C%2B%2B

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


/*
class Solution
{
public:

    using VS = vector< string >;
    using VI = vector< int >;
    using VVI = vector< VI >;
    using Map = unordered_map< char, int >;
    static constexpr int INF = numeric_limits< int >::max();

    VS commonChars( VS& words, VI count=VI( 123, INF ), VS res={} )
    {
        for( auto& word: words )
        {
            Map m; for( auto ch: word) ++m[ ch ]; // (m)ap of (ch)aracter count
            for( auto ch{ 97 }; ch < 123; ++ch )  // lowercase ordinal values for 'a' ( 97 ) to 'z' ( 122 ) inclusive
                if( count[ ch ] > m[ ch ] )
                    count[ ch ] = m[ ch ];
        }
        for( char ch{ 97 }; ch < 123; ++ch )
            generate_n( back_inserter( res ), count[ ch ], [=](){ return string( 1,ch ); });
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
*/

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
class Solution
{
public:
    bool isValid( string S, size_t pos=string::npos )
    {
        for( ; ! S.empty() && ( pos = S.find( "abc" )) != string::npos; S.erase( pos, 3 ));
        return S.empty();
    }
};

int main()
{
    string str{ "abcabcababcc" };
    Solution solution;
    cout << boolalpha << solution.isValid( str ) << endl;

    return 0;
}
*/


class Solution
{
public:

    int longestOnes( vector<int>& A, int K, int res=0 )
    {
        for( auto L{ A.begin() }, R{ L }; R != A.end(); res = max( res, (int) distance( L,R ) ) )
            if( *R == 1 )
                ++R;
            else
            if( *R == 0 && K > 0 )
                ++R, --K;
            else
            if( *R == 0 && K == 0 && *L++ == 0 )
                ++K;
        return res;
    }

};

int main()
{
    Solution solution;
    vector< int > A{ 0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1 }; auto K{ 3 };
    cout << solution.longestOnes( A, K ) << endl;
    return 0;
}
