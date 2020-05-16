/*
 * 918. Maximum Sum Circular Subarray
 *
 * Q: https://leetcode.com/problems/maximum-sum-circular-subarray/
 * A: https://leetcode.com/problems/maximum-sum-circular-subarray/discuss/633598/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    int maxSubarraySumCircular(VI& A, int INF = 1e9) {
        auto min = kadane(A, std::less<int>{}),
             max = kadane(A, std::greater<int>{}),
             sum = accumulate(A.begin(), A.end(), 0);
        return std::max(max, sum - min ? sum - min : -INF); // max of "no wrap" xor "wrap" 🎯
    }
private:
    template <typename Cmp>
    int kadane(VI& A, Cmp f) {
        auto sum = A[0],
             ans = A[0];
        for (auto i{ 1 }; i < A.size(); ++i)
            sum = f(sum + A[i], A[i]) ? sum + A[i] : A[i],
            ans = f(ans, sum) ? ans : sum;
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
