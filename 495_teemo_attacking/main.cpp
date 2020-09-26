/*
 * 495. Teemo Attacking
 *
 * Q: https://leetcode.com/problems/teemo-attacking/
 * A: https://leetcode.com/problems/teemo-attacking/discuss/865500/Javascript-Python3-C%2B%2B-Accumulate-Non-overlapping-Intervals-i..j
 */

#include <iostream>
#include <vector>

using namespace std;

namespace Concise {
    class Solution {
    public:
        using VI = vector<int>;
        int findPoisonedDuration(VI& A, int K, int hi = -1, int total = 0) {
            for (auto x: A) {
                auto i = max(hi, x),
                     j = x + K;
                total += j - i;
                hi = max(hi, j);
            }
            return total;
        }
    };
}
namespace Verbose {
    class Solution {
    public:
        using VI = vector<int>;
        int findPoisonedDuration(VI& A, int K, int hi = -1, int total = 0) {
            for (auto x: A) {
                auto i = max(hi, x),
                     j = x + K - 1;     // -1 for i..j inclusive
                total += j - i + 1;     // +1 for i..j inclusive
                hi = max(hi, j + 1);    // +1 to skip past redundant timeslot j
            }
            return total;
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
