/*
 * 1250. Check If It Is a Good Array
 *
 * Q: https://leetcode.com/problems/check-if-it-is-a-good-array/
 * A: https://leetcode.com/problems/check-if-it-is-a-good-array/discuss/590623/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    bool isGoodArray(VI& A, bool good = false) {
        auto x = A.back(); A.pop_back();
        for_each(A.begin(), A.end(), [&](auto y) { x = gcd(x, y); });
        return x == 1;
    }
private:
    int gcd(int a, int b) { return !b ? a : gcd(b, a % b); }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
