/*
 * 1482. Minimum Number of Days to Make m Bouquets
 *
 * Q: https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/
 * A: https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/discuss/700480/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    int minDays(VI& A, int T, int K, int INF = int(1e9 + 1)) {
        auto ok = [&](int today, int adj = 0, int cnt = 0) {
            for (auto day: A) {
                adj = day <= today ? adj + 1 : 0;
                if (adj == K)
                    adj = 0, ++cnt;
            }
            return T <= cnt; // target T bouquets 🎯
        };
        auto i = 0,
             j = INF;
        while (i < j) {
            auto k = (i + j) / 2;
            if (!ok(k))
                i = k + 1;
            else
                j = k;
        }
        return i < INF ? i : -1;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
