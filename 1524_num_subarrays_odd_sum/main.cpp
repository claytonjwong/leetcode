/*
 * 1524. Number of Sub-arrays With Odd Sum
 *
 * Q: https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/
 * A: https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/discuss/754751/Javascript-Python3-C%2B%2B-count-of-evenodd-sums
 */

#include <iostream>
#include <vector>

using namespace std;

namespace Question2 {
    class Solution {
    public:
        using VI = vector<int>;
        using LL = long long;
        using VLL = vector<LL>;
        int numOfSubarrays(VI& A, int sum = 0, VLL cnt = VLL{ 1, 0 }) {
            for (auto i{ 0 }; i < A.size(); ++i)
                ++cnt[(sum += A[i]) % 2];
            return (cnt[0] * cnt[1]) % int(1e9 + 7);
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
