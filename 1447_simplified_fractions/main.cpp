/*
 * 1447. Simplified Fractions
 *
 * Q: https://leetcode.com/problems/simplified-fractions/discuss/639812/Javascript-and-C%2B%2B-solutions
 * A: https://leetcode.com/problems/simplified-fractions/discuss/639812/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    using VS = vector<string>;
    VS simplifiedFractions(int N, VS ans = {}) {
        for (size_t j{ 2 }; j <= N; ++j)
            for (size_t i{ 1 }; i < j; ++i)
                if (__gcd(i, j) == 1)
                    ans.push_back(to_string(i) + "/" + to_string(j));
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
