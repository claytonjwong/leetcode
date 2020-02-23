/*
 * https://leetcode.com/contest/weekly-contest-177
 *
 * Rank	            Name	        Score	Finish Time 	Q1 (4)	    Q2 (5)	    Q3 (5)	    Q4 (6)
 * 3855 / 9092	    claytonjwong 	9	    1:08:28	        1:08:28	    0:21:38
 */

#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

/*
 * 1360. Number of Days Between Two Dates
 *
 * Q: https://leetcode.com/problems/number-of-days-between-two-dates/
 * A: https://leetcode.com/problems/number-of-days-between-two-dates/discuss/517586/Javascript-and-C%2B%2B-solutions
 */

namespace Q1 {
    class Solution {
    public:
        int daysBetweenDates(string a, string b, int y1 = 0, int m1 = 0, int d1 = 0, int y2 = 0, int m2 = 0, int d2 = 0) {
            vector<int> monthDays{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};
            for (auto i = 1; i < monthDays.size(); ++i)
                monthDays[i] += monthDays[i - 1];
            a[4] = a[7] = ' ';
            b[4] = b[7] = ' ';
            stringstream ss1{a}, ss2{b};
            ss1 >> y1 >> m1 >> d1;
            ss2 >> y2 >> m2 >> d2;
            auto leapYears = [](auto y, auto m) {
                if (m <= 2)
                    --y; // don't count current year if month is Jab/Feb
                return y / 400 + y / 4 - y / 100;
            };
            auto x = (y1 * 365) + d1 + monthDays[m1 - 1] + leapYears(y1, m1),
                 y = (y2 * 365) + d2 + monthDays[m2 - 1] + leapYears(y2, m2);
            return abs(x - y);
        }
    };
}

/*
 * 1361. Validate Binary Tree Nodes
 *
 * Q: https://leetcode.com/problems/validate-binary-tree-nodes/
 * A: https://leetcode.com/problems/validate-binary-tree-nodes/discuss/517576/Javascript-and-C%2B%2B-solutions
 */

namespace Q2 {

//    class Solution {
//    public:
//        using VI = vector<int>;
//        using Q = queue<int>;
//        using Seen = unordered_set<int>;
//        bool validateBinaryTreeNodes(int N, VI& L, VI& R, Q q = Q{{0}}, Seen seen = Seen{0}) {
//            while (!q.empty()) {
//                auto cur = q.front(); q.pop();
//                auto l = L[cur],
//                     r = R[cur];
//                if ((l > -1 && seen.find(l) != seen.end()) || (r > -1 && seen.find(r) != seen.end()))
//                    return false;
//                if (l > -1) q.push(l), seen.insert(l);
//                if (r > -1) q.push(r), seen.insert(r);
//            }
//            return seen.size() == N;
//        }
//    };

    class Solution {
    public:
        using VI = vector<int>;
        bool validateBinaryTreeNodes(int N, VI& L, VI& R, VI P = {}) {
            generate_n(back_inserter(P), N, [i = -1]() mutable { return ++i; });
            auto join = [&](auto a, auto b) {
                a = find(P, a);
                b = find(P, b);
                if (a == b)
                    return false;
                P[a] = b; // arbitrary choice
                return true;
            };
            for (auto i = 0; i < N; ++i) {
                if (L[i] > -1 && !join(i, L[i])) return false;
                if (R[i] > -1 && !join(i, R[i])) return false;
            }
            auto rep = find(P, 0);
            for (auto i = 1; i < N; ++i)
                if (rep != find(P, i)) return false;
            return true;
        }
    private:
        int find(VI& P, int x) { return P[x] = P[x] == x ? P[x] : find(P, P[x]); };
    };
}

int main() {
    Q1::Solution solution;
    cout << solution.daysBetweenDates("2020-01-15", "2019-12-31") << endl;
    return 0;
}