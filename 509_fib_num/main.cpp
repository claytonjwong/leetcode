/*
 * 509. Fibonacci Number
 *
 * Q: https://leetcode.com/problems/fibonacci-number/
 * A: https://leetcode.com/problems/fibonacci-number/discuss/595781/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>

using namespace std;

namespace TopDown {
    class Solution {
    public:
        int fib(int N) {
            return N < 2 ? N : fib(N - 1) + fib(N - 2);
        }
    };
}
namespace BottomUp {
    class Solution {
    public:
        int fib(int N, int a = 0, int b = 1, int c = 1) {
            if (N < 2)
                return N;
            for (; --N; c = a + b, a = b, b = c);
            return c;
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
