/*
 * 560. Subarray Sum Equals K
 *
 * Q: https://leetcode.com/problems/subarray-sum-equals-k/
 * A: https://leetcode.com/problems/subarray-sum-equals-k/discuss/592292/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using Map = unordered_map<int, int>;
    int subarraySum(VI& A, int T, Map seen = {}, int cnt = 0) {
        int N = A.size();
        VI S(N + 1);
        for (auto i{ 1 }; i <= N; ++i)
            S[i] = S[i - 1] + A[i - 1];
        for (auto i{ 0 }; i <= N; ++i) {
            auto x = S[i],
                 y = S[i] - T; // target 🎯
            cnt += seen[y];
            ++seen[x];
        }
        return cnt;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
