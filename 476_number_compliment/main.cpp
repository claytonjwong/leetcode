/*
 * 476. Number Complement
 *
 * Q: https://leetcode.com/problems/number-complement/
 * A: https://leetcode.com/problems/number-complement/discuss/613046/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>

using namespace std;

class Solution {
public:
    int findComplement(int x, long i = 1) {
        while (i < x)
            i <<= 1;
        return ~x & (i - 1);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
