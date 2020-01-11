/*
 * 1273. Delete Tree Nodes
 *
 * Q: https://leetcode.com/problems/delete-tree-nodes/
 * A: https://leetcode.com/problems/delete-tree-nodes/discuss/476958/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    int deleteTreeNodes(int N, VI& parent, VI& value) {
        VVI children(N);
        for (auto i = 1; i < N; ++i) { // i-th child, j-th parent
            auto j = parent[i];
            children[j].push_back(i);
        }
        dfs(0, children, value);
        return bfs(0, children, value);
    }
private:
    int dfs(int node, VVI& children, VI& value, int sum = 0) {
        for (auto child: children[node])
            sum += dfs(child, children, value);
        return value[node] += sum;
    }
    int bfs(int node, VVI& children, VI& value, int cnt = 1) { // count starts at 1 to include the root
        for (queue<int> q{{children[node].begin(), children[node].end()}}; !q.empty(); q.pop()) {
            auto cur = q.front();
            if (value[cur] != 0) {
                ++cnt;
                for (auto child: children[cur])
                    q.push(child);
            }
        }
        return cnt;
    }
};

int main() {
    Solution solution;
    auto N = 7;
    Solution::VI parent{-1,0,0,1,2,2,2}, value{1,-2,4,0,-2,-1,-1};
    cout << solution.deleteTreeNodes(N, parent, value) << endl;
    return 0;
}
