/*
 * 674. Longest Continuous Increasing Subsequence
 *
 * Q: https://leetcode.com/problems/longest-continuous-increasing-subsequence/
 * A: https://leetcode.com/problems/longest-continuous-increasing-subsequence/discuss/635727/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    int findLengthOfLCIS(VI& A) {
        int max = !A.empty();
        for (auto i{ 1 }, run{ 1 }; i < A.size(); ++i)
            max = std::max(max, run = A[i - 1] < A[i] ? run + 1 : 1);
        return max;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
