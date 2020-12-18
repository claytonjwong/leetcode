/*
 * 334. Increasing Triplet Subsequence
 *
 * Q: https://leetcode.com/problems/increasing-triplet-subsequence/
 * A: https://leetcode.com/problems/increasing-triplet-subsequence/discuss/977048/Kt-Js-Py3-Cpp-Construct-a-b-c
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    bool increasingTriplet(VI& A, long a = 6e9, long b = 6e9, long c = 6e9) {
        for (auto x: A)
            if      (x <= a) a = x;
            else if (x <= b) b = x;
            else if (x <= c) c = x;
        return c < 6e9;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
