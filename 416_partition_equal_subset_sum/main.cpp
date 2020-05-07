/*
 * 416. Partition Equal Subset Sum
 *
 * Q: https://leetcode.com/problems/partition-equal-subset-sum/
 * A: https://leetcode.com/problems/partition-equal-subset-sum/discuss/617275/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <numeric>

using namespace std;

namespace TopDown {
    class Solution {
    public:
        using VI = vector<int>;
        bool canPartition(VI& A) {
            auto total = accumulate(A.begin(), A.end(), 0);
            return total % 2 ? false : go(A, total / 2);
        }
    private:
        using Set = unordered_map<int, unordered_map<int, bool>>;
        bool go(VI& A, int T, int i = 0, Set&& seen = {}) {
            if (T < 0 || seen[T][i])
                return false;
            seen[T][i] = true;
            if (i == A.size())
                return T == 0; // target 🎯
            return go(A, T - A[i], i + 1, move(seen)) || go(A, T, i + 1, move(seen)); // with xor without
        }
    };
}
namespace BottomUp {
    class Solution {
    public:
        using VI = vector<int>;
        bool canPartition(VI& A) {
            auto total = accumulate(A.begin(), A.end(), 0);
            if (total % 2)
                return false;
            auto T = total / 2; // target 🎯
            VI dp(T + 1);
            dp[0] = 1;
            for (auto x: A)
                for (auto sum{ T }; sum >= x; --sum) // potential sums to reach
                    if (dp[sum - x]) // if we can reach sum without x
                        dp[sum] = 1; // then we can reach sum with x
            return dp[T]; // reached target sum?
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
