/*
 * 1578. Minimum Deletion Cost to Avoid Repeating Letters
 *
 * Q: https://leetcode.com/problems/minimum-deletion-cost-to-avoid-repeating-letters/
 * A: https://leetcode.com/problems/minimum-deletion-cost-to-avoid-repeating-letters/discuss/836954/Javascript-Python3-C%2B%2B-Greedy
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    int minCost(string S, VI& cost, int total = 0) {
        int N = S.size(),
            i = 0;
        while (i < N) {
            auto j{ i };
            auto run = cost[j],
                 max = cost[j];
            while (j + 1 < N && S[j] == S[j + 1]) {  // 🚌 accumulate current "run" cost and track the maximum cost
                ++j;
                run += cost[j];
                max = std::max(max, cost[j]);
            }
            total += run - max;                      // 🎯 greedily consume K - 1 minimal values for each "run" of length K if 1 < K
            i = j + 1;
        }
        return total;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
