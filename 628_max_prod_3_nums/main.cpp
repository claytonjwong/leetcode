/*
 * 628. Maximum Product of Three Numbers
 *
 * Q: https://leetcode.com/problems/maximum-product-of-three-numbers/
 * A: https://leetcode.com/problems/maximum-product-of-three-numbers/discuss/504153/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    int maximumProduct(VI& A) {
        auto a = -1001, b = -1001, c = -1001, p = 0, q = 0;
        for (auto x: A) {
            if (x > a)
                c = b, b = a, a = x;
            else if (x > b)
                c = b, b = x;
            else if (x > c)
                c = x;

            if (x < p)
                q = p, p = x;
            else if (x < q)
                q = x;
        }
        return max(a * b * c, a * p * q);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
