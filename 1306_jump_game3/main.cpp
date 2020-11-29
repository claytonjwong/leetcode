/*
 * 1306. Jump Game III
 *
 * Q: https://leetcode.com/problems/jump-game-iii/
 * A: https://leetcode.com/problems/jump-game-iii/discuss/464420/Kt-Js-Py3-Cpp-BFS-%2B-DFS
 */

#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

namespace BFS {
    class Solution {
    public:
        using VI = vector<int>;
        using Set = unordered_set<int>;
        using Queue = queue<int>;
        bool canReach(VI& A, int start, Set seen = {}) {
            Queue q{{ start }};
            while (q.size()) {
                auto i = q.front(); q.pop();
                if (!A[i])
                    return true;
                for (auto j: VI{ i + A[i], i - A[i] })
                    if (0 <= j && j < A.size() && seen.insert(j).second)
                        q.push(j);
            }
            return false;
        }
    };
}
namespace DFS {
    class Solution {
    public:
        using VI = vector<int>;
        using Set = unordered_set<int>;
        using fun = function<bool(int)>;
        bool canReach(VI& A, int start, Set seen = {}) {
            fun go = [&](auto i) {
                if (i < 0 || A.size() <= i || !seen.insert(i).second)
                    return false;
                if (!A[i])
                    return true;
                return go(i + A[i]) || go(i - A[i]);
            };
            return go(start);
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
