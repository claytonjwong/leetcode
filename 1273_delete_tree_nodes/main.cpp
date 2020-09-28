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
    using Queue = queue<int>;
    int deleteTreeNodes(int N, VI& P, VI& total, int pruned = 0) {
        VI degree(N, 0);
        for (auto parent: P)
            if (parent != -1)
                ++degree[parent];
        Queue q;
        for (auto i{ 0 }; i < N; ++i)
            if (!degree[i])
                q.push(i);
        VI nodes(N, 1);
        while (q.size()) {
            auto child = q.front(); q.pop();
            auto parent = P[child];
            if (!total[child]) {
                pruned += nodes[child];
            } else if (parent != -1) {
                nodes[parent] += nodes[child];
                total[parent] += total[child];
            }
            if (parent != -1 && !--degree[parent])
                q.push(parent);
        }
        return N - pruned;
    }
};

int main() {
    Solution solution;
    auto N = 7;
    Solution::VI parent{-1,0,0,1,2,2,2}, value{1,-2,4,0,-2,-1,-1};
    cout << solution.deleteTreeNodes(N, parent, value) << endl;
    return 0;
}
