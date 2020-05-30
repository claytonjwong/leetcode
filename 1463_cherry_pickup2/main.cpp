/*
 * 1463. Cherry Pickup II
 *
 * Q: https://leetcode.com/problems/cherry-pickup-ii/
 * A: https://leetcode.com/problems/cherry-pickup-ii/discuss/660828/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>

using namespace std;

namespace TopDown {
    class Solution {
    public:
        using VI = vector<int>;
        using VVI = vector<VI>;
        int cherryPickup(VVI& A) {
            int M = A.size(),
                N = A[0].size();
            return go(A, 0, 0, N - 1);
        }
    private:
        int go(VVI& A, int i, int L, int R, int max = 0) {
            if (i == A.size())
                return 0;
            for (auto p{ -1 }; p <= 1; ++p) { // L column offset: left, same, right
                auto left = L + (0 < i ? p : 0);
                if (!(0 <= left && left < A[0].size()))
                    continue;
                for (auto q{ -1 }; q <= 1; ++q) { // R column offset: left, same, right
                    auto right = R + (0 < i ? q : 0);
                    if (!(0 <= right && right < A[0].size()) || right <= left) // pruning condition: right <= left is always a sub-optimal solution
                        continue;
                    auto cand = A[i][left] + (left != right ? A[i][right] : 0); // maximum candidate
                    max = std::max(max, cand + go(A, i + 1, left, right));
                }
            }
            return max;
        }
    };
}

namespace TopDownMemo {
    class Solution {
    public:
        using VI = vector<int>;
        using VVI = vector<VI>;
        int cherryPickup(VVI& A) {
            int M = A.size(),
                N = A[0].size();
            return go(A, 0, 0, N - 1);
        }
    private:
        using Memo = unordered_map<string, int>;
        int go(VVI& A, int i, int L, int R, Memo&& m = {}) {
            stringstream key; key << i << "," << L << "," << R;
            if (m.find(key.str()) != m.end())
                return m[key.str()];
            if (i == A.size())
                return m[key.str()] = 0;
            for (auto p{ -1 }; p <= 1; ++p) { // L column offset: left, same, right
                auto left = L + (0 < i ? p : 0);
                if (!(0 <= left && left < A[0].size()))
                    continue;
                for (auto q{ -1 }; q <= 1; ++q) { // R column offset: left, same, right
                    auto right = R + (0 < i ? q : 0);
                    if (!(0 <= right && right < A[0].size()) || right <= left) // pruning condition: right <= left is always a sub-optimal solution
                        continue;
                    auto cand = A[i][left] + (left != right ? A[i][right] : 0); // maximum candidate
                    m[key.str()] = std::max(m[key.str()], cand + go(A, i + 1, left, right, move(m)));
                }
            }
            return m[key.str()];
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
