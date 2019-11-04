/*

Weekly Contest 161
Nov 03, 2019 at 12:32 PM
1 h 30 m	5/19	0:18:41	1/4	1584/4646

Q3: https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/
A3: https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/discuss/420213/Javascript-and-C%2B%2B-solutions

 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <sstream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <sstream>

using namespace std;

// inefficient first solution is accepted using depth score & traverses s in both directions to fix-it-up
/*
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        s = makeValid(s, '(', ')');
        s = makeValid({s.rbegin(), s.rend()}, ')', '(');
        return {s.rbegin(), s.rend()};
    }
private:
    string makeValid(const string& s, char beg, char end, int d=0, string res={}) {
        for (auto c: s) {
            d += c == beg ? 1 : c == end ? -1 : 0;
            if (d > -1)
                res.push_back(c);
            else
                d = 0; // skip past this
        }
        return res;
    }
};
*/

class Solution {
public:
    string minRemoveToMakeValid(string s, string t={}, unordered_set<int> del={}, vector<int> stack={}) {
        for (auto i=0; i < s.size(); ++i) {
            if (s[i] == '(')
                stack.push_back(i);
            if (s[i] == ')') {
                if (stack.empty())
                    del.insert(i);
                else
                    stack.pop_back();
            }
        }
        del.insert(stack.begin(), stack.end());
        for (auto i=0; i < s.size(); ++i)
            if (del.find(i) == del.end())
                t.push_back(s[i]);
        return t;
    }
};

int main() {

    Solution solution;
    cout << solution.minRemoveToMakeValid("))((") << endl;
    return 0;
}
