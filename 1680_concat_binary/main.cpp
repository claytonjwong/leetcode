/*
 * 1680. Concatenation of Consecutive Binary Numbers
 *
 * Q: https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers/
 * A: https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers/discuss/962337/Kt-Js-Py3-Cpp-Construct-and-sum-Accumulate
 */

#include <iostream>

using namespace std;

class Solution {
public:
    using LL = long long;
    int concatenatedBinary(int N, string s = {}, LL k = 1, LL mod = LL(1e9 + 7), LL ans = 0) {
        for (auto x{ 1 }; x <= N; ++x) {
            auto pad = false;
            for (int i = log2(x); 0 <= i; --i)
                if (x & (1 << i))
                    s.push_back('1'), pad = true;
                else if (pad)
                    s.push_back('0');
        }
        for (auto c: string{ s.rbegin(), s.rend() }) {
            if (c == '1')
                ans = (ans + k) % mod;
            k = 2 * k % mod;
        }
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
