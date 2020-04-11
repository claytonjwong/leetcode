/*
 * 1403. Minimum Subsequence in Non-Increasing Order
 *
 * Q: https://leetcode.com/problems/minimum-subsequence-in-non-increasing-order/
 * A: https://leetcode.com/problems/minimum-subsequence-in-non-increasing-order/discuss/574389/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    VI minSubsequence(VI& A, VI ans = {}) {
        sort(A.rbegin(), A.rend());
        auto total = accumulate(A.begin(), A.end(), 0),
             half = total / 2;
        for (auto i{ 0 }, sum{ 0 }; i < A.size() && sum <= half; ++i)
            sum += A[i], ans.push_back(A[i]);
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
