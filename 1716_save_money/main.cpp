/*
 * 1716. Calculate Money in Leetcode Bank
 *
 * Q: https://leetcode.com/problems/calculate-money-in-leetcode-bank/
 * A: https://leetcode.com/problems/calculate-money-in-leetcode-bank/discuss/1008853/Kt-Js-Py3-Cpp-Iterative-Accumulation
 */

#include <iostream>

using namespace std;

class Solution {
public:
    int totalMoney(int n, int start = 1, int day = 0, int x = 0, int total = 0) {
        while (n--) {
            if (day++ % 7 == 0)
                x = start++;
            total += x++;
        }
        return total;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
