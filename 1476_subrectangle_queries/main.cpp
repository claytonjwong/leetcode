/*
 * 1476. Subrectangle Queries
 *
 * Q: https://leetcode.com/problems/subrectangle-queries/
 * A: https://leetcode.com/problems/subrectangle-queries/discuss/685431/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

class SubrectangleQueries {
    using VI = vector<int>;
    using VVI = vector<VI>;
    VVI A;
public:
    SubrectangleQueries(VVI& A_) : A{ A_ } {
    }
    void updateSubrectangle(int p, int q, int u, int v, int x) {
        for (auto i{ p }; i <= u; ++i)
            for (auto j{ q }; j <= v; ++j)
                A[i][j] = x;
    }
    int getValue(int i, int j) {
        return A[i][j];
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
