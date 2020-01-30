/*
 * 1170. Compare Strings by Frequency of the Smallest Character
 *
 * Q: https://leetcode.com/problems/compare-strings-by-frequency-of-the-smallest-character/
 * A: https://leetcode.com/problems/compare-strings-by-frequency-of-the-smallest-character/discuss/493772/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using VS = vector<string>;
    VI numSmallerByFrequency(VS& queries, VS& words, VI A = {}, VI ans = {}) {
        auto f = [](string& s, int i = 1) {
            sort(s.begin(), s.end());
            while (i < s.size() && s[i - 1] == s[i])
                ++i;
            return i;
        };
        transform(words.begin(), words.end(), back_inserter(A), [&](string& s) { return f(s); });
        sort(A.begin(), A.end());
        transform(queries.begin(), queries.end(), back_inserter(ans), [&](auto& s) {
            return distance(upper_bound(A.begin(), A.end(), f(s)), A.end());
        });
        return ans;
    }
};

int main() {
    Solution solution;
//    Solution::VS queries{"cbd"}, words{"zaaaz"};
//    Solution::VS queries{"bbb","cc"}, words{"a","aa","aaa","aaaa"};
    Solution::VS queries{"bba","abaaaaaa","aaaaaa","bbabbabaab","aba","aa","baab","bbbbbb","aab","bbabbaabb"},
                 words{"aaabbb","aab","babbab","babbbb","b","bbbbbbbbab","a","bbbbbbbbbb","baaabbaab","aa"};
    auto ans = solution.numSmallerByFrequency(queries, words);
    copy(ans.begin(), ans.end(), ostream_iterator<int>(cout, " ")), cout << endl;
    return 0;
}
