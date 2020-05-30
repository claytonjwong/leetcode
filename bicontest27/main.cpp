/*
 * https://leetcode.com/contest/biweekly-contest-27
 *
 * Rank          Name           Score   Finish Time    Q1 (3)     Q2 (4)     Q3 (5)    Q4 (6)
 * 1156 / 7924   claytonjwong   12      0:36:02        0:03:19    0:17:38    0:36:02
 */

#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

/*
 * 1460. Make Two Arrays Equal by Reversing Sub-arrays
 *
 * Q: https://leetcode.com/problems/make-two-arrays-equal-by-reversing-sub-arrays/
 * A: https://leetcode.com/problems/make-two-arrays-equal-by-reversing-sub-arrays/discuss/660539/Javascript-and-C%2B%2B-solutions
 */
namespace Question1 {
    class Solution {
    public:
        using VI = vector<int>;
        using Map = unordered_map<int, int>;
        bool canBeEqual(VI& T, VI& A, Map m = {}) {
            for (auto x: T) ++m[x];
            for (auto x: A) --m[x];
            return all_of(m.begin(), m.end(), [](auto& pair) { return !pair.second; });
        }
    };
}

/*
 * 1461. Check If a String Contains All Binary Codes of Size K
 *
 * Q: https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/
 * A: https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/discuss/660632/Incorrect-problem-statement!!!
 */
namespace Question2 {
    class Solution {
    public:
        using Queue = deque<char>;
        using Set = unordered_set<string>;
        bool hasAllCodes(string S, int K, Queue q = {}, Set all = {}) {
            for (auto c: S) {
                q.push_back(c);
                if (q.size() == K) all.insert({ q.begin(), q.end() }), q.pop_front();
            }
            return all.size() == 1 << K;
        }
    };
}

/*
 * 1462. Course Schedule IV
 *
 * Q: https://leetcode.com/problems/course-schedule-iv/
 * A: https://leetcode.com/problems/course-schedule-iv/discuss/660619/Javascript-and-C%2B%2B-solutions
 */
namespace Question3 {
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
}

/*
 * 1463. Cherry Pickup II
 *
 * Q: https://leetcode.com/problems/cherry-pickup-ii/
 * A: https://leetcode.com/problems/cherry-pickup-ii/discuss/660828/Javascript-and-C%2B%2B-solutions
 */
namespace Question4 {
    namespace TopDown {
        class Solution {
        public:
            using VI = vector<int>;
            using VVI = vector<VI>;
            int cherryPickup(VVI& A) {
                int M = A.size(),
                    N = A[0].size();
                return go(A, 0, 0, N - 1);
            }
        private:
            int go(VVI& A, int i, int L, int R, int max = 0) {
                if (i == A.size())
                    return 0;
                for (auto p{ -1 }; p <= 1; ++p) { // L column offset: left, same, right
                    auto left = L + (0 < i ? p : 0);
                    if (!(0 <= left && left < A[0].size()))
                        continue;
                    for (auto q{ -1 }; q <= 1; ++q) { // R column offset: left, same, right
                        auto right = R + (0 < i ? q : 0);
                        if (!(0 <= right && right < A[0].size()) || right <= left) // pruning condition: right <= left is always a sub-optimal solution
                            continue;
                        auto cand = A[i][left] + (left != right ? A[i][right] : 0); // maximum candidate
                        max = std::max(max, cand + go(A, i + 1, left, right));
                    }
                }
                return max;
            }
        };
    }
    namespace TopDownMemo {
        class Solution {
        public:
            using VI = vector<int>;
            using VVI = vector<VI>;
            int cherryPickup(VVI& A) {
                int M = A.size(),
                    N = A[0].size();
                return go(A, 0, 0, N - 1);
            }
        private:
            using Memo = unordered_map<string, int>;
            int go(VVI& A, int i, int L, int R, Memo&& m = {}) {
                stringstream key; key << i << "," << L << "," << R;
                if (m.find(key.str()) != m.end())
                    return m[key.str()];
                if (i == A.size())
                    return m[key.str()] = 0;
                for (auto p{ -1 }; p <= 1; ++p) { // L column offset: left, same, right
                    auto left = L + (0 < i ? p : 0);
                    if (!(0 <= left && left < A[0].size()))
                        continue;
                    for (auto q{ -1 }; q <= 1; ++q) { // R column offset: left, same, right
                        auto right = R + (0 < i ? q : 0);
                        if (!(0 <= right && right < A[0].size()) || right <= left) // pruning condition: right <= left is always a sub-optimal solution
                            continue;
                        auto cand = A[i][left] + (left != right ? A[i][right] : 0); // maximum candidate
                        m[key.str()] = std::max(m[key.str()], cand + go(A, i + 1, left, right, move(m)));
                    }
                }
                return m[key.str()];
            }
        };
    }
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
