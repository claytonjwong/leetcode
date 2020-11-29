/*
 * 1672. Richest Customer Wealth
 *
 * Q: https://leetcode.com/problems/richest-customer-wealth/
 * A: https://leetcode.com/problems/richest-customer-wealth/discuss/952772/Kt-Js-Py3-Cpp-1-Liners
 */

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    int maximumWealth(VVI& A, int best = 0) {
        for (auto& row: A)
            best = max(best, accumulate(row.begin(), row.end(), 0));
        return best;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
