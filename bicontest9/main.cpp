/*

Biweekly Contest 9
Sep 23, 2019 at 3:48 PM
1 h 30 m	7/18	1:39:21	2/4	1278/2143

https://leetcode.com/contest/biweekly-contest-9

 */

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <queue>

using namespace std;

class Solution {
public:
    int maxNumberOfApples(vector<int>& A, int cap=5000, int ans=0) {
        sort(A.begin(), A.end());
        for (auto weight: A)
            if (cap - weight >= 0)
                cap -= weight, ++ans;
        return ans;
    }
};

int main() {
    vector<int> A{684,549,656,651,229,188,862,977,346,999,40,888,867,83,871,722,840,968,361,702,949,667,402,364,515,738,916,46,193,868,75,154,361,523,455,876,279,182,591,39,956,518,208,370,418,404,534,255,138,880,241,47,67,306,875,201,401,136,325,902,787,350,632,396,519,986,626,264,187,651,841,825,641,956,97,672,44,324,813,408,691,210,291,481,406,151,743,874,352,226,351,3,795,202,493,561,433,136,160,250};
    cout << Solution().maxNumberOfApples(A) << endl;
    return 0;
}

/*
class Solution {
public:
    using VI = vector<int>;
    using Moves = vector<VI>;
    using Queue = queue<VI>;
    using Seen = unordered_map<int, unordered_map<int, bool>>;
    int minKnightMoves(int x, int y, Queue q=Queue({VI{0,0}}), Seen seen={}, int depth=0, int ans=0) {
        x = abs(x), y = abs(y);
        Moves moves{{1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}};
        for (VI cur; !q.empty(); ++depth) {
            auto N = q.size();
            while (N--) {
                cur = q.front(), q.pop();
                auto [i, j] = tie(cur[0], cur[1]);
                if (i == x && j == y)
                    return depth;
                for (auto& move: moves) {
                    auto next_i = i + move[0],
                         next_j = j + move[1];
                    if (next_i < 0 || next_i > 300 || next_j < 0 || next_j > 300 || seen[next_i][next_j])
                        continue;
                    q.push({next_i, next_j});
                    seen[next_i][next_j] = true;
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;
    cout << solution.minKnightMoves(0, 0) << endl;
    cout << solution.minKnightMoves(1, 2) << endl;
    cout << solution.minKnightMoves(5, 5) << endl;
    cout << solution.minKnightMoves(-34, -156) << endl;
    cout << solution.minKnightMoves(300, 0) << endl;
    cout << solution.minKnightMoves(-27, -166) << endl;
    return 0;
}
*/
