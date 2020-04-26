/*
 * 1423. Maximum Points You Can Obtain from Cards
 *
 * Q: https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/
 * A: https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/discuss/597883/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

namespace Question2_ForLoop {
    class Solution {
    public:
        using VI = vector<int>;
        int maxScore(VI& A, int K) {
            int N = A.size();
            auto sum = accumulate(A.begin() + N - K, A.end(), 0),
                 max = sum;
            for (auto i{ 0 }, j{ N - K }; K--; max = std::max(max, sum += A[i++] - A[j++])); // slide window by K 👉
            return max;
        }
    };
}
namespace Question2_WhileLoop {
    class Solution {
    public:
        using VI = vector<int>;
        int maxScore(VI& A, int K) {
            int N = A.size(),
                i = 0,
                j = N - K;
            auto sum = accumulate(A.begin() + j, A.end(), 0),
                 max = sum;
            while (K--) max = std::max(max, sum += A[i++] - A[j++]); // slide window by K 👉
            return max;
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
