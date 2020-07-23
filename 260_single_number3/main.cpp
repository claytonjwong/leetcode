/*
 * 260. Single Number III
 *
 * Q: https://leetcode.com/problems/single-number-iii/
 * A: https://leetcode.com/problems/single-number-iii/discuss/750939/Javascript-Python3-C%2B%2B-Seen-and-Counter-solutions-O(N)-memory
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

namespace Set {
    class Solution {
    public:
        using VI = vector<int>;
        using Set = unordered_set<int>;
        VI singleNumber(VI& A, Set seen = {}) {
            for (auto x: A)
                if (!seen.insert(x).second) seen.erase(x); // 🚫 remove x seen twice 👀 and ✅ keep x seen once 👀
            return { seen.begin(), seen.end() };
        }
    };
}

namespace Counter {
    class Solution {
    public:
        using VI = vector<int>;
        using Map = unordered_map<int, int>;
        VI singleNumber(VI& A, Map m = {}, VI ans = {}) {
            for (auto x: A)
                ++m[x];
            for (auto [x, cnt]: m)
                if (cnt == 1)
                    ans.push_back(x);
            return ans;
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
