/*
 * 773. Sliding Puzzle
 *
 * Q: https://leetcode.com/problems/sliding-puzzle/
 * A: https://leetcode.com/problems/sliding-puzzle/discuss/113694/C%2B%2B-BFS-with-explanation-and-example-(-EASY-to-understand-)
 */

#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    using Queue = queue<string>;
    using Set = unordered_set<string>;
    int slidingPuzzle(VVI& A, string T = "123450", VVI adj = {{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}}, int depth = 0) {
        stringstream ss; for (auto& row: A) copy(row.begin(), row.end(), ostream_iterator<int>(ss, ""));
        Queue q{{ ss.str() }};
        Set seen{ ss.str() };
        while (q.size()) {
            int k = q.size();
            while (k--) {
                auto cur = q.front(); q.pop();
                if (cur == T) // 🎯 target T found
                    return depth;
                auto i = cur.find('0');
                for (auto j: adj[i]) {
                    auto next{ cur };
                    swap(next[i], next[j]);
                    if (seen.insert(next).second)
                        q.push(next);
                }
            }
            ++depth;
        }
        return -1;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
