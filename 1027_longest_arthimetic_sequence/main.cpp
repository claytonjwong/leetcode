/*
 * 1027. Longest Arithmetic Sequence
 *
 * Q: https://leetcode.com/problems/longest-arithmetic-sequence/
 * A: https://leetcode.com/problems/longest-arithmetic-sequence/discuss/544568/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

namespace Verbose {
    class Solution {
    public:
        using VI = vector<int>;
        using Map = unordered_map<int, unordered_map<int, int>>;
        int longestArithSeqLength(VI& A, Map buckets = {}, int max = 0) { // buckets is {diff: {index: len}}
            int N = A.size();
            for (auto i = 0; i < N; ++i) {
                for (auto j = i + 1; j < N; ++j) {
                    auto diff = A[j] - A[i];
                    if (buckets[diff][i])
                        buckets[diff][j] = 1 + buckets[diff][i]; // case 1: append j to existing arithmetic sequence ending at i
                    else
                        buckets[diff][j] = 2;                    // case 2: start a new arithmetic sequence (2 for i and j inclusive)
                    max = std::max(max, buckets[diff][j]);
                }
            }
            return max;
        }
    };
}

namespace Concise {

//    class Solution {
//    public:
//        using VI = vector<int>;
//        using Map = unordered_map<int, unordered_map<int, int>>;
//        int longestArithSeqLength(VI& A, Map dp = {}, int max = 0) { // dp is {diff: {index: len}}
//            int N = A.size();
//            for (auto i = 0; i < N; ++i) {
//                for (auto j = i + 1; j < N; ++j) {
//                    auto k = A[j] - A[i];
//                    dp[k][j] = 1 + (dp[k][i] ? dp[k][i] : 1);
//                    max = std::max(max, dp[k][j]);
//                }
//            }
//            return max;
//        }
//    };

    class Solution {
    public:
        using VI = vector<int>;
        using Map = unordered_map<int, unordered_map<int, int>>;
        int longestArithSeqLength(VI& A, Map dp = {}, int max = 0) { // dp is {diff: {index: len}}
            int N = A.size();
            for (auto i = 0; i < N; ++i)
                for (auto j = i + 1, k = 0; j < N; ++j)
                    k = A[j] - A[i],
                    max = std::max(max, dp[k][j] = 1 + (dp[k][i] ? dp[k][i] : 1));
            return max;
        }
    };
}

int main() {
    Verbose::Solution solution;
    Verbose::Solution::VI A{3,6,9,12};
    cout << solution.longestArithSeqLength(A) << endl;
    return 0;
}
