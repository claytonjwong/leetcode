/*
 * 1464. Maximum Product of Two Elements in an Array
 *
 * Q: https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/
 * A: https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/discuss/661624/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    int maxProduct(VI& A) {
        sort(A.begin(), A.end());
        return (A[A.size() - 2] - 1) * (A[A.size() - 1] - 1);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
