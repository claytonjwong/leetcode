/*
 * https://leetcode.com/contest/weekly-contest-193/ranking/110/
 *
 * Rank            Name            Score    Finish Time    Q1 (3)     Q2 (4)     Q3 (5)    Q4 (6)
 * 2737 / 13794    claytonjwong    7        0:09:54        0:00:55    0:09:54
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/*
 * Running Sum of 1d Array
 *
 * Q: https://leetcode.com/problems/running-sum-of-1d-array/
 * A: https://leetcode.com/problems/running-sum-of-1d-array/discuss/686233/Javascript-and-C%2B%2B-solutions
 */
namespace Question1 {
    class Solution {
    public:
        using VI = vector<int>;
        VI runningSum(VI& A, int sum = 0, VI ans = {}) {
            transform(A.begin(), A.end(), back_inserter(ans), [&](auto x) { return sum += x; });
            return ans;
        }
    };
}

/*
 * Least Number of Unique Integers after K Removals
 *
 * Q: https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/
 * A: https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/discuss/686410/Javascript-and-C%2B%2B-solutions
 */
namespace Question2 {
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
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
