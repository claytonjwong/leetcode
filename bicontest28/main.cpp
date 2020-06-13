/*
 * https://leetcode.com/contest/biweekly-contest-28/ranking/75/
 *
 * Rank          Name           Score   Finish Time     Q1 (3)     Q2 (4)     Q3 (5)   Q4 (7)
 * 1858 / 6427   claytonjwong   7       0:13:22         0:06:49    0:13:22
 */

#include <iostream>
#include <vector>

using namespace std;

/*
 * 1475. Final Prices With a Special Discount in a Shop
 *
 * Q: https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/
 * A: https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/discuss/685454/Javascript-and-C%2B%2B-solutions
 */
namespace Question1_BruteForce {
    class Solution {
    public:
        using VI = vector<int>;
        VI finalPrices(VI& A) {
            int N = A.size();
            for (auto i{ 0 }; i < N; ++i) {
                for (auto j{ i + 1 }; j < N; ++j) {
                    if (A[i] >= A[j]) {
                        A[i] -= A[j]; // apply discount 🎯
                        break;
                    }
                }
            }
            return A;
        }
    };
}
namespace Question1_Stack {
    class Solution {
    public:
        using VI = vector<int>;
        VI finalPrices(VI& A, VI S = {}) {
            for (auto j{ 0 }; j < A.size(); ++j) {
                while (!S.empty()) {
                    auto i = S.back(); // i is the top of the stack
                    if (A[i] < A[j])
                        break;
                    A[i] -= A[j]; // A[i] >= A[j] apply discount 🎯
                    S.pop_back();
                }
                S.push_back(j); // push current j to stack as previous i
            }
            return A;
        }
    };
}

/*
 * 1476. Subrectangle Queries
 *
 * Q: https://leetcode.com/problems/subrectangle-queries/
 * A: https://leetcode.com/problems/subrectangle-queries/discuss/685431/Javascript-and-C%2B%2B-solutions
 */
namespace Question2 {
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
}

int main() {

    return 0;
}
