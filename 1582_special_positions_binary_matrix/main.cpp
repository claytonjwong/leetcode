/*
 * 1582. Special Positions in a Binary Matrix
 *
 * Q: https://leetcode.com/problems/special-positions-in-a-binary-matrix
 * A: https://leetcode.com/problems/special-positions-in-a-binary-matrix/discuss/843916/Kt-Js-Py3-Cpp-Sum-Row-and-Column
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    int numSpecial(VVI& A, int cnt = 0) {
        int M = A.size(),
            N = A[0].size();
        VI row(M),
           col(N);
        for (auto i{ 0 }; i < M; ++i)
            for (auto j{ 0 }; j < N; ++j)
                if (A[i][j])
                    ++row[i],
                    ++col[j];
        for (auto i{ 0 }; i < M; ++i)
            for (auto j{ 0 }; j < N; ++j)
                if (A[i][j] && row[i] == 1 && col[j] == 1)
                    ++cnt;
        return cnt;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
