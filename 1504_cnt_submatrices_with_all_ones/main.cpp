/*
 * 1504. Count Submatrices With All Ones
 *
 * Q: https://leetcode.com/problems/count-submatrices-with-all-ones/
 * A: https://leetcode.com/problems/count-submatrices-with-all-ones/discuss/762330/Kt-Js-Py3-Cpp-Brute-Force
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    using fun = function<int(int, int)>;
    int numSubmat(VVI& A, int total = 0) {
        fun go = [&](auto row, auto col) {
            auto cnt{ 0 };
            auto M = A.size(),
                 N = A[0].size();
            for (auto i{ row }; i < M; ++i)
                for (auto j{ col }; j < N; ++j)
                    if (A[i][j])
                        ++cnt;
                    else
                        N = j;
            return cnt;
        };
        auto M = A.size(),
             N = A[0].size();
        for (auto i{ 0 }; i < M; ++i)
            for (auto j{ 0 }; j < N; ++j)
                total += go(i, j); // 🎯 count of all submatrices starting with i,j as top-left corner
        return total;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
