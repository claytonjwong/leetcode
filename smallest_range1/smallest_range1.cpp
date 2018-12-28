/*

 Q: https://leetcode.com/problems/smallest-range-i/description/
 A:

Given an array A of integers, for each integer A[i] we may choose any x with -K <= x <= K, and add x to A[i].

After this process, we have some array B.

Return the smallest possible difference between the maximum value of B and the minimum value of B.

Example 1:

Input: A = [1], K = 0
Output: 0
Explanation: B = [1]
Example 2:

Input: A = [0,10], K = 2
Output: 6
Explanation: B = [2,8]
Example 3:

Input: A = [1,3,6], K = 3
Output: 0
Explanation: B = [3,3,3] or B = [4,4,4]


Note:

1 <= A.length <= 10000
0 <= A[i] <= 10000
0 <= K <= 10000

*/

#include <iostream>
#include <vector>
#include <set>
#include <numeric>
#include <algorithm>

using namespace std;


class Solution {
public:
    int smallestRangeI ( vector< int >& A, int K ) {
        set< int > choosen;
        auto target = static_cast< int >(  accumulate( A.begin(), A.end(), 0 ) / A.size()  );
        for_each( A.begin(), A.end(), [&]( const int value ){
            auto diff = abs( value - target );

        });
        auto [ minIt, maxIt ] = minmax_element( choosen.begin(), choosen.end() );
        return *maxIt - *minIt;
    }
};

int main() {

    Solution s;

    vector< int > A{ 1 };  int K = 0;
    auto result = s.smallestRangeI( A, K );
    assert( result == 0 );

    A = { 0, 10 };  K = 2;
    result = s.smallestRangeI( A, K );
    assert( result == 6 );

    A = { 1, 3, 6 };  K = 3;
    result = s.smallestRangeI( A, K );
    assert( result == 0 );

    return 0;
}