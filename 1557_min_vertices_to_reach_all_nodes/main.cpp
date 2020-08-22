/*
 * 1557. Minimum Number of Vertices to Reach All Nodes
 *
 * Q: https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/
 * A: https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/discuss/805698/Javascript-Python3-C%2B%2B-In-Degree-0
 */

#include <iostream>
#include <vector>
#include <unordered_set>
#include <numeric>

using namespace std;

namespace Complicated {
    class Solution {
    public:
        using VI = vector<int>;
        using VVI = vector<VI>;
        VI findSmallestSetOfVertices(int N, VVI& E, VI ans = {}) {
            VI deg(N);
            for (auto& edge: E) {
                auto [_, tail] = tie(edge[0], edge[1]);
                ++deg[tail];
            }
            for (auto i{ 0 }; i < N; ++i)
                if (!deg[i])
                    ans.push_back(i);
            return ans;
        }
    };
}

namespace Simplified {
    class Solution {
    public:
        using VI = vector<int>;
        using VVI = vector<VI>;
        using Set = unordered_set<int>;
        VI findSmallestSetOfVertices(int N, VVI& E) {
            VI nodes(N); iota(nodes.begin(), nodes.end(), 0);
            Set all{ nodes.begin(), nodes.end() };
            for (auto& edge: E) {
                auto [_, tail] = tie(edge[0], edge[1]);
                all.erase(tail);
            }
            return { all.begin(), all.end() };
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
