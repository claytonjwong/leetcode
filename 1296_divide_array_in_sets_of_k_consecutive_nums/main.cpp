/*
 * 1296. Divide Array in Sets of K Consecutive Numbers
 *
 * Q: https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/
 * A: https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/discuss/460543/Javascript-and-C%2B%2B-solutions
 */
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    using Map = map<int, int>;
    bool isPossibleDivide(vector<int>& A, int K, Map m = {}) {
        for (auto x: A)
            ++m[x];
        for (auto it = m.begin(); it != m.end(); ++it) {
            auto [x, need] = make_tuple(it->first, it->second); // need = m[x]
            if (need == 0)
                continue;
            for (auto i = 0; i < K; ++i) {
                auto [y, has] = make_tuple(x + i, m[x + i]);
                if (has < need)
                    return false;
                m[y] -= need;
            }
        }
        return true;
    }
};

int main() {
    Solution solution;
    vector<int> A = { 1,2,3,4 };
    cout << solution.isPossibleDivide(A, 3) << endl;
    return 0;
}
