/*
 * 1481. Least Number of Unique Integers after K Removals
 *
 * Q: https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/
 * A: https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/discuss/686410/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <unordered_map>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using Map = unordered_map<int, int>;
    using Pairs = vector<pair<int, int>>;
    using Set = unordered_set<int>;
    int findLeastNumOfUniqueInts(VI& A, int K, Map m = {}, VI all = {}) {
        for (auto x: A)
            ++m[x];
        Pairs P{ m.begin(), m.end() };
        sort(P.begin(), P.end(), [](auto& a, auto& b) { return a.second < b.second; }); // sort all by ascending frequency
        for (auto [x, n]: P) // x occurs n times
            fill_n(back_inserter(all), n, x);
        return Set{ all.begin() + K, all.end() }.size(); // greedily drop first K least freq nums and return size of remaining set
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
