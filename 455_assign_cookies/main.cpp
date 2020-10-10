/*
 * 455. Assign Cookies
 *
 * Q: https://leetcode.com/problems/assign-cookies/
 * A: https://leetcode.com/problems/assign-cookies/discuss/93990/Javascript-Python3-C%2B%2B-Greedy
 */

#include <iostream>
#include <vector>

using namespace std;

namespace Concise {
    class Solution {
    public:
        using VI = vector<int>;
        int findContentChildren(VI& need, VI& have, int i = 0) {
            sort(need.begin(), need.end());
            sort(have.begin(), have.end());
            for (auto j{ 0 }; i < need.size() && j < have.size(); ++j)
                if (need[i] <= have[j])
                    ++i;
            return i;
        }
    };
}
namespace Verbose {
    class Solution {
    public:
        using VI = vector<int>;
        int findContentChildren(VI& need, VI& have, int cnt = 0) {
            sort(need.begin(), need.end());
            sort(have.begin(), have.end());
            auto j{ 0 };
            for (auto i{ 0 }; i < need.size(); ++i) {
                while (j < have.size() && !(need[i] <= have[j]))
                    ++j;
                if (j < have.size() && need[i] <= have[j])
                    ++cnt,
                    ++j;
            }
            return cnt;
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
