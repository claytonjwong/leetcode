/*
 * 1558. Minimum Numbers of Function Calls to Make Target Array
 *
 * Q: https://leetcode.com/problems/minimum-numbers-of-function-calls-to-make-target-array/
 * A: https://leetcode.com/problems/minimum-numbers-of-function-calls-to-make-target-array/discuss/813579/Javascript-Python3-C%2B%2B-Operation-0-%2B-1
 */

#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    int minOperations(VI& A) {
        return accumulate(A.begin(), A.end(), 0, [&](auto ops, auto x) { return ops + __builtin_popcount(x); })
             + log2(*max_element(A.begin(), A.end()));
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
