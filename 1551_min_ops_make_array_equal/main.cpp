/*
 * 1551. Minimum Operations to Make Array Equal
 *
 * Q: https://leetcode.com/problems/minimum-operations-to-make-array-equal/discuss/794101/Javascript-Python3-C%2B%2B-Single-xor-Double-Middle
 * A: https://leetcode.com/problems/minimum-operations-to-make-array-equal/discuss/794101/Javascript-Python3-C%2B%2B-Single-xor-Double-Middle
 */

#include <iostream>

using namespace std;

namespace Concise {
    class Solution {
    public:
        int minOperations(int n, int ans = 0) {
            return (n / 2) * ((n + 1) / 2);
        }
    };
}

namespace Verbose {
    class Solution {
    public:
        int minOperations(int n, int ans = 0) {
            for (auto i{ 0 }, cur = n % 2 ? 2 : 1; i < n / 2; ++i, cur += 2)
                ans += cur;
            return ans;
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
