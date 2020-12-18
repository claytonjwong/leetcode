/*
 * 334. Increasing Triplet Subsequence
 *
 * Q: https://leetcode.com/problems/increasing-triplet-subsequence/
 * A: https://leetcode.com/problems/increasing-triplet-subsequence/discuss/977048/Kt-Js-Py3-Cpp-Track-Two-Minimums
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    bool increasingTriplet(VI& A, long a = 6e9, long b = 6e9) {
        for (auto x: A)
            if (x <= a)
                a = x;
            else if (x <= b)
                b = x;
            else
                return true;
        return false;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
