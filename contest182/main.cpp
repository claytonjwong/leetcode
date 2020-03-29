/*
 * https://leetcode.com/contest/weekly-contest-182/
 *
 * Rank            Name           Score   Finish Time   Q1 (3)     Q2 (4)     Q3 (5)    Q4 (8)
 * 1068 / 11694    claytonjwong   12      0:27:14       0:03:32    0:07:17	  0:27:14
 */

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <cmath>
#include <numeric>
#include <algorithm>
#include <iterator>
#include <cmath>

using namespace std;

/*
 * 1394. Find Lucky Integer in an Array
 *
 * Q1: https://leetcode.com/problems/find-lucky-integer-in-an-array/
 * A1: https://leetcode.com/problems/find-lucky-integer-in-an-array/discuss/554794/Javascript-and-C%2B%2B-solutions
 */

namespace Question1 {
    class Solution {
    public:
        using Map = map<int, int>;
        using VI = vector<int>;
        int findLucky(VI& A, Map m = {}) {
            for (auto x: A)
                ++m[x];
            for (auto it = m.rbegin(); it != m.rend(); ++it) {
                auto [k, v] = tie(it->first, it->second);
                if (k == v)
                    return v; // 🍀 lucky number 🍀
            }
            return -1;
        }
    };
}


/*
 * 1395. Count Number of Teams
 *
 * Q2: https://leetcode.com/problems/count-number-of-teams/
 * A2: https://leetcode.com/problems/count-number-of-teams/discuss/555491/Javascript-and-C%2B%2B-solutions
 */

namespace Question2 {
    class Solution {
    public:
        using VI = vector<int>;
        int numTeams(VI& A, int ans = 0) {
            int N = A.size();
            for (auto i{ 0 }; i < N; ++i)
                for (auto j{ i + 1 }; j < N; ++j)
                    for (auto k{ j + 1 }; k < N; ++k)
                        if ((A[i] < A[j] && A[j] < A[k]) || (A[i] > A[j] && A[j] > A[k]))
                            ++ans;
            return ans;
        }
    };
}


/*
 * 1396. Design Underground System
 *
 * Q3: https://leetcode.com/problems/design-underground-system/
 * A3: https://leetcode.com/problems/design-underground-system/discuss/554805/Javascript-and-C%2B%2B-solutions
 */

namespace Question3 {
//    class UndergroundSystem {
//    public:
//        void checkIn(int id, string s1, int t1) {
//            notes[id] = {s1, t1};
//        }
//        void checkOut(int id, string s2, int t2) {
//            auto [s1, t1] = notes[id];
//            edges[s1][s2].push_back(t2 - t1); // add edge (s1 👉 s2) with time delta abs(t1 -t2) ⏰
//        }
//        double getAverageTime(string s1, string s2) {
//            return accumulate(edges[s1][s2].begin(), edges[s1][s2].end(), 0.0) / edges[s1][s2].size();
//        }
//    private:
//        using Note = tuple<string, int>;
//        using Notes = unordered_map<int, Note>;
//        Notes notes; // { id: { source-station, check-in time }}
//        using Edges = unordered_map<string, unordered_map<string, vector<int>>>;
//        Edges edges; // { source: { destination: { time deltas }}}
//    };

    class UndergroundSystem {
    public:
        void checkIn(int id, string s1, int t1) {
            notes[id] = {s1, t1};
        }
        void checkOut(int id, string s2, int t2) {
            auto [s1, t1] = notes[id];
            auto& [total, cnt] = edges[s1][s2]; // update edge (s1 👉 s2) to include time delta abs(t1 -t2) ⏰
            total += (t2 - t1), ++cnt;
        }
        double getAverageTime(string s1, string s2) {
            auto [total, cnt] = edges[s1][s2];
            return total / cnt;
        }
    private:
        using Note = tuple<string, int>;
        using Notes = unordered_map<int, Note>;
        Notes notes; // { id: { source-station, check-in time }}
        using Edge = tuple<double, int>;
        using Edges = unordered_map<string, unordered_map<string, Edge>>;
        Edges edges; // { source: { destination: { total time, count of time entries }}}
    };
}

int main() {
    cout << "Hello World!" << endl;
    return 0;
}
