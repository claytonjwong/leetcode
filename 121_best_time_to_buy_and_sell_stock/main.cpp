/*
 * 121. Best Time to Buy and Sell Stock
 *
 * Q: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
 * A: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/discuss/507318/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    int maxProfit(VI& A, int ans = 0) {
        int low = A.empty() ? -1 : A[0];
        for (auto x: A)
            ans = max(ans, x - low),
            low = min(low, x);
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
