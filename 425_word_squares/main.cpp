/*
 * 425. Word Squares
 *
 * Q: https://leetcode.com/problems/word-squares/
 * A: https://leetcode.com/problems/word-squares/discuss/871098/Javascript-Python3-C%2B%2B-Map-Prefix-and-DFS-%2B-BT
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    using VS = vector<string>;
    using VVS = vector<VS>;
    using Map = unordered_map<string, VS>;
    using fun = function<void(VS&&)>;
    VVS wordSquares(VS& A, Map m = {}, VVS ans = {}) {
        int N = A[0].size();
        for (auto& word: A) {
            string pre;
            m[pre].emplace_back(word);
            for (auto c: word) {
                pre.push_back(c);
                m[pre].emplace_back(word);
            }
        }
        fun go = [&](VS&& path) {
            int i = path.size();
            if (i == N) {
                ans.emplace_back(path);
                return;
            }
            string pre;
            for (auto j{ 0 }, k{ i }; 0 < i && j < k; ++j)
                pre.push_back(path[j][k]);
            for (auto& word: m[pre])
                path.emplace_back(word),
                go(move(path)),
                path.pop_back();
        };
        go({});
        return ans;
    }
};

//class Solution {
//public:
//    using VS = vector<string>;
//    using VVS = vector<VS>;
//    using Set = unordered_set<string>;
//    using fun = function<void(VS&&)>;
//    struct Node {
//        unordered_map<char, shared_ptr<Node>> children;
//        VS words;
//    };
//    VVS wordSquares(VS& words, VVS ans = {}) {
//        int N = words.size();
//        auto root = make_shared<Node>();
//        for (auto& word: words) {
//            auto cur{ root };
//            for (auto c: word) {
//                if (cur->children.find(c) == cur->children.end())
//                    cur->children[c] = make_shared<Node>();
//                cur = cur->children[c];
//                cur->words.emplace_back(word);
//            }
//        }
//        fun go = [&](VS&& path) {
//            if (path.size() == N) {
//                ans.emplace_back(path);
//                return;
//            }
//            for (auto i{ 0 }; i < N; ++i) {
//                if (path.empty()) {
//                    path.push_back(words[i]),
//                    go(move(path)),
//                    path.pop_back();
//                } else if (find(path.begin(), path.end(), words[i]) == path.end()) {
//                    string prefix;
//                    int k = path.size();
//                    for (auto j{ 1 }; j <= k; ++j)
//                        prefix.push_back(path[j - 1][k]);
//                    auto cur{ root };
//                    for (auto c: prefix) {
//                        if (cur->children.find(c) == cur->children.end())
//                            return;
//                        cur = cur->children[c];
//                    }
//                    for (auto& word: cur->words) {
//                        if (find(path.begin(), path.end(), word) == path.end())
//                            path.push_back(word),
//                            go(move(path)),
//                            path.pop_back();
//                    }
//                }
//            }
//        };
//        go({});
//        return ans;
//    }
//};

//class Solution {
//public:
//    using VS = vector<string>;
//    using VVS = vector<VS>;
//    using Set = unordered_set<string>;
//    using fun = function<void(VS&&, Set&&)>;
//    struct Node {
//        unordered_map<char, shared_ptr<Node>> children;
//        VS words;
//    };
//    VVS wordSquares(VS& words, VVS ans = {}) {
//        int N = words[0].size();
//        auto root = make_shared<Node>();
//        root->words = words;
//        for (auto& word: words) {
//            auto cur{ root };
//            for (auto c: word) {
//                if (cur->children.find(c) == cur->children.end())
//                    cur->children[c] = make_shared<Node>();
//                cur = cur->children[c];
//                cur->words.emplace_back(word);
//            }
//        }
//        fun go = [&](VS&& path, Set&& seen) {
//            if (path.size() == N) {
//                ans.emplace_back(path);
//                return;
//            }
//            for (auto& cand: words) {
//                if (seen.find(cand) != seen.end())
//                    continue;
//                if (path.empty())
//                    cout << cand << endl;
//                string prefix;
//                int k = path.size();
//                for (auto j{ 1 }; j <= k; ++j)
//                    prefix.push_back(path[j - 1][k]);
//                auto cur{ root };
//                for (auto c: prefix) {
//                    if (cur->children.find(c) == cur->children.end())
//                        return;
//                    cur = cur->children[c];
//                }
//                for (auto& word: cur->words) {
//                    if (seen.find(word) != seen.end())
//                        continue;
//                    path.emplace_back(word), seen.insert(word),
//                    go(move(path), move(seen)),
//                    path.pop_back(), seen.erase(word);
//                }
//            }
//        };
//        go({}, {});
//        return ans;
//    }
//};


int main() {
    Solution solution;
    Solution::VS words{ "area","lead","wall","lady","ball" };
    auto ans = solution.wordSquares(words);
    for (auto& row: ans)
        copy(row.begin(), row.end(), ostream_iterator<string>(cout, " ")), cout << endl;
    return 0;
}
