/*
 * 1099. Two Sum Less Than K
 *
 * Q: https://leetcode.com/problems/two-sum-less-than-k/
 * A: https://leetcode.com/problems/two-sum-less-than-k/discuss/603797/Kt-Js-Py3-Cpp-Greedy-%2B-Brute-Force-solutions
 */

#include <iostream>
#include <vector>
#include <set>

using namespace std;

namespace Greedy {
    class Solution {
    public:
        using VI = vector<int>;
        int twoSumLessThanK(VI& A, int K, int best = -1) {
            sort(A.begin(), A.end());
            int N = A.size(),
                i = 0,
                j = N - 1;
            while (i < j) {
                if (A[i] + A[j] < K) {
                    best = max(best, A[i] + A[j]);
                    ++i;
                } else {
                    --j;
                }
            }
            return best;
        }
    };
}

namespace BruteForce {
    class Solution {
    public:
        using VI = vector<int>;
        int twoSumLessThanK(VI& A, int K, int best = -1) {
            int N = A.size();
            for (auto i{ 0 }; i < N; ++i)
                for (auto j{ i + 1 }; j < N; ++j)
                    if (A[i] + A[j] < K)
                        best = max(best, A[i] + A[j]);
            return best;
        }
    };
}

namespace LowerBound {
    class Solution {
    public:
        using VI = vector<int>;
        using Set = set<int>;
        int twoSumLessThanK(VI &A, int K, Set seen = {}, int max = -1) {
            for (auto x: A) {
                auto T = K - x;
                auto it = seen.lower_bound(T);
                if (it != seen.begin())
                    max = std::max(max, x + *--it);
                seen.insert(x);
            }
            return max;
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
