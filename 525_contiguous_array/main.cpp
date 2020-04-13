/*
 * 525. Contiguous Array
 *
 * Q: https://leetcode.com/problems/contiguous-array/
 * A: https://leetcode.com/problems/contiguous-array/discuss/577638/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using Map = unordered_map<int, int>;
    int findMaxLength(VI& A, Map seen = {}, int max = 0) {
        int N = A.size();
        VI dp(N + 1);
        for (auto i{ 1 }; i <= N; ++i)
            dp[i] = dp[i - 1] + (A[i - 1] == 0 ? -1 : 1);
        for (auto i{ 0 }; i <= N; ++i) {
            auto x = dp[i];
            if (seen.find(x) != seen.end())
                max = std::max(max, i - seen[x]);
            else
                seen[x] = i;
        }
        return max;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
