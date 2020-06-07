/*
 * 1471. The k Strongest Values in an Array
 *
 * Q: https://leetcode.com/problems/the-k-strongest-values-in-an-array/
 * A: https://leetcode.com/problems/the-k-strongest-values-in-an-array/discuss/674391/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    VI getStrongest(VI& A, int K) {
        sort(A.begin(), A.end());
        auto m = A[(A.size() - 1) / 2];
        sort(A.begin(), A.end(), [&](auto a, auto b) { return abs(b - m) == abs(a - m) ? b < a : abs(b - m) < abs(a - m); });
        A.resize(K);
        return A;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
