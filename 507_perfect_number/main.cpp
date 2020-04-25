/*
 * 507. Perfect Number
 *
 * Q: https://leetcode.com/problems/perfect-number/
 * A: https://leetcode.com/problems/perfect-number/discuss/595770/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>

using namespace std;

class Solution {
public:
    bool checkPerfectNumber(int x, int sum = 1) {
        for (auto i{ 2 }; i * i <= x; ++i)
            if (x % i == 0)
                sum += i + (x / i);
        return x > 1 && x == sum;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
