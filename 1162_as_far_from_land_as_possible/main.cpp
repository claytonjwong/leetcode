/*
 * 1162. As Far from Land as Possible
 *
 * Q: https://leetcode.com/problems/as-far-from-land-as-possible/
 * A: https://leetcode.com/problems/as-far-from-land-as-possible/discuss/748163/Javascript-Python3-C%2B%2B-BFS-from-land-to-explore-water
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    using Grid = vector<vector<int>>;
    using Queue = queue<tuple<int, int>>;
    using Map = unordered_map<int, unordered_map<int, bool>>;
    using Dirs = vector<tuple<int,int>>;
    int maxDistance(Grid& A, Queue q = {}, Map seen = {}, int depth = 0) {
        int N = A.size();
        for (auto i{ 0 }; i < N; ++i)
            for (auto j{ 0 }; j < N; ++j)
                if (A[i][j])
                    q.push({ i, j }), seen[i][j] = true; // 🔍 init BFS queue with all 👀 seen land cells
        if (q.size() == N * N)
            return -1; // ⭐️ edge case 1: no water
        while (q.size()) {
            int k = q.size();
            while (k--) {
                auto [i, j] = q.front(); q.pop();
                for (auto [u, v]: Dirs{{i - 1, j}, {i, j + 1}, {i + 1, j}, {i, j - 1}}) // clockwise directions: [ 👆, 👉, 👇, 👈 ]
                    if (!(u < 0 || u == N || v < 0 || v == N || A[u][v] || seen[u][v])) // 🚌 BFS explore 👀 unseen water cells
                        q.push({ u, v }), seen[u][v] = true;
            }
            ++depth;
        }
        return depth - 1; // 🚌 BFS case: explored water from land, ending at max depth + 1 XOR ⭐️ edge case 2: no land
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
