/*
 * 57. Insert Interval
 *
 * Q: https://leetcode.com/problems/insert-interval/
 * A: https://leetcode.com/problems/insert-interval/discuss/844958/C%2B%2B-with-Screenshare-%2B-Detailed-Explanation
 */

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    using Map = map<int, int>;
    using VI = vector<int>;
    using VVI = vector<VI>;
    VVI insert(VVI& A, VI& add, Map m = {}, VVI ans = {}) {
        for (auto& interval: A) {
            auto [i, j] = tie(interval[0], interval[1]);
            m[i] = j;
        }
        auto [beg, end] = tie(add[0], add[1]);
        auto [min, max] = tie(add[0], add[1]);
        if (m.find(beg) != m.end()) {
            max = std::max(max, m[beg]); // max end for same begin key
        }
        auto i = m.insert({ beg, end }).first;
        auto j = i;
        if (i != m.begin() && i->first <= prev(i)->second) // overlap exists to-the-left 👈
            i = prev(i);
        while (j != m.end() && j->first <= end) // overlap exists to-the-right 👉
            j = next(j);
        for (auto k{ i }; k != j; ++k) {
            min = std::min(min, k->first);
            max = std::max(max, k->second);
        }
        m.erase(i, j);
        m.insert({ min, max });
        transform(m.begin(), m.end(), back_inserter(ans), [](auto& pair) {
            return VI{ pair.first, pair.second };
        });
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
