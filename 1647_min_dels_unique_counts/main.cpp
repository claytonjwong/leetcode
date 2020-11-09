/*
 * 1647. Minimum Deletions to Make Character Frequencies Unique
 *
 * Q: https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/
 * A: https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/discuss/927497/Kt-Js-Py3-Cpp-Map-%2B-Seen-Counts
 */

#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    using Map = unordered_map<int, int>;
    using Set = unordered_set<int>;
    int minDeletions(string s, Map m = {}, Set seen = {}, int dels = 0) {
        for (auto c: s)
            ++m[c];
        for (auto [_, cnt]: m)
            while (cnt && !seen.insert(cnt).second)
                ++dels,
                --cnt;
        return dels;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
