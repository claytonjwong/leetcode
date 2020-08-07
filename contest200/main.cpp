/*
 * https://leetcode.com/contest/weekly-contest-200/ranking/
 *
 * Rank            Name             Score    Finish Time    Q1 (3)     Q2 (4)     Q3 (5)    Q4 (6)
 * 8074 / 15381    claytonjwong     3        0:02:40        0:02:40
 *
 * Screenshare: https://www.youtube.com/watch?v=ZDOjZwHqTgU
 */

#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <numeric>
#include <algorithm>
#include <iterator>
#include <queue>

using namespace std;

/*
 * 1535. Find the Winner of an Array Game
 *
 * Q: https://leetcode.com/problems/find-the-winner-of-an-array-game/
 * A: https://leetcode.com/problems/find-the-winner-of-an-array-game/discuss/768447/Javascript-Python3-C%2B%2B-Deque-a-b-...-first-two-elements
 */

class Solution {
public:
    using VI = vector<int>;
    using Deque = deque<int>;
    int getWinner(VI& A, int K, int same = 0, int last = -1) {
        int N = A.size();
        if (N == 1 || K == 1)                         // 💎 edge cases
            return max(A[0], A[1]);
        if (N <= K)                                   // 💎 edge cases
            return *max_element(A.begin(), A.end());
        Deque q{ A.begin(), A.end() };
        for (;;) {                     // compare first two elements: A[ ✅ a, 🚫 b, ... ] 👀
            auto a = q.front(); q.pop_front();
            auto b = q.front(); q.pop_front();
            if (a < b)                 // case 1: ⭐️ diff winner 🚫 b, reset same to 1
                same = 1;
            if (b < a && ++same >= K)  // case 2: ⭐️ same winner ✅ a, increment same by 1
                return a;              //         🎯 same winner ✅ a, target K times
            q.push_front(max(a, b));   // push max to front 👈
            q.push_back(min(a, b));    // push min to back  👉
        }
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
