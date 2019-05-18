#include <iostream>
#include <deque>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    using Unique = unordered_set< char >;
    using Diff = deque< size_t >;
    bool buddyStrings( string A, string B, Diff D={} ){
        if( A.size() != B.size() )
            return false;
        if( A == B )
            return Unique{ A.begin(), A.end() }.size() < A.size();
        for( auto i{ 0 }; i < A.size(); ++i )
            if( A[ i ] != B[ i ] )
                D.push_back( i );
        if( D.size() != 2 )
            return false;
        swap( A[ D.front() ], A[ D.back() ] );
        return A == B;
    }
};

int main() {
    Solution solution;
    cout << solution.buddyStrings( "ab", "ba" ) << endl
         << solution.buddyStrings( "ab", "ab" ) << endl
         << solution.buddyStrings( "aa", "aa" ) << endl
         << solution.buddyStrings( "aaaaaaabc", "aaaaaaacb" ) << endl
         << solution.buddyStrings( "", "aa" ) << endl;
    return 0;
}
