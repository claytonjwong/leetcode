/*

 916. Word Subsets
 
 Q: https://leetcode.com/problems/word-subsets/description/
 A: https://leetcode.com/problems/word-subsets/discuss/179522/Verbose-C++-(-easy-to-understand-)
 
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*
using VS = vector< string >;
using Map = unordered_map< char,int >;
class Solution {
    Map toMap( const string& s ){
        Map m;
        for( const auto c: s )
            ++m[ c ];
        return m;
    }
    Map toMap( const vector<Map>& maps ){
        Map result;
        for( const auto& map: maps )
            for( const auto& p: map )
                result[ p.first ] = max( result[ p.first ], p.second );
        return result;
    }
    bool isUniversal( const string& s, const Map& needles ){
        const Map haystack = toMap( s );
        for( const auto& needle: needles ){
            auto it = haystack.find( needle.first );
            if( it == haystack.end() || it->second < needle.second )
                return false;
        }
        return true;
    }
public:
    VS wordSubsets( VS& A, VS& B, Map target={}, VS ans={} ){
        vector<Map> targets;
        for( const auto& b: B )
            targets.push_back( toMap( b ) );
        target = toMap( targets );
        for( const auto& a: A )
            if( isUniversal( a, target ))
                ans.push_back( a );
        return ans;
    }
};
*/

using VS = vector< string >;
using VI = vector< int >;
size_t start = 'a', N = 'z'+1;
class Solution {
    VI generate( const string& str ){
        VI cur( N );
        for( const auto c: str )
            ++cur[ c ];
        return cur;
    }
public:
    VS wordSubsets( VS& A, VS& B, VI needle=VI( N ), VS ans={} ){
        for( const auto& b: B ){
            auto cur{ generate( b )};
            for( auto i{ start };  i != N;  ++i )
                needle[ i ] = max( needle[ i ], cur[ i ] );
        }
        for( const auto& a: A ){
            auto haystack{ generate( a )};
            auto found{ true };
            for( auto i{ start };  i != N;  ++i ) if( haystack[ i ] < needle[ i ] ){
                found = false;
                break;
            }
            if( found ) ans.push_back( a );
        }
        return ans;
    }
};


int main(int argc, const char * argv[]) {
    
    Solution s;
    VS A{ "amazon","apple","facebook","google","leetcode" }, B{ "e","oo" };
    auto result = s.wordSubsets( A, B );

    return 0;
}
