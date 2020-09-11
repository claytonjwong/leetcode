/*
 * 152. Maximum Product Subarray
 *
 * Q: https://leetcode.com/problems/maximum-product-subarray/
 * A: https://leetcode.com/problems/maximum-product-subarray/discuss/48233/Javascript-Python3-C%2B%2B-MinMax-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    int maxProduct(VI& A) {
        auto min = A[0],
             max = A[0],
             ans = A[0];
        for (auto i{ 1 }; i < A.size(); ++i) {
            tie(min, max) = std::minmax({ A[i], min * A[i], max * A[i] });
            ans = std::max(ans, max);
        }
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
