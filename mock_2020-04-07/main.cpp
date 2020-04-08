/*
Amazon- Online Assessment
Completed April 7, 2020 5:38 PM
88%
Your interview score of 7.11/10 beats 88% of all users.
Time Spent: 24 minutes 57 seconds
Time Allotted: 1 hour
*/

#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;


/*
 * 1122. Relative Sort Array
 *
 * Q: https://leetcode.com/problems/relative-sort-array/
 * A: https://leetcode.com/problems/relative-sort-array/discuss/568451/Javascript-and-C%2B%2B-solutions
 */
namespace Question1 {
    class Solution {
    public:
        using VI = vector<int>;
        using Map = unordered_map<int, int>;
        using Multiset = multiset<int>;
        VI relativeSortArray(VI& A, VI& order, Map m = {}, Multiset leftovers = {}, VI ans = {}) {
            for (auto x: order)
                m[x] = 0;
            for (auto x: A)
                if (m.find(x) != m.end())
                    ++m[x];
                else
                    leftovers.insert(x);
            for (auto x: order)
                fill_n(back_inserter(ans), m[x], x);
            copy(leftovers.begin(), leftovers.end(), back_inserter(ans));
            return ans;
        }
    };
}


/*
 * 1155. Number of Dice Rolls With Target Sum
 *
 * Q: https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/
 * A: https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/discuss/402767/Javascript-and-C%2B%2B-Solutions
 */

namespace Question2 {
    class Solution {
    public:
        int numRollsToTarget(int d, int f, int t) {
            return go(d, f, t);
        }
    private:
        using VI = vector<int>;
        using VVI = vector<VI>;
        int go(int d, int f, int t, VVI&& m = VVI(30 + 1, VI(1000 + 1, -1))) {
            if (m[d][t] > -1)
                return m[d][t];
            if (d == 0)
                return m[d][t] = int(t == 0);
            auto cnt{ 0 };
            for (auto i{ 1 }; i <= f; ++i)
                if (t - i >= 0)
                    cnt = (cnt + go(d - 1, f, t - i, move(m))) % int(1e9 + 7);
            return m[d][t] = cnt;
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
