/*
 * 886. Possible Bipartition
 *
 * Q: https://leetcode.com/problems/possible-bipartition/
 * A: https://leetcode.com/problems/possible-bipartition/discuss/655306/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    using Set = unordered_set<int>;
    using Map = unordered_map<int, Set>;
    bool possibleBipartition(int N, VVI& E, Map m = {}, queue<int> q = {}, Set seen = {}) {
        for (auto& edge: E) {
            auto [u, v] = tie(edge[0], edge[1]);
            m[u].insert(v);
            m[v].insert(u);
        }
        VI color(N + 1, -1); // +1 for 1-based indexing, -1 == no color
        while (N--) {
            if (seen.insert(N).second) // first time N is seen 👀
                q.push(N);
            while (!q.empty()) {
                auto cur = q.front(); q.pop();
                if (color[cur] == -1)
                    color[cur] = 0; // arbitrary default choice for color (this could also be 1)
                for (auto adj: m[cur]) {
                    if (color[adj] == color[cur]) // adjacent node with same color ❌
                        return false;
                    if (!seen.insert(adj).second) // adjacent node already seen 👀
                        continue;
                    color[adj] = color[cur] ^ 1;
                    q.push(adj);
                }
            }
        }
        return true; // all adjacent nodes have opposite colors ✅
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
