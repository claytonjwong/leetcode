/*
 * 74. Search a 2D Matrix
 *
 * Q: https://leetcode.com/problems/search-a-2d-matrix/
 * A: https://leetcode.com/problems/search-a-2d-matrix/discuss/605294/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    bool searchMatrix(VVI& A, int T) {
        int M = A.size(),
            N = M ? A[0].size() : 0;
        if (!M || !N)
            return false;
        auto find = [=](VI& A, int i, int j) {
            while (i < j) {
                auto k = (i + j) / 2;
                if (T > A[k])
                    i = k + 1;
                else
                    j = k;
            }
            return i;
        };
        VI rows; transform(A.begin(), A.end(), back_inserter(rows), [](auto& row) { return row.back(); });
        auto i = find(rows, 0, M - 1);
        auto j = find(A[i], 0, N - 1);
        return A[i][j] == T;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
