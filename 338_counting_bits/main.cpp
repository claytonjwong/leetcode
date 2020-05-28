/*
 * 338. Counting Bits
 *
 * Q: https://leetcode.com/problems/counting-bits/
 * A: https://leetcode.com/problems/counting-bits/discuss/657068/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

namespace BruteForce {
    class Solution {
    public:
        using VI = vector<int>;
        VI countBits(int num, VI ans = {}) {
            for (auto i{ 0 }; i <= num; ++i) {
                auto bits{ 0 };
                for (auto j{ 0 }; j < 32; ++j)
                    if (i & (1 << j))
                        ++bits;
                ans.push_back(bits);
            }
            return ans;
        }
    };
}

namespace DP_Verbose {
    class Solution {
    public:
        using VI = vector<int>;
        VI countBits(int num, int pow = 0, VI ans = { 0 }) {
            for (auto i{ 1 }; i <= num; ++i)
                if (!(i & (i - 1)))
                    ans.push_back(1), pow = i; // max pow2
                else
                    ans.push_back(1 + ans[i - pow]); // +1 for max pow2 + the prev ans w/o max pow2
            return ans;
        }
    };
}

namespace DP_concise {
    class Solution {
    public:
        using VI = vector<int>;
        VI countBits(int num, int pow = 0, VI ans = { 0 }) {
            for (auto i{ 1 }; i <= num; ++i) {
                if (!(i & (i - 1))) pow = i;     // max pow2
                ans.push_back(1 + ans[i - pow]); // +1 for max pow2 + prev ans w/o max pow2
            }
            return ans;
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
