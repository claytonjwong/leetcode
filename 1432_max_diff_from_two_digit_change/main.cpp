/*
 * 1432. Max Difference You Can Get From Changing an Integer
 *
 * Q: https://leetcode.com/problems/max-difference-you-can-get-from-changing-an-integer/
 * A: https://leetcode.com/problems/max-difference-you-can-get-from-changing-an-integer/discuss/613159/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

namespace Greedy {
    class Solution {
    public:
        int maxDiff(int x) {
            auto max = [=]() {
                auto hi{ '9' };
                auto a = to_string(x);
                for (auto c: a)
                    if (c < '9' && hi == '9')
                        hi = c;
                transform(a.begin(), a.end(), a.begin(), [=](auto c) { return c == hi ? '9' : c; });
                return stoi(a);
            };
            auto min = [=]() {
                auto zero = '0',
                     one = '0';
                auto b = to_string(x),
                     d = b;
                for (auto c: b)
                    if (b[0] != c && c > '0' && zero == '0')
                        zero = c;
                    else if (c > '0' && one == '0')
                        one = c;
                transform(b.begin(), b.end(), b.begin(), [=](auto c) { return c == zero ? '0' : c; });
                transform(d.begin(), d.end(), d.begin(), [=](auto c) { return c == one  ? '1' : c; });
                return std::min(stoi(b), stoi(d));
            };
            return max() - min();
        }
    };
}
namespace BruteForce {
    class Solution {
    public:
        static constexpr int INF = 1e9 + 7;
        using VC = vector<char>;
        int maxDiff(int x, int min = INF, int max = -INF) {
            VC digits(10);
            iota(digits.begin(), digits.end(), '0');
            copy(digits.begin(), digits.end(), ostream_iterator<int>(cout, " ")), cout << endl;
            for (auto i: digits) {
                for (auto j: digits) {
                    auto cur = to_string(x);
                    if (cur[0] == i && j == '0')
                        continue; // no leading 0 ❌
                    transform(cur.begin(), cur.end(), cur.begin(), [=](auto c) { return c == i ? j : c; });
                    min = std::min(min, stoi(cur));
                    max = std::max(max, stoi(cur));
                }
            }
            return max - min;
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
