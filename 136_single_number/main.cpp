/*
 * 136. Single Number
 *
 * Q: https://leetcode.com/problems/single-number/
 * A: https://leetcode.com/problems/single-number/discuss/559253/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    int singleNumber(VI& A, int res = 0) {
        for (auto x: A)
            res ^= x;
        return res;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
