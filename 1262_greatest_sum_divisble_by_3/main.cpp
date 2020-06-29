/*
 * 1262. Greatest Sum Divisible by Three
 *
 * Q: https://leetcode.com/problems/greatest-sum-divisible-by-three/
 * A: https://leetcode.com/problems/greatest-sum-divisible-by-three/discuss/439097/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

namespace Verbose {
    class Solution {
    public:
        using VI = vector<int>;
        using VVI = vector<VI>;
        int maxSumDivThree(VI &A) {
            int N = A.size();
            VVI buckets(N + 1, VI(3));
            for (auto i{1}; i <= N; ++i) {
                buckets[i] = buckets[i - 1]; // create current from previous 🤔
                for (auto j: VI{0, 1, 2}) {
                    auto sum = A[i - 1] + buckets[i - 1][j]; // add A[i] onto each previous bucket (A[i - 1] for A[i] because buckets is offset by 1)
                    buckets[i][sum % 3] = max(buckets[i][sum % 3], sum); // update each (current sum % 3) bucket to max of itself and the current sum
                }
            }
            return buckets[N][0]; // max sum of all N items of A which is evenly divisible by 3 🎯
        }
    };
}

namespace MemOpt {
    class Solution {
    public:
        using VI = vector<int>;
        int maxSumDivThree(VI& A) {
            int N = A.size();
            VI cur(3);
            for (auto i{ 1 }; i <= N; ++i) {
                auto pre{ cur }; // create current from previous 🤔
                for (auto j: VI{ 0, 1, 2 }) {
                    auto sum = A[i - 1] + pre[j]; // add A[i] onto each previous bucket (A[i - 1] for A[i] because buckets is offset by 1)
                    cur[sum % 3] = max(cur[sum % 3], sum); // update each (current sum % 3) bucket to max of itself and the current sum
                }
            }
            return cur[0]; // max sum of all N items of A which is evenly divisible by 3 🎯
        }
    };
}

namespace MemOptMoreConcise {
    class Solution {
    public:
        using VI = vector<int>;
        int maxSumDivThree(VI& A) {
            VI cur(3);
            for (auto x: A) {
                auto pre{ cur }; // create current from previous 🤔
                for (auto y: pre) {
                    auto sum = x + y; // add A[i] (ie. x) onto each previous bucket value (ie. y)
                    cur[sum % 3] = max(cur[sum % 3], sum); // update each (current sum % 3) bucket to max of itself and the current sum
                }
            }
            return cur[0]; // max sum of all N items of A which is evenly divisible by 3 🎯
        }
    };
}

namespace MemOptMostConcise {
    class Solution {
    public:
        using VI = vector<int>;
        int maxSumDivThree(VI& A) {
            VI cur(3);
            for (auto x: A) {
                auto pre{ cur }; // create current from previous 🤔
                for (auto y: pre)
                    cur[(x + y) % 3] = max(cur[(x + y) % 3], x + y); // update each (current sum % 3) bucket to max of itself and the current sum
            }
            return cur[0]; // max sum of all N items of A which is evenly divisible by 3 🎯
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
