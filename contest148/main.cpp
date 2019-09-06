/*
 * https://leetcode.com/contest/weekly-contest-148
 *
 *   Rank	        Name        	Score	Finish Time 	Q1 (4)	        Q2 (5)	    Q3 (6)	        Q4 (7)
 *   1109 / 5319	claytonjwong 	10	    1:45:29     	0:46:24  *3		            1:10:29  *4
 *
 */


#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <sstream>
#include <numeric>
#include <algorithm>
#include <iterator>

using namespace std;

/*
class Solution {
public:
    using VI = vector< int >;
    int movesToMakeZigzag( VI& A, int ans1=0, int ans2=0 ){
        auto N = static_cast< int >( A.size() ), diff{ 0 };
        auto even{ A }, odd{ A };
        for( auto i{ 0 }, j{ 1 }; i < N || j < N; i += 2, j += 2 ){
            if( 0 < i && i < N && even[i] >= even[i-1] ) ans1 += even[i] - even[i-1] + 1, even[i] = even[i-1] - 1;
            if(        i+1 < N && even[i] >= even[i+1] ) ans1 += even[i] - even[i+1] + 1, even[i] = even[i+1] - 1;
            if(   j < N && odd[j] >= odd[j-1] ) ans2 += odd[j] - odd[j-1] + 1, odd[j] = odd[j-1] - 1;
            if( j+1 < N && odd[j] >= odd[j+1] ) ans2 += odd[j] - odd[j+1] + 1, odd[j] = odd[j+1] - 1;
        }
        return min( ans1, ans2 );
    }
};

int main() {

    Solution solution;
    Solution::VI A{ 7,4,8,9,7,7,5 };
    auto ans = solution.movesToMakeZigzag( A );
    cout << ans << endl;
    return 0;
}
*/

class SnapshotArray {
public:
    explicit SnapshotArray( int _ ){ }

    void set( int i, int x ){
        A[i] = x;
    }

    int get( int i, int id ){
        return seen[id][i];
    }

    int snap() {
        seen.push_back( A );
        A.clear();
        auto N = static_cast< int >( seen.size() );
        return N - 1;
    }

private:
    using Values = unordered_map< int,int >; // "get" values not explicitly "set" default to 0
    using Seen = vector< Values >;
    Values A;
    Seen seen;
};

int main() {
    SnapshotArray sa( 3 );
    sa.set( 0, 5 );
    cout << sa.snap() << endl;
    sa.set( 0, 6 );
    cout << sa.get( 0, 0 ) << endl;
    return 0;
}
