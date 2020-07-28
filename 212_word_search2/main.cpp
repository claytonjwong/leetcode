/*
 * 212. Word Search II
 *
 * Q: https://leetcode.com/problems/word-search-ii/
 * A: https://leetcode.com/problems/word-search-ii/discuss/713117/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
    using VS = vector<string>;
    using VVC = vector<vector<char>>;
    using Seen = unordered_map<int, unordered_map<int, bool>>;
    using Set = unordered_set<string>;
    using Adj = vector<pair<int, int>>;
    struct TrieNode {
        using Map = unordered_map<char, shared_ptr<TrieNode>>;
        Map children;
        bool isEnd = false;
    };
    shared_ptr<TrieNode> root;
    VVC A;
    int M, N;
    Set found;
    void go(int i, int j, shared_ptr<TrieNode> cur, string&& path = {}, Seen&& seen = {}) {
        if (seen[i][j]) // ❌ already seen i,j 👀
            return;
        if (cur->isEnd) // 🎯 found word
            found.insert(path);
        seen[i][j] = true;  // 👀 ✅ seen forward-tracking
        for (auto [u, v]: Adj{{i - 1, j}, {i, j + 1}, {i + 1, j}, {i, j - 1}}) // clockwise [ 👆, 👉, 👇, 👈 ]
            if (0 <= u && u < M && 0 <= v && v < N && cur->children.find(A[u][v]) != cur->children.end())
                path.push_back(A[u][v]), // 🚌 ✅ path forward-tracking
                go(u, v, cur->children[A[u][v]], move(path), move(seen)),
                path.pop_back();         // 🚌 🚫 path back-tracking
        seen[i][j] = false; // 👀 🚫 seen back-tracking
    }
public:
    VS findWords(VVC& A_, VS& words) {
        A = A_;
        root = make_shared<TrieNode>();
        auto add = [=](auto& word) {
            auto cur{ root };
            for (auto c: word) {
                if (cur->children.find(c) == cur->children.end())
                    cur->children[c] = make_shared<TrieNode>();
                cur = cur->children[c];
            }
            cur->isEnd = true;
        };
        for (auto& word: words)
            add(word);
        M = A.size();
        N = M ? A[0].size() : 0;
        for (auto i{ 0 }; i < M; ++i)
            for (auto j{ 0 }; j < N; ++j)
                if (root->children.find(A[i][j]) != root->children.end())
                    go(i, j, root->children[A[i][j]], string(1, A[i][j]));
        return { found.begin(), found.end() };
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
