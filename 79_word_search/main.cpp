/*
 * 79. Word Search
 *
 * Q: https://leetcode.com/problems/word-search/
 * A: https://leetcode.com/problems/word-search/discuss/747545/Javascript-Python3-C%2B%2B-DFS-%2B-BT
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    using Board = vector<vector<char>>;
    using Map = unordered_map<int, unordered_map<int, bool>>;
    using Dirs = vector<tuple<int, int>>;
    Board A;
    int M, N;
    string T, path;
    Map seen;
    bool go(int i, int j) {
        // 🛑 OOB, char mismatch, or already seen
        if (i < 0 || i == M || j < 0 || j == N || A[i][j] != T[path.size()] || seen[i][j])
            return false;
        // 🚀 DFS + BT
        path.push_back(A[i][j]), seen[i][j] = true; // 👀 path seen ✅ forward-tracking
        if (path.size() == T.size())
            return true; // ⭐️ path == target T 🎯
        for (auto [u, v]: Dirs{{i - 1, j}, {i, j + 1}, {i + 1, j}, {i, j - 1}}) // clockwise directions: [ 👆, 👉, 👇, 👈 ]
            if (go(u, v))
                return true;
        path.pop_back(), seen[i][j] = false;        // 👀 path seen 🚫 back-tracking
        return false;
    }
public:
    bool exist(Board& A_, string T_) {
        A = A_;
        T = T_;
        M = A.size();
        N = A[0].size();
        for (auto i{ 0 }; i < M; ++i)
            for (auto j{ 0 }; j < N; ++j)
                if (go(i, j))
                    return true;
        return false;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
