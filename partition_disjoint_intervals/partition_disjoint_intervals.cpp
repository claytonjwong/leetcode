/*

915. Partition Array into Disjoint Intervals

Q: https://leetcode.com/problems/partition-array-into-disjoint-intervals/
A: https://leetcode.com/problems/partition-array-into-disjoint-intervals/discuss/183412/Concise-C%2B%2B-multiset

*/

#include <iostream>
#include <vector>
#include <map>
#include <numeric>
#include <set>

using namespace std;

/*
using Map = map<int, int>;
class Solution {
public:
    int partitionDisjoint( vector<int>& A, Map L={}, Map R={} ){
        for( const auto value: A ) ++R[ value ];
        for( const auto value: A ){
            ++L[ value ]; if( --R[ value ] == 0 ) R.erase( value );
            if( L.crbegin()->first <= R.cbegin()->first )
                return accumulate( L.cbegin(), L.cend(), 0,
                    []( int value, const Map::value_type& x ){ return value + x.second; });
        }
    }
};
*/


class Solution {
public:
    int partitionDisjoint( vector<int>& A ){
        multiset<int> L, R{ A.cbegin(), A.cend() };
        for( const auto value: A ){
            L.insert( value ), R.erase( R.find( value ) );
            if( *L.crbegin() <= *R.cbegin() )
                return L.size();
        }
    }
};


int main() {

    vector<int> A{ 1,1,1,0,12,6 };
    Solution s;
    auto result = s.partitionDisjoint( A );

    return 0;
}