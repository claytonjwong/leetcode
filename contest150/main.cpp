/*
 * Rank	        Name	        Score	Finish Time 	Q1 (3)	    Q2 (4)	        Q3 (5)  	Q4 (7)
 * 2413 / 5338	claytonjwong 	7	    0:40:45	        0:09:48	    0:30:45  *2
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <sstream>

using namespace std;

/*
class Solution {
public:
    using Counter = unordered_map<char, int>;
    int countCharacters(vector<string>& words, string chars, int ans=0) {
        auto bucket = counter(chars);
        for(auto word: words) {
            auto ok = true;
            auto cur = counter(word);
            for(auto& pair: cur) {
                auto ch = pair.first;
                auto cnt = pair.second;
                if (bucket[ch] < cnt) {
                    ok = false;
                    break;
                }
            }
            if (ok)
                ans += word.size();
        }
        return ans;
    }
private:
    Counter counter(const string& str, Counter cnt={}) {
        for (auto ch: str)
            ++cnt[ch];
        return cnt;
    }
};

int main() {
    Solution solution;
    vector<string> words{"hello","world","leetcode"};
    auto ans = solution.countCharacters(words,"welldonehoneyr");
    cout << ans << endl;
    return 0;
}
*/

/*
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int val_) : val{val_}, left{nullptr}, right{nullptr} {}
};

class Solution {
public:
    using Sum = vector<int>;
    static constexpr int INF = static_cast<int>(1e5+1);
    int maxLevelSum(TreeNode* root, Sum sum=Sum(16, 0)) {
        if (root) {
            go(root, sum);
        }
        auto it = max_element(sum.begin(), sum.end());
        return distance(sum.begin(), it) + 1; // +1 for 1-based indexing
    }
private:
    void go(TreeNode* root, Sum& sum, int depth=0) {
        sum[depth] += root->val;
        if (root->left) go(root->left, sum, depth+1);
        if (root->right) go(root->right, sum, depth+1);
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(7);
    root->right = new TreeNode(0);
    root->left->left = new TreeNode(7);
    root->left->right = new TreeNode(-8);
    auto ans = Solution().maxLevelSum(root);
    cout << ans << endl;
    return 0;
}
 */

/*
// TLE
class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    static constexpr int INF = 101, OUT = 102;

    int maxDistance(VVI& grid, int ans=0) {
        if (grid.size() == 1 && grid[0].size() == 1) // If no land or water exists in the grid, return -1
            return -1;
        auto M = static_cast<int>(grid.size()),
             N = static_cast<int>(grid[0].size());
        VVI dist(M, VI(N, INF));
        for (auto i=0; i < M; ++i)
            for (auto j=0; j < N; ++j)
                bfs(grid, dist, M, N, i, j);
        for (auto i=0; i < M; ++i)
            for (auto j=0; j < N; ++j)
                if (dist[i][j] != INF && ans < dist[i][j])
                    ans = dist[i][j];
        if (ans == 0 || ans >= INF)
            return -1;
        return ans;
    }
private:
    using Seen = unordered_set<string>;
    void bfs(const VVI& grid, VVI& dist, const int M, const int N, int i, int j, Seen seen={}) {
        if (!(0<=i && i<M && 0<=j && j<N))
            return;
        queue<pair<int,int>> q({{i,j}});
        while (!q.empty()) {
            auto i = q.front().first,
                 j = q.front().second;
            q.pop();
            if (!seen.insert(key(i, j)).second)
                continue;
            auto U = value(grid, dist, M, N, i-1, j),
                 D = value(grid, dist, M, N, i+1, j),
                 L = value(grid, dist, M, N, i, j-1),
                 R = value(grid, dist, M, N, i, j+1);
            auto minimum = min({U, D, L, R});
            dist[i][j] = grid[i][j] == 1 ? 0 : min(dist[i][j], minimum + 1);
            if (U != OUT) q.push({i-1, j});
            if (D != OUT) q.push({i+1, j});
            if (L != OUT) q.push({i,j-1});
            if (R != OUT) q.push({i, j+1});
        }
    }
    int value(const VVI& grid, const VVI& dist, const int M, const int N, const int i, const int j) {
        if (!(0<=i && i<M && 0<=j && j<N))
            return OUT;
        return dist[i][j];
    }
    string key(const int i, const int j) {
        stringstream stream;
        stream << i << "," << j;
        return stream.str();
    }
};

int main() {
    Solution solution;
    Solution::VVI grid{{0,0,1,1,1},{0,1,1,0,0},{0,0,1,1,0},{1,0,0,0,0},{1,1,0,0,1}};
    auto ans = solution.maxDistance(grid);
    cout << ans << endl;
    return 0;
}
*/

/*

 set ans = 0

 land: cell of value 1
 water: cell of value <= 0

 use case: land and water

     for each grid row -> i
        for each grid col -> j
            if grid[i][j] is land
                then perform dfs through each adjacent water cell and update the cell's value (decrement for each hop)
     for each grid row -> i
        for each grid col -> j
            if grid[i][j] is water
                then check and set ans to the minimum of itself and the cell's value

 use case: no land or no water -> ans == 0, return -1

 otherwise return -ans ( ie. negative of a negative is positive )

 */

class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    int maxDistance(VVI& grid, int ans=0) {
        if (grid.empty() || grid[0].empty()) {
            return -1;
        }
        auto M = static_cast<int>(grid.size()), N = static_cast<int>(grid[0].size());
        for (auto i=0; i < M; ++i) {
            for (auto j=0; j < N; ++j) {
                if (grid[i][j] == 1) {
                    bfs(grid, i, j);
                }
            }
        }
        for (auto i=0; i < M; ++i) {
            for (auto j=0; j < N; ++j) {
                if (ans > grid[i][j]) {
                    ans = grid[i][j];
                }
            }
        }
        return ans < 0 ? -ans : -1;
    }
private:
    using Seen = unordered_set<string>;
    using Queue = queue<pair<int, int>>;
    string hash(int i, int j) {
        stringstream stream;
        stream << i << "," << j;
        return stream.str();
    }
    bool isOK(VVI& grid, int i, int j) {
        return 0 <= i && i < grid.size() && 0 <= j && j < grid[0].size();
    }
    void bfs(VVI& grid, int i, int j, Seen seen={}) {
        Queue q({{i, j}});
        for (auto len=0; !q.empty(); --len) {
            auto N = q.size();
            while (N--) {
                i = q.front().first;
                j = q.front().second;
                q.pop();
                auto key = hash(i, j);
                if (!seen.insert(key).second) {
                    return;
                }
                if (grid[i][j] == 0 || grid[i][j] < len) { // only update water cells
                    grid[i][j] = len;
                }
                VVI dirs{{-1,0}, {0,1}, {1,0}, {0,-1}};
                for (auto dir: dirs) {
                    if (isOK(grid, i+dir[0], j+dir[1])) {
                        q.push({i+dir[0], j+dir[1]});
                    }
                }
            }
        }
    }
};

int main() {
    Solution solution;
    vector<vector<int>> grid {
        {1, 0, 0},
        {0, 0, 0},
        {0, 0, 0},
    };
    auto ans = solution.maxDistance(grid);
    cout << ans << endl;
    return 0;
}

