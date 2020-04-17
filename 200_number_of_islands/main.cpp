/*
 * 200. Number of Islands
 *
 * Q: https://leetcode.com/problems/number-of-islands/
 * A: https://leetcode.com/problems/number-of-islands/discuss/583920/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    using Grid = vector<vector<char>>;
    using Seen = unordered_map<int, unordered_map<int, bool>>;
    int numIslands(Grid& A, Seen seen = {}, int cnt = 0) {
        int M = A.size(),
                N = !M ? 0 : A[0].size();
        for (auto i{ 0 }; i < M; ++i)
            for (auto j{ 0 }; j < N; ++j)
                if (A[i][j] == '1' && !seen[i][j])
                    dfs(A, seen, i, j), ++cnt;
        return cnt;
    }
private:
    using Dirs = vector<pair<int, int>>;
    void dfs(Grid& A, Seen& seen, int i, int j) {
        if (i == -1 || i == A.size() || j == -1 || j == A[0].size() || A[i][j] == '0' || seen[i][j])
            return;
        seen[i][j] = true;
        for (auto [u, v]: Dirs{{-1,0},{0,1},{1,0},{0,-1}})
            dfs(A, seen, i + u, j + v);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
