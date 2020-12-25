/*
 * 498. Diagonal Traverse
 *
 * Q: https://leetcode.com/problems/diagonal-traverse/
 * A: https://leetcode.com/problems/diagonal-traverse/discuss/986121/Kt-Js-Py3-Cpp-Traverse-(Up-%2B-Right)
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    VI findDiagonalOrder(VVI& A, int rev = 0, VI diags = {}) {
        int M = A.size(),
            N = M ? A[0].size() : 0;
        auto diag = [&](auto i, auto j) {                   // traverse diag 👆 👉  (up + right)
            VI res;
            while (0 <= i && j < N)
                res.push_back(A[i--][j++]);
            if (rev)
                reverse(res.begin(), res.end());
            rev ^= 1;
            return res;
        };
        for (auto i{ 0 }; i < M; ++i) {                     // first column
            auto d = diag(i, 0);
            diags.insert(diags.end(), d.begin(), d.end());
        }
        for (auto j{ 1 }; j < N; ++j) {                     // last row
            auto d = diag(M - 1, j);
            diags.insert(diags.end(), d.begin(), d.end());
        }
        return diags;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
