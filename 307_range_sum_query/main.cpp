/*
 * 307. Range Sum Query - Mutable
 *
 * Q: https://leetcode.com/problems/range-sum-query-mutable/
 * A: https://leetcode.com/problems/range-sum-query-mutable/discuss/665390/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

namespace Naive {
    class NumArray {
    public:
        using VI = vector<int>;
        NumArray(VI& A) : A{ A } {
        }
        void update(int i, int val) {
            A[i] = val;
        }
        int sumRange(int i, int j, int sum = 0) {
            while (i <= j)
                sum += A[i++];
            return sum;
        }
    private:
        VI A;
    };
}

namespace PrefixSums {
    class NumArray {
    public:
        using VI = vector<int>;
        NumArray(VI& A) : A{ A } {
            int N = A.size();
            dp.resize(N + 1);
            prefixSums();
        }
        void update(int i, int val) {
            A[i] = val;
            prefixSums(i);
        }
        int sumRange(int i, int j, int sum = 0) {
            return dp[j + 1] - dp[i];
        }
    private:
        VI A, dp;
        void prefixSums(int start = 0) {
            if (!start)
                dp[0] = 0;
            for (auto i{ start + 1 }; i < dp.size(); ++i) dp[i] = A[i - 1] + dp[i - 1];
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
