/*
 * Rank            Name            Score    Finish Time    Q1 (3)     Q2 (4)    Q3 (5)   Q4 (6)
 * 4757 / 14373    claytonjwong    7        0:17:32        0:01:00    0:17:32
 */

#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <numeric>
#include <iterator>

using namespace std;

/*
 * 1550. Three Consecutive Odds
 *
 * Q: https://leetcode.com/problems/three-consecutive-odds/
 * A: https://leetcode.com/problems/three-consecutive-odds/discuss/794079/Javascript-Python3-C%2B%2B-1-Liners-via-reduce()
 */
namespace Question1 {
    class Solution {
    public:
        using VI = vector<int>;
        bool threeConsecutiveOdds(VI& A) {
            return accumulate(A.begin(), A.end(), false, [i = -1, &A](auto found, auto _) mutable {
                return ++i < 2 ? found : found || ((A[i - 2] % 2) && (A[i - 1] % 2) && (A[i] % 2));
            });
        }
    };
}

/*
 * 1551. Minimum Operations to Make Array Equal
 *
 * Q: https://leetcode.com/problems/minimum-operations-to-make-array-equal/discuss/794101/Javascript-Python3-C%2B%2B-Single-xor-Double-Middle
 * A: https://leetcode.com/problems/minimum-operations-to-make-array-equal/discuss/794101/Javascript-Python3-C%2B%2B-Single-xor-Double-Middle
 */
namespace Question2 {
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
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
