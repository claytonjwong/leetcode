/*
 * 1380. Lucky Numbers in a Matrix
 *
 * Q: https://leetcode.com/problems/lucky-numbers-in-a-matrix/
 * A: https://leetcode.com/problems/lucky-numbers-in-a-matrix/discuss/539707/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    VI luckyNumbers (VVI& A, int INF = 1e9 + 7, VI ans = {}) {
        auto M = A.size(),
             N = A[0].size();
        VI min(M,  INF),
           max(N, -INF);
        for (auto i = 0; i < M; ++i)
            for(auto j = 0; j < N; ++j)
                min[i] = std::min(min[i], A[i][j]),
                max[j] = std::max(max[j], A[i][j]);
        for (auto i = 0; i < M; ++i)
            for(auto j = 0; j < N; ++j)
                if (min[i] == max[j])  // \U0001f340 lucky number \U0001f340
                    ans.push_back(A[i][j]);
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
