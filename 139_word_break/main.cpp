/*
 * 139. Word Break
 *
 * Q: https://leetcode.com/problems/word-break/
 * A: https://leetcode.com/problems/word-break/discuss/632205/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

namespace TopDown {
    class Solution {
    public:
        using Set = unordered_set<string>;
        bool wordBreak(string s, vector<string>& words) {
            Set dict{ words.begin(), words.end() };
            return go(s, dict);
        }
    private:
        bool go(string& s, Set& dict, int i = 0) {
            int N = s.size();
            if (i == N) // can we reach the N-th index? 🎯
                return 1;
            for (auto j{ i + 1 }; j <= N; ++j)
                if (dict.find(s.substr(i, j - i)) != dict.end() && go(s, dict, j))
                    return 1;
            return 0;
        }
    };
}

namespace TopDownMemo {
    class Solution {
    public:
        using Set = unordered_set<string>;
        using VI = vector<int>;
        bool wordBreak(string s, vector<string>& words) {
            VI memo(s.size() + 1, -1);
            Set dict{ words.begin(), words.end() };
            return go(s, dict, memo);
        }
    private:
        bool go(string& s, Set& dict, VI& m, int i = 0) {
            if (m[i] > -1)
                return m[i];
            int N = s.size();
            if (i == N) // can we reach the N-th index? 🎯
                return m[i] = 1;
            for (auto j{ i + 1 }; j <= N; ++j)
                if (dict.find(s.substr(i, j - i)) != dict.end() && go(s, dict, m, j))
                    return m[i] = 1;
            return m[i] = 0;
        }
    };
}

namespace BottomUp {
    class Solution {
    public:
        using VI = vector<int>;
        bool wordBreak(string s, vector<string>& words) {
            int N = s.size();
            VI dp(N + 1);
            dp[0] = 1; // we can reach the 0-th index with no words
            for (auto i{ 0 }; i < N; ++i) {
                if (!dp[i])
                    continue; // i is not reachable ❌
                for (auto& word: words) {
                    auto j = i + word.size();
                    if (j <= N && word == s.substr(i, j - i))
                        dp[j] = 1;
                }
            }
            return dp[N]; // can we reach the N-th index? 🎯
        }
    };
}

namespace BottomUpMemOpt {
        class Solution {
            public:
            using Set = unordered_set<int>;
            bool wordBreak(string s, vector<string>& words, Set reach = Set{ 0 }) { // we can reach the 0-th index with no words
                int N = s.size();
                for (auto i{ 0 }; i < N; ++i) {
                    if (reach.find(i) == reach.end())
                        continue; // i is not reachable ❌
                    for (auto& word: words) {
                        auto j = i + word.size();
                        if (j <= N && word == s.substr(i, j - i))
                            reach.insert(j);
                    }
                }
                return reach.find(N) != reach.end(); // can we reach the N-th index? 🎯
            }
        };
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
