/*
 * 1475. Final Prices With a Special Discount in a Shop
 *
 * Q: https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/
 * A: https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/discuss/685454/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

namespace BruteForce {
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
namespace Stack {
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

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
