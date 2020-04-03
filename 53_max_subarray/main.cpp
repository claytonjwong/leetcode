/*
 * 53. Maximum Subarray
 *
 * Q: https://leetcode.com/problems/maximum-subarray/
 * A: https://leetcode.com/problems/maximum-subarray/discuss/561900/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    int maxSubArray(VI& A) {
        int sum = A[0],
            max = A[0];
        for (auto i{ 1 }; i < A.size(); ++i)
            sum = std::max(sum + A[i], A[i]),
            max = std::max(max, sum);
        return max;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
