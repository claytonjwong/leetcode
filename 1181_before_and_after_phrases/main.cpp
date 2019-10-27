/*

1181. Before and After Puzzle

Q: https://leetcode.com/problems/before-and-after-puzzle/
A: https://leetcode.com/problems/before-and-after-puzzle/discuss/406561/Javascript-and-C%2B%2B-Solutions

*/

#include <iostream>
#include <sstream>
#include <vector>
#include <deque>
#include <unordered_map>
#include <map>
#include <set>
#include <string>

using namespace std;

// I am copying over way too much redundant info... just reference the phrase index instead in the map
/*
class Solution {
public:
    using VS = vector<string>;
    using Words = vector<deque<string>>;
    using Map = unordered_multimap<string, pair<int,string>>;
    using Answer = set<string>;
    VS beforeAndAfterPuzzles(VS& phrases, Words words={}, Map prefix={}, Map suffix={}, Answer ans={}) {
        int N = phrases.size();
        for (auto& phrase: phrases) {
            words.emplace_back(deque<string>{});
            istringstream stream{phrase};
            for (string word; stream >> word; words.back().push_back(word));
            prefix.insert({words.back().front(), {N, phrase}});
            suffix.insert({words.back().back(), {N, phrase}});
            --N;
        }
        for (auto& [s, s_pair]: suffix) {
            auto i = s_pair.first;
            auto s_phrase = s_pair.second;
            for (auto& [p, p_pair]: prefix) {
                auto j = p_pair.first;
                auto p_phrase = p_pair.second;
                if (i == j || s != p)
                    continue;
                ans.insert(s_phrase + p_phrase.substr(p.size()));
            }
        }
        return {ans.begin(), ans.end()};
    }
};
*/

// ok this is much better...
class Solution {
public:
    using VS = vector<string>;
    using Map = unordered_multimap<string, int>;
    VS beforeAndAfterPuzzles(VS& phrases, Map prefix={}, Map suffix={}, string first={}, string last={}, set<string> ans={}) {
        auto i = 0;
        for (auto& phrase: phrases) {
            istringstream stream{phrase};
            for (stream >> first, last = first; stream >> last;);
            prefix.insert({first, i});
            suffix.insert({last, i});
            ++i;
        }
        for (auto& [last, i]: suffix)
            for (auto& [first, j]: prefix)
                if (i != j && last == first)
                    ans.insert(phrases[i] + phrases[j].substr(last.size()));
        return {ans.begin(), ans.end()};
    }
};

int main() {
    Solution::VS phrases{"mission statement",
                         "a quick bite to eat",
                         "a chip off the old block",
                         "chocolate bar",
                         "mission impossible",
                         "a man on a mission",
                         "block party",
                         "eat my words",
                         "bar of soap"};
//    Solution::VS phrases{"a", "b", "a"};
    auto ans = Solution().beforeAndAfterPuzzles(phrases);
    copy(ans.begin(), ans.end(), ostream_iterator<string>(cout, "\n")); cout << endl;
    return 0;
}