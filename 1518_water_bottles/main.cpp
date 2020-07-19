/*
 * 1518. Water Bottles
 *
 * Q: https://leetcode.com/problems/water-bottles/
 * A: https://leetcode.com/problems/water-bottles/discuss/743230/Javascript-Python3-C%2B%2B-1-Liners
 */

#include <iostream>

namespace TopDownConcise {
    class Solution {
    public:
        int numWaterBottles(int n, int k) {
            return n < k ? n : k + numWaterBottles(n - k + 1, k);
        }
    };
}

namespace TopDownVerbose {
    class Solution {
    public:
        int numWaterBottles(int n, int k) {
            // 🛑 base case: drink all n bottles and 🚫 cannot exchange enough empty bottles for another drink
            if (n < k)
                return n;
            // 🚀 recursive case: drink k bottles at a time and ✅ exchange those k empty bottles for +1 more drink 🍺
            return k + numWaterBottles(n - k + 1, k);
        }
    };
}

namespace BottomUp {
    class Solution {
    public:
        int numWaterBottles(int n, int k, int d = 0) {
            while (k <= n)
                d = d + k,     // 🚀 drink k bottles at a time
                n = n - k + 1; // ✅ exchange k empty bottles for +1 more drink 🍺
            return d + n;      // 🛑 drink remaining n bottles and 🚫 cannot exchange enough empty bottles for another drink
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
