#include <iostream>
#include <vector>
#include <map>

using namespace std;

//Given an array of integers A with even length, return true if and only if it is possible to reorder it such that A[2 * i + 1] = 2 * A[2 * i] for every 0 <= i < len(A) / 2.
//
//
//
// 2 * A[2 * i] = A[2 * i + 1]
//
// 0, 1  ==>  2 * A[0] == A[1]
// 2, 3  ==>  2 * A[2] == A[3]
//

//Example 1:
//
//Input: [3,1,3,6]
//Output: false

//Example 2:
//
//Input: [2,1,2,6]
//Output: false

//Example 3:
//
//Input: [4, -2, 2, -4]
//     i  0   1  2   3   4
//
//Reordered: [ -2, 4 ]
//
//  i=0    A[ 1 ] = 4 ==

//Output: true
//Explanation: We can take two groups, [-2,-4] and [2,4] to form [-2,-4,2,4] or [2,4,-2,-4].

//Example 4:
//
//Input: [1,2,4,16,8,4]
//Output: false
//
//
//Note:
//
//0 <= A.length <= 30000
//A.length is even
//-100000 <= A[i] <= 100000

/*
 *
 * observations:
 *
 * there must be an even amount of positive and negative values, since 2x a value is that twice value,
 * therefore the 2x of that value is twice as positive xor twice as negative, also positive and negative
 * values must be ordered next to eachother ( NNPP ) or (PPNN) is OK, however (NPNP) will never work out
 * we can call these pairs
 *
 * each value can be either the first or second of a pair,
 *  if the value is chosen as the first of a pair then there must exist another value which is twice its size
 *  if the value is chosen as the second of a pair, then there must exist another value which is half its size
 * therefore it makes sense to order A for linearly finding pairs which match this criteria
 *
 */

bool cmp( int a, int b ){ return b < a; }
class Solution {
public:
    bool canReorderDoubled( vector<int>& A, map<int,int> m={} ){
        if( A.empty() ) return true;
        for( auto x: A )
            ++m[ (x < 0 )? -x : x ];
        for( auto pre{ m.begin() }, cur{ (pre == m.end())? pre : next(pre) }; pre != m.end() && cur != m.end();
                  pre = next(pre), cur = (pre == m.end())? pre : next(pre) )
            if( 2 * pre->first != cur->first || pre->second != cur->second )
                return false;
        return true;
    }
};

int main() {

    Solution s;
    vector<int> A{ -8,-4,-2,-1,0,0,1,2,4,8 };
    cout << s.canReorderDoubled( A ) << endl;

    return 0;
}