/*
 * 70. Climbing Stairs
 *
 * Q: https://leetcode.com/problems/climbing-stairs/
 * A: https://leetcode.com/problems/climbing-stairs/discuss/765266/Javascript-Python3-C%2B%2B-fib-O(1)-mem-with-a-b-c
 */

#include <iostream>

class Solution {
public:
    int climbStairs(int N, int a = 0, int b = 1, int c = 1) {
        while (N--)
            c = a + b, a = b, b = c;
        return c;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
