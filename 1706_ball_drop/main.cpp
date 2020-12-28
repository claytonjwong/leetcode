/*
 * 1706. Where Will the Ball Fall
 *
 * Q: https://leetcode.com/problems/where-will-the-ball-fall/
 * A: https://leetcode.com/problems/where-will-the-ball-fall/discuss/988174/kt-js-py3-cpp-simulation-recursive-iterative
 */

#include <iostream>
#include <vector>

using namespace std;

namespace RecursiveConcise {
    class Solution {
    public:
        using VI = vector<int>;
        using VVI = vector<VI>;
        using fun = function<int(int, int)>;
        VI findBall(VVI& A, VI ans = {}) {
            int M = A.size(),
                N = A[0].size();
            fun drop = [&](auto i, auto j) {
                return i == M ? j : 0 <= j && j < N && 0 <= j + A[i][j] && j + A[i][j] < N && A[i][j] == A[i][j + A[i][j]] ? drop(i + 1, j + A[i][j]) : -1;
            };
            for (auto j{ 0 }; j < N; ans.push_back(drop(0, j++)));
            return ans;
        }
    };
}
namespace RecursiveVerbose {
    class Solution {
    public:
        using VI = vector<int>;
        using VVI = vector<VI>;
        using fun = function<int(int, int)>;
        VI findBall(VVI& A, VI ans = {}) {
            int M = A.size(),
                N = A[0].size();
            fun drop = [&](auto i, auto j) {
                if (i == M)
                    return j;
                if (0 <= j && j < N && 0 <= j + A[i][j] && j + A[i][j] < N && A[i][j] == A[i][j + A[i][j]])
                    return drop(i + 1, j + A[i][j]);
                return -1;
            };
            for (auto j{ 0 }; j < N; ans.push_back(drop(0, j++)));
            return ans;
        }
    };
}
namespace Iterative {
    class Solution {
    public:
        using VI = vector<int>;
        using VVI = vector<VI>;
        VI findBall(VVI& A, VI ans = {}) {
            int M = A.size(),
                N = A[0].size();
            for (auto k{ 0 }; k < N; ++k) {
                auto i = 0,
                     j = k;
                while (i < M && 0 <= j && j < N && 0 <= j + A[i][j] && j + A[i][j] < N && A[i][j] == A[i][j + A[i][j]])
                    j += A[i][j], ++i;
                ans.push_back(i == M ? j : -1);
            }
            return ans;
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
