/*
 *
 * Contest 112
 *
 * https://leetcode.com/contest/weekly-contest-112
 *
 * Q1: https://leetcode.com/problems/minimum-increment-to-make-array-unique/
 * A1: https://leetcode.com/problems/minimum-increment-to-make-array-unique/discuss/197971/fun-C%2B%2B-iterative-solutions
 * A2: https://leetcode.com/problems/minimum-increment-to-make-array-unique/discuss/197783/Simple-C%2B%2B-with-explanation
 *
 * Q2: https://leetcode.com/problems/validate-stack-sequences/
 * A2: https://leetcode.com/problems/validate-stack-sequences/discuss/198471/Simple-C%2B%2B
 *
 * Q3: https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/
 * A3:
 *
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <queue>
#include <stack>
#include <sstream>

using namespace std;






/*
class Solution {
public:
    int minIncrementForUnique( vector<int>& A, int ans=0 ){
        set<int> unique;
        for( int i=0; i <= 80000; ++i ){
            unique.insert( i );
        }
        for( const auto a: A ){
            auto it = lower_bound( unique.begin(), unique.end(), a );
            if( it != unique.end() ){
                ans += *it - a;
                unique.erase( it );
            }
        }
        return ans;
    }
};
*/


/*
class Solution {
public:
    int minIncrementForUnique( vector<int> &A, bitset<80001> V={}, int w=0, int i=0 ){
        sort( A.begin(), A.end() );
        for( const auto a: A ){
            for( w = a;  V[ w ];  ++w, ++i);
            V[ w ] = true;
        }
        return i;
    }
};
*/

/*
class Solution {
public:
    int minIncrementForUnique( vector<int> &A, int sum=0 ){
        sort( A.begin(), A.end() );
        for( auto it = A.empty() ? A.begin() : next( A.begin() );  it != A.end();  ++it ){
            int m = max( *prev( it ) + 1,  *it );
            sum += m - *it;
            *it = m;
        }
        return sum;
    }
};
*/

/*
class Solution {
public:
    int minIncrementForUnique( vector<int> &A, int sum=0 ){
        sort( A.begin(), A.end() );
        int m = A.empty() ? 0 : A.front();
        for( auto it = A.empty() ? A.begin() : next( A.begin() );  it != A.end();  ++it ){
            m = max( m + 1,  *it );
            sum += m - *it;
        }
        return sum;
    }
};
*/

/*
class Solution {
public:
    int minIncrementForUnique( vector<int> &A, int sum=0 ){
        sort( A.begin(), A.end() );
        int m = A.empty() ? 0 : A.front();
        for( auto it = A.empty() ? A.begin() : next( A.begin() );  it != A.end();  ++it )
            m = max( m + 1,  *it ), sum += m - *it;
        return sum;
    }
};
*/

/*
using VI = vector< int >;
class Solution {
public:
    bool validateStackSequences( VI& pushed, VI& popped, VI stack={} ){
        reverse( popped.begin(), popped.end() );
        for( const auto x: pushed ){
            stack.push_back( x );
            while( !stack.empty() && stack.back() == popped.back() ){
                stack.pop_back();
                popped.pop_back();
            }
        }
        return stack == popped;
    }
};
*/

/*
using VI = vector< int >;
class Solution {
public:
    bool validateStackSequences( VI& pushed, VI& popped, VI stack={} ){
        reverse( popped.begin(), popped.end() );
        for( const auto x: pushed )
            for( stack.push_back( x );  !stack.empty() && stack.back() == popped.back();  stack.pop_back(), popped.pop_back() );
        return stack == popped;
    }
};
*/


/*

947. Most Stones Removed with Same Row or Column

On a 2D plane, we place stones at some integer coordinate points.  Each coordinate point may have at most one stone.

Now, a move consists of removing a stone that shares a column or row with another stone on the grid.

What is the largest possible number of moves we can make?



Example 1:

Input: stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
Output: 5
Example 2:

Input: stones = [[0,0],[0,2],[1,1],[2,0],[2,2]]
Output: 3
Example 3:

Input: stones = [[0,0]]
Output: 0


Note:

1 <= stones.length <= 1000
0 <= stones[i][j] < 10000



 */




int main() {

    /*
    Solution s;
    vector<int> A{ 1,1,2,2,3,7 };
    cout << s.minIncrementForUnique( A ) << endl;
    */

    /*
    Solution s;
    VI pushed{ 1,2,3,4,5 };
    VI popped{ 4,5,3,2,1 };
    cout << s.validateStackSequences( pushed, popped ) << endl;
    */



    return 0;
}


