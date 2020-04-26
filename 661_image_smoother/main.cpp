/*
 * 661. Image Smoother
 *
 * Q: https://leetcode.com/problems/image-smoother/
 * A: https://leetcode.com/problems/image-smoother/discuss/599157/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    VVI imageSmoother(VVI& A) {
        auto M = A.size(),
             N = M ? A[0].size() : 0;
        VVI ans(M, VI(N));
        auto scale = [&](auto i, auto j) {
            auto sum{ A[i][j] }, cnt{ 1 };
            for (auto& dir: VVI{{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}}) {
                auto u = i + dir[0],
                     v = j + dir[1];
                if (u < 0 || u == M || v < 0 || v == N)
                    continue;
                sum += A[u][v], ++cnt;
            }
            return sum / cnt;
        };
        for (auto i{ 0 }; i < M; ++i)
            for (auto j{ 0 }; j < N; ++j)
                ans[i][j] = scale(i, j);
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
