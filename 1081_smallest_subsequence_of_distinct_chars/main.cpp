/*
 * 1081. Smallest Subsequence of Distinct Characters
 *
 * Q: https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/
 * A: https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/discuss/891644/Kt-Js-Py3-C%2B%2B-Monotonic-Queue-%2B-Detailed-Explanation
 */

#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    using Set = unordered_set<char>;
    using Map = unordered_map<char, int>;
    string smallestSubsequence(string s, string A = {}, Set have = {}, Map last = {}) {
        for (auto i{ 0 }; i < s.size(); ++i)
            last[s[i]] = i;
        for (auto i{ 0 }; i < s.size(); ++i) {
            while (have.find(s[i]) == have.end() && A.size() && s[i] < A.back() && i < last[A.back()])
                have.erase(A.back()), A.pop_back();
            if (have.insert(s[i]).second)
                A.push_back(s[i]);
        }
        return A;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
