/*
 * 1150. Check If a Number Is Majority Element in a Sorted Array
 *
 * Q: https://leetcode.com/problems/check-if-a-number-is-majority-element-in-a-sorted-array/
 * A: https://leetcode.com/problems/check-if-a-number-is-majority-element-in-a-sorted-array/discuss/854521/Javascript-Python3-C%2B%2B-Equal-Range-via-.-Binary-Search
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    bool isMajorityElement(VI& A, int T) {
        auto [ i, j ] = equal_range(A.begin(), A.end(), T);
        return A.size() / 2 < distance(i, j);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
