/*
 * https://leetcode.com/contest/biweekly-contest-32/
 * https://www.youtube.com/watch?v=xuyvk8ycHFs
 *
 * Rank            Name            Score    Finish Time     Q1 (3)       Q2 (4)    Q3 (5)    Q4 (6)
 * 6181 / 10463    claytonjwong    3        0:46:48         0:36:48 *2
 */

#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <iterator>
#include <numeric>

using namespace std;

/*
 * 1539. Kth Missing Positive Number
 *
 * Q: https://leetcode.com/problems/kth-missing-positive-number/
 * A: https://leetcode.com/problems/kth-missing-positive-number/discuss/780016/Javascript-Python3-C%2B%2B-solutions
 */
namespace Question1 {
    class Solution {
    public:
        using VI = vector<int>;
        using Set = unordered_set<int>;
        int findKthPositive(VI& A, int K) {
            Set seen{ A.begin(), A.end() };
            for (auto i{ 1 };; ++i)
                if (seen.find(i) == seen.end() && !--K)
                    return i;
        }
    };
}

/*
 * 1540. Can Convert String in K Moves
 *
 * Q: https://leetcode.com/problems/can-convert-string-in-k-moves/
 * A: https://leetcode.com/problems/can-convert-string-in-k-moves/discuss/780454/Javascript-Python3-C%2B%2B-add-%2B-del-needs
 */
namespace Question2 {
    class Solution {
    public:
        using Map = unordered_map<int, int>;
        bool canConvertString(string s, string t, int K, Map need = {}, int needs = 0) {
            if (s.size() != t.size())
                return false;
            // ✅ add needs
            for (auto i{ 0 }; i < s.size(); ++i) {
                auto diff = (t[i] - s[i] + 26) % 26;
                if (diff)
                    ++need[diff], ++needs;
            }
            // 🚫 del needs
            for (auto i{ 1 }; i <= K && needs; ++i) {
                auto diff = i % 26;
                if (need[diff])
                    --need[diff], --needs;
            }
            return !needs; // 🎯 no needs
        }
    };
}

int main() {
    Question2::Solution solution;
    cout << solution.canConvertString("input", "ouput", 9) << endl;
    cout << solution.canConvertString("abc", "bcd", 10) << endl;
    cout << solution.canConvertString("aab", "bbb", 27) << endl;
    cout << solution.canConvertString("qsxkjbfz", "xyfirptk", 73) << endl;
    return 0;
}
