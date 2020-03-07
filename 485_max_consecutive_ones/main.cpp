/*
 * 485. Max Consecutive Ones
 *
 * Q: https://leetcode.com/problems/max-consecutive-ones/
 * A: https://leetcode.com/problems/max-consecutive-ones/discuss/530121/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    int findMaxConsecutiveOnes(VI& A, int ans = 0) {
        for (auto i = 0, cur = 0; i < A.size(); ++i)
            ans = max(ans, cur = A[i] == 0 ? 0 : cur + 1);
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
