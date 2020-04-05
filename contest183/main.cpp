/*
 * https://leetcode.com/contest/weekly-contest-183/
 *
 * Rank           Name           Score   Finish Time    Q1 (4)     Q2 (4)     Q3 (6)    Q4 (7)
 * 2373 / 12539	  claytonjwong   10      1:00:28                   0:10:59    1:00:28
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
#include <deque>

using namespace std;

/*
 * 1404. Number of Steps to Reduce a Number in Binary Representation to One
 *
 * Q: https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/
 * A: https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/discuss/564286/Javascript-and-C%2B%2B-solutions
 */
namespace Question2 {
    class Solution {
    public:
        int numSteps(string s, deque<int> A = {}, int steps = 0) {
            transform(s.begin(), s.end(), back_inserter(A), [](auto c) { return int(c == '1'); });
            auto div = [&]() {
                A.pop_back();
            };
            auto inc = [&]() {
                int N = A.size(), i = N - 1, carry = 1;
                A[i] = 0; // 1 + 1 = 0 and carry = 1
                while (--i >= 0 && carry)
                    if (A[i])
                        A[i] = 0; // 1 + 1 = 0 and carry = 1
                    else
                        A[i] = 1, // 0 + 1 = 1 and carry = 0
                                carry = 0;
                if (carry) A.push_front(1);
            };
            while (A.size() > 1) {
                if (A.back() == 0)
                    div();
                else
                    inc();
                ++steps;
            }
            return steps;
        }
    };
}

int main() {
    Question2::Solution solution;
    cout << solution.numSteps("1111011110000011100000110001011011110010111001010111110001") << endl;
    return 0;
}


/*
 * 1405. Longest Happy String
 *
 * Q: https://leetcode.com/problems/longest-happy-string/
 * A: https://leetcode.com/problems/longest-happy-string/discuss/565380/Javascript-and-C%2B%2B-solutions
 */
namespace Question3 {
    class Solution {
    public:
        using Map = unordered_map<char, int>;
        using VP = vector<pair<char, int>>;
        string longestDiverseString(int a, int b, int c, bool found = false, string ans = {}) {
            Map m{{'a', a}, {'b', b}, {'c', c}};
            do {
                found = false;
                VP A{m.begin(), m.end()};
                sort(A.begin(), A.end(), [](auto& a, auto& b) { return a.second > b.second; });
                auto N = ans.size();
                for (auto i{ 0 }; i < 3; ++i) {
                    auto [cur, cnt] = A[i];
                    if (cnt > 0 && (N < 2 || ans[N - 2] != cur || ans[N - 1] != cur)) {
                        ans.push_back(cur);
                        --m[cur];
                        found = true;
                        break;
                    }
                }
            } while (found);
            return ans;
        }
    };
}