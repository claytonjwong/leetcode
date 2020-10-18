/*
 * 1624. Largest Substring Between Two Equal Characters
 *
 * Q: https://leetcode.com/problems/largest-substring-between-two-equal-characters/
 * A: https://leetcode.com/problems/largest-substring-between-two-equal-characters/discuss/900287/Kt-Js-Py3-Cpp-Map-(concise-%2B-verbose)-solutions
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

namespace Concise {
    class Solution {
    public:
        using VI = vector<int>;
        using Map = unordered_map<char, int>;
        int maxLengthBetweenEqualCharacters(string s, Map m = {}, VI cand = {}) {
            for_each(s.begin(), s.end(), [i = -1, &m](auto c) mutable { m[c] = ++i; });
            transform(s.begin(), s.end(), back_inserter(cand), [i = -1, &m](auto c) mutable { return m[c] - ++i - 1; });  // -1 for (i..j) non-inclusive
            return *max_element(cand.begin(), cand.end());
        }
    };
}

namespace Verbose {
    class Solution {
    public:
        using Map = unordered_map<char, int>;
        int maxLengthBetweenEqualCharacters(string s, Map m = {}, int best = -1) {
            int N = s.size();
            for (auto i{ 0 }; i < N; ++i)
                if (m.find(s[i]) != m.end())
                    best = max(best, i - m[s[i]] - 1);  // -1 for (i..j) non-inclusive
                else
                    m[s[i]] = i;
            return best;
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
