/*
 * 1362. Closest Divisors
 *
 * Q: https://leetcode.com/problems/closest-divisors/
 * A: https://leetcode.com/problems/closest-divisors/discuss/523218/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    VI closestDivisors(int x, int a = 0, int b = 0, int diff = int(1e9 + 7)) {
        for (auto i = 1; i * i <= x + 2; ++i) {
            auto j = (x + 1) / i,
                    k = (x + 2) / i;
            if (i * j == x + 1 && abs(i - j) < diff) a = i, b = j, diff = abs(i - j);
            if (i * k == x + 2 && abs(i - k) < diff) a = i, b = k, diff = abs(i - k);
        }
        return {a, b};
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
