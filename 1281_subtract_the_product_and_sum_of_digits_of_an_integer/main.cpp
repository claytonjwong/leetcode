/*
 * 1281. Subtract the Product and Sum of Digits of an Integer
 *
 * Q: https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/
 * A: https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/discuss/448550/Javascript-and-C%2B%2B-solutions
 */
#include <iostream>

using namespace std;

class Solution {
public:
    int subtractProductAndSum(int n, int p = 1, int s = 0) {
        while (n)
            p *= n % 10,
            s += n % 10,
            n /= 10;
        return p - s;
    }
};

int main() {
    Solution solution;
    auto ans = solution.subtractProductAndSum(234);
    cout << ans << endl;
    return 0;
}
