/*
 * 1283. Find the Smallest Divisor Given a Threshold
 *
 * Q: https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/
 * A: https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/discuss/925931/Kt-Js-Py3-Cpp-Binary-Search
 */

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    int smallestDivisor(VI& A, int T) {
        auto f = [&](auto div) {
            return accumulate(A.begin(), A.end(), 0, [&](auto total, auto num) {
                return total + ceil(num / double(div));
            });
        };
        int i = 1,
            j = 1e6;
        while (i < j) {
            auto k = (i + j) / 2;
            if (T < f(k))
                i = k + 1;
            else
                j = k;
        }
        return i;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
