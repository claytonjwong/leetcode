/*
 * 1561. Maximum Number of Coins You Can Get
 *
 * Q: https://leetcode.com/problems/maximum-number-of-coins-you-can-get/
 * A: https://leetcode.com/problems/maximum-number-of-coins-you-can-get/discuss/806726/Javascript-Python3-C%2B%2B-Greedy-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    int maxCoins(VI& A, int ans = 0) {
        sort(A.begin(), A.end());
        int N = A.size(),
            K = N / 3,
            i = N - 2;
        while (K--)
            ans += A[i], i -= 2;
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
