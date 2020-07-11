/*
 * 1508. Range Sum of Sorted Subarray Sums
 *
 * Q: https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/
 * A: https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/discuss/730561/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    int rangeSum(VI& A, int N, int L, int R, VI sums = {}, int mod = 1e9 + 7, int ans = 0) {
        for (auto i{ 0 }; i < N; ++i) {
            auto sum{ 0 };
            for (auto j{ i }; j < N; ++j)
                sums.push_back(sum = (sum + A[j]) % mod);
        }
        sort(sums.begin(), sums.end());
        for (auto i{ L - 1 }; i <= R - 1; ++i) // -1 for 1-based indexing to 0-based indexing
            ans = (ans + sums[i]) % mod;
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
