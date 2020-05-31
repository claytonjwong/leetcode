/*
 * 1466. Reorder Routes to Make All Paths Lead to the City Zero
 *
 * Q: https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/
 * A: https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/discuss/661712/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

namespace Question3 {
    class Solution {
    public:
        using VI = vector<int>;
        using VVI = vector<VI>;
        using Set = unordered_set<int>;
        using Map = unordered_map<int, Set>;
        using Roads = unordered_set<string>;
        int minReorder(int N, VVI& E, Map m = {}, Roads roads = {}, int ans = 0) {
            auto key = [](auto u, auto v) { stringstream ss; ss << u << "," << v; return ss.str(); };
            auto addRoad = [&](auto u, auto v) { roads.insert(key(u, v)); };
            auto hasRoad = [&](auto u, auto v) { return roads.find(key(u, v)) != roads.end(); };
            for (auto& edge: E) {
                auto [u, v] = tie(edge[0], edge[1]);
                m[u].insert(v);
                m[v].insert(u);
                addRoad(v, u);
            }
            queue<int> q{{ 0 }};
            Set seen{ 0 };
            while (!q.empty()) {
                auto u = q.front(); q.pop();
                for (auto v: m[u]) {
                    if (seen.find(v) != seen.end())
                        continue;
                    if (!hasRoad(u, v))
                        ++ans;
                    q.push(v), seen.insert(v);
                }
            }
            return ans;
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
