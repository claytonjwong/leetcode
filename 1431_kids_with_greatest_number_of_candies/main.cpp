/*
 * 1431. Kids With the Greatest Number of Candies
 *
 * Q: https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/
 * A: https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/discuss/611820/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VB = vector<bool>;
    using VI = vector<int>;
    VB kidsWithCandies(VI& A, int K, VB ans = {}) {
        int max = *max_element(A.begin(), A.end());
        transform(A.begin(), A.end(), back_inserter(ans), [=](auto x) { return x + K >= max; });
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
