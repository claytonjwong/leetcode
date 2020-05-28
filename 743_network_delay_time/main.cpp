/*
 * 743. Network Delay Time
 *
 * Q: https://leetcode.com/problems/network-delay-time/
 * A: https://leetcode.com/problems/network-delay-time/discuss/656011/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    int networkDelayTime(VVI& E, int N, int K, int INF = 1e9 + 7) {
        VI dist(N + 1, INF); // +1 for 1-based indexing
        dist[K] = 0;
        while (--N) {
            for (auto& edge: E) {
                auto [u, v, w] = tie(edge[0], edge[1], edge[2]);
                if (dist[v] > dist[u] + w)
                    dist[v] = dist[u] + w;
            }
        }
        auto max = *max_element(dist.begin() + 1, dist.end()); // +1 to exclude sentinel at index 0
        return max < INF ? max : -1;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
