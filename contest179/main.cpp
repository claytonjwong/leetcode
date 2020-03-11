/*
 * https://leetcode.com/contest/weekly-contest-179
 *
 * Rank         Name           Score    Finish Time      Q1 (3)     Q2 (4)    Q3 (5)       Q4 (6)
 * 3152 / 9847	claytonjwong   12       1:36:38          0:08:37    0:17:47   1:26:38  *2
 */

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <algorithm>
#include <iterator>

using namespace std;

/*
 * 1374. Generate a String With Characters That Have Odd Counts
 *
 * Q: https://leetcode.com/problems/generate-a-string-with-characters-that-have-odd-counts/
 * A: https://leetcode.com/problems/generate-a-string-with-characters-that-have-odd-counts/discuss/534396/Javascript-and-C%2B%2B-solutions
 */

//class Solution {
//public:
//    string generateTheString(int N, string ans = {}) {
//        fill_n(back_inserter(ans), N - 1, 'a');
//        ans.push_back(N % 2 ? 'a' : 'b');
//        return ans;
//    }
//};

//class Solution {
//public:
//    string generateTheString(int N) {
//        return string(N - 1, 'a') + (N % 2 ? 'a' : 'b');
//    }
//};

/*
 * 1375. Bulb Switcher III
 *
 * Q: https://leetcode.com/problems/bulb-switcher-iii
 * A: https://leetcode.com/problems/bulb-switcher-iii/discuss/532580/Javascript-solution
 */

//class Solution {
//public:
//    using VI = vector<int>;
//    int numTimesAllBlue(VI& A, int max = 0, int ans = 0) {
//        for (auto i = 0; i < A.size(); ++i) {
//            max = std::max(max, A[i]);
//            if (max == i + 1)
//                ++ans;
//        }
//        return ans;
//    }
//};

/*
 * 1376. Time Needed to Inform All Employees
 *
 * Q: https://leetcode.com/problems/time-needed-to-inform-all-employees/
 * A: https://leetcode.com/problems/time-needed-to-inform-all-employees/discuss/534379/Javascript-and-C%2B%2B-solutions
 */

//class Solution {
//public:
//    using VI = vector<int>;
//    using Map = unordered_map<int, VI>;
//    int numOfMinutes(int N, int root, VI& parent, VI& cost, Map adj = {}) {
//        for (auto i = 0; i < N; ++i)
//            if (parent[i] > -1)
//                adj[parent[i]].push_back(i);
//        return go(root, cost, adj);
//    }
//private:
//    int go(int i, VI& cost, Map& adj, int max = 0) {
//        for (auto j: adj[i])
//            max = std::max(max, cost[i] + go(j, cost, adj));
//        return max;
//    }
//};

int main() {

    return 0;
}
