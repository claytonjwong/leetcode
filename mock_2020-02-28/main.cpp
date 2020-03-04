/*
 * Attempted February 28, 2020 4:07 PM
 * Your interview score of 2.68/10 beats 38% of all users.
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

/*
 * 278. First Bad Version
 *
 * Q: https://leetcode.com/problems/first-bad-version/
 * A: https://leetcode.com/problems/first-bad-version/discuss/527936/Javascript-and-C%2B%2B-solutions
 */

/*
bool isBadVersion(int x) {
    return x >= 1;
}

//class Solution {
//public:
//    int firstBadVersion(int n) {
//        return go(1, n);
//    }
//private:
//    using LL = long long;
//    int go(LL i, LL j) {
//        LL k = (i + j) / 2;
//        if (isBadVersion(k)) {
//            if (k == 1 || !isBadVersion(k - 1))
//                return k;
//            return go(i, k - 1);
//        }
//        else {
//            return go(k + 1, j);
//        }
//    }
//};

class Solution {
public:
    using LL = long long;
    int firstBadVersion(int n) {
        LL i = 1, j = n;
        while (i < j) {
            auto k = (i + j) / 2;
            if (isBadVersion(k)) {
                j = k;
            } else {
                i = k + 1;
            }
        }
        return i;
    }
};

int main() {
    Solution solution;
    cout << solution.firstBadVersion(5) << endl;
    return 0;
}
*/


/*
 * 211. Add and Search Word - Data structure design
 *
 * Q: https://leetcode.com/problems/add-and-search-word-data-structure-design/
 * A: https://leetcode.com/problems/add-and-search-word-data-structure-design/discuss/528035/Javascript-and-C%2B%2B-solutions
 */

//class WordDictionary {
//private:
//    struct TrieNode {
//        bool isEnd = false;
//        unordered_map<char, shared_ptr<TrieNode>> children;
//    };
//    shared_ptr<TrieNode> trieRoot;
//public:
//    /** Initialize your data structure here. */
//    WordDictionary() : trieRoot{make_shared<TrieNode>()} {}
//
//    /** Adds a word into the data structure. */
//    void addWord(string word) {
//        auto node = trieRoot;
//        for (auto c: word) {
//            if (node->children.find(c) == node->children.end())
//                node->children[c] = make_shared<TrieNode>();
//            node = node->children[c];
//        }
//        node->isEnd = true;
//    }
//
//    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
//    bool search(string word, shared_ptr<TrieNode> start = nullptr) {
//        auto node = start ? start : trieRoot;
//        for (auto i = 0; i < word.size(); ++i) {
//            if (word[i] == '.') {
//                for (auto& [_, child]: node->children) {
//                    if (search(word.substr(i + 1), child))
//                        return true;
//                }
//                return false;
//            }
//            if (node->children.find(word[i]) == node->children.end())
//                return false;
//            node = node->children[word[i]];
//        }
//        return node && node->isEnd;
//    }
//};
//
//int main() {
//    WordDictionary wd;
//    wd.addWord("at");
//    wd.addWord("and");
//    wd.addWord("an");
//    cout << wd.search("a") << " == 0" << endl;
//    cout << wd.search(".at") << " == 0" << endl;
//    wd.addWord("bat");
//    cout << wd.search(".at") << " == 1" << endl;
//    cout << wd.search("an.") << " == 1" << endl;
//    cout << wd.search("a.d.") << " == 0" << endl;
//    return 0;
//}

/*
 * 200. Number of Islands
 *
 * Q: https://leetcode.com/problems/number-of-islands/
 * A: https://leetcode.com/problems/number-of-islands/discuss/528817/Javascript-and-C%2B%2B-solutions
 */


// class Solution {
// public:
//     using Grid = vector<vector<char>>;
//     using Seen = unordered_map<int, unordered_map<int, bool>>;
//     using Dirs = vector<tuple<int, int>>;
//     int numIslands(Grid& A, int color = 0) {
//         auto M = A.size(),
//              N = M == 0 ? 0 : A[0].size();
//         for (auto i = 0; i < M; ++i)
//             for (auto j = 0; j < N; ++j)
//                 if (A[i][j] == '1')
//                     ++color, go(A, color, i, j);
//         return color;
//     }
// private:
//     Dirs dirs = {{-1,0},{0,1},{1,0},{0,-1}};
//     void go(Grid& A, int color, int i, int j, Seen&& seen = {}) {
//         auto M = A.size(),
//              N = M == 0 ? 0 : A[0].size();
//         if (i < 0 || i >= M || j < 0 || j >= N || A[i][j] != '1' || seen[i][j])
//             return;
//         A[i][j] += color;
//         seen[i][j] = true;
//         for (auto [u, v]: dirs)
//             go(A, color, i + u, j + v, move(seen));
//     }
// };

class Solution {
public:
    using Grid = vector<vector<char>>;
    int numIslands(Grid& A, int color = 0) {
        auto M = A.size(),
                N = M == 0 ? 0 : A[0].size();
        for (auto i = 0; i < M; ++i)
            for (auto j = 0; j < N; ++j)
                if (A[i][j] == '1')
                    ++color, bfs(A, color, i, j);
        return color;
    }
private:
    using Seen = unordered_map<int, unordered_map<int, bool>>;
    vector<vector<int>> dirs = {{-1,0},{0,1},{1,0},{0,-1}};
    void bfs(Grid& A, int color, int i, int j, Seen seen = {}) {
        auto M = A.size(),
                N = M == 0 ? 0 : A[0].size();
        queue<tuple<int, int>> q{{{i, j}}};
        seen[i][j] = true;
        while (!q.empty()) {
            auto [i, j] = q.front(); q.pop();
            A[i][j] += color;
            for (auto& dir: dirs) {
                int u = i + dir[0],
                        v = j + dir[1];
                if (u < 0 || u >= M || v < 0 || v >= N || A[u][v] != '1' || seen[u][v])
                    continue;
                q.push({u, v});
                seen[u][v] = true;
            }
        }
    }
};

int main() {
    Solution solution;
    Solution::Grid A{{'1','1','1','1','1','0','1','1','1','1','1','1','1','1','1','0','1','0','1','1'},{'0','1','1','1','1','1','1','1','1','1','1','1','1','0','1','1','1','1','1','0'},{'1','0','1','1','1','0','0','1','1','0','1','1','1','1','1','1','1','1','1','1'},{'1','1','1','1','0','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},{'1','0','0','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},{'1','0','1','1','1','1','1','1','0','1','1','1','0','1','1','1','0','1','1','1'},{'0','1','1','1','1','1','1','1','1','1','1','1','0','1','1','0','1','1','1','1'},{'1','1','1','1','1','1','1','1','1','1','1','1','0','1','1','1','1','0','1','1'},{'1','1','1','1','1','1','1','1','1','1','0','1','1','1','1','1','1','1','1','1'},{'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},{'0','1','1','1','1','1','1','1','0','1','1','1','1','1','1','1','1','1','1','1'},{'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},{'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},{'1','1','1','1','1','0','1','1','1','1','1','1','1','0','1','1','1','1','1','1'},{'1','0','1','1','1','1','1','0','1','1','1','0','1','1','1','1','0','1','1','1'},{'1','1','1','1','1','1','1','1','1','1','1','1','0','1','1','1','1','1','1','0'},{'1','1','1','1','1','1','1','1','1','1','1','1','1','0','1','1','1','1','0','0'},{'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},{'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},{'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'}};
    cout << solution.numIslands(A) << endl;
    return 0;
}

/*

iterate through A

upon A[i][j] == '1'
    increment count by 1
    perform DFS and update the island by coloring it (add count to it)

return count

*/

/*
class Solution {
public:
    using Grid = vector<vector<char>>;
    using Seen = unordered_map<int, unordered_map<int, bool>>;
    int numIslands(Grid& A, Seen seen = {}, int cnt = 0) {
        int M = A.size(),
                N = M == 0 ? 0 : A[0].size();
        for (auto i = 0; i < M; ++i) {
            for (auto j = 0; j < N; ++j) {
                if (A[i][j] != '1')
                    continue;
                dfs(A, M, N, seen, i, j, ++cnt);
            }
        }
        return cnt;
    }
private:
    using VI = vector<int>;
    using VVI = vector<VI>;
    VVI dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}}; // 👆, 👉, 👇, 👈
    void dfs(Grid& A, int M, int N, Seen& seen, int i, int j, int cnt) {
        if (!(0 <= i && i < M && 0 <= j && j < N) || A[i][j] != '1' || seen[i][j])
            return;
        A[i][j] += cnt;
        seen[i][j] = true;
        for (auto& dir: dirs) {
            dfs(A, M, N, seen, i + dir[0], j + dir[1], cnt);
        }

    }
};
*/