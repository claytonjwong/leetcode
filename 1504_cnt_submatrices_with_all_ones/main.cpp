/*
 * 1504. Count Submatrices With All Ones
 *
 * Q: https://leetcode.com/problems/count-submatrices-with-all-ones/
 * A: https://leetcode.com/problems/count-submatrices-with-all-ones/discuss/762330/Javascript-Python3-C%2B%2B-brute-force
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    using VI = vector<int>;
    using VVI = vector<VI>;
    using Dirs = vector<tuple<int, int>>;
    VVI A;
    int go(int row, int col, int M, int N, int cnt = 0) {
        for (auto i{ row }; i < M; ++i)
            for (auto j{ col }; j < N; ++j)
                if (A[i][j])
                    ++cnt;
                else
                    N = j;
        return cnt;
    }
public:
    int numSubmat(VVI& A_, int ans = 0) {
        A = A_;
        int M = A.size(),
                N = A[0].size();
        for (auto i{ 0 }; i < M; ++i)
            for (auto j{ 0 }; j < N; ++j)
                ans += go(i, j, M, N); // 🎯 count all submatrices starting with i,j as top-left corner
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
