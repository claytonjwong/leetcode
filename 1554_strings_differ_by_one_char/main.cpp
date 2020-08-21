/*
 * 1554. Strings Differ by One Character
 *
 * Q: https://leetcode.com/problems/strings-differ-by-one-character/
 * A: https://leetcode.com/problems/strings-differ-by-one-character/discuss/804559/Javascript-Python3-C%2B%2B-Diff-Collision-Base-123
 */

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    using VS = vector<string>;
    using LL = long long;
    using VLL = vector<LL>;
    using Set = unordered_set<LL>;
    bool differByOne(VS& A, Set seen = {}, LL MOD = LL(1e13)) {
        int M = A.size(),
            N = A[0].size();
        VLL hash(M);
        // 1. generate each i-th rolling hash
        for (auto i{ 0 }; i < M; ++i) {
            LL base{ 1 };
            for (auto j{ 0 }; j < N; ++j) {
                hash[i] = (hash[i] + A[i][j] * base) % MOD;
                base = 123 * base % MOD;
            }
        }
        // 2. remove each j-th char from each i-th rolling hash to 🔍 find a diff collision 💥
        for (auto i{ 0 }; i < M; ++i) {
            LL base{ 1 };
            for (auto j{ 0 }; j < N; ++j) {
                auto diff = (hash[i] - A[i][j] * base) % MOD;
                if (!seen.insert(diff).second)
                    return true;  // 🎯 found a diff collision 💥
                base = 123 * base % MOD;
            }
        }
        return false;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
