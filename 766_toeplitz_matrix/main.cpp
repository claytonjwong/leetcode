/*
 * 766. Toeplitz Matrix
 *
 * Q: https://leetcode.com/contest/weekly-contest-68/problems/toeplitz-matrix/
 * A: https://leetcode.com/problems/toeplitz-matrix/discuss/682523/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    bool isToeplitzMatrix(VVI& A) {
        int M = A.size(),
            N = A[0].size();
        for (auto i{ 1 }; i < M; ++i)
            for (auto j{ 1 }; j < N; ++j)
                if (A[i - 1][j - 1] != A[i][j])
                    return false;
        return true;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
