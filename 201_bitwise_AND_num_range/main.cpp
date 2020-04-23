/*
 * 201. Bitwise AND of Numbers Range
 *
 * Q: https://leetcode.com/problems/bitwise-and-of-numbers-range/
 * A: https://leetcode.com/problems/bitwise-and-of-numbers-range/discuss/593850/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>

using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int M, int N, int ans = 0) {
        for (unsigned int i = 1 << 31; i > 0; i >>= 1)
            if (i > N && M >= i >> 1)
                ans |= i >> 1,
                  N -= i >> 1,
                  M -= i >> 1;
        return ans;
    }
};

int main() {
    Solution solution;
    cout << solution.rangeBitwiseAnd(2147483646, 2147483647) << endl;
    return 0;
}
