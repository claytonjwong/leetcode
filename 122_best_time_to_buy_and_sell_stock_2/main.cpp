/*
 * 122. Best Time to Buy and Sell Stock II
 *
 * Q: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
 * A: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/discuss/565175/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

namespace Complex {
    class Solution {
    public:
        using VI = vector<int>;
        int maxProfit(VI& A, int profit = 0) {
            int N = A.size();
            for (auto i{ 0 }, j{ 0 }; i < N; i = j + 1) {
                while (i < N - 1 && A[i] > A[i + 1]) ++i; // valley 👇
                j = i;
                while (j < N - 1 && A[j] < A[j + 1]) ++j; // peak 👆
                profit += max(0, A[j] - A[i]);
            }
            return profit;
        }
    };
}
namespace Simple {
    class Solution {
    public:
        using VI = vector<int>;
        int maxProfit(VI& A, int profit = 0) {
            for (auto i{ 1 }; i < A.size(); ++i)
                profit += max(0, A[i] - A[i - 1]); // only count positive hillside steps 👆
            return profit;
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
