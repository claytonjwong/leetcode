/*
 * 140. Word Break II
 *
 * Q: https://leetcode.com/problems/word-break-ii/
 * A: https://leetcode.com/problems/word-break-ii/discuss/765548/Javascript-Python3-C%2B%2B-top-down-%2B-bottom-up-(partial)
 */

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

namespace BruteForce {
    class Solution {
    public:
        using VS = vector<string>;
        using Set = unordered_set<string>;
        using func = function<VS(int)>;
        VS wordBreak(string S, VS& A) {
            int N = S.size();
            Set dict{ A.begin(), A.end() };
            func go = [&](int i, VS words = {}) {
                if (i == N)                             // 🛑 base case: "empty" word can be constructed when there are no remaining characters in S
                    return VS{""};
                for (auto j{ i + 1 }; j <= N; ++j) {    // ⭐️ candidate substrings S[i..j), ie. from i inclusive to j non-inclusive
                    auto cand = S.substr(i, j - i);
                    if (dict.find(cand) != dict.end())
                        for (auto& tail: go(j))         // 🚀 DFS concat tails to 🔍 found candidates, ie. build 🎯 words from 👈 right-to-left
                            words.emplace_back(cand + (tail.size() ? " " : "") + tail);
                }
                return words;
            };
            return go(0);
        }
    };
}

namespace Memo {
    class Solution {
    public:
        using VS = vector<string>;
        using Set = unordered_set<string>;
        using func = function<VS(int)>;
        using Map = unordered_map<int, VS>;
        VS wordBreak(string S, VS& A, Map m = {}) {
            int N = S.size();
            Set dict{ A.begin(), A.end() };
            func go = [&](int i, VS words = {}) {
                if (m.find(i) != m.end())               // 🤔 memo
                    return m[i];
                if (i == N)                             // 🛑 base case: "empty" word can be constructed when there are no remaining characters in S
                    return m[i] = VS{""};
                for (auto j{ i + 1 }; j <= N; ++j) {    // ⭐️ candidate substrings S[i..j), ie. from i inclusive to j non-inclusive
                    auto cand = S.substr(i, j - i);
                    if (dict.find(cand) != dict.end())
                        for (auto& tail: go(j))         // 🚀 DFS concat tails to 🔍 found candidates, ie. build 🎯 words from 👈 right-to-left
                            words.emplace_back(cand + (tail.size() ? " " : "") + tail);
                }
                return m[i] = words;
            };
            return go(0);
        }
    };
}

namespace BottomUp {
    class Solution {
    public:
        using VS = vector<string>;
        using VVS = vector<VS>;
        using Set = unordered_set<string>;
        VS wordBreak(string S, VS& A) {
            int N = S.size();
            VVS dp(N + 1);                              // 🤔 memo
            dp.back().push_back("");                    // 🛑 base case: "empty" word can be constructed when there are no remaining characters in S
            Set dict{ A.begin(), A.end() };
            for (auto i{ N - 1 }; 0 <= i; --i) {        // ⭐️ candidate substrings S[i..j), ie. from i inclusive to j non-inclusive
                for (auto j{ i + 1 }; j <= N; ++j) {
                    auto cand = S.substr(i, j - i);
                    if (dict.find(cand) != dict.end())
                        for (auto& tail: dp[j])         // 🚀 concat each tail onto the current candidate, 👈 ie. build the answer from right to left
                            dp[i].push_back(cand + (tail.size() ? " " : "") + tail);
                }
            }
            return dp[0];
        }
    };
}

int main() {
    Memo::Solution solution;
    vector<string> A{"cat","cats","and","sand","dog"};
    auto ans = solution.wordBreak("catsanddog", A);
    for (auto& s: ans)
        cout << s << endl;
    return 0;
}
