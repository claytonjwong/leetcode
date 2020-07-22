/*
 * 1520. Maximum Number of Non-Overlapping Substrings
 *
 * Q: https://leetcode.com/problems/maximum-number-of-non-overlapping-substrings/
 * A: https://leetcode.com/problems/maximum-number-of-non-overlapping-substrings/discuss/749421/Javascript-Python3-C%2B%2B-beginend-index-%2B-greedy-consumption
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    using VS = vector<string>;
    using Map = unordered_map<int, int>;
    using Set = unordered_set<char>;
    VS maxNumOfSubstrings(string s, Map beg = {}, Map end = {}, VS ans = {}) {
        // 1. track the min begin index and max end index of each character
        Set all{ s.begin(), s.end() };
        for (auto c: all) {
            beg[c] = s.find_first_of(c);
            end[c] = s.find_last_of(c);
        }
        // 2. update the min begin index and max end index for each unique character candidate
        Set seen;
        for (auto cand: s) {
            if (!seen.insert(cand).second)
                continue;
            auto i = beg[cand],
                 j = end[cand];
            auto min = i,
                 max = j;
            while (i <= max) {
                auto c = s[i++];
                min = std::min(min, beg[c]);
                max = std::max(max, end[c]);
            }
            beg[cand] = min;
            end[cand] = max;
        }
        // 3. sort the intervals by end index for greedy consumption of non-overlapping intervals
        string A{ all.begin(), all.end() };
        sort(A.begin(), A.end(), [&](auto a, auto b) { return end[a] < end[b]; });
        auto pre{ -1 }; // end index inclusive of previous interval
        for (auto cand: A) {
            auto i = beg[cand],
                 j = end[cand];
            if (pre < i) { // non-overlapping interval
                ans.push_back(s.substr(i, j - i + 1)); // 🎯 +1 for i..j inclusive
                pre = j;
            }
        }
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
