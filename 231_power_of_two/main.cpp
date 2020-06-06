/*
 * 231. Power of Two
 *
 * Q: https://leetcode.com/problems/power-of-two/
 * A: https://leetcode.com/problems/power-of-two/discuss/672555/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int x) {
        return x <= 0 ? false : !(x & (x - 1));
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
