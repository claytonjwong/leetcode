/*
 * 1462. Course Schedule IV
 *
 * Q: https://leetcode.com/problems/course-schedule-iv/
 * A: https://leetcode.com/problems/course-schedule-iv/discuss/660619/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    using VB = vector<bool>;
    using VI = vector<int>;
    using VVI = vector<VI>;
    using Set = unordered_set<int>;
    using Map = unordered_map<int, Set>;
    VB checkIfPrerequisite(int N, VVI& E, VVI& queries, Map m = {}, VB ans = {}) {
        for (auto& edge: E) {
            auto [u, v] = tie(edge[0], edge[1]);
            m[u].insert(v);
        }
        for (auto& query: queries) {
            auto [beg, end] = tie(query[0], query[1]);
            ans.push_back(dfs(m, beg, end));
        }
        return ans;
    }
private:
    bool dfs(Map& m, int i, int target, Set&& seen = {}, bool found = false) {
        if (i == target)
            return true;
        if (!seen.insert(i).second)
            return false;
        for (auto j: m[i])
            found |= dfs(m, j, target, move(seen));
        return found;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
