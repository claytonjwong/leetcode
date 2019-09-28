/*
 * Weekly Contest 154
 * Sep 15, 2019 at 3:44 PM
 * 1 h 30 m	12/19	1:26:30	3/4	869/4765
 *
 * Q1: https://leetcode.com/problems/maximum-number-of-balloons/
 * A1: https://leetcode.com/problems/maximum-number-of-balloons/discuss/383197/C%2B%2B-Solution
 *
 * Q2: https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/
 * A2: https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/discuss/383205/C%2B%2B-Solution
 *
 * Q3: https://leetcode.com/problems/k-concatenation-maximum-sum/
 * A3: https://leetcode.com/problems/k-concatenation-maximum-sum/discuss/383239/C%2B%2B-Solution
 *
 */

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <algorithm>
#include <iterator>
#include <sstream>

using namespace std;

/*

 In order to spell "balloon", we need

 1 a
 1 b
 2 l
 2 o
 1 n

 Iterate through characters of text from left -> right and count the # of a, b, l, o, n

 Divide l and o count by 2

 return the minimum of the count of a, b, l, o, n

 */

/*
class Solution {
public:
    using Counter = unordered_map<char, int>;
    int maxNumberOfBalloons(string text) {
        Counter cnt;
        for (auto ch: text) {
            ++cnt[ch];
        }
        cnt['l'] >>= 1, cnt['o'] >>= 1;
        return min({cnt['a'], cnt['b'], cnt['l'], cnt['o'], cnt['n']});
    }
};

int main() {
    Solution solution;
    cout << solution.maxNumberOfBalloons("nlaebolko") << endl;
    cout << solution.maxNumberOfBalloons("loonbalxballpoon") << endl;
    cout << solution.maxNumberOfBalloons("leetcode") << endl;
    cout << solution.maxNumberOfBalloons("balon") << endl;
    return 0;
}
*/

/*

 Recursive solution using a stack

 text = ""
 for each character in the string
    if the character is a letter
        append character onto text
    if the character is (
        push text onto the stack and reset text = ""
    if the character is )
        pop value from stack, reverse it, and append it onto text
 return text

 */

/*
class Solution {
public:
    using Stack = vector<string>;
    string reverseParentheses(string s, string t={}, Stack last={}) {
        for (auto ch: s) {
            if (isalpha(ch)) {
                t.push_back(ch);
            } else if (ch == '(') {
                last.push_back(t);
                t.clear();
            } else if (ch == ')') {
                t = last.back().append({t.rbegin(), t.rend()});
                last.pop_back();
            }
        }
        return t;
    }
};

int main() {
    Solution solution;
    cout << solution.reverseParentheses("(abcd)") << endl;
    cout << solution.reverseParentheses("(u(love)i)") << endl;
    cout << solution.reverseParentheses("(ed(et(oc))el)") << endl;
    cout << solution.reverseParentheses("a(bcdefghijkl(mno)p)q") << endl;
    return 0;
}
*/

/*

 Use cases:

 * if A contains all positive numbers, then return the accumulated sum times k mod 1e9+7
 * if A contains all negative numbers, then return 0


 */


class Solution {
public:
    using LL = long long;
    static constexpr auto MOD = static_cast<int>(1e9 + 7);
    static constexpr auto INF = static_cast<int>(1e4 + 1);
    int kConcatenationMaxSum(vector<int>& A, int k) {
        auto [minIt, maxIt] = minmax_element(A.begin(), A.end());
        LL sum = 0, ans1 = 0, ans2 = 0, ans3 = 0;
        tie(sum, ans1) = kadane(A);
        tie(sum, ans2) = kadane(A, sum);
        tie(sum, ans3) = kadane(A, sum);
        LL delta1 = ans2 - ans1, delta2 = ans3 - ans2;
        return k == 1 || delta1 == 0 ? ans1 : delta2 == 0 ? ans2 : ans1 + (delta1 * (k-1) % MOD);
    }
private:
    pair<LL, LL> kadane(const vector<int>& A, LL sum=0, LL ans=-INF) {
        for (auto i=0; i < A.size(); ++i) {
            sum = max(0LL, sum + A[i] % MOD);
            ans = max(ans, sum);
        }
        return {sum, ans};
    }
};

int main() {
    Solution solution;
    vector<int> A{1,2}, B{1,-2,1}, C{-1,-2}, D{-5,-2,0,0,3,9,-2,-5,4};
    cout << solution.kConcatenationMaxSum(A, 3) << endl;
    cout << solution.kConcatenationMaxSum(B, 5) << endl;
    cout << solution.kConcatenationMaxSum(C, 7) << endl;
    cout << solution.kConcatenationMaxSum(D, 5) << endl;
    return 0;
}


/*
// wrong algorithm -- doesn't find what i'm looking for, only finds "leaf" nodes
class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    using AdjList = unordered_map<int, VI>;
    using Answer = set<VI>;
    VVI criticalConnections(int n, VVI& graph, AdjList adjList={}, Answer ans={}) {
        for (auto edge: graph) {
            auto [u, v] = tie(edge[0], edge[1]);
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        for (auto pair: adjList) {
            auto u = pair.first;
            auto adj = pair.second;
            if (adj.size() == 1) {
                set<int> critical{u, adj[0]}; // sort critical connection end-points u -> v
                ans.insert({critical.begin(), critical.end()});
            }
        }
        return {ans.begin(), ans.end()};
    }
};

int main() {
    Solution::VVI G{
        {0, 1},
        {1, 2},
        {2, 0},
        {1, 3},
    };
    Solution solution;
    auto ans = solution.criticalConnections(4, G);
    for (auto i=0; i < ans.size(); ++i, cout << endl) {
        copy(ans[i].begin(), ans[i].end(), ostream_iterator<int>(cout, " "));
    }
    return 0;
}
*/
