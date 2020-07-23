/*
 * 1376. Time Needed to Inform All Employees
 *
 * Q: https://leetcode.com/problems/time-needed-to-inform-all-employees/
 * A: https://leetcode.com/problems/time-needed-to-inform-all-employees/discuss/534379/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

namespace DFS {
    class Solution {
        using VI = vector<int>;
        using Map = unordered_map<int, VI>;
        VI cost;
        Map adj;
        int go(int i, int max = 0) {
            for (auto j: adj[i])
                max = std::max(max, go(j));
            return cost[i] + max;
        }
    public:
        int numOfMinutes(int N, int root, VI& A, VI& cost_) {
            cost = cost_;
            for (auto i{ 0 }; i < N; ++i)
                if (-1 < A[i])
                    adj[A[i]].push_back(i);
            return go(root);
        }
    };
}

namespace BFS {
    class Solution {
    public:
        using VI = vector<int>;
        using Map = unordered_map<int, VI>;
        int numOfMinutes(int N, int root, VI& A, VI& cost, Map adj = {}, int max = 0) {
            for (auto i = 0; i < N; ++i)
                if (-1 < A[i])
                    adj[A[i]].push_back(i);
            VI dist(N);
            queue<int> q{{ root }};
            while (q.size()) {
                auto i = q.front(); q.pop();
                for (auto j: adj[i]) {
                    dist[j] = dist[i] + cost[i];
                    max = std::max(max, dist[j]);
                    q.push(j);
                }
            }
            return max;
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
