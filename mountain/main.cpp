/*
 *
 * 941. Valid Mountain Array
 *
 * Q: https://leetcode.com/problems/valid-mountain-array/
 * A: https://leetcode.com/problems/valid-mountain-array/discuss/195385/Concise-C%2B%2B
 *
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool validMountainArray( vector<int>& A ){

//        auto i = adjacent_find( A.cbegin(), A.cend(), greater_equal<int>() );
//        auto j = adjacent_find( A.crbegin(), A.crend(), greater_equal<int>() );
//        auto k = adjacent_find( A.crbegin(), A.crend(), greater_equal<int>() ).base();
//        cout << " dist(i): " << distance(A.cbegin(), i) << " *i: " << *i << "  i == end ? " << (i == A.cend()) << endl;
//        cout << " dist(j.base()): " << distance(A.cbegin(), j.base()) << " *j " << *j << endl;
//        cout << " dist(k): " << distance(A.cbegin(), k) << " *k " << *k << " k == end ? " << (k == A.cend()) << endl;
//        cout << " overall distance " << distance(
//            adjacent_find( A.cbegin(), A.cend(), greater_equal<int>() ),
//            adjacent_find( A.crbegin(), A.crend(), greater_equal<int>() ).base() ) << endl;
        return 1 == distance(
            adjacent_find( A.cbegin(), A.cend(), greater_equal<int>() ),
            adjacent_find( A.crbegin(), A.crend(), greater_equal<int>() ).base() );
    }
};

int main() {

    Solution s;
    vector<int> A{ 1, 2 };

    cout << s.validMountainArray( A ) << endl;

    return 0;
}