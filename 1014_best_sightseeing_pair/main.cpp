/*
 * 1014. Best Sightseeing Pair
 *
 * Q: https://leetcode.com/problems/best-sightseeing-pair/
 * A: https://leetcode.com/problems/best-sightseeing-pair/discuss/592496/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

namespace BruteForce {
    class Solution {
    public:
        using VI = vector<int>;
        int maxScoreSightseeingPair(VI& A, int max = -1) {
            auto score = [&](auto i, auto j) { return A[i] + A[j] + i - j; };
            int N = A.size();
            for (auto i{ 0 }; i < N; ++i)
                for (auto j{ i + 1 }; j < N; ++j)
                    max = std::max(max, score(i, j));
            return max;
        }
    };
}

namespace Linear {
    class Solution {
    public:
        using VI = vector<int>;
        int maxScoreSightseeingPair(VI& A, int max = -1) {
            auto score = [&](auto i, auto j) { return A[i] + A[j] + i - j; };
            int N = A.size();
            for (auto i{ 0 }, j{ 1 }; j < N; ++j) {
                max = std::max(max, score(i, j));
                if (A[i] + i < A[j] + j)
                    i = j; // best i found at j
            }
            return max;
        }
    };
}

int main() {
    Linear::Solution::VI A{8,1,5,2,6,5,8,9,3,1,2,3,4,5,6,7,8,3,1,0};
    Linear::Solution s;
    cout << s.maxScoreSightseeingPair(A) << endl;
    return 0;
}
