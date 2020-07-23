/*
 * 1438. Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit
 *
 * Q: https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit
 * A: https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/discuss/751204/Javascript-Python3-C%2B%2B-Map-for-MinMax
 */

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using Map = map<int, int>; // contents of sliding window [value, freq]
    int longestSubarray(VI& A, int T, Map m = {}, int best = 1) {
        int N = A.size(),
                i = 0,
                j = 1; // A[i..j) => i inclusive to j non-inclusive
        m[A[i]] = 1;
        for (;;) {
            auto min = m.begin()->first,
                    max = prev(m.end())->first;
            if (max - min <= T) {
                best = std::max(best, j - i); // 🎯 best, ie. max length from i inclusive to j non-inclusive
                if (j == N)
                    break;
                ++m[A[j++]];    // "grow" window
            } else {
                if (!--m[A[i]]) // "shrink" window
                    m.erase(A[i]);
                ++i;
            }
        }
        return best;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
