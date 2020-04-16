/*
 * 268. Missing Number
 *
 * Q: https://leetcode.com/problems/missing-number/
 * A: https://leetcode.com/problems/missing-number/discuss/581574/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    int missingNumber(VI& A) {
        int N = A.size() + 1;
        auto sum = accumulate(A.begin(), A.end(), 0);
        return (N * (N - 1) / 2) - sum;
    }
};

class Solution {
public:
    using VI = vector<int>;
    int missingNumber(VI& A) {
        return ((A.size() + 1) * A.size() / 2) - accumulate(A.begin(), A.end(), 0);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
