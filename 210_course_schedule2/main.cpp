/*
 * 210. Course Schedule II
 *
 * Q: https://leetcode.com/problems/course-schedule-ii/
 * A: https://leetcode.com/problems/course-schedule-ii/discuss/742411/Javascript-Python3-C%2B%2B-DFS-%2B-BFS-Pruning
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

namespace BFS {
    class Solution {
    public:
        using VI = vector<int>;
        using VVI = vector<VI>;
        VI findOrder(int N, VVI& A, VI ans = {}) {
            VVI adj(N); // adjacent children
            VI cnt(N);  // incoming edge count
            for (auto& edge: A) {
                auto [v, u] = tie(edge[0], edge[1]);
                adj[u].push_back(v);
                ++cnt[v];
            }
            // ⭐️ BFS pruning of nodes with no incoming edge count
            queue<int> q;
            for (auto i{ 0 }; i < N; ++i)
                if (!cnt[i])
                    q.push(i);
            while (q.size()) {
                auto u = q.front(); q.pop();
                ans.push_back(u); // 🎯 bfs pruned
                for (auto v: adj[u])
                    if (!--cnt[v])
                        q.push(v);
            }
            return ans.size() == N ? ans : VI{};
        }
    };
}

namespace DFS {
    class Solution {
        using VI = vector<int>;
        using VVI = vector<VI>;
        using Map = unordered_map<int, bool>;
        VVI A, adj;
        int N;
        VI ans;
        Map visited;
        bool go(int u, Map&& visiting = {}) {
            if (visited[u])  // 🤔 🔍 already visited
                return true;
            if (visiting[u]) // ❌ cycle
                return false;
            visiting[u] = true;  // 👀 ephemeral visiting: ✅ forward-tracking
            for (auto v: adj[u])
                if (!go(v, move(visiting)))
                    return false;
            visiting[u] = false; // 👀 ephemeral visiting: 🚫 back-tracking
            visited[u] = true; // 🤔 📌 permanent visited
            ans.push_back(u); // 🎯 the answer is dfs pruned in reverse order, ie. as the recusive stack unwinds
            return true;
        }
    public:
        VI findOrder(int N_, VVI& A_) {
            N = N_;
            A = A_;
            adj = VVI(N); // adjacent children
            for (auto& edge: A) {
                auto [v, u] = tie(edge[0], edge[1]);
                adj[u].push_back(v);
            }
            for (auto i{ 0 }; i < N; ++i)
                if (!go(i))
                    return {};
            return { ans.rbegin(), ans.rend() }; // 🎯 the answer is dfs constructed in reverse order
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
