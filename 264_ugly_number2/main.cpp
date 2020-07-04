/*
 * 264. Ugly Number II
 *
 * Q: https://leetcode.com/problems/ugly-number-ii/
 * A: https://leetcode.com/problems/ugly-number-ii/discuss/719537/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
    using LL = long long;
    using VLL = vector<LL>;
    using Queue = priority_queue<LL, VLL, greater<LL>>;
    using Set = unordered_set<LL>;
    int nthUglyNumber(int N, Queue q = {}, Set seen = {}) {
        q.push(1), seen.insert(1);
        while (--N) {
            auto i = q.top(); q.pop(); // ⭐️ i-th ugly number
            for (auto factor: VLL{ 2, 3, 5 })
                if (seen.insert(i * factor).second) q.push(i * factor); // 👀 push unseen i-th factors onto q
        }
        return q.top(); // 🎯 N-th ugly number
    }
};

int main() {
    Solution solution;
    cout << solution.nthUglyNumber(10) << endl;
    return 0;
}
